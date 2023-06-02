#ifndef MENU_HPP
#define MENU_HPP
#include <string>
using namespace std;

class Menu {
 protected:
   string menuName;
   string choice;
   
 public:
   Menu(string name) : menuName(name) {}
   ~Menu();
   void quit() const;
   void chessDisplay() const;
   void menuDisplay();
   virtual void displayChoices() = 0;
   virtual void chooseOption() = 0;
};

class MainMenu : public Menu {
 public:
   MainMenu() : Menu("Main Menu") {}
   void displayChoices() override;
   void chooseOption() override;
};

class StartMenu : public Menu {
 public:
   StartMenu() : Menu("Start Menu") {}
   void displayChoices() override;
   void chooseOption() override;
};

class SurrenderMenu : public Menu {
 public:
   SurrenderMenu() : Menu("Surrender Menu") {}
   void displayChoices() override;
   void chooseOption() override;
};


#endif
