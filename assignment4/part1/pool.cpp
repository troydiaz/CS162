#include "pool.h"

#include <iostream>

using namespace std;

//Pool Implementation

Pool::Pool()
{
    PlayerInPool = false;
}

void Pool::percept() const
{
    cout << "You hear wind blowing." << endl;
}

void Pool::encounter()
{
    cout << "You have drowned." << endl;
}

// Getters
bool Pool::getPlayerInPool() const
{
    return PlayerInPool;
}

// Setters
void Pool::setPlayerInPool(bool Pos)
{
    PlayerInPool = Pos;
}

