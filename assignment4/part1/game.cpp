#include "game.h"
#include "gold.h"
#include "stalactites.h"
#include "pool.h"
#include "wumpus.h"

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

//Game Implementation

// Constructor
Game::Game()
{	
	side = 0;
	num_arrows = 0;
	debug_view = false;
	PlayerCol = 0;
	PlayerRow = 0;
	PlayerHasGold = false;
	PlayerIsAlive = true;
	oxygen_level = 0;
	turns = 0;

	room_vec = vector<vector<Room>>(side, vector<Room>(side));
}

// Destructor
Game::~Game()
{
	//Game destructor
}

// Copy Constructor
Game::Game(const Game& other)
{
	side = other.side;
    num_arrows = other.num_arrows;
    debug_view = other.debug_view;
	PlayerCol = other.PlayerCol;
    PlayerRow = other.PlayerRow;
    PlayerHasGold = other.PlayerHasGold;
	PlayerIsAlive = other.PlayerIsAlive;
	oxygen_level = other.oxygen_level;
	room_vec = other.room_vec;
}

// Assignment Operator Overload
Game& Game::operator = (const Game& other)
{
	if (this != &other)
	{
		side = other.side;
        num_arrows = other.num_arrows;
        debug_view = other.debug_view;
        PlayerRow = other.PlayerRow;
        PlayerCol = other.PlayerCol;
        PlayerHasGold = other.PlayerHasGold;
		PlayerIsAlive = other.PlayerIsAlive;
		oxygen_level = other.oxygen_level;
		room_vec = other.room_vec;
	}
}

void Game::set_up(int s)
{
	//set up the game
	this->side = s;

	//start with 3 arrows
	setNumArrows(this->num_arrows = 3);	
	
	//start with oxygen level of side*2
	setOxygenLevel(s*2); 

	// Resetting conditions of 2d board
	room_vec.clear(); 
    room_vec.resize(s, vector<Room>(s)); 

	// Create the game board: 2D vector of Room objects
	for (int i = 0; i < s; i++)
	{
		vector<Room> s_vec;
		for (int j = 0; j < s; j++)
		{
			Room r;
			s_vec.push_back(r);
		}
		room_vec.push_back(s_vec);
	}

	int RandomRow = 0;
	int RandomCol = 0;

	// Player/Escape rope random position
	set_rand_player(RandomRow, RandomCol);

	// Gold random position
	set_rand_gold(RandomRow, RandomCol);

	// Two pools random position
	set_rand_pool(RandomRow, RandomCol);

	// Two stalactices random position
	set_rand_stalactites(RandomRow, RandomCol);

	// Wumpus random position
	set_rand_wumpus(RandomRow, RandomCol);
}

void Game::set_rand_player(int RandomRow, int RandomCol)
{
	do
	{
		// Finding an empty room to put event in
		PlayerRow = rand() % this->side;
		PlayerCol = rand() % this->side;
	}
	while (is_room_empty(PlayerRow, PlayerCol));

	// Setting the empty room to have an event
	room_vec[PlayerRow][PlayerCol].setPlayerIn(true);
	room_vec[PlayerRow][PlayerCol].setEscapeRope(true);
}

void Game::set_rand_gold(int RandomRow, int RandomCol) 
{
	do 
	{
		RandomRow = rand() % this->side;
		RandomCol = rand() % this->side;
	} 
	while (is_room_empty(RandomRow, RandomCol));

	room_vec[RandomRow][RandomCol].setGold(true);
}

void Game::remove_gold_pos()
{
	// Finding where gold is currently in
	for (int i = 0; i < side; i++)
	{
		for (int j = 0; j < side; j++)
		{
			if(room_vec[i][j].getGold())
			{
				// Removing gold in room
				room_vec[i][j].setGold(false);
				break;
			}
		}
	}
}

