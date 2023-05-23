#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "Piece.hpp"

class Square {
 private:
    Piece* currPiece;
 public:
    void setPiece(Piece*);
    void removePiece();
};

#endif