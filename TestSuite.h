#ifndef TESTSUITE_H
#define TESTSUITE_H

#include "MyString.h"
#include <fstream>

using namespace std;

class TestSuite {
private:
    int totalTests;
    int passedTests;
    ofstream logFile;

    void runTest(string testName, bool testResult);
    void writeToLog(string message);
    string getCurrentDateTime();

public:
    TestSuite();
    ~TestSuite();

    // Core testin functions.
    void testConstructors();
    void testLength();
    void testCharacterAt();
    void testEqualTo();
    void testAppend();
    void testToLower();
    void testToUpper();
    void testFind();
    void testFindWithStartIndex();
    void testReplace();
    //void testEqualityOperator();
    //void testSubscriptOperator();
    //void testAssignmentOperator();
    //void testLessThanOperator();

    // Run all tests, that way we just have to run the code once.
    void runAllTests();

    // Display final summary, that way the user knows whether the tests passed or not immediately.
    void displaySummary();

    // Log final summary, to save these results to a log file. 
    void logFinalSummary();
};

#endif