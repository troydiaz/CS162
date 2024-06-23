#include "gold.h"

#include <iostream>

using namespace std;

//Gold Implementation

Gold::Gold()
{
    HasGold = false;
}

void Gold::percept() const
{
    cout << "You see a glimmer nearby." << endl;
}

void Gold::encounter()
{
    cout << "The gold has been picked up!" << endl;
}

// Setters
bool Gold::setPlayerHasGold(bool Pos)
{
    HasGold = Pos;
}

// Getters
bool Gold::getPlayerHasGold() const
{
    return HasGold;
}


