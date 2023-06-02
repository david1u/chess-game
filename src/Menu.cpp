#include "../header/Menu.hpp"
#include <cstdlib>
#include <fstream>
#include <stdexcept>
#include <iostream>
using namespace std;

void Menu::quit() {
    exit(0);
}

void Menu::chessDisplay() const {
    string filename = "../text/ChessText.txt";
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
    cout << "=== Main Menu ===" << endl;
    cout << "[1] Single Player" << endl;
    cout << "[2] Two Player\n" << endl;
    cout << "[Q]uit" << endl;
    cout << "=================" << endl;
    cout << "Enter your choice: ";
    chooseOption();
}
void MainMenu::chooseOption() {

}

void StartMenu::displayChoices() {
    cout << "=== Start Menu ===" << endl;
    cout << "[P]lay" << endl;
    cout << "[Q]uit" << endl;
    cout << "=================" << endl;
    cout << "Enter your choice: ";
    chooseOption();
}
void StartMenu::chooseOption() {

}

void SurrenderMenu::displayChoices() {
    cout << "=== Surrender Menu ===" << endl;
    cout << "[S]urrender" << endl;
    cout << "[R]eturn" << endl;
    cout << "=================" << endl;
    cout << "Enter your choice: ";
    chooseOption();
}
void SurrenderMenu::chooseOption() {

}