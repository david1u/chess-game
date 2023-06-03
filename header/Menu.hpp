#ifndef MENU_HPP
#define MENU_HPP
#include <string>
using namespace std;

class Menu {
 protected:
    string menuName;
    string choice = "";

    virtual void displayChoices() = 0;
    void quit() const;
    void chessDisplay() const;

 public:
    Menu(string name) : menuName(name) {}
    ~Menu();

    void menuDisplay();
    virtual Menu* chooseOption() = 0;
};

class MainMenu : public Menu {
 private:
    void displayChoices() override;
 public:
    MainMenu() : Menu("Main Menu") {}
    Menu* chooseOption() override;
};

class StartMenu : public Menu {
 private: 
    void displayChoices() override;
 public:
    StartMenu() : Menu("Start Menu") {}
    Menu* chooseOption() override;
};

class SurrenderMenu : public Menu {
 private:
    void displayChoices() override;
 public:
    SurrenderMenu() : Menu("Surrender Menu") {}
    Menu* chooseOption() override;
};


#endif
