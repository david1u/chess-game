#include "../header/Game.hpp"

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

void Game::run() {
    // Game logic goes here
    // implement the game loop, handle player turns, moves, and interactions with the board
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
    int startX = king->getXCoord();
    int startY = king->getYCoord();
    for(const auto& pair: king->getPossibleMoves(board)){
        board->updateBoard(pair.first, pair.second, king);
        if(!inCheck(king, enemyPieces)){
            return true;
        }
        board->updateBoard(startX, startY, king);
    }
    return false;
}

bool Game::checkCanBeBlocked(King* king, vector<Piece*> myPieces, vector<Piece*> enemyPieces) {
    for (Piece* piece : myPieces) {
        int startX = piece->getXCoord();
        int startY = piece->getYCoord();
        for (const auto& pair : piece->getPossibleMoves(board)) {
            board->updateBoard(pair.first, pair.second, piece);
            if (!inCheck(king, enemyPieces)) {
                board->updateBoard(startX, startY, king);
                return true;
            }
            board->updateBoard(startX, startY, king);
        }
    }
    return false;
}

bool Game::isCheckmate(King* king, vector<Piece*> myPieces, vector<Piece*> enemyPieces) {
    return inCheck(king, enemyPieces) &&
        !canEscapeCheck(king, enemyPieces) &&
        !checkCanBeBlocked(king, myPieces, enemyPieces);
}
