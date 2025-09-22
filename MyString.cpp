#include "MyString.h"
#include <algorithm>
#include <cctype>

using namespace std;

// Constructors
MyString::MyString() {
    data = "";
}

MyString::MyString(string str) {
    data = str;
}

// Destructor
MyString::~MyString() {}

// Member functions
int MyString::length() {
    return data.length();
}

char MyString::characterAt(int index) {
    if (index < 0 || index >= data.length()) {
        return '\0'; // Return null character for an invalid index.
    }
    return data[index];
}

bool MyString::EqualTo(MyString other) {
    return data == other.data;
}

void MyString::Append(MyString other) {
    data = data + other.data;
}

void MyString::ToLower() {
    for (int i = 0; i < data.length(); i++) {
        data[i] = tolower(data[i]);
    }
}

void MyString::ToUpper() {
    for (int i = 0; i < data.length(); i++) {
        data[i] = toupper(data[i]);
    }
}

int MyString::Find(MyString findString) {
    int pos = data.find(findString.data);
    if (pos >= 0) {
        return pos;
    }
    return -1;
}

int MyString::Find(int startIndex, MyString findString) {
    if (startIndex < 0 || startIndex >= data.length()) {
        return -1;
    }
    int pos = data.find(findString.data, startIndex);
    if (pos >= 0) {
        return pos;
    }
    return -1;
}

void MyString::Replace(MyString findString, MyString replaceString) {
    int pos = 0;
    while ((pos = data.find(findString.data, pos)) >= 0) {
        data.replace(pos, findString.data.length(), replaceString.data);
        pos += replaceString.data.length();
    }
}

void MyString::ReadFromConsole() {
    getline(cin, data);
}

void MyString::WriteToConsole() {
    cout << data;
}

//////////////////////////////////////////////////
// Operator overloads
//bool MyString::operator==(MyString rhs) {
//    return data == rhs.data;
//}
//
//char MyString::operator[](int index) {
//    if (index < 0 || index >= data.length()) {
//        return '\0'; // Return null character for invalid index
//    }
//    return data[index];
//}
//
//MyString MyString::operator=(MyString rhs) {
//    data = rhs.data;
//    return *this;
//}
//
//bool MyString::operator<(MyString rhs) {
//    return data < rhs.data; // Uses lexicographical comparison
//}

// Helper function
string MyString::getString() {
    return data;
}