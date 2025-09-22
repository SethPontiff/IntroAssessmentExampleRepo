#ifndef ITEMS_H
#define ITEMS_H

#include "MyString.h"

using namespace std;

class Item {
public:
    Item();
    ~Item();

    virtual void Description();
    virtual void Use();
};

class Lamp : public Item {
private:
    bool turnedOn;

public:
    Lamp();
    ~Lamp();

    void Description() override;
    void Use() override;
};

class BoxOfDonuts : public Item {
private:
    int count;

public:
    BoxOfDonuts();
    ~BoxOfDonuts();

    void Description() override;
    void Use() override;
};

class Cat : public Item {
private:
    bool purring;

public:
    Cat();
    ~Cat();

    void Description() override;
    void Use() override;
};

#endif