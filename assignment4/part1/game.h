#ifndef GAME_H
#define GAME_H 

#include <vector>
#include <iostream> 
#include "room.h"
#include "game.h"
#include "gold.h"
#include "stalactites.h"
#include "pool.h"
#include "wumpus.h"

using namespace std;

//Game interface 
class Game
{
private:
	
	//declare a 2D vector of Room objects:
	vector<vector<Room> > room_vec;

	//other member variables:
	int side; 				//side of the board
	int num_arrows; 		//keep track of number of errors remaining
	bool debug_view;		//debug mode or not
	int PlayerRow, PlayerCol; // position of player
	bool PlayerHasGold; // If player has gold or not
	bool PlayerIsAlive; // If player is alive or not
	int oxygen_level; // Keeps track number of oxygen player has
	int turns; // Keeps track of moves made in pool

public:

/********************************************************************* 
** Function: Game()
** Description: Game constructor to initialize private member variables
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Game();

/********************************************************************* 
** Function: ~Game()
** Description: Game destructor to free dynamic memory
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
~Game();

/********************************************************************* 
** Function: Game(const Game& other)
** Description: Game copy constructor to copy member variables
** Parameters: other
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Game(const Game& other);

/********************************************************************* 
** Function: operator = (const Game& other)
** Description: Game AOO to assign memory to copied member variables 
** Parameters: other
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Game& operator = (const Game& other);

/********************************************************************* 
** Function: set_up()
** Description: Creates the game with number of arrows, oxygen level, 
board size, random positions of events and player
** Parameters: int
** Pre-Conditions: Length of board side
** Post-Conditions: Displays number of arrows, oxygen level, board size,
random positions of events and player
*********************************************************************/
void set_up(int);

/********************************************************************* 
** Function: display_game()
** Description: Displays the board with player, if debug is true then displays
board with player, escape rope, gold, pool, stalactites, and wumpus.
** Parameters: bool debug
** Pre-Conditions: Bool value of debug
** Post-Conditions: Displays board with or without game symbols
*********************************************************************/
void display_game(bool debug) const;

/********************************************************************* 
** Function: check_win()
** Description: Returns true based on the winning conditions of the game, which
is to get the gold and return back to the escape rope
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Returns true if conditional is met, false if conditional fails
*********************************************************************/
bool check_win() const;

/********************************************************************* 
** Function: get_dir()
** Description: Displays directional inputs and gets user input for that
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns directional input from user
*********************************************************************/
char get_dir();

/********************************************************************* 
** Function: wumpus_move()
** Description: Moves wumpus if arrow misses.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Removes wumpus from current room and moves it to random room
*********************************************************************/
void wumpus_move();

/********************************************************************* 
** Function: fire_arrow()
** Description: Checks rooms in which direction player shot the arrow in. Checks
3 rooms.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: If player shoots, misses, or hits wall, then moves wumpus. If player
shoots, hits the wumpus, then remove wumpus from room. 
*********************************************************************/
void fire_arrow();

/********************************************************************* 
** Function: move_up()
** Description: Moves player up
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Shifts player up 1 room 
*********************************************************************/
void move_up();

/********************************************************************* 
** Function: move_down()
** Description: Moves player down
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Shifts player down 1 room 
*********************************************************************/
void move_down();

/********************************************************************* 
** Function: move_left()
** Description: Moves player to the left
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Shifts player to the left 1 room
*********************************************************************/
void move_left();

/********************************************************************* 
** Function: move_right()
** Description: Moves player to the right
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Shifts player to the right 1 room
*********************************************************************/
void move_right();

/********************************************************************* 
** Function: move()
** Description: Gets directional input from player or fire arrow
** Parameters: char
** Pre-Conditions: Character input from player
** Post-Conditions: Calls directional functions based on player input or fire arrow
*********************************************************************/
void move(char);

/********************************************************************* 
** Function: get_input()
** Description: Gets input from player based on options given
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Gets character input from player
*********************************************************************/
char get_input();

/********************************************************************* 
** Function: play_game()
** Description: Performs the games rules by displaying percepts, checking for 
events in rooms, and moving character
** Parameters: int side, bool debug_view, Game& g, Gold& go, Pool& p, Stalactites& stal, Wumpus& w
** Pre-Conditions: Taking in side length, boolean value of debug, and referenced objects to event classes
** Post-Conditions: Performs these game rules while check_win is false and check_loss is true
*********************************************************************/
void play_game(int side, bool debug_view, Game& g, Gold& go, Pool& p, Stalactites& stal, Wumpus& w);

/********************************************************************* 
** Function: is_room_empty()
** Description: Checks if room has an event
** Parameters: int row, int col
** Pre-Conditions: Number for row and col
** Post-Conditions: Returns true if any event is in room, false if room is empty
*********************************************************************/
bool is_room_empty(int row, int col);

/********************************************************************* 
** Function: is_gold_near()
** Description: Checks rooms adjacent to player if gold event is near 
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Returns boolean value if event is near player
*********************************************************************/
bool is_gold_near() const;

/********************************************************************* 
** Function: is_pool_near()
** Description: Checks rooms adjacent to player if pool event is near
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Returns boolean value if event is near player
*********************************************************************/
bool is_pool_near() const;

/********************************************************************* 
** Function: is_stalactites_near()
** Description: Checks rooms adjacent to player if stalactites event is near
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Returns boolean value if event is near player
*********************************************************************/
bool is_stalactites_near() const;

/********************************************************************* 
** Function: is_wumpus_near()
** Description: Checks rooms adjacent to player if wumpus event is near
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Returns boolean value if event is near player
*********************************************************************/
bool is_wumpus_near() const;

/********************************************************************* 
** Function: set_rand_player()
** Description: Sets players position to a random room that is empty
** Parameters: int RandomRow, int RandomCol
** Pre-Conditions: none
** Post-Conditions: Sets that room to have player
*********************************************************************/
void set_rand_player(int RandomRow, int RandomCol);

/********************************************************************* 
** Function: set_rand_gold()
** Description: Sets gold position to a random room that is empty
** Parameters: int RandomRow, int RandomCol
** Pre-Conditions: none
** Post-Conditions: Sets that room to have gold
*********************************************************************/
void set_rand_gold(int RandomRow, int RandomCol);

/********************************************************************* 
** Function: set_rand_pool()
** Description: Sets pools position to a random room that is empty
** Parameters: int RandomRow, int RandomCol
** Pre-Conditions: none
** Post-Conditions: Sets that room to have pool
*********************************************************************/
void set_rand_pool(int RandomRow, int RandomCol);

/********************************************************************* 
** Function: set_rand_stalactites()
** Description: Sets stalactites position to a random room that is empty
** Parameters: int RandomRow, int RandomCol
** Pre-Conditions: none
** Post-Conditions: Sets that room to have stalactite
*********************************************************************/
void set_rand_stalactites(int RandomRow, int RandomCol);

/********************************************************************* 
** Function: set_rand_wumpus()
** Description: Sets wumpus position to a random room that is empty
** Parameters: int RandomRow, int RandomCol
** Pre-Conditions: none
** Post-Conditions: Sets that room to have wumpus
*********************************************************************/
void set_rand_wumpus(int RandomRow, int RandomCol);

/********************************************************************* 
** Function: remove_wumpus_pos()
** Description: Removes wumpus from room
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Sets value of wumpus to be false in that room
*********************************************************************/
void remove_wumpus_pos();

/********************************************************************* 
** Function: remove_gold_pos()
** Description: Removes gold from room
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Sets value of gold to be false in that room
*********************************************************************/
void remove_gold_pos();

/********************************************************************* 
** Function: picked_gold()
** Description: If player enters room with gold, then set PlayerHasGold to be true
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Player has gold
*********************************************************************/
bool picked_gold();

/********************************************************************* 
** Function: wumpus_death()
** Description: If player enters room with wumpus, then set PlayerIsAlive to be false
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Ends game
*********************************************************************/
bool wumpus_death();

/********************************************************************* 
** Function: stalactite_death()
** Description: If player enters room with stalactite, then 75% chance PlayerIsAlive is false
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Ends game
*********************************************************************/
bool stalactite_death();

/********************************************************************* 
** Function: pool_death()
** Description: If player enters room with pool, then player has to make moves equal to
the side length of grid * 2 to escape pool.
** Parameters: none
** Pre-Conditions: Checks oxygen level of player
** Post-Conditions: Ends game
*********************************************************************/
bool pool_death();

/********************************************************************* 
** Function: decrease_oxygen_level()
** Description: Decrements oxygen by 1 for every move made in pool
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Decreases oxygen level by 1
*********************************************************************/
void decrease_oxygen_level();

/********************************************************************* 
** Function: PlayerSubmerged()
** Description: Checks conditions of player in pool, such as entering a pool,
staying in pool, leaving pool, and decreasing oxygen level of player in pool
** Parameters: Pool&
** Pre-Conditions: none
** Post-Conditions: Checks player and pool conditions
*********************************************************************/
void PlayerSubmerged(Pool&);

/********************************************************************* 
** Function: check_loss()
** Description: If PlayerIsAlive is false, then end game
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Ends game if condition is met
*********************************************************************/
bool check_loss() const;

// Getters
/********************************************************************* 
** Function: getSide()
** Description: Gets value of private member side
** Parameters: none
** Pre-Conditions: none 
** Post-Conditions: none
*********************************************************************/
int getSide() const;

/********************************************************************* 
** Function: getNumArrows()
** Description: Gets value of private member numArrows
** Parameters: none
** Pre-Conditions: none 
** Post-Conditions: none
*********************************************************************/
int getNumArrows() const;

/********************************************************************* 
** Function: getDebugView()
** Description: Gets value of private member debugView
** Parameters: none
** Pre-Conditions: none 
** Post-Conditions: none
*********************************************************************/
bool getDebugView() const;

/********************************************************************* 
** Function: getPlayerRow()
** Description: Gets value of private member playerRow
** Parameters: none
** Pre-Conditions: none 
** Post-Conditions: none
*********************************************************************/
int getPlayerRow() const;

/********************************************************************* 
** Function: getPlayerCol()
** Description: Gets value of private member playerCol
** Parameters: none
** Pre-Conditions: none 
** Post-Conditions: none
*********************************************************************/
int getPlayerCol() const;

/********************************************************************* 
** Function: getPlayerHasGold()
** Description: Gets value of private member playerHasGold
** Parameters: none
** Pre-Conditions: none 
** Post-Conditions: none
*********************************************************************/
bool getPlayerHasGold() const;

/********************************************************************* 
** Function: getPlayerIsAlive()
** Description: Gets value of private member playerIsAlive
** Parameters: none
** Pre-Conditions: none 
** Post-Conditions: none
*********************************************************************/
bool getPlayerIsAlive() const;

/********************************************************************* 
** Function: getOxygenLevel()
** Description: Gets value of private member oxygenLevel
** Parameters: none
** Pre-Conditions: none 
** Post-Conditions: none
*********************************************************************/
int getOxygenLevel() const;

/********************************************************************* 
** Function: getTurns()
** Description: Gets value of private member turns
** Parameters: none
** Pre-Conditions: none 
** Post-Conditions: none
*********************************************************************/
int getTurns() const;

// Setters
/********************************************************************* 
** Function: setSide()
** Description: Sets value of private member side
** Parameters: int s
** Pre-Conditions: none
** Post-Conditions: Sets new value of private member side
*********************************************************************/
void setSide(int s);

/********************************************************************* 
** Function: setNumArrows()
** Description: Sets value of private member numArrows
** Parameters: int num
** Pre-Conditions: none
** Post-Conditions: Sets new value of private member numArrows
*********************************************************************/
void setNumArrows(int num);

/********************************************************************* 
** Function: setDebugView()
** Description: Sets value of private member debugView
** Parameters: bool debug
** Pre-Conditions: none
** Post-Conditions: Sets new value of private member debugView
*********************************************************************/
void setDebugView(bool debug);

/********************************************************************* 
** Function: setPlayerRow()
** Description: Sets value of private member playerRow
** Parameters: int row
** Pre-Conditions: none
** Post-Conditions: Sets new value of private member playerRow
*********************************************************************/
void setPlayerRow(int row);

/********************************************************************* 
** Function: setPlayerCol()
** Description: Sets value of private member playerCol
** Parameters: int col
** Pre-Conditions: none
** Post-Conditions: Sets new value of private member playerCol
*********************************************************************/
void setPlayerCol(int col);

/********************************************************************* 
** Function: setPlayerHasGold()
** Description: Sets value of private member playerHasGold
** Parameters: bool hasGold
** Pre-Conditions: none
** Post-Conditions: Sets new value of private member playerHasGold
*********************************************************************/
void setPlayerHasGold(bool hasGold);

/********************************************************************* 
** Function: setPlayerIsAlive()
** Description: Sets value of private member playerIsAlive
** Parameters: bool isAlive
** Pre-Conditions: none
** Post-Conditions: Sets new value of private member playerIsAlive
*********************************************************************/
void setPlayerIsAlive(bool isAlive);

/********************************************************************* 
** Function: setOxygenLevel()
** Description: Sets value of private member oxygenLevel
** Parameters: int level
** Pre-Conditions: none
** Post-Conditions: Sets new value of private member oxygenLevel
*********************************************************************/
void setOxygenLevel(int level);

/********************************************************************* 
** Function: setTurns()
** Description: Sets value of private member turns
** Parameters: int moves
** Pre-Conditions: none
** Post-Conditions: Sets new value of private member turns
*********************************************************************/
void setTurns(int moves);

};
#endif