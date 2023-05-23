#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <vector>
#include "Piece.hpp"

class Player {
 private:
    string name;
    //true represents white piece, false represents black piece
    bool blackWhite;
    vector<Piece*> eliminated;
 public:
    void makeMove();
    void surrender();
    void addEliminated(Piece*);

    ~Player();
};

#endif