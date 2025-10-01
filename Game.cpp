#include "Game.h"
#include <iostream>

using namespace std;

Room::Room() {
    description = "An empty room.";
    itemType = "none";
}

Room::Room(string roomDescription, string itemTypeName) {
    description = roomDescription;
    itemType = itemTypeName;
}

Room::~Room() {
}

void Room::Description() {
    cout << description << endl;

    if (itemType == "lamp") {
        cout << "You see: ";
        lamp.Description();
        cout << endl;
    }
    else if (itemType == "donuts") {
        cout << "You see: ";
        donuts.Description();
        cout << endl;
    }
    else if (itemType == "cat") {
        cout << "You see: ";
        cat.Description();
        cout << endl;
    }
}

void Room::UseItem() {
    if (itemType == "lamp") {
        lamp.Use();
    }
    else if (itemType == "donuts") {
        donuts.Use();
    }
    else if (itemType == "cat") {
        cat.Use();
    }
    else {
        cout << "There is no item in this room to use.";
    }
}

bool Room::HasItem() {
    return itemType != "none";
}

Game::Game() {
    SetupRooms();
    currentRoomIndex = 0; // Starting in the first room here.
}

Game::~Game() {
}

void Game::SetupRooms() {
    rooms[0] = Room("You are in a cozy living room with a fireplace.", "lamp");
    rooms[1] = Room("You are in a bright kitchen with marble countertops.", "donuts");
    rooms[2] = Room("You are in a peaceful garden with flowers everywhere.", "cat");
    rooms[3] = Room("You are in a quiet bedroom with a comfortable bed.", "none");
}

//test why but again
void Game::Run() {
    cout << "=== WELCOME TO THE TEXT ADVENTURE GAME ===" << endl;
    cout << "Type 'help' for a list of commands." << endl;
    cout << endl;

    rooms[currentRoomIndex].Description();
    cout << endl;

    MyString command;
    while (true) {
        cout << "What would you like to do? ";
        command.ReadFromConsole();

        command.ToLower();

        if (command.EqualTo(MyString("quit"))) {
            cout << "Thanks for playing! Goodbye!" << endl;
            break;
        }

        ProcessCommand(command);
        cout << endl;
    }
}

void Game::ProcessCommand(MyString command) {
    // We can also make a copy here instead of using it directly, but it's unnecessary.
    command.ToLower();

    if (command.EqualTo(MyString("move north"))) {
        MoveNorth();
    }
    else if (command.EqualTo(MyString("move south"))) {
        MoveSouth();
    }
    else if (command.EqualTo(MyString("move east"))) {
        MoveEast();
    }
    else if (command.EqualTo(MyString("move west"))) {
        MoveWest();
    }
    else if (command.EqualTo(MyString("use item"))) {
        UseItem();
    }
    else if (command.EqualTo(MyString("look"))) {
        rooms[currentRoomIndex].Description();
    }
    else if (command.EqualTo(MyString("help"))) {
        DisplayHelp();
    }
    else if (command.Find(MyString("spell ")) == 0) {
        CheckSpell(command);
    }
    else {
        cout << "I don't understand that command. Type 'help' for available commands.";
    }
}

void Game::MoveNorth() {
    currentRoomIndex = 0;
    cout << "You moved North." << endl;
    rooms[currentRoomIndex].Description();
}

void Game::MoveSouth() {
    currentRoomIndex = 1;
    cout << "You moved South." << endl;
    rooms[currentRoomIndex].Description();
}

void Game::MoveEast() {
    currentRoomIndex = 2;
    cout << "You moved East." << endl;
    rooms[currentRoomIndex].Description();
}

void Game::MoveWest() {
    currentRoomIndex = 3;
    cout << "You moved West." << endl;
    rooms[currentRoomIndex].Description();
}

void Game::UseItem() {
    rooms[currentRoomIndex].UseItem();
}

void Game::CheckSpell(MyString command) {
    // Extract the spell name from "spell X" command
    // Get the part after "spell "
    string fullCommand = command.getString();
    if (fullCommand.length() > 6) {
        string spellPart = fullCommand.substr(6); // Specifically, here is where we get everything after "spell "
        MyString spellName = MyString(spellPart);

        // Check if player knows this spell
        if (player.FindSpell(spellName)) {
            cout << "You know the spell '" << spellName.getString() << "'! You cast it successfully.";
            
            //We can technically add if/else checks per spell name (or even better, use Polymorphism to cast a single action!) in order to write different spell effects depending on what the spell is.
        }
        else {
            cout << "You don't know the spell '" << spellName.getString() << "'. Known spells: fireball, frostbolt, shadowbolt, polymorph";
        }
    }
    else {
        cout << "Please specify a spell name. Example: spell fireball";
    }
}

void Game::DisplayHelp() {
    cout << "Available commands:" << endl;
    cout << "  move north - Move to the northern room" << endl;
    cout << "  move south - Move to the southern room" << endl;
    cout << "  move east  - Move to the eastern room" << endl;
    cout << "  move west  - Move to the western room" << endl;
    cout << "  use item   - Use the item in the current room" << endl;
    cout << "  spell X    - Check if you know spell X (fireball, frostbolt, shadowbolt, polymorph)" << endl;
    cout << "  look       - Look around the current room" << endl;
    cout << "  help       - Show this help message" << endl;
    cout << "  quit       - Exit the game" << endl;
}