#include "../header/Piece.hpp"
#include "../header/Board.hpp"
#include <cstdlib>
#include <iostream>

std::vector<std::pair<int, int>> Piece::getPossibleMoves(Board &board) {
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

bool Pawn::move(int newCol, int newRow, Board *board) {

    //std::cout << "Using the pawn's move check" << std::endl;


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

    //if(abs(dcol) == 1 && drow == (this->getColor() ? -1 : 1)) {
    //    if(board.isFree(newRow, newCol)) {
    //        // The destination square is free, so this could be an en passant capture
    //        Piece* lastMovedPiece = board.getLastMovedPiece();
    //        if(lastMovedPiece != nullptr
    //           && typeid(*lastMovedPiece) == typeid(Pawn)
    //           && lastMovedPiece->getColor() != this->getColor()
    //           && lastMovedPiece->getMoveCount() == 1
    //           && lastMovedPiece->getXCoord() == newCol
    //           && lastMovedPiece->getYCoord() == (this->getColor() ? newRow + 1 : newRow - 1)) {
    //            // The last piece moved was an opponent's pawn that moved two squares forward
    //            // and ended up adjacent to this pawn, so this is a valid en passant capture
    //            return true;
    //        }
    //    }
    //}



    // If the pawn is moving straight forward, the destination square must be free
    if(dcol == 0 && !board.isFree(newRow, newCol)) {
        return false;
    }
        

    // If all checks passed, the move is valid
    Piece* currentPiece = board.getPiece(this->getYCoord(), this->getXCoord());
    currentPiece->incMoveCount();
    //std::cout << "Valid move found" << std::endl;
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
    if(!board.isFree(newY, newX)){
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
     || (abs(newX - this->getXCoord()) != abs(newY - this->getYCoord()))
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
     || (abs(newX - this->getXCoord()) != abs(newY - this->getYCoord()))) 
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
    if(!board.isFree(newY, newX)){
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
