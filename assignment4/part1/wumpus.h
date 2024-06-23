#ifndef WUMPUS_H
#define WUMPUS_H 

//Derived from event class
#include "event.h"

//Wumpus Interface

using namespace std;

class Wumpus : public Event
{
private:
    bool IsPlayerDead; // Keeping track of player's status

public:

/********************************************************************* 
** Function: Wumpus()
** Description: Wumpus class default constructor to initialize private member variables
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Wumpus();

/********************************************************************* 
** Function: percept()
** Description: Displays percept message to player
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void percept() const override;

/********************************************************************* 
** Function: encounter()
** Description: Displays event message to player
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void encounter() override;

// Getters
/********************************************************************* 
** Function: getIsPlayerDead()
** Description: Gets value of private member isPlayerDead
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
bool getIsPlayerDead() const;

// Setters
/********************************************************************* 
** Function: setIsPlayerDead()
** Description: Sets value of private member isPlayerDead
** Parameters: bool Pos
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void setIsPlayerDead(bool Pos);

};

#endif