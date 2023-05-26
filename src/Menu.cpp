#include "Menu.hpp"
#include <iostream>
using namespace std;

void Menu::displayMenu() {
    cout << "=== Game Menu ===" << endl;
    cout << "1. Single Player" << endl;
    cout << "2. TwoPlayer" << endl;
    cout << "3. Quit" << endl;
    cout << "=================" << endl;
    cout << "Enter your choice: ";
    chooseOption();
}

void Menu::chooseOption() {
    cin >> choice;
    switch(choice) {
        case 1:
            singlePlayer();
            break;
        case 2:
            twoPlayer();
            break;
        case 3:
            quit();
            break;
        default:
            cout << "Invalid choice, Please select again." << endl;
            displayMenu();
            break;
    }
}

void Menu::singlePlayer(){
    
}

void Menu::twoPlayer() {

}

void Menu::quit() {

}