#include "../header/Piece.hpp"
#include "../header/Board.hpp"
#include <cstdlib>

std::vector<std::pair<int, int>> Piece::getPossibleMoves(Board* board) {
    std::vector<std::pair<int, int>> moves;

        for (int x = 0; x < 8; ++x) {
            for (int y = 0; y < 8; ++y) {
                if (move(x, y, board)) {
                    moves.push_back(std::make_pair(x, y));
                }
            }
        }

    return moves;
}

bool Pawn::move(int newX, int newY, Board* board) {
    if (enPassant) {
        return true;
    }
    
    if(!board->isFree(newX, newY)){
        Piece* enemyPiece = board->getPiece(newX, newY);
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
bool Pawn::enPassant(int newX, int newY, Board* board) {
    //pawns must be next to each other
    //pawns must be enemies
    //enemy piece must have moved 2 spaces in 1 turn
    Piece* enemyPiece = board->getPiece(newX, this->getYCoord());
    if (enemyPiece != nullptr) {
        if (enemyPiece->getName() == BLACK_PAWN || enemyPiece->getName() == WHITE_PAWN) {
            if (this->getColor() != enemyPiece->getColor()) {
                if (enemyPiece->getMoveCount() == 1 && (enemyPiece->getYCoord() == 4 || enemyPiece->getYCoord() == 5)) {
                    enemyPiece->setYCoord(newY);
                    return true;
                }
            }
        }
    }
    
    return false;
}

bool Rook::move(int newX, int newY, Board* board) { 
    if(!board->isFree(newX, newY)){
        Piece* enemyPiece = board->getPiece(newX, newY);
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
bool Knight::move(int newX, int newY, Board* board) {   
    if(!board->isFree(newX, newY)){
        Piece* enemyPiece = board->getPiece(newX, newY);
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
bool Bishop::move(int newX, int newY, Board* board) {  
    if(!board->isFree(newX, newY)){
        Piece* enemyPiece = board->getPiece(newX, newY);
        if(enemyPiece->getColor() && this->getColor()
        || !enemyPiece->getColor() && !this->getColor())
        return false;
    }   
    if(abs(newX - this->getXCoord() == abs(newY - this->getYCoord())))
        return true; 
    return false;
}
bool Queen::move(int newX, int newY, Board* board) { 
    if(!board->isFree(newX, newY)){
        Piece* enemyPiece = board->getPiece(newX, newY);
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
bool King::move(int newX, int newY, Board* board) {  
    if(!board->isFree(newX, newY)){
        Piece* enemyPiece = board->getPiece(newX, newY);
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
