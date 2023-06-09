#include "../header/Menu.hpp"
#include "../header/Game.hpp"
using namespace std;
#include <iostream>

int main(int argv, char** argc) {
    Menu* currentMenu = nullptr;
    Menu* prevMenu = nullptr;
    ResultsMenu* results = nullptr;
    bool whiteWins;
    while(true) {
        currentMenu = new StartMenu();
        while(dynamic_cast<GameInitiateMenu*>(currentMenu) == nullptr && 
        dynamic_cast<LoadMenu*>(currentMenu) == nullptr) {
            prevMenu = currentMenu;
            currentMenu->menuDisplay();
            currentMenu = currentMenu->chooseOption();
            delete prevMenu;
        }

        if(dynamic_cast<GameInitiateMenu*>(currentMenu) != nullptr) {
            //currentMenu is GameInitiateMenu
            GameInitiateMenu* GameMenu = dynamic_cast<GameInitiateMenu*>(currentMenu);
            GameMenu->menuDisplay();
            //GameMenu p1, and p2 are populated with the player names.
            //Use GameMenu->getPlayerOneName(), and getPlayerTwoName().
            //This is where we should initiate Game class with player names as parameters.
            Game* game = new Game(GameMenu->getPlayerOneName(), GameMenu->getPlayerTwoName());
            whiteWins = game->run();
            results = new ResultsMenu();
            results->menuDisplay(whiteWins);
            results->chooseOption(); //this is only returning nullptr or quitting
            delete results;
        }
        else if (dynamic_cast<LoadMenu*>(currentMenu) != nullptr) {
            //currentMenu is LoadMenu
        }
        if(currentMenu != nullptr){
            delete currentMenu;
        }
        //this will restart at StartMenu. Players have to quit using the [Q] option.
    }

    return 0;
}