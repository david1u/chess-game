#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <vector>
#include <map>
#include "Piece.hpp"
#include "Board.hpp"


class Player {
 private:
    string name;
    //true represents white piece, false represents black piece
    bool blackWhite;
    vector<String> eliminated;
    map<char, int> letterToNum = {
        {'a', 0}, {'b', 1}, {'c', 2}, {'d', 3},
        {'e', 4}, {'f', 5}, {'g', 6}, {'h', 7}
    };
 public:
    bool getColor();
    void makeMove(Board*);
    void surrender();
    void addEliminated(Piece*);
    void showEliminated();
  
class Player
{
private:
   string name;
   // true represents white piece, false represents black piece
   bool white;
   vector<Piece *> eliminated;

public:
   Player(std::string name, bool white);
   void makeMove();
   void surrender();
   void addEliminated(Piece *);

   ~Player();
};

#endif