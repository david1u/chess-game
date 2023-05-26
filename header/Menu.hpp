#ifndef MENU_HPP
#define MENU_HPP
#include "string"

class Menu {
 protected:
    string choice = "";
 public:
    void quit();
    virtual void chooseOption() = 0;
}

#endif
