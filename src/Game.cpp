#include "../header/Game.hpp"
#include "../header/DrawBoard.hpp"

Game::Game(std::string p1Name, std::string p2Name) {
    board = new Board();  // Initialize the board object
    player1 = new Player(p1Name, true);  // Initialize player 1 as white
    player2 = new Player(p2Name, false);  // Initialize player 2 as black
    menu = nullptr; // default for now

}
Menu* Game::getMenu() const{
    return menu;
}

void Game::setMenu(Menu* newMenu){
    menu = newMenu;
}

Board* Game::getBoard() const {
    return board;
}

Player* Game::getPlayerOne() const {
    return player1;
}

Player* Game::getPlayerTwo() const {
    return player2;
}

bool Game::run() {

    Piece* whiteKing = board->getPiece(7, 4);
    Piece* blackKing = board->getPiece(0, 4);
    bool winner = true;

    updatePieceVectors();

    // Game logic goes here
    // implement the game loop, handle player turns, moves, and interactions with the board

    // Draw board
    while(true){
        draw_board::printBoard(board);

        int moveResult = player1->makeMove(board);
        while(moveResult != 0 && moveResult != 1){
            std::cout << "Failed to make move for Player 1" << endl;
            moveResult = player1->makeMove(board);
        }
        if (moveResult == 1) {
            winner = false; // Assuming player 2 wins if player 1 resigns
            break;
        }
        // while(player1->makeMove(board) == 1){
        //     std::cout << "Failed to make move for Player 1" << endl;
        // }
        // if()
        //inCheck(whiteKing, blackPieces);
        updatePieceVectors();
        if (isCheckmate(whiteKing, whitePieces, blackPieces)) {
            //std::cout << "Black wins by checkmate.\n";
            winner = false;
            break;
        } else if (isCheckmate(blackKing, blackPieces, whitePieces)) {
            //std::cout << "White wins by checkmate.\n";
            winner = true;
            break;
        }
        
        draw_board::printBoard(board);
        moveResult = player2->makeMove(board);
        while(moveResult != 0 && moveResult != 1){
            std::cout << "Failed to make move for Player 2" << endl;
            moveResult = player2->makeMove(board);
        }
        if (moveResult == 1) {
            winner = true; // Assuming player 1 wins if player 2 resigns
            break;
        }
        updatePieceVectors();
        // if(inCheck(whiteKing, blackPieces)) {
        //     std::cout << "white king in check" << endl;
        // }
        if (isCheckmate(whiteKing, whitePieces, blackPieces)) {
            //std::cout << "Black wins by checkmate.\n";
            winner = false;
            break;
        } else if (isCheckmate(blackKing, blackPieces, whitePieces)) {
            //std::cout << "White wins by checkmate.\n";
            winner = true;
            break;
        }
    }
    // draw_board::printBoard(board);
    return winner;
}

Game::~Game() {
    delete board;
    delete player1;
    delete player2;
    delete menu;
}

bool Game::inCheck(Piece* king, vector<Piece*> enemyPieces) {
    if(!king) {
        std::cout << "King is nullptr" << std::endl;
    }
    //std::cout << "The king is located at column: " << king->getXCoord() << " and row: " << king->getYCoord() << std::endl;
    for(Piece* piece : enemyPieces) {
        if(piece->move(king->getXCoord(), king->getYCoord(), board)) {
            //std::cout << king->getColor() << " king in check" << endl;
            return true;
        }
    }
    //std::cout << king->getColor() << " king is not in check" << endl;
    return false;
}

bool Game::canEscapeCheck(Piece* king, vector<Piece*> enemyPieces) {
    int col = king->getXCoord();
    int row = king->getYCoord();
    Piece* toBeTempRemoved = nullptr;
    for(const auto& pair: king->getPossibleMoves(board)){
        toBeTempRemoved = nullptr;
        if(!board->isFree(pair.second, pair.first)) {
            toBeTempRemoved = board->getPiece(pair.second, pair.first);
            board->removePiece(toBeTempRemoved);
        }
        board->updateBoard(pair.second, pair.first, king);
        updatePieceVectors();

        if(!inCheck(king, enemyPieces)){
            board->updateBoard(row, col, king);
            if(toBeTempRemoved) {
                board->addPiece(toBeTempRemoved);
            }
            updatePieceVectors();
            //std::cout << king->getColor() << " king can escape check" << endl;
            return true;
        }
        board->updateBoard(row, col, king);
        if(toBeTempRemoved) {
            board->addPiece(toBeTempRemoved);
        }
        updatePieceVectors();
    }
    //std::cout << king->getColor() << " king can not escape check" << endl;
    return false;
}

bool Game::checkCanBeBlocked(Piece* king, vector<Piece*> myPieces, vector<Piece*> enemyPieces) {
    for (Piece* piece : myPieces) {
        int col = piece->getXCoord();
        int row = piece->getYCoord();
        Piece* toBeTempRemoved = nullptr;
        for (const auto& pair : piece->getPossibleMoves(board)) {
            toBeTempRemoved = nullptr;
            // if it's a take, simulate the take
            if(!board->isFree(pair.second, pair.first)) {
                toBeTempRemoved = board->getPiece(pair.second, pair.first);
                board->removePiece(toBeTempRemoved);
            }
            //move the piece to that location
            board->updateBoard(pair.second, pair.first, piece);
            updatePieceVectors();
            //draw_board::printBoard(board);
            if (!inCheck(king, enemyPieces)) {
                board->updateBoard(row, col, piece);
                if(toBeTempRemoved) {
                    //std::cout << "trying to add " << toBeTempRemoved->getName() << " back" << endl;
                    board->addPiece(toBeTempRemoved);
                }
                updatePieceVectors();
                //std::cout << king->getColor() << " king check can be blocked" << endl;
                return true;
            }
            board->updateBoard(row, col, piece);
            if(toBeTempRemoved) {
                //std::cout << "trying to add " << toBeTempRemoved->getName() << " back" << endl;
                board->addPiece(toBeTempRemoved);
            }
            updatePieceVectors();
        }
    }
    //std::cout << king->getColor() << " king check can no be blocked" << endl;
    return false;
}

bool Game::isCheckmate(Piece* king, vector<Piece*> myPieces, vector<Piece*> enemyPieces) {
    return inCheck(king, enemyPieces) &&
        !canEscapeCheck(king, enemyPieces) &&
        !checkCanBeBlocked(king, myPieces, enemyPieces);
}

void Game::updatePieceVectors() {

    whitePieces.clear();
    blackPieces.clear();

    auto chessBoard = board->getBoard();

    for (const auto& row : chessBoard) {
        for (const auto& piece : row) {
            if (piece != nullptr) {  // Ignore empty squares
                if (piece->getColor()) { // true for white
                    whitePieces.push_back(piece);
                } else { // false for black
                    blackPieces.push_back(piece);
                }
            }
        }
    }
}