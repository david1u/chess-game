#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Piece.hpp"
#include "Board.hpp"


class Player {
   private:
      std::string name;
      //true represents white piece, false represents black piece
      bool blackWhite;
      std::vector<std::string> eliminated;
      std::map<char, int> letterToNum = {
         {'a', 0}, {'b', 1}, {'c', 2}, {'d', 3},
         {'e', 4}, {'f', 5}, {'g', 6}, {'h', 7}
      };
   public:
      Player(std::string name, bool color);
      bool getColor();
      bool makeMove(Board*);
      void surrender();
      void addEliminated(Piece*);
      void showEliminated() const;
      ~Player();
};
#endif