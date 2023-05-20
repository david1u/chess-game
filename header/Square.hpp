#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "Piece.hpp"

class square {
 private:
    bool color;
    bool occupied;
    Piece currPiece;
 public:
    void setPiece(Piece &);
    void removePiece();
};

#endif