#include "../header/Piece.hpp"
#include "../header/Board.hpp"
#include <cstdlib>


bool Pawn::move(int newX, int newY, Board &board) {
    if (enPassant) {
        return true;
    }
    
    if(!board.isFree(newX, newY)){
        Piece* enemyPiece = board.getPiece(newX, newY);
        if(enemyPiece->getColor() && this->getColor()
        || !enemyPiece->getColor() && !this->getColor())
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
    // if(!board.isFree(newX, newY)){
    //     Piece* enemyPiece = board.getPiece(newX, newY);
    //     if(enemyPiece->getColor() && this->getColor()
    //     || !enemyPiece->getColor() && !this->getColor())
    //     return false;
    // }
    // if((abs(this->getXCoord() - newX) != 0 && this->getYCoord() - newY == 0)
    //  || (abs(this->getXCoord() - newX) == 0 && this->getYCoord() - newY != 0)){
    //     return true;
    // }   
    // return false; 

    //if both old x and y coords are same as new x and y coords
    // or if the piece at the new coords is the same color as the rook
    //  return false
    if ((this->getXCoord() == newX && this->getYCoord() == newY)
     || (board.getPiece(newX, newY)->getColor() == this->getColor())) {
        return false;
    }

    //check to see if there are no pieces in the way
    //horizontal movement
    if (this->getYCoord() == newY) {
        for (int i = this->getXCoord(); i != newX; i += (newX - this->getXCoord()) / abs(newX - this->getXCoord())) {
            if (!board.isFree(i, newY)) {
                return false;
            }
        }
    } else if (this->getXCoord() == newX) {
        //vertical movement
        for (int i = this->getYCoord(); i != newY; i += (newY - this->getYCoord()) / abs(newY - this->getYCoord())) {
            if (!board.isFree(newX, i)) {
                return false;
            }
        }
    } else {
        return false;
    }

    return true;
}
bool Knight::move(int newX, int newY, Board &board) {   
    if(!board.isFree(newX, newY)){
        Piece* enemyPiece = board.getPiece(newX, newY);
        if(enemyPiece->getColor() && this->getColor()
        || !enemyPiece->getColor() && !this->getColor())
        return false;
    }  
    if((abs(newX - this->getXCoord()) == 2 && abs(newY - this->getYCoord()) == 1)
    || (abs(newX - this->getXCoord()) == 1 && abs(newY - this->getYCoord()) == 2)){
        return true;
    }
    return false; 
}
bool Bishop::move(int newX, int newY, Board &board) {  
    if(!board.isFree(newX, newY)){
        Piece* enemyPiece = board.getPiece(newX, newY);
        if(enemyPiece->getColor() && this->getColor()
        || !enemyPiece->getColor() && !this->getColor())
        return false;
    }   
    if(abs(newX - this->getXCoord() == abs(newY - this->getYCoord())))
        return true; 
    return false;
}
bool Queen::move(int newX, int newY, Board &board) { 
    if(!board.isFree(newX, newY)){
        Piece* enemyPiece = board.getPiece(newX, newY);
        if(enemyPiece->getColor() && this->getColor()
        || !enemyPiece->getColor() && !this->getColor())
        return false;
    }
    if(abs(newX - this->getXCoord() == abs(newY - this->getYCoord()))){
        return true; 
    }
    else if((abs(this->getXCoord() - newX) != 0 && this->getYCoord() - newY == 0)
     || (abs(this->getXCoord() - newX) == 0 && this->getYCoord() - newY != 0)){
        return true;
    }    
    return false; 
}
bool King::move(int newX, int newY, Board &board) {  
    if(!board.isFree(newX, newY)){
        Piece* enemyPiece = board.getPiece(newX, newY);
        if(enemyPiece->getColor() && this->getColor()
        || !enemyPiece->getColor() && !this->getColor())
        return false;
    }   
    if((abs(this->getXCoord() - newX) == 0 && abs(this->getYCoord() - newY) == 1)
     || (abs(this->getXCoord() - newX) == 1 && abs(this->getYCoord() - newY) == 0)
     || (abs(this->getXCoord() - newX) == 1 && abs(this->getYCoord() - newY) == 1)){
        return true;
    }
    return false; 
}
