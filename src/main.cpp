#include "../header/Menu.hpp"
#include "../header/Game.hpp"
#include <fstream>
using namespace std;
#include <iostream>

void printResultsMenu(bool);

int main(int argc, char** argv) {
    Menu* currentMenu = nullptr;
    while (true) {
        currentMenu = new StartMenu();
        while (dynamic_cast<GameInitiateMenu*>(currentMenu) == nullptr && 
               dynamic_cast<LoadMenu*>(currentMenu) == nullptr) {
            currentMenu->menuDisplay();
            Menu* nextMenu = currentMenu->chooseOption();
            if (nextMenu == nullptr) {
                // Quit option was selected, break out of the loop
                break;
            }
            delete currentMenu;
            currentMenu = nextMenu;
        }

        if (currentMenu == nullptr || currentMenu->getShouldQuit()) {
            // Quit option was selected, break out of the outer loop
            delete currentMenu;
            break;
        }

        if (dynamic_cast<GameInitiateMenu*>(currentMenu) != nullptr) {
            // currentMenu is GameInitiateMenu
            GameInitiateMenu* gameMenu = dynamic_cast<GameInitiateMenu*>(currentMenu);
            gameMenu->menuDisplay();
            // GameMenu p1 and p2 are populated with the player names.
            // Use gameMenu->getPlayerOneName() and getPlayerTwoName().
            // This is where we should initiate the Game class with player names as parameters.
            Game* game = new Game(gameMenu->getPlayerOneName(), gameMenu->getPlayerTwoName());
            bool whiteWon = game->run();
            printResultsMenu(whiteWon);
            delete game;
        }

        delete currentMenu;
        // This will restart at StartMenu. Players have to quit using the [Q] option.
    }

    return 0;
}

void printResultsMenu(bool whiteWon){
    //open file to display what is in the Checkmate.txt file
    string filename = "text/Checkmate.txt";
    ifstream file(filename);

    if(file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << '\n';
        }
        file.close();
    }
    else {
        throw runtime_error("File failed to open");
    }

    cout << "================================================\n";
    
    if(whiteWon) {
        cout << "               WHITE WINS!\n";
    }
    else{
        cout << "               BLACK WINS!\n";  
    }

    cout << "================================================\n";
} 