void Game::set_rand_pool(int RandomRow, int RandomCol) 
{
	for (int i = 0; i < 2; i++)
	{
		do 
		{
			RandomRow = rand() % this->side;
			RandomCol = rand() % this->side;
		}
		while (is_room_empty(RandomRow, RandomCol));
		room_vec[RandomRow][RandomCol].setPool(true);
	}
}

void Game::set_rand_stalactites(int RandomRow, int RandomCol) 
{
	for (int i = 0; i < 2; i++)
	{
		do 
		{
			RandomRow = rand() % this->side;
			RandomCol = rand() % this->side;
		}
		while (is_room_empty(RandomRow, RandomCol));

		room_vec[RandomRow][RandomCol].setStalactites(true);
	}
}

void Game::set_rand_wumpus(int RandomRow, int RandomCol) 
{
	do 
	{
		RandomRow = rand() % this->side;
		RandomCol = rand() % this->side;
	} 
	while (is_room_empty(RandomRow, RandomCol));

	room_vec[RandomRow][RandomCol].setWumpus(true);
}

void Game::remove_wumpus_pos()
{
	// Finding where wumpus is currently in
	for (int i = 0; i < side; i++)
	{
		for (int j = 0; j < side; j++)
		{
			if(room_vec[i][j].getWumpus())
			{
				// Removing wumpus from room
				room_vec[i][j].setWumpus(false);
				break;
			}
		}
	}
}

bool Game::is_room_empty(int row, int col)
{
	// Checking if any one room has a event
	// Return false if a room empty, true if at least one event is in a room

	return 
		room_vec[row][col].getPlayerIn() || 
		room_vec[row][col].getGold() || 
		room_vec[row][col].getPool() || 
		room_vec[row][col].getStalactites() || 
		room_vec[row][col].getWumpus(); 
}

void Game::display_game(bool debug) const
{
	cout << endl << endl;
	cout << "Arrows remaining: " << getNumArrows() << endl;
	cout << "Oxygen Level: " << getOxygenLevel() << endl; 
	
	string line = "";
	for (int i = 0; i < this->side; ++i)
		line += "-----";

	for (int i = 0; i < this->side; ++i)
	{
		cout << line << endl;
		for (int j = 0; j < this->side; ++j)
		{
			if (i == PlayerRow && j == PlayerCol)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}

			if (debug == 1)
			{
				if (room_vec[i][j].getGold())
				{
					cout << "G";
				}
				else if (room_vec[i][j].getPool())
				{
					cout << "P";
				}
				else if (room_vec[i][j].getStalactites())
				{
					cout << "S";
				}
				else if (room_vec[i][j].getWumpus())
				{
					cout << "W";
				}
				else if (room_vec[i][j].getEscapeRope())
				{
					cout << "~";
				}
			else
			{
				cout << " ";
			}
			}
			cout << " ||";
		}
		cout << endl;
	}
	cout << line << endl;
}

bool Game::check_win() const
{
	//check if game win
	// End game if player has gold and made it to escape room (starting point)
	if (room_vec[PlayerRow][PlayerCol].getEscapeRope() && PlayerHasGold)
    {
        cout << "You win!" << endl;
        return true;
    }

	return false;
}

bool Game::check_loss() const
{
	//check if game loss
	if (PlayerIsAlive == false)
    {
        cout << "You lost!" << endl;
        return false;
    }

	return true;
}

bool Game::picked_gold()
{
	Gold g;
	//checks if player has entered the room with gold and removes gold from room
	if (room_vec[PlayerRow][PlayerCol].getGold())
	{
		PlayerHasGold = g.setPlayerHasGold(true);
		remove_gold_pos();
		g.encounter();
	}
}

bool Game::wumpus_death()
{
	Wumpus w;
	//checks if player has entered the room with wumpus and ends the game
	if (room_vec[PlayerRow][PlayerCol].getWumpus())
	{
		w.setIsPlayerDead(false);
		PlayerIsAlive = w.getIsPlayerDead();
		w.encounter();
	}
}

