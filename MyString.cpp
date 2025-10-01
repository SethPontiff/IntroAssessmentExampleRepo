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

    int position = 0;
    // Keeping track of where we are in the string as we search. So 0 means we're starting from the beginning basically.

    while ((position = data.find(findString.data, position)) >= 0) 
    //data.find (findString.data, position)
    //This searches for the first occurence of the findString.data starting from the index position.
    //If it's found, find() returns the index where the match begins. If not, find() returns -1.
    //>= 0 checks if we found a match.
    // position = will update our position variable with the found index.
    {
        data.replace(position, findString.data.length(), replaceString.data);
        //We go to the position, which is where we start the replacement.
        //Then, we use findString.data.length() to see how many characters to remove.
        //Finally, we use replaceString.data to read what we're going to insert into their place.

        position += replaceString.data.length();
        //This moves our search position past the newly inserted replacement string.
        //Main reason we do this is to prevent infinite loops if the replacement string contains the search string.
        //Also means we don't accidentally re-process the replacement text.
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