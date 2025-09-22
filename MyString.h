#ifndef MYSTRING_H
#define MYSTRING_H

#include <string>
#include <iostream>

using namespace std;

class MyString {
private:
    string data;

public:

    MyString();
    MyString(string str);

    ~MyString();

    int length();
    char characterAt(int index);
    bool EqualTo(MyString other);
    void Append(MyString other);
    void ToLower();
    void ToUpper();
    int Find(MyString findString);
    int Find(int startIndex, MyString findString);
    void Replace(MyString findString, MyString replaceString);
    void ReadFromConsole();
    void WriteToConsole();

    // Operator overloads
    //bool operator==(MyString rhs);
    //char operator[](int index);
    //MyString operator=(MyString rhs);
    //bool operator<(MyString rhs);

    // Helper function to get the underlying string (useful for testing purposes)
    string getString();
};

#endif