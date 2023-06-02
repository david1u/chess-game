#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <vector>
#include "Piece.hpp"

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