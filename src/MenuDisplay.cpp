#include "../header/MenuDisplay.hpp"
#include <iostream>
using namespace std;

void MenuDisplay::mainMenu() {
    cout << "       _                   \n   ___| |__   ___  ___ ___ tm\n  / __| '_ \\ / _ \\/ __/ __|\n | (__| | | |  __/\\__ \\__ \\ \n  \\___|_| |_|\\___||___/___/" << endl;
    cout << endl;
    cout << " =========================== " << endl;
    cout << endl;

    cout << "         [N]ew Game." << endl;
    cout << "         [Q]uit." << endl;
    cout << endl;
    cout << " =========================== " << endl;
}

void MenuDisplay::startGameMenu(){
    cout << "       _                   \n   ___| |__   ___  ___ ___ tm\n  / __| '_ \\ / _ \\/ __/ __|\n | (__| | | |  __/\\__ \\__ \\ \n  \\___|_| |_|\\___||___/___/" << endl;
    cout << endl;
    cout << " =========================== " << endl;
    cout << endl;

    cout << "       [1] Player (AI)." << endl;
    cout << "       [2] Players." << endl;
    cout << endl;
    cout << " =========================== " << endl;
}

void MenuDisplay::SurrenderMenu(){
    cout << " =========================== " << endl;
    cout << endl;
    cout << "         SURRENDER?" << endl << endl;;

    cout << "         [C]onfirm." << endl;
    cout << "         [R]eturn." << endl;
    cout << endl;
    cout << " =========================== " << endl;
}

void MenuDisplay::ResultsMenu(std::string winner){
    cout << "       _                   \n   ___| |__   ___  ___ ___ tm\n  / __| '_ \\ / _ \\/ __/ __|\n | (__| | | |  __/\\__ \\__ \\ \n  \\___|_| |_|\\___||___/___/" << endl;
    cout << endl;
    cout << " =========================== " << endl;
    cout << endl;
    cout << "         " << winner << " WINS!!!" << endl;
    cout << endl;
    cout << "                   ※\\(^o^)/※" << endl;
    cout << " =========================== " << endl;
}
//void MenuDisplay::singlePlayer(){
//
//}
//
//void MenuDisplay::twoPlayer() {
//
//}
//
void MenuDisplay::quit() {
    cout << " =========================== " << endl;
    cout << endl;
    cout << endl;
    cout << "     Thanks for playing!" << endl;
    cout << endl;
    cout << endl;
    cout << " =========================== " << endl;
}