#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <string>
#include <vector>
#include "Board.hpp"
#include "Player.hpp"
#include "Menu.hpp"

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
    void run();
    bool inCheck(King* king, vector<Piece*> enemyPieces);
    bool canEscapeCheck(King* king, vector<Piece*> enemyPieces);
    bool checkCanBeBlocked(King* king, vector<Piece*> myPieces, vector<Piece*> enemyPieces);
    bool isCheckmate(King* king, vector<Piece*> myPieces, vector<Piece*> enemyPieces);

};

#endif