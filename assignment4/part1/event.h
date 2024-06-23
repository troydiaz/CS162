#ifndef EVENT_H
#define EVENT_H 

using namespace std;

//Event Interface
//Note: this must be an abstract class!

class Event
{

protected:

public:

/********************************************************************* 
** Function: percept()
** Description: Virtual function displaying percept messages to player
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
virtual void percept() const = 0;

/********************************************************************* 
** Function: encounter()
** Description: Virtual function displaying event messages to player
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
virtual void encounter() = 0;

/********************************************************************* 
** Function: ~Event()
** Description: Virtual destructor to free dynamic memory
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
virtual ~Event() {}
	
};
#endif