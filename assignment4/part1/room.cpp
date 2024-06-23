#include "room.h"

using namespace std;

//Room Implementation

// Constructor

Room::Room() : PlayerIn(false), GoldIn(false), PoolIn(false), StalactitesIn(false), WumpusIn(false), EscapeRopeIn(false){}

// Setters
void Room::setPlayerIn(bool InRoom) 
{
    PlayerIn = InRoom;
}

void Room::setGold(bool Pos) 
{
    GoldIn = Pos;
}

void Room::setPool(bool Pos) 
{
    PoolIn = Pos;
}

void Room::setStalactites(bool Pos) 
{
    StalactitesIn = Pos;
}

void Room::setWumpus(bool Pos) 
{
    WumpusIn = Pos;
}

void Room::setEscapeRope(bool Pos) 
{
    EscapeRopeIn = Pos;
}

// Getters
bool Room::getPlayerIn() const 
{
    return PlayerIn;
}

bool Room::getGold() const 
{
    return GoldIn;
}

bool Room::getPool() const 
{
    return PoolIn;
}

bool Room::getStalactites() const 
{
    return StalactitesIn;
}

bool Room::getWumpus() const 
{
    return WumpusIn;
}

bool Room::getEscapeRope() const 
{
    return EscapeRopeIn;
}
