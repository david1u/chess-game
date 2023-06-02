#include "../header/Menu.hpp"
#include <cstdlib>
#include <fstream>
#include <stdexcept>
#include <iostream>
using namespace std;

void Menu::quit() const {
    exit(0);
}

void Menu::menuDisplay(){
    chessDisplay();
    cout << "\n========================================\n\n";
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

void MainMenu::displayChoices() {
    cout << "        [1] Single Player" << endl;
    cout << "        [2] Two Player\n" << endl;
    cout << "        [Q]uit" << endl;
}
void MainMenu::chooseOption() {

}

void StartMenu::displayChoices() {
    cout << "        [P]lay" << endl;
    cout << "        [Q]uit" << endl;
}
void StartMenu::chooseOption() {

}

void SurrenderMenu::displayChoices() {
    cout << "        [S]urrender" << endl;
    cout << "        [R]eturn" << endl;
}
void SurrenderMenu::chooseOption() {

}