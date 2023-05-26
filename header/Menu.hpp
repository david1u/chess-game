#ifndef MENU_HPP
#define MENU_HPP

namespace Menu {
 private:
    int choice = 0;
 public:
    void displayMenu();
    void singlePlayer();
    void twoPlayer();
    void quit();
    void chooseOption();
}

#endif