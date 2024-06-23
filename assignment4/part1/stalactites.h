#ifndef STALACTITES_H
#define STALACTITES_H 

//Derived from event class
#include "event.h"

//Stalactites Interface

using namespace std;

class Stalactites : public Event
{
public:

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
    
};

#endif