#include "Player.h"
#include <iostream>

using namespace std;

Player::Player() {
    // Initialize the spellbook with fixed spells. If you want more of a challenge, you can add functionality for the player adding their own spells.
    spells[0] = MyString("fireball");
    spells[1] = MyString("frostbolt");
    spells[2] = MyString("shadowbolt");
    spells[3] = MyString("polymorph");
}

Player::~Player() {
}

bool Player::FindSpell(MyString spellName) {
    // Converting the search spell to lowercase for comparison, to make our lives easier.
    spellName.ToLower();

    // Search through all known spells (can also use binary search, but it's not strictly necessary).
    for (int i = 0; i < 4; i++) {
        if (spells[i].EqualTo(spellName)) {
            return true; // Spell found (hence true!)
        }
    }

    return false; // Spell not found (hence...well, false.)
}