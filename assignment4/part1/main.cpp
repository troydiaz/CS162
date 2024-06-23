/********************************************************************* 
** Program Filename: wumpus
** Author: Troy Diaz
** Date: 03/18/24
** Description:  The game is designed around an adventurer who is looking 
for gold in a grid and escapes alive. While searching for gold, the adventurer 
must avoid or deal with obstacles such as the Wumpus, stalactites, and being 
submerged underwater. Messages or percepts are displayed to the adventurer 
to warn or draw attention to events in the game.
** Input: Grid size, debug mode, movement, arrow firing
** Output: Grid, percepts, oxygen level, arrow count, status, win/loss, 
invalid inputs
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"
#include "gold.h"
#include "stalactites.h"
#include "pool.h"
#include "wumpus.h"

using namespace std;

int main()
{
	//set the random seed
	srand(time(NULL));
	
	int side_len = 0, input = -1;
	bool debug = false;
	
	Game g;
	Gold go;
	Pool p;
	Stalactites stal;
	Wumpus w;

	//get one input: side length of the cave
	while (side_len < 5 || side_len > 50)
	{
		cout << "Side length of cave: ";
		cin >> side_len;

		if (side_len < 5 || side_len > 50)
		{
			cout << "Please choose a number >= 5 or <= 50." << endl;
		}
	}

	//get the 2nd input --> debug mode or not
	while (true)
	{
		cout << "Debug mode? (1/0): ";
		cin >> input;

		if (input == 0 || input == 1)
		{
			debug = input;
			break;
		}
		else
		{
			cout << "Please choose 1 (true) or 0 (false)." << endl;
		}
	}

	//Play game
	g.play_game(side_len, debug, g, go, p, stal, w);

	return 0;
}