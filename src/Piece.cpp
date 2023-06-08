#include "../header/Piece.hpp"
#include "../header/Board.hpp"
#include <cstdlib>
#include <iostream>

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

bool Pawn::move(int newCol, int newRow, Board* board) {
    std::cout << "Using the pawn's move check" << std::endl;

    // Calculate the change in x and y coordinates
    int dcol = newCol - this->getXCoord();
    int drow = newRow - this->getYCoord();

    // If the column movement is greater than 1 or row movement is greater than 2, automatically a failed move
    if(abs(dcol) > 1 || abs(drow) > 2) {
        return false;
    }
    // Pawns can only move forward
    if(this->getColor() && drow > 0 || !this->getColor() && drow < 0) {
        return false;
    }

    // Pawns can only move forward one square, unless it's their first move
    // if(abs(dy) > 1 || abs(dx) > 1)
    //     return false;
    if(abs(drow) == 2 && moveCount != 0) {
        return false;
    }

    // Pawns can only capture to the diagonals
    if(abs(dcol) == 1 && abs(drow) == 1) {
        if(board->isFree(newRow, newCol)) { // If the diagonal square is free, it's not a valid capture
            return false;
        }       
        else {
            Piece* enemyPiece = board->getPiece(newRow, newCol);
            // Check if the piece at the destination is of the same color
            if(enemyPiece->getColor() == this->getColor()) {
                 return false;
            }
        }
    }

    if(abs(dcol) == 1 && drow == (this->getColor() ? -1 : 1)) {
        if(board->isFree(newRow, newCol)) {
            // The destination square is free, so this could be an en passant capture
            Piece* lastMovedPiece = board->getLastMovedPiece();
            if(lastMovedPiece != nullptr
               && typeid(*lastMovedPiece) == typeid(Pawn)
               && lastMovedPiece->getColor() != this->getColor()
               && lastMovedPiece->getMoveCount() == 1
               && lastMovedPiece->getXCoord() == newCol
               && lastMovedPiece->getYCoord() == (this->getColor() ? newRow + 1 : newRow - 1)) {
                // The last piece moved was an opponent's pawn that moved two squares forward
                // and ended up adjacent to this pawn, so this is a valid en passant capture
                return true;
            }
        }
    }

    // If the pawn is moving straight forward, the destination square must be free
    if(dcol == 0 && !board->isFree(newRow, newCol)) {
        return false;
    }
        

    // If all checks passed, the move is valid
    moveCount++;
    return true;
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
