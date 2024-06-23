#ifndef POOL_H
#define POOL_H 

//Derived from event class
#include "event.h"

//Pool Interface

using namespace std;

class Pool : public Event
{
private:
    bool PlayerInPool; // Keeping track of player in pool
public:

/********************************************************************* 
** Function: Pool()
** Description: Pool class default constructor to initialize private member variables
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Pool();

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
** Function: getPlayerInPool()
** Description: Gets value of private member playerInPool
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
bool getPlayerInPool() const;

// Setters
/********************************************************************* 
** Function: setPlayerInPool()
** Description: Sets value of private member playerInPool
** Parameters: bool Pos
** Pre-Conditions: none
** Post-Conditions: Sets new value of private member playerInPool
*********************************************************************/
void setPlayerInPool(bool Pos);
    
};

#endif