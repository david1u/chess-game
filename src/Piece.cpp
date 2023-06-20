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
    if(abs(drow) == 2 && abs(dcol) > 0) {
        return false;
    }

    if(abs(drow) < 1 && abs(dcol) > 0) {
        return false;
    }

    
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



    // // If the pawn is moving straight forward, the destination square must be free
    // if(dcol == 0 && !board->isFree(newRow, newCol)) {
    //     return false;
    // }
        

    // // If all checks passed, the move is valid
    // Piece* currentPiece = board->getPiece(this->getYCoord(), this->getXCoord());
    // currentPiece->incMoveCount();
    // //std::cout << "Valid move found" << std::endl;
    // return true;
    // If the pawn is moving straight forward, the destination square must be free
    if(dcol == 0 && !board->isFree(newRow, newCol)) {
        return false;
    }
        

    // If all checks passed, the move is valid
    // std::cout << "Valid move found" << std::endl;
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
bool Rook::move(int newCol, int newRow, Board* board) {
    // Make sure you aren't moving to your own square
    if(newCol == getXCoord() && newRow == getYCoord()) {
        return false;
    }

    if (getXCoord() != newCol && getYCoord() != newRow)
    {
        return false;
    }

    if (getXCoord() == newCol) 
    {
        int step = (newRow > getYCoord()) ? 1 : -1; // Direction of movement

        for (int i = getYCoord() + step; i != newRow; i += step) 
        {
            // If there is a piece blocking the path
            if (!board->isFree(i, newCol))
            {
                return false;
            }
        }
    } else if (getYCoord() == newRow) 
    {
        int step = (newCol > getXCoord()) ? 1 : -1; // Direction of movement

        for (int i = xCoord + step; i != newCol; i += step) 
        {
            // If there is a piece blocking the path
            if (!board->isFree(newRow, i))
            {
                return false;
            }
        }
    }

    Piece* destinationPiece = board->getPiece(newRow, newCol);
    if (destinationPiece && destinationPiece->getColor() == this->getColor())
    {
        return false;
    }

    return true;
}

bool Knight::move(int newCol, int newRow, Board* board) {
    // Make sure you aren't moving to your own square
    if(newCol == getXCoord() && newRow == getYCoord()) {
        return false;
    }

    // Check if the move is L-shaped
    if ((abs(newCol - getXCoord()) == 2 && abs(newRow - getYCoord()) == 1) ||
        (abs(newCol - getXCoord()) == 1 && abs(newRow - getYCoord()) == 2))
    {
        // Check if destination cell is free or contains an enemy piece
        Piece* destinationPiece = board->getPiece(newRow, newCol);
        if (destinationPiece && destinationPiece->getColor() == this->getColor())
        {
            return false;
        }

        return true;
    }

    // If we get here, then the move is not valid
    return false;
}


bool Bishop::move(int newCol, int newRow, Board* board) {
    // return false if trying to move to the same spot
    if(newCol == getXCoord() && newRow == getYCoord()) {
        return false;
    }

    // Check if destination is on a diagonal from the current position
    if (abs(newCol - getXCoord()) == abs(newRow - getYCoord()))
    {
        // Determine the direction of the move
        int colDirection = (newCol - getXCoord()) / abs(newCol - getXCoord());
        int rowDirection = (newRow - getYCoord()) / abs(newRow - getYCoord());

        // Iterate over each cell in the path
        for (int i = 1; i < abs(newCol - getXCoord()); ++i)
        {
            // Calculate the coordinates of the intermediate cell
            int intermediateCol = getXCoord() + i * colDirection;
            int intermediateRow = getYCoord() + i * rowDirection;

            // If any intermediate cell is not free, then the move is invalid
            if (!board->isFree(intermediateRow, intermediateCol))
            {
                return false;
            }
        }

        // Check if destination cell is free or contains an enemy piece
        Piece* destinationPiece = board->getPiece(newRow, newCol);
        if (!destinationPiece || destinationPiece->getColor() != white)
        {
            return true;
        }
    }

    // If we get here, then the move is not valid
    return false;
}

bool Queen::move(int newCol, int newRow, Board* board) {
    // Return false if trying to move to the same spot
    if(newCol == getXCoord() && newRow == getYCoord()) {
        return false;
    }

    // Check if the move is along a straight line (Rook's move)
    if (getXCoord() == newCol || getYCoord() == newRow) 
    {
        // Direction of movement
        int rowStep = (getYCoord() == newRow) ? 0 : (newRow > getYCoord()) ? 1 : -1; 
        int colStep = (getXCoord() == newCol) ? 0 : (newCol > getXCoord()) ? 1 : -1; 

        int curRow = getYCoord() + rowStep;
        int curCol = getXCoord() + colStep;

        while (curRow != newRow || curCol != newCol) 
        {
            // If there is a piece blocking the path
            if (!board->isFree(curRow, curCol))
            {
                return false;
            }

            curRow += rowStep;
            curCol += colStep;
        }
    }
    // Check if the move is along a diagonal (Bishop's move)
    else if (abs(newCol - getXCoord()) == abs(newRow - getYCoord())) 
    {
        // Determine the direction of the move
        int colDirection = (newCol - getXCoord()) / abs(newCol - getXCoord());
        int rowDirection = (newRow - getYCoord()) / abs(newRow - getYCoord());

        // Iterate over each cell in the path
        for (int i = 1; i < abs(newCol - getXCoord()); ++i)
        {
            // Calculate the coordinates of the intermediate cell
            int intermediateCol = getXCoord() + i * colDirection;
            int intermediateRow = getYCoord() + i * rowDirection;

            // If any intermediate cell is not free, then the move is invalid
            if (!board->isFree(intermediateRow, intermediateCol))
            {
                return false;
            }
        }
    } 
    else 
    {
        return false;
    }

    // Check if destination cell is free or contains an enemy piece
    Piece* destinationPiece = board->getPiece(newRow, newCol);
    if (destinationPiece && destinationPiece->getColor() == this->getColor())
    {
        return false;
    }

    return true;
}

bool King::move(int newCol, int newRow, Board* board) {
    // Make sure you aren't moving to your own square
    if(newCol == getXCoord() && newRow == getYCoord()) {
        return false;
    }

    // Check if the move is only one square in any direction
    if (abs(newCol - getXCoord()) <= 1 && abs(newRow - getYCoord()) <= 1) 
    {
        // Check if destination cell is free or contains an enemy piece
        Piece* destinationPiece = board->getPiece(newRow, newCol);
        if (destinationPiece && destinationPiece->getColor() == this->getColor())
        {
            return false;
        }
        return true;
    } 

    return false;
}
