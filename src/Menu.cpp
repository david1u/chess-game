#include "../header/Menu.hpp"
#include <cstdlib>
#include <fstream>
#include <stdexcept>
#include <iostream>
using namespace std;

void Menu::quit() const {
    exit(0);
}

Menu::~Menu() {
    //NEEDS IMPLEMENTATION
}

void Menu::menuDisplay() {
    chessDisplay();
    cout << "                " << this->menuName << endl;
    cout << "========================================\n\n";
    this->displayChoices();
    cout << "\n========================================\n";
    cout << "Enter your choice:";
    cin >> this->choice;
}

void Menu::chessDisplay() const {
    //open file to display what is in the ChessText.txt file
    string filename = "text/ChessText.txt";
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
}

string Menu::getMenuName() const {
    return this->menuName;
}

void MainMenu::displayChoices() {
    cout << "        [2] Two Player" << endl;
    cout << "        [L]oad Game" << endl;
    cout << "        [Q]uit" << endl;
}

Menu* MainMenu::chooseOption() {
    Menu* newMenu = nullptr;
    if(this->choice == "2"){
        return new GameInitiateMenu();
    }
    else if(this->choice == "l" || this->choice == "L"){
        //load game option
    }
    else if(this->choice == "q" || this->choice == "Q"){
        quit();
    }
    else {
        //choice was not taken in correctly.
        cout << "choice was not valid, please choose again." << endl;
        newMenu = new MainMenu();
    }
    return newMenu;
}

void StartMenu::displayChoices() {
    cout << "        [P]lay" << endl;
    cout << "        [Q]uit" << endl;
}

Menu* StartMenu::chooseOption() {
    Menu* newMenu = nullptr;
    if(this->choice == "p" || this->choice == "P"){
        newMenu = new MainMenu();
    }
    else if(this->choice == "q" || this->choice == "Q"){
        quit();
    }
    else {
        //choice was not taken in correctly.
        cout << "choice was not valid, please choose again." << endl;
        newMenu = new StartMenu();
    }
    return newMenu;
}

void SurrenderMenu::displayChoices() {
    cout << "        [S]urrender" << endl;
    cout << "        [R]eturn" << endl;
}

Menu* SurrenderMenu::chooseOption() {
    //NEEDS IMPLEMENTATION
    return nullptr;
}

void ResultsMenu::displayChoices() {
    //NEEDS IMPLEMENTATION
}

Menu* ResultsMenu::chooseOption() {
    //NEEDS IMPLEMENTATION
    return nullptr;
}

void GameInitiateMenu::displayChoices() {
    cout << "        Player One(WHITE)\n";
    cout << "        Player Two(BLACK)\n";
}

void GameInitiateMenu::menuDisplay() {
    chessDisplay();
    cout << "                " << this->menuName << endl;
    cout << "========================================\n\n";
    this->displayChoices();
    cout << "\n========================================\n";
    cin.ignore();
    //Fill in variables for p1, p2.
    cout << "Enter Player One name:";
    getline(cin, p1);
    cout << "Enter Player Two name:";
    getline(cin, p2);
}

string GameInitiateMenu::getPlayerOneName() const {
    return p1;
}

string GameInitiateMenu::getPlayerTwoName() const {
    return p2;
}

Menu* GameInitiateMenu::chooseOption() {
    //NEEDS IMPLEMENTATION
    return nullptr;
}

void LoadMenu::displayChoices() {
    //NEEDS IMPLEMENTATION
}

Menu* LoadMenu::chooseOption() {
    //NEEDS IMPLEMENTATION
    return nullptr;
}
