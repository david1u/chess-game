#ifndef MENU_DISP_HPP
#define MENU_DISP_HPP
#include <string>

namespace MenuDisplay {
    std::ostream& operator << (std::ostream& out, std::string t);
    
    void mainMenu();
    void startGameMenu();
    void SurrenderMenu();
    void ResultsMenu(std::string);

    void singlePlayer();
    void twoPlayer();
    
    void quit();
}

#endif