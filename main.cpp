#include <iostream>
#include "MyString.h"
#include "TestSuite.h"
#include "Game.h"

using namespace std;

// Main function for the string class specifically.
int main() {
    cout << "MyString Class - Assessment 2" << endl;
    cout << "==============================" << endl;

    // Making and running the jank unit tests.
    TestSuite tests;
    tests.runAllTests();
    tests.displaySummary();
    tests.logFinalSummary();

    cout << endl << "Test results have been saved to TestResults.txt" << endl;
    cout << "Press Enter to continue...";
    cin.get();

    return 0;
}

//int main() {
//    cout << "Text Adventure Game - Assessment 3" << endl;
//    cout << "==================================" << endl << endl;
//
//    Game game;
//    game.Run();
//
//    return 0;
//}