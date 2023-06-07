#include "../header/Piece.hpp"
#include "../header/Board.hpp"
#include <cstdlib>


bool Pawn::move(int newX, int newY, Board &board) {
    if (enPassant) {
        return true;
    }
    
    if(!board.isFree(newX, newY)){
        Piece* enemyPiece = board.getPiece(newX, newY);
        if(enemyPiece->getColor() == this->getColor())
        return false;
    }

    bool jump2 = false;
    if(moveCount == 0){
        jump2 = true;
    }
    if(this->getColor()){
        if(this->getXCoord() - newX == 0 && this->getYCoord() - newY == 2){
        if(jump2){
            return true;
        }
        return false;
        }
        if(this->getXCoord() - newX == 0 && this->getYCoord() - newY == 1){
            return true;
        }
    }
    else{
        if(this->getXCoord() - newX == 0 && this->getYCoord() - newY == -2){
        if(jump2){
            return true;
        }
        return false;
        }
        if(this->getXCoord() - newX == 0 && this->getYCoord() - newY == -1){
            return true;
        }
    }
    

    return false;
}
bool Pawn::enPassant(int newX, int newY, Board &board) {
    //pawns must be next to each other
    //pawns must be enemies
    //enemy piece must have moved 2 spaces in 1 turn
    Piece* enemyPiece = board.getPiece(newX, this->getYCoord());
    if (enemyPiece == BLACK_PAWN || enemyPiece == WHITE_PAWN) {
        if (this->getColor() != enemyPiece->getColor()) {
            if (enemyPiece->getMoveCount() == 1 && (enemyPiece->getYCoord() == 4 || enemyPiece->getYCoord() == 5)) {
                enemyPiece->setYCoord = newY;
                return true;
            }
        }
    }

    return false;
}

bool Rook::move(int newX, int newY, Board &board) {
    //if both old x and y coords are same as new x and y coords
    // or if both old x and y coords are different from new x and y coords
    // or if the piece at the new coords is the same color as the rook
    //  return false
    if ((this->getXCoord() == newX && this->getYCoord() == newY)
     || (this->getXCoord() != newX && this->getYCoord() != newY)
     || (board.getPiece(newX, newY)->getColor() == this->getColor())) {
        return false;
    }

    //check if there are no pieces in the way from old coords to new coords
    Piece* movement = this;
    //calculate the x and y direction the piece will be moving in
    //-1 if piece moves left or down
    //1 if piece moves right or up
    //0 if piece doesn't move in that direction
    int xDirection = 0;
    int yDirection = 0;
    if (newX != this->getXCoord()) {
        xDirection = (newX - this->getXCoord()) / abs(newX - this->getXCoord());
    }
    if (newY != this->getYCoord()) {
        yDirection = (newY - this->getYCoord()) / abs(newY - this->getYCoord());
    }
    while ((movement->getXCoord() != newX) || (movement->getYCoord() != newY)) {
        //check to see if the piece is null
        if (movement != nullptr && movement != this) {
            return false;
        }
        //move the piece 1 space over
        movement = board.getPiece(movement->getXCoord() + xDirection, movement->getYCoord() + yDirection);
    }

    return true;
}

bool Knight::move(int newX, int newY, Board &board) {   
    if(!board.isFree(newX, newY)){
        Piece* enemyPiece = board.getPiece(newX, newY);
        if(enemyPiece->getColor() == this->getColor())
        return false;
    }  
    if((abs(newX - this->getXCoord()) == 2 && abs(newY - this->getYCoord()) == 1)
    || (abs(newX - this->getXCoord()) == 1 && abs(newY - this->getYCoord()) == 2)){
        return true;
    }
    return false; 
}

bool Bishop::move(int newX, int newY, Board &board) {
    //if both old x and y coords are same as new x and y coords
    // or if the difference between x coords isnt the same as the difference between y coords
    // or if the piece at the new coords is the same color as the bishop
    //  return false
    if ((this->getXCoord() == newX && this->getYCoord() == newY)
     || (abs(newX - this->getXCoord()) != abs(newY - this->getYCoord))
     || (board.getPiece(newX, newY)->getColor() == this->getColor())) {
        return false;
    }

    //check if there are no pieces in the way
    Piece* movement = this;
    //calculate the x and y direction the piece will be moving in
    //-1 if piece moves left or down
    //1 if piece moves right or up
    int xDirection = (newX - this->getXCoord()) / abs(newX - this->getXCoord());
    int yDirection = (newY - this->getYCoord()) / abs(newY - this->getYCoord());
    while ((movement->getXCoord() != newX) || (movement->getYCoord() != newY)) {
        //check to see if the piece is null
        if (movement != nullptr && movement != this) {
            return false;
        }
        //move the piece 1 space over
        movement = board.getPiece(movement->getXCoord() + xDirection, movement->getYCoord() + yDirection);
    }

    return true;
}

bool Queen::move(int newX, int newY, Board &board) {
    //if piece would end up staying in same place
    // or if piece isn't going to move horizontally, vertically, or diagonally
    // or if the piece at the new coords is the same color as the rook
    //  return false
    if ((this->getXCoord() == newX && this->getYCoord() == newY)
     || ((this->getXCoord() != newX && this->getYCoord() != newY)
     || (abs(newX - this->getXCoord()) != abs(newY - this->getYCoord))) 
     || (board.getPiece(newX, newY)->getColor() == this->getColor())) {
        return false;
    }
    
    //check if there are no pieces in the way
    Piece* movement = this;
    //calculate the x and y direction the piece will be moving in
    //-1 if piece moves left or down
    //1 if piece moves right or up
    //0 if piece doesn't move in that direction
    int xDirection = 0;
    int yDirection = 0;
    if (newX != this->getXCoord()) {
        xDirection = (newX - this->getXCoord()) / abs(newX - this->getXCoord());
    }
    if (newY != this->getYCoord()) {
        yDirection = (newY - this->getYCoord()) / abs(newY - this->getYCoord());
    }
    while ((movement->getXCoord() != newX) || (movement->getYCoord() != newY)) {
        //check to see if the piece is null
        if (movement != nullptr && movement != this) {
            return false;
        }
        //move the piece 1 space over
        movement = board.getPiece(movement->getXCoord() + xDirection, movement->getYCoord() + yDirection);
    }

    return true;
}

bool King::move(int newX, int newY, Board &board) {  
    if(!board.isFree(newX, newY)){
        Piece* enemyPiece = board.getPiece(newX, newY);
        if(enemyPiece->getColor() == this->getColor())
        return false;
    }   
    if((abs(this->getXCoord() - newX) == 0 && abs(this->getYCoord() - newY) == 1)
     || (abs(this->getXCoord() - newX) == 1 && abs(this->getYCoord() - newY) == 0)
     || (abs(this->getXCoord() - newX) == 1 && abs(this->getYCoord() - newY) == 1)){
        return true;
    }
    return false; 
}
