/********************************************************************* 
** Program Filename: assignment3
** Author: Troy Diaz
** Date: 02/26/2024
** Description: A program that simulates an air traffic control system.
** Input: Add a new flight, remove an existing flight, update a flight's current airport
to its new destination airport: "taking off," and quit program
** Output: Print all airport/flight information, print information of one flight
based on the flight number provided by user input, and print information of each program.
*********************************************************************/
#include <iostream>
#include "manager.h"
#include <fstream>

using namespace std;

int main()
{	
	Manager m;
	m.run();
	
	return 0;
}
