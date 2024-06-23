#ifndef ROOM_H
#define ROOM_H 

#include "event.h"

using namespace std;

//Room Interface
//Note: Each room may be empty or has an event (bat, gold, pit, or wumpus);
//		Use event polymorphically

class Room
{
private: 
    bool PlayerIn; // If player is in room
    bool GoldIn; // If gold is in room
    bool PoolIn; // If pool is in room
    bool StalactitesIn; // If stalactites is in room
    bool WumpusIn; // If wumpus is in room
    bool EscapeRopeIn; // If escape rope is in room
	
public:

/********************************************************************* 
** Function: Room()
** Description: Room class default constructor to initialize private member variables
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Room();

// Setters
/********************************************************************* 
** Function: setPlayerIn()
** Description: Sets value of private member playerIn
** Parameters: bool InRoom
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void setPlayerIn(bool InRoom);

/********************************************************************* 
** Function: setGold()
** Description: Sets value of private member gold
** Parameters: bool Pos
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void setGold(bool Pos);

/********************************************************************* 
** Function: setPool()
** Description: Sets value of private member pool
** Parameters: bool Pos
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void setPool(bool Pos);

/********************************************************************* 
** Function: setStalactites()
** Description: Sets value of private member stalactites
** Parameters: bool Pos
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void setStalactites(bool Pos);

/********************************************************************* 
** Function: setWumpus()
** Description: Sets value of private member wumpus
** Parameters: bool Pos
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void setWumpus(bool Pos);

/********************************************************************* 
** Function: setEscapeRope()
** Description: Sets value of private member escapeRope
** Parameters: bool Pos
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void setEscapeRope(bool Pos);

// Getters
/********************************************************************* 
** Function: getPlayerIn()
** Description: Gets value of private member playerIn
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
bool getPlayerIn() const;

/********************************************************************* 
** Function: getGold()
** Description: Gets value of private member gold
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
bool getGold() const;

/********************************************************************* 
** Function: getPool()
** Description: Gets value of private member pool
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
bool getPool() const;

/********************************************************************* 
** Function: getStalactites()
** Description: Gets value of private member stalactites
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
bool getStalactites() const;

/********************************************************************* 
** Function: getWumpus()
** Description: Gets value of private member wumpus
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
bool getWumpus() const;

/********************************************************************* 
** Function: getEscapeRope()
** Description: Gets value of private member escapeRope
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
bool getEscapeRope() const;

};

#endif