bool Game::stalactite_death()
{
	Stalactites s;
	// 50% chance stalactite kills player
	int random_number = rand() % 2; 
	if (room_vec[PlayerRow][PlayerCol].getStalactites() && random_number == 0)
	{
		PlayerIsAlive = false;
		s.encounter();
	}
}

void Game::PlayerSubmerged(Pool& p)
{
	// entering a pool
	if ((room_vec[PlayerRow][PlayerCol].getPool() && getTurns() == 0)) 
	{
		p.setPlayerInPool(true);
		setTurns(1);
	}
	else if(getTurns() == 1) // staying in pool
	{
		if (room_vec[PlayerRow][PlayerCol].getPool() && getTurns() == 1) // leaving pool
		{
			cout << "You have left the pool." << endl;
			p.setPlayerInPool(false);
			setTurns(0);
			setOxygenLevel(this->side*2);
		}
		else
		{
			// Decrease oxygen by 1 for every move within pool
			decrease_oxygen_level();
		}
	}
}

bool Game::pool_death()
{
	Pool p;
	// If player runs out of oxygen
	if (getOxygenLevel() == 0)
	{
		PlayerIsAlive = false;
		p.encounter();
	}
}

void Game::decrease_oxygen_level()
{
	// decrease oxygen level by 1 every turn
	int oxygen = getOxygenLevel();
	setOxygenLevel(oxygen-1);
}


void Game::move_up() 
{
	//move player up
	int temprow = PlayerRow - 1;

	if (temprow >= 0)
	{
		// setting old position to be false
		room_vec[PlayerRow][PlayerCol].setPlayerIn(false);

		// assigning updated position to PlayerRow index
		PlayerRow = temprow;

		// setting new position to be true in this room
		room_vec[PlayerRow][PlayerCol].setPlayerIn(true);
	}
	else
	{
		cout << "Can't move any further up!" << endl;
	}

	return;
}

void Game::move_down() 
{
	//move player down
	int temprow = PlayerRow + 1;

	if (temprow < this->side)
	{
		// setting old position to be false
		room_vec[PlayerRow][PlayerCol].setPlayerIn(false);

		// assigning updated position to PlayerRow index
		PlayerRow = temprow;

		// setting new position to be true in this room
		room_vec[PlayerRow][PlayerCol].setPlayerIn(true);
	}
	else
	{
		cout << "Can't move any further down!" << endl;
	}

	return;
}

void Game::move_left() 
{
	//move player left
	int tempcol = PlayerCol - 1;

	if (tempcol >= 0)
	{
		// setting old position to be false
		room_vec[PlayerRow][PlayerCol].setPlayerIn(false);

		// assigning updated position to PlayerCol index
		PlayerCol = tempcol;

		// setting new position to be true in this room
		room_vec[PlayerRow][PlayerCol].setPlayerIn(true);
	}
	else
	{
		cout << "Can't move to the left!" << endl;
	}

	return;
}

void Game::move_right() 
{
	//move player right
	int tempcol = PlayerCol + 1;

	if (tempcol < this->side)
	{
		// setting old position to be false
		room_vec[PlayerRow][PlayerCol].setPlayerIn(false);

		// assigning updated position to PlayerCol index
		PlayerCol = tempcol;

		// setting new position to be true in this room
		room_vec[PlayerRow][PlayerCol].setPlayerIn(true);
	}
	else
	{
		cout << "Can't move to the right!" << endl;
	}

	return;
}

char Game::get_dir()
{
	//get direction of arrow:
	char dir;

	if (this->num_arrows == 0)
	{
		cout << "You have no arrows left..." << endl;
		return dir;
	}
	else
	{
		cout << "Fire an arrow...." << endl;
		cout << "W-up" << endl;
		cout << "A-left" << endl;
		cout << "S-down" << endl;
		cout << "D-right" << endl;
		cout << "Enter direction: " << endl;
		cin >> dir;
		cin.ignore(256, '\n');

		return dir;
	}
}

void Game::wumpus_move()
{
	// 75% chance wumpus will move after missed arrow
	int random_number = rand() % 4;
	int row = 0;
	int col = 0;

	// Removing current position of wumpus
	if (random_number != 0)
	{
		remove_wumpus_pos();

		// Setting new position of wumpus
		set_rand_wumpus(row, col);
	}

	return;
}

void Game::fire_arrow()
{
	// The player may fire arrow...

	// Using temporary position to check arrows conditions
	int traveledrow = PlayerRow;
	int traveledcol = PlayerCol;
	char dir = get_dir();
	bool wumpus_hit = false;

	if (this->num_arrows == 0)
	{
		return;
	}
	else
	{
		this->num_arrows -= 1;
		cout << "Arrow has been shot!" << endl;
	}

	// Arrows range is 3 rooms, checking each room in direction fired if Wumpus is in it
	for (int i = 0; i < 3; i++)
	{
		if (dir == 'w')
			traveledrow--;
		if (dir == 's')
			traveledrow++;
		if (dir == 'a')
			traveledcol--;
		if (dir == 'd')
			traveledcol++;

		// If arrow has passed the bounds, break out of for loop
		if (traveledrow < 0 || traveledcol < 0 || traveledrow >= side || traveledcol >= side)
			break;

		// If arrow has hit wumpus, set wumpus event to be false and display message
		if (room_vec[traveledrow][traveledcol].getWumpus())
		{
			wumpus_hit = true;
			room_vec[traveledrow][traveledcol].setWumpus(false);
			cout << "The Wumpus has been killed!" << endl;
			break;
		}
	}

	// If arrow missed wumpus, 75% chance wumpus will move to a new empty room
	if (wumpus_hit == false)
	{
		cout << "The arrow missed its mark..." << endl;
		wumpus_move();
	}

	return;
}

void Game::move(char c) 
{
	// Handle player's action: move or fire an arrow
	if (c == 'f'){
		Game::fire_arrow();
		return;
	}
	switch(c){
		case 'w':
			Game::move_up();
			break;
		case 'a':
			Game::move_left();
			break;
		case 's':
			Game::move_down();
			break;
		case 'd':
			Game::move_right();
			break;
	}
}

char Game::get_input()
{
	//get action, move direction or firing an arrow	
	char c;

	cout << endl << endl << "Player move..." << endl << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;
	cout << "f-fire an arrow" << endl;

	cout << "Enter input: ";
	cin >> c;
	cin.ignore(256, '\n');

	return c;
}

void Game::play_game(int side, bool debug, Game& g, Gold& go, Pool& p, Stalactites& stal, Wumpus& w)
{
	Game::set_up(side);
	this->debug_view = debug;

	char input, arrow_input;
	
	while (Game::check_win() == false && Game::check_loss() == true)
	{
		//print game board
		Game::display_game(debug);

		//display percerts around player's location
		if (is_gold_near() == true)
		{
			go.percept();
		}
		if (is_pool_near() == true)
		{
			p.percept();
		}
		if (is_stalactites_near() == true)
		{
			stal.percept();
		}
		if (is_wumpus_near() == true)
		{
			w.percept();
		}
		
		//Player move...
		//1. get input
		input = Game::get_input();

		//2. move player
		Game::move(input);

		//3. may or may not encounter events
		// if player is in pool, dont check these conditions
		PlayerSubmerged(p);

		if (p.getPlayerInPool())
		{
			pool_death();
		}
		else
		{
			picked_gold();
			wumpus_death();
			stalactite_death();
		}

	}
	return;
}

bool Game::is_gold_near() const
{
	// Directly Above
	if (PlayerRow > 0 && room_vec[PlayerRow - 1][PlayerCol].getGold())
		return true;

	// Directly Below
	if (PlayerRow < side - 1 && room_vec[PlayerRow + 1][PlayerCol].getGold())
		return true;

	// Directly to the Left
	if (PlayerCol > 0 && room_vec[PlayerRow][PlayerCol - 1].getGold())
		return true;

	// Directly to the Right
	if (PlayerCol < side - 1 && room_vec[PlayerRow][PlayerCol + 1].getGold())
		return true;

	// If no event is nearby
	return false;
}

bool Game::is_pool_near() const
{
	// Directly Above
	if (PlayerRow > 0 && room_vec[PlayerRow - 1][PlayerCol].getPool())
		return true;

	// Directly Below
	if (PlayerRow < side - 1 && room_vec[PlayerRow + 1][PlayerCol].getPool())
		return true;

	// Directly to the Left
	if (PlayerCol > 0 && room_vec[PlayerRow][PlayerCol - 1].getPool())
		return true;

	// Directly to the Right
	if (PlayerCol < side - 1 && room_vec[PlayerRow][PlayerCol + 1].getPool())
		return true;

	// If no event is nearby
	return false;
}

bool Game::is_stalactites_near() const
{
	// Directly Above
	if (PlayerRow > 0 && room_vec[PlayerRow - 1][PlayerCol].getStalactites())
		return true;

	// Directly Below
	if (PlayerRow < side - 1 && room_vec[PlayerRow + 1][PlayerCol].getStalactites())
		return true;

	// Directly to the Left
	if (PlayerCol > 0 && room_vec[PlayerRow][PlayerCol - 1].getStalactites())
		return true;

	// Directly to the Right
	if (PlayerCol < side - 1 && room_vec[PlayerRow][PlayerCol + 1].getStalactites())
		return true;

	// If no event is nearby
	return false;
}

bool Game::is_wumpus_near() const
{
	// Directly Above
	if (PlayerRow > 0 && room_vec[PlayerRow - 1][PlayerCol].getWumpus())
		return true;

	// Directly Below
	if (PlayerRow < side - 1 && room_vec[PlayerRow + 1][PlayerCol].getWumpus())
		return true;

	// Directly to the Left
	if (PlayerCol > 0 && room_vec[PlayerRow][PlayerCol - 1].getWumpus())
		return true;

	// Directly to the Right
	if (PlayerCol < side - 1 && room_vec[PlayerRow][PlayerCol + 1].getWumpus())
		return true;

	// If no event is nearby
	return false;
}

// Getters
int Game::getSide() const 
{
    return side;
}

int Game::getNumArrows() const 
{
    return num_arrows;
}

bool Game::getDebugView() const 
{
    return debug_view;
}

int Game::getPlayerRow() const 
{
    return PlayerRow;
}

int Game::getPlayerCol() const 
{
    return PlayerCol;
}

bool Game::getPlayerHasGold() const 
{
    return PlayerHasGold;
}

bool Game::getPlayerIsAlive() const 
{
    return PlayerIsAlive;
}

int Game::getOxygenLevel() const
{
    return oxygen_level;
}

int Game::getTurns() const
{
	return turns;
}

// Setters

void Game::setSide(int s) 
{
    side = s;
}

void Game::setNumArrows(int num) 
{
    num_arrows = num;
}

void Game::setDebugView(bool debug) 
{
    debug_view = debug;
}

void Game::setPlayerRow(int row) 
{
    PlayerRow = row;
}

void Game::setPlayerCol(int col) 
{
    PlayerCol = col;
}

void Game::setPlayerHasGold(bool hasGold) 
{
    PlayerHasGold = hasGold;
}

void Game::setPlayerIsAlive(bool isAlive) 
{
    PlayerIsAlive = isAlive;
}

void Game::setOxygenLevel(int level)
{
    oxygen_level = level;
}

void Game::setTurns(int moves)
{
	turns = moves;
}