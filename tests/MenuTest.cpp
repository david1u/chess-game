#include <gtest/gtest.h>
#include <sstream>
#include "../header/Menu.hpp"
using namespace std;

TEST(MenuTests, InputTest) {
    // Saving old buffer
    streambuf* oldCinBuffer = cin.rdbuf();

    // Creating a stringstream to use as the new "standard input"
    stringstream testInput;
    testInput.str("P");

    // Redirecting standard input to the stringstream
    cin.rdbuf(testInput.rdbuf());

    // Creating a StartMenu and calling chooseOption function that uses user input
    StartMenu* myMenu = new StartMenu();
    Menu* resultMenu = myMenu->chooseOption();
    
    // Testing conditions based on the expected outcomes of the function
    ASSERT_NE(resultMenu, nullptr); // Make sure non-null pointer
    EXPECT_EQ(resultMenu->getMenuName(), "MainMenu");

    // Restoring the original standard input streambuf
    cin.rdbuf(oldCinBuffer);

    delete myMenu;
    delete resultMenu;
}