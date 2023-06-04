#include "../header/Piece.hpp"
#include "../header/Board.hpp"
#include <cstdlib>


bool Pawn::move(int newX, int newY, Board &board) { 
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

    if(abs(this->getXCoord() - newX) == 0 && abs(this->getYCoord() - newY) == 2){
        if(jump2){
            return true;
        }
        return false;
    }
    if(abs(this->getXCoord() - newX) == 0 && abs(this->getYCoord() - newY) == 1){
        return true;
    }

    return false; 
}
bool Rook::move(int newX, int newY, Board &board) { 
    if(!board.isFree(newX, newY)){
        Piece* enemyPiece = board.getPiece(newX, newY);
        if(enemyPiece->getColor() && this->getColor()
        || !enemyPiece->getColor() && !this->getColor())
        return false;
    }
    if((abs(this->getXCoord() - newX) != 0 && this->getYCoord() - newY == 0)
     || (abs(this->getXCoord() - newX) == 0 && this->getYCoord() - newY != 0)){
        return true;
    }   
    return false; 
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

bool Pawn::enPassant(int newX, int newY, Board &board) {
    //function is from POV of piece taking other piece
    //assuming that the move is a valid move
    int X = newX;
    int Y = newY;
    if(white){
        Y++;
        if(board.isFree(X, Y)){
            return false;
        }
        else{
            Piece* enemyPiece = board.getPiece(X, Y);
            if(enemyPiece->getColor()){
                return false;
            }
            else if(enemyPiece->getMoveCount() == 1)
                return true;
            else 
                return false;
        }
    }
    else{
        Y--;
    }

    return false; 
}
