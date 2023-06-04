#include "../header/Menu.hpp"

int main(int argv, char** argc) {
    Menu* currentMenu = new StartMenu();
    while(true) {
        currentMenu->menuDisplay();
        currentMenu = currentMenu->chooseOption();
    }
    return 0;
}