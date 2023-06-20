#ifndef MENU_HPP
#define MENU_HPP
#include <string>
using namespace std;

class Menu {
 protected:
    string menuName;
    string choice = "";
   bool shouldQuit;

    virtual void displayChoices() = 0;
    void chessDisplay() const;

 public:
    Menu(string name) : menuName(name), shouldQuit(false) {}
    ~Menu();
    string getMenuName() const;
   void quit() {shouldQuit = true;}
       bool getShouldQuit() const {
        return shouldQuit;
    }
    virtual void menuDisplay();
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
    StartMenu() : Menu("Start") {}
    Menu* chooseOption() override;
};

class SurrenderMenu : public Menu {
 private:
    void displayChoices() override;
 public:
    SurrenderMenu() : Menu("Surrender Menu") {}
    Menu* chooseOption() override;
};

class ResultsMenu : public Menu {
 private:
   void displayChoices() override;
 public:
   ResultsMenu() : Menu("Results") {}
   Menu* chooseOption() override;
};  

class GameInitiateMenu : public Menu {
 private:
   void displayChoices() override;
   string p1, p2;
 public:
   string getPlayerOneName() const;
   string getPlayerTwoName() const;
   GameInitiateMenu() : Menu("Game Initiate") {}
   void menuDisplay() override;
   Menu* chooseOption() override;
};

class LoadMenu : public Menu {
 private:
   void displayChoices() override;
 public:
   LoadMenu() : Menu("Results") {}
   Menu* chooseOption() override;
};  

#endif