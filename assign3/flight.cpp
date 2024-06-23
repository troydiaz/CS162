#include "flight.h"
#include <iostream>
#include <string>

using namespace std;

// Constructor

Flight::Flight()
{
	flight_num = "";
	curr_loc = "";
	dest = "";
	num_pilots = 0;
	pilots = nullptr;
}

// Destructor

Flight::~Flight()
{
	if (pilots != nullptr)
	{
		delete[] pilots;
	}
}

Flight::Flight (int size)
{
	this-> num_pilots = size;
	this-> pilots = new string[size];
}

// Copy Constructor

Flight::Flight(const Flight& other)
{
    // Copy member variables
    flight_num = other.flight_num;
    curr_loc = other.curr_loc;
    dest = other.dest;
    num_pilots = other.num_pilots;

    // new memory for pilots and copy content
    if (other.pilots != nullptr) 
	{
        pilots = new string[num_pilots];
        for (int i = 0; i < num_pilots; ++i) 
		{
            pilots[i] = other.pilots[i];
        }
    } 
	else 
	{
        pilots = nullptr;
    }
}

// Assignment Operator Overload

Flight& Flight::operator = (const Flight& other)
{
    if (this != &other) 
	{ 
        // Copy member variables
        flight_num = other.flight_num;
        curr_loc = other.curr_loc;
        dest = other.dest;
        num_pilots = other.num_pilots;

        // deleting exisitng memory
		if (pilots != nullptr)
		{
			delete[] pilots;
		}

        //  new memory for pilots and copy content
        if (other.pilots != nullptr) 
		{
            pilots = new string[num_pilots];
            for (int i = 0; i < num_pilots; ++i)
			{
                pilots[i] = other.pilots[i];
            }
        } 
    }

	// returning dereferenced pointer
    return *this;
}

void Flight::populate_flight(ifstream& fin, Flight* f_arr, int a) 
{
	// populating f_arr array from txt file
	fin >> flight_num;
	fin >> curr_loc;
	fin >> dest;

	fin >> num_pilots;
	set_num_pilots(num_pilots);

	// setting pilots array to be size num_pilots
	pilots = new string[get_num_pilots()];

	// looping for num_pilots to get pilot name info
	for (int b = 0; b < get_num_pilots(); b++)
	{
		fin >> pilots[b];
	}

	return;
}

void Flight::print_one_flight()
{
	// Printing only one flight at specified index
	cout << "----------------------" << endl;
	cout << "Flight #: " << this->flight_num << endl;
	cout << "Current at: " << this->curr_loc << endl;
	cout << "Destination: " << this->dest << endl;

	for (int b = 0; b < get_num_pilots(); b++)
	{
		cout << "Pilot " << b+1 << ": " << pilots[b] << endl;
	}
	cout << "----------------------" << endl;	
}

void Flight::print_flight(int a) 
{
	// Printing only one flight at specified index
	cout << endl;
	cout << "Flight " << a+1 << ":" << endl;
	cout << "----------------------" << endl;
	cout << "Flight #: " << this->flight_num << endl;
	cout << "Current at: " << this->curr_loc << endl;
	cout << "Destination: " << this->dest << endl;

	for (int b = 0; b < get_num_pilots(); b++)
	{
		cout << "Pilot " << b+1 << ": " << pilots[b] << endl;
	}
	cout << "----------------------" << endl;

	return;
}

void Flight::set_user_pilots(int num_pilots)
{
	string pilot_name = "";
	pilots = new string[num_pilots];

	// looping for num_pilots of times to get pilots info from user
	for (int i = 0; i < num_pilots; i++)
	{
		cout << "Enter name for pilot " << i+1 << ": ";
		cin >> pilot_name;
		pilots[i] = pilot_name;
	}
}

void Flight::write_flight(ofstream& fout)
{
	// writing to file using f_arr array elements
	fout << this->flight_num << " " << this->curr_loc << " " << this->dest << " " << this->num_pilots << " ";
	// forgot num flights
	for (int b = 0; b < get_num_pilots(); b++)
	{
		fout << pilots[b] << " ";
	}
	fout << endl;
}

// ----------------------------Accessors------------------------------

string Flight::get_flight_num() const
{
	return flight_num;
}
string Flight::get_curr_loc() const
{
	return curr_loc;
}
string Flight::get_dest() const
{
	return dest;
}
int Flight::get_num_pilots() const
{
	return num_pilots;
}
string* Flight::get_pilots() const
{
	return pilots;
}

// ----------------------------Mutators------------------------------

void Flight::set_flight_num(const string newflight_num)
{
	flight_num = newflight_num;
}
void Flight::set_curr_loc(const string newcurr_loc)
{
	curr_loc = newcurr_loc;
}
void Flight::set_dest(const string newdest)
{
	dest = newdest;
}
void Flight::set_num_pilots(const int newnum_pilots)
{
	num_pilots = newnum_pilots;
}
void Flight::set_pilots(const string*& newpilots)
{
	newpilots = pilots;
}