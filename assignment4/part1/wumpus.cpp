#include "wumpus.h"

#include <iostream>

using namespace std;

//Wumpus Implementation

Wumpus::Wumpus()
{
    IsPlayerDead = false;
}

void Wumpus::percept() const
{
    cout << "You smell a terrible stench." << endl;
}

void Wumpus::encounter()
{
    cout << "The Wumpus has killed you." << endl;
}

// Getters
bool Wumpus::getIsPlayerDead() const
{
    return IsPlayerDead;
}

// Setters
void Wumpus::setIsPlayerDead(bool Pos)
{
    IsPlayerDead = Pos;
}