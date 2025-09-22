#ifndef PLAYER_H
#define PLAYER_H

#include "MyString.h"

using namespace std;

class Player {
private:
    MyString spells[4];

public:
    Player();
    ~Player();

    bool FindSpell(MyString spellName);
};

#endif