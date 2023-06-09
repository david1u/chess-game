#include "../header/Game.hpp"
#include "../header/DrawBoard.hpp"

Game::Game(std::string p1Name, std::string p2Name) {
    board = new Board();  // Initialize the board object
    player1 = new Player(p1Name, true);  // Initialize player 1 as white
    player2 = new Player(p2Name, false);  // Initialize player 2 as black
    menu = nullptr; // default for now

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

void Game::run() {

    King* whiteKing = nullptr;
    King* blackKing = nullptr;

    for (auto& piece : whitePieces) {
        if (piece->getName() == WHITE_KING) { 
            King* whiteKing = dynamic_cast<King*>(piece);
            break; // stop the loop as soon as we found the King
        }
    }

    for (auto& piece : blackPieces) {
        if (piece->getName() == BLACK_KING) { 
            King* blackKing = dynamic_cast<King*>(piece);
            break; // stop the loop as soon as we found the King
        }
    }
    // Game logic goes here
    // implement the game loop, handle player turns, moves, and interactions with the board

    // Draw board
    while(true){
        draw_board::printBoard(board);
        while(!player1->makeMove(board)){
            std::cout << "Failed to make move for Player 1" << endl;
        }
        // if (isCheckmate(whiteKing, whitePieces, blackPieces)) {
        //     std::cout << "Black wins by checkmate.\n";
        //     break;
        // } else if (isCheckmate(blackKing, blackPieces, whitePieces)) {
        //     std::cout << "White wins by checkmate.\n";
        //     break;
        // }
        
        draw_board::printBoard(board);
        while(!player2->makeMove(board)){
            std::cout << "Failed to make move for Player 2" << endl;
        }
        // if (isCheckmate(whiteKing, whitePieces, blackPieces)) {
        //     std::cout << "Black wins by checkmate.\n";
        //     break;
        // } else if (isCheckmate(blackKing, blackPieces, whitePieces)) {
        //     std::cout << "White wins by checkmate.\n";
        //     break;
        // }
    }
}

Game::~Game() {
    delete board;
    delete player1;
    delete player2;
    delete menu;
}

bool Game::inCheck(King* king, vector<Piece*> enemyPieces) {
    for(Piece* piece : enemyPieces) {
        if(piece->move(king->getXCoord(), king->getYCoord(), board)) {
            return true;
        }
    }
    return false;
}

bool Game::canEscapeCheck(King* king, vector<Piece*> enemyPieces) {
    int col = king->getXCoord();
    int row = king->getYCoord();
    for(const auto& pair: king->getPossibleMoves(board)){
        board->updateBoard(pair.second, pair.first, king);
        if(!inCheck(king, enemyPieces)){
            return true;
        }
        board->updateBoard(row, col, king);
    }
    return false;
}

bool Game::checkCanBeBlocked(King* king, vector<Piece*> myPieces, vector<Piece*> enemyPieces) {
    for (Piece* piece : myPieces) {
        int col = piece->getXCoord();
        int row = piece->getYCoord();
        for (const auto& pair : piece->getPossibleMoves(board)) {
            board->updateBoard(pair.second, pair.first, piece);
            if (!inCheck(king, enemyPieces)) {
                board->updateBoard(row, col, king);
                return true;
            }
            board->updateBoard(row, col, king);
        }
    }
    return false;
}

bool Game::isCheckmate(King* king, vector<Piece*> myPieces, vector<Piece*> enemyPieces) {
    return inCheck(king, enemyPieces) &&
        !canEscapeCheck(king, enemyPieces) &&
        !checkCanBeBlocked(king, myPieces, enemyPieces);
}
