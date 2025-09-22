#ifndef GAME_H
#define GAME_H

#include "MyString.h"
#include "Items.h"
#include "Player.h"

using namespace std;

class Room {
private:
    string description;
    string itemType;
    Lamp lamp;
    BoxOfDonuts donuts;
    Cat cat;

public:
    Room();
    Room(string roomDescription, string itemTypeName);
    ~Room();

    void Description();
    void UseItem();
    bool HasItem();
};

class Game {
private:
    int currentRoomIndex;
    Room rooms[4]; // North, South, East, West rooms
    Player player; // Our player class, which contains their spells (and more, but that will come later).

public:
    Game();
    ~Game();

    void Run();
    void ProcessCommand(MyString command);
    void MoveNorth();
    void MoveSouth();
    void MoveEast();
    void MoveWest();
    void UseItem();
    void CheckSpell(MyString command);
    void DisplayHelp();
    void SetupRooms();
};

#endif