#ifndef GOLD_H
#define GOLD_H 

//Derived from event class
#include "event.h"

//Gold Interface

using namespace std;

class Gold : public Event
{
private:
    bool HasGold; // Keeps track of player holding gold

public:

/********************************************************************* 
** Function: Gold()
** Description: Gold class default constructor to initialize private member variables
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none 
*********************************************************************/
Gold();

/********************************************************************* 
** Function: percept()
** Description: Displays percept message to player
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Displays percept message to player
*********************************************************************/
void percept() const override;

/********************************************************************* 
** Function: encounter()
** Description: Displays event message to player
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Displays event message to player
*********************************************************************/
void encounter() override;

// Setters
/********************************************************************* 
** Function: setPlayerHasGold()
** Description: Sets value of private member playerHasGold
** Parameters: bool Pos
** Pre-Conditions: none
** Post-Conditions: Sets new value of private member playerHasGold
*********************************************************************/
bool setPlayerHasGold(bool Pos);

// Getters
/********************************************************************* 
** Function: getPlayerHasGold()
** Description: Gets value of private member playerHasGold
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
bool getPlayerHasGold() const;

};

#endif