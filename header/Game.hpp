#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <string>
#include <vector>
#include "Board.hpp"
#include "Player.hpp"
#include "Menu.hpp"

class Menu;

class Game {
private:
    Board* board;
    std::vector<Piece*> whitePieces;
    std::vector<Piece*> blackPieces;
    Player* player1;
    Player* player2;
    Menu* menu;
public:
    Game(std::string p1Name, std::string p2Name);
    ~Game();
    Menu* getMenu() const;
    void setMenu(Menu*);
    Board* getBoard() const;
    Player* getPlayerOne() const;
    Player* getPlayerTwo() const;
    bool run();
    void updatePieceVectors();
    bool inCheck(Piece* king, std::vector<Piece*> enemyPieces);
    bool canEscapeCheck(Piece* king, std::vector<Piece*> enemyPieces);
    bool checkCanBeBlocked(Piece* king, std::vector<Piece*> myPieces, std::vector<Piece*> enemyPieces);
    bool isCheckmate(Piece* king, std::vector<Piece*> myPieces, std::vector<Piece*> enemyPieces);

};

#endif