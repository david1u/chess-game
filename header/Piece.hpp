#ifndef PIECE_HPP
#define PIECE_HPP

class Piece {
 private:
    bool captured;
 public:
    virtual void captured() = 0;
    virtual void movePiece() = 0;
};

#endif