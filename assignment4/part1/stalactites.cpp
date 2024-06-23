#include "stalactites.h"

#include <iostream>

using namespace std;

//Stalactites Implementation

void Stalactites::percept() const
{
    cout << "You hear water dripping." << endl;
}

void Stalactites::encounter()
{
    cout << "You were crushed by a stalactite." << endl;
}

