#include "Square.hpp"
#include <iostream>

using namespace std;

void Square::setPiece(Piece* piece) {
    currPiece = piece;
}

void Square::removePiece() {
    currPiece = nullptr;
    //hi
}