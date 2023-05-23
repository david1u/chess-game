#ifndef PIECE_HPP
#define PIECE_HPP

class Piece {
 private:
    //true represents white piece, false represents black piece
    bool blackWhite;
 public:
    virtual void movePiece() = 0;
};

#endif