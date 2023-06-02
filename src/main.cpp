#include "../header/Menu.hpp"

int main(int argv, char** argc) {
    Menu* mainmenu = new MainMenu();
    mainmenu->chessDisplay();
    return 0;
}