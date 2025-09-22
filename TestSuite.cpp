#define _CRT_SECURE_NO_WARNINGS
#include "TestSuite.h"
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

TestSuite::TestSuite() {
    totalTests = 0;
    passedTests = 0;

    logFile.open("TestResults.txt", ios::app);
    if (!logFile.is_open()) {
        cout << "Warning: Could not open log file!" << endl;
    }
}

TestSuite::~TestSuite() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

void TestSuite::writeToLog(string message) {
    if (logFile.is_open()) {
        logFile << message << endl;
    }
}

string TestSuite::getCurrentDateTime() {
    time_t now = time(0);
    string timeString = ctime(&now);

    if (timeString.length() > 0 && timeString[timeString.length() - 1] == '\n') {
        timeString = timeString.substr(0, timeString.length() - 1);
    }

    return timeString;
}

void TestSuite::runTest(string testName, bool testResult) {
    totalTests++;

    cout << testName;

    // Add spaces to make it look neat, because otherwise I'll go mad.
    for (int i = testName.length(); i < 30; i++) {
        cout << " ";
    }

    if (testResult) {
        cout << "PASS" << endl;
        passedTests++;
        writeToLog(testName + " - PASS");
    }
    else {
        cout << "FAIL" << endl;
        writeToLog(testName + " - FAIL");
    }
}

void TestSuite::testConstructors() {
    cout << endl << "Testing Constructors:" << endl;
    cout << "--------------------" << endl;

    // Testing the default constructor.
    MyString str1;
    runTest("Default Constructor", str1.length() == 0);

    // Testing the string constructor.
    MyString str2("Hello");
    runTest("String Constructor", str2.length() == 5 && str2.getString() == "Hello");
}

void TestSuite::testLength() {
    cout << endl << "Testing Length Function:" << endl;
    cout << "-----------------------" << endl;

    MyString str1("Hello");
    MyString str2("");
    MyString str3("A");

    runTest("Length of 'Hello'", str1.length() == 5);
    runTest("Length of empty string", str2.length() == 0);
    runTest("Length of single char", str3.length() == 1);
}

void TestSuite::testCharacterAt() {
    cout << endl << "Testing CharacterAt Function:" << endl;
    cout << "----------------------------" << endl;

    MyString str("Hello");

    runTest("First character", str.characterAt(0) == 'H');
    runTest("Last character", str.characterAt(4) == 'o');
    runTest("Invalid negative index", str.characterAt(-1) == '\0');
    runTest("Invalid high index", str.characterAt(10) == '\0');
}

void TestSuite::testEqualTo() {
    cout << endl << "Testing EqualTo Function:" << endl;
    cout << "------------------------" << endl;

    MyString str1("Hello");
    MyString str2("Hello");
    MyString str3("World");
    MyString str4("");
    MyString str5("");

    runTest("Equal strings", str1.EqualTo(str2));
    runTest("Different strings", !str1.EqualTo(str3));
    runTest("Empty strings equal", str4.EqualTo(str5));
}

void TestSuite::testAppend() {
    cout << endl << "Testing Append Function:" << endl;
    cout << "-----------------------" << endl;

    MyString str1("Hello");
    MyString str2(" World");
    str1.Append(str2);

    runTest("Append strings", str1.getString() == "Hello World");
}

void TestSuite::testToLower() {
    cout << endl << "Testing ToLower Function:" << endl;
    cout << "------------------------" << endl;

    MyString str1("HELLO World");
    str1.ToLower();

    runTest("Convert to lowercase", str1.getString() == "hello world");
}

void TestSuite::testToUpper() {
    cout << endl << "Testing ToUpper Function:" << endl;
    cout << "------------------------" << endl;

    MyString str1("hello WORLD");
    str1.ToUpper();

    runTest("Convert to uppercase", str1.getString() == "HELLO WORLD");
}

void TestSuite::testFind() {
    cout << endl << "Testing Find Function:" << endl;
    cout << "---------------------" << endl;

    MyString str("Hello World");
    MyString findStr1("World");
    MyString findStr2("xyz");
    MyString findStr3("Hello");

    runTest("Find 'World'", str.Find(findStr1) == 6);
    runTest("Find non-existent", str.Find(findStr2) == -1);
    runTest("Find at beginning", str.Find(findStr3) == 0);
}

void TestSuite::testFindWithStartIndex() {
    cout << endl << "Testing Find with Start Index:" << endl;
    cout << "------------------------------" << endl;

    MyString str("Hello Hello World");
    MyString findStr("Hello");

    runTest("Find from index 0", str.Find(0, findStr) == 0);
    runTest("Find from index 1", str.Find(1, findStr) == 6);
    runTest("Find from late index", str.Find(10, findStr) == -1);
}

void TestSuite::testReplace() {
    cout << endl << "Testing Replace Function:" << endl;
    cout << "------------------------" << endl;

    MyString str("Hello World Hello");
    MyString findStr("Hello");
    MyString replaceStr("Hi");
    str.Replace(findStr, replaceStr);

    runTest("Replace all occurrences", str.getString() == "Hi World Hi");
}

//void TestSuite::testEqualityOperator() {
//    cout << endl << "Testing Equality Operator (==):" << endl;
//    cout << "-------------------------------" << endl;
//
//    MyString str1("Hello");
//    MyString str2("Hello");
//    MyString str3("World");
//
//    runTest("Equal strings with ==", str1 == str2);
//    runTest("Different strings with ==", !(str1 == str3));
//}
//
//void TestSuite::testSubscriptOperator() {
//    cout << endl << "Testing Subscript Operator ([]):" << endl;
//    cout << "-------------------------------" << endl;
//
//    MyString str("Hello");
//
//    runTest("First char with []", str[0] == 'H');
//    runTest("Last char with []", str[4] == 'o');
//    runTest("Invalid negative with []", str[-1] == '\0');
//    runTest("Invalid high with []", str[10] == '\0');
//}
//
//void TestSuite::testAssignmentOperator() {
//    cout << endl << "Testing Assignment Operator (=):" << endl;
//    cout << "--------------------------------" << endl;
//
//    MyString str1("Hello");
//    MyString str2("World");
//
//    str2 = str1;
//
//    runTest("Assignment operator", str2.getString() == "Hello");
//}
//
//void TestSuite::testLessThanOperator() {
//    cout << endl << "Testing LessThan Operator (<):" << endl;
//    cout << "------------------------------" << endl;
//
//    MyString str1("Apple");
//    MyString str2("Banana");
//    MyString str3("Apple");
//
//    runTest("Apple < Banana", str1 < str2);
//    runTest("Banana not < Apple", !(str2 < str1));
//    runTest("Apple not < Apple", !(str1 < str3));
//}

void TestSuite::runAllTests() {
    cout << "Running MyString Test Suite..." << endl;
    cout << "================================" << endl;

    // Logging the start of test run, to make it clear when the tests start.
    writeToLog("=== Test Run Started ===");
    writeToLog(getCurrentDateTime());
    writeToLog("");

    testConstructors();
    testLength();
    testCharacterAt();
    testEqualTo();
    testAppend();
    testToLower();
    testToUpper();
    testFind();
    testFindWithStartIndex();
    testReplace();
    //testEqualityOperator();
    //testSubscriptOperator();
    //testAssignmentOperator();
    //testLessThanOperator();
}

void TestSuite::displaySummary() {
    cout << endl << endl;
    cout << "================================" << endl;
    cout << "TEST SUMMARY" << endl;
    cout << "================================" << endl;
    cout << "Total Tests: " << totalTests << endl;
    cout << "Passed: " << passedTests << endl;
    cout << "Failed: " << (totalTests - passedTests) << endl;

    if (totalTests > 0) {
        double percentage = (passedTests * 100.0) / totalTests;
        cout << "Pass Rate: " << percentage << "%" << endl;
    }

    if (passedTests == totalTests) {
        cout << endl << "All tests PASSED! Great job!" << endl;
    }
    else {
        cout << endl << "Some tests failed. Check your implementation." << endl;
    }
}

void TestSuite::logFinalSummary() {
    writeToLog("");
    writeToLog("=== Test Summary ===");
    writeToLog("Check console for detailed test results");

    if (totalTests > 0) {
        if (passedTests == totalTests) {
            writeToLog("Result: ALL TESTS PASSED!");
        }
        else {
            writeToLog("Result: Some tests failed");
        }
    }

    writeToLog(getCurrentDateTime());
    writeToLog("=== End Test Run ===");
    writeToLog(""); // Empty line for readability between test runs. Again, for my sanity.
}