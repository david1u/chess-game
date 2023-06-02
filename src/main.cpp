#include "../header/Menu.hpp"

int main(int argv, char** argc) {
    Menu* mainmenu = new MainMenu();
    mainmenu->menuDisplay();
    return 0;
}