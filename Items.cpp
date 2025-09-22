#include "Items.h"
#include <iostream>

using namespace std;

Item::Item() {
}

Item::~Item() {
}

void Item::Description() {
    cout << "This is a basic item.";
}

void Item::Use() {
    cout << "You used the item.";
}

Lamp::Lamp() {
    turnedOn = false;
}

Lamp::~Lamp() {
}

void Lamp::Description() {
    if (turnedOn) {
        cout << "A bright lamp that is currently ON, providing light.";
    }
    else {
        cout << "A lamp that is currently OFF.";
    }
}

void Lamp::Use() {
    if (turnedOn) {
        turnedOn = false;
        cout << "You turned the lamp OFF.";
    }
    else {
        turnedOn = true;
        cout << "You turned the lamp ON. It now provides light!";
    }
}

BoxOfDonuts::BoxOfDonuts() {
    count = 6;
}

BoxOfDonuts::~BoxOfDonuts() {
}

void BoxOfDonuts::Description() {
    if (count > 0) {
        cout << "A delicious box of donuts with " << count << " donuts remaining.";
    }
    else {
        cout << "An empty donut box. All the donuts have been eaten!";
    }
}

void BoxOfDonuts::Use() {
    if (count > 0) {
        count--;
        cout << "You ate a delicious donut! Yum! " << count << " donuts remaining.";
    }
    else {
        cout << "The box is empty! No more donuts to eat.";
    }
}

Cat::Cat() {
    purring = false;
}

Cat::~Cat() {
}

void Cat::Description() {
    if (purring) {
        cout << "A fluffy cat that is purring contentedly.";
    }
    else {
        cout << "A cute cat sitting quietly, looking at you with curious eyes.";
    }
}

void Cat::Use() {
    if (purring) {
        purring = false;
        cout << "You stop petting the cat. It looks at you expectantly.";
    }
    else {
        purring = true;
        cout << "You pet the cat. It starts purring loudly! *purr purr*";
    }
}