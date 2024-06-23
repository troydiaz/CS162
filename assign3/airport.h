#ifndef AIRPORT_H
#define AIRPORT_H 

#include <iostream>
#include <string>
#include <fstream>

#include "flight.h"
#include "manager.h"

using namespace std;

class Manager;

class Airport
{
private:
	string name;		//airport name
	int num_flights;	//number of flights
	int cap;			//capacity
	Flight *f_arr;		//flight array

public:

    /********************************************************************* 
    ** Function: Airport
    ** Description: Constructor, initializes class member values when called.
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: none
    *********************************************************************/
    Airport();

    /********************************************************************* 
    ** Function: ~Airport
    ** Description: Destructor, frees dynamic memory when f_arr is out of scope.
    ** Parameters: none
    ** Pre-Conditions: none 
    ** Post-Conditions: none
    *********************************************************************/
    ~Airport();
    
    /********************************************************************* 
    ** Function: populate_airport
    ** Description: Fills the elements of the Airport array a_arr by reading hte contents
    of the file and using a for loop to populate each flight element.
    ** Parameters: ifstream& fin - referenced object to reading file, 
    Airport* a_arr - pointer to Airport member variables, int i - passing in index
    from for loop.
    ** Pre-Conditions: A file is opened
    ** Post-Conditions: A file is closed
    *********************************************************************/
    void populate_airport(ifstream& fin, Airport* a_arr, int i);

    /********************************************************************* 
    ** Function: add_a_flight
    ** Description: Passes in an object p that holds flight info into f_arr at num_flights
    index. Adds one to num_flights in airport.
    ** Parameters: Flight& p - referenced object that holds flight info.
    ** Pre-Conditions: num_flights < 4. 
    ** Post-Conditions: Adds a flight to f_arr.
    *********************************************************************/
    void add_a_flight(Flight& p);

    /********************************************************************* 
    ** Function: remove_a_flight
    ** Description: Removes a flight based on user choice, idx. Removing a specific 
    flight at f_arr[] and then using a for loop to set it equal to f_arr[i-1]. Then decrementing
    num_flights at specific airport by 1.
    ** Parameters: int idx - user input that is between 0 and num_flights
    ** Pre-Conditions: Needs user choice at idx index.
    ** Post-Conditions: Returns Flight() constructor
    *********************************************************************/
    Flight remove_a_flight(int idx);

    /********************************************************************* 
    ** Function: change_a_flight
    ** Description: Changes a flights current location to be its destination.
    ** Parameters: int idx - user input that is between 0 and num_flights
    ** Pre-Conditions: Needs user choice idx.
    ** Post-Conditions: Returns Flight() constructor with updated flight info at specific
    f_arr index.
    *********************************************************************/
    Flight change_a_flight(int idx);

    /********************************************************************* 
    ** Function: print_airport
    ** Description: Prints out each Airport Information and their Flight Information.
    ** Parameters: none
    ** Pre-Conditions: a_arr and f_arr are populated when program opens airport.txt file
    ** Post-Conditions: Prints out airport/flight info
    *********************************************************************/
    void print_airport();

    /********************************************************************* 
    ** Function: airport_flight_number
    ** Description: Returns num_flights at specific index.
    ** Parameters: none
    ** Pre-Conditions: Passing in a_arr array at specific index in for loop
    ** Post-Conditions: Returns flight_num
    *********************************************************************/
    int airport_flight_number();

    /********************************************************************* 
    ** Function: print_airport_only
    ** Description: Prints the airports information only and not the flight information.
    ** Parameters: none
    ** Pre-Conditions: Needs specific index in a_arr array to print out name, cap, and 
    num_flights
    ** Post-Conditions: Prints out airport info.
    *********************************************************************/
    void print_airport_only();

    /********************************************************************* 
    ** Function: print_single_airport
    ** Description: Prints out one airport of user choice and the flight info associated
    with airport.
    ** Parameters: string choice - user selected airport, A, B, or C
    ** Pre-Conditions: needs choice from user
    ** Post-Conditions: Prints out one airport and flight info
    *********************************************************************/
    void print_single_airport(string choice);

    /********************************************************************* 
    ** Function: look_for_airport
    ** Description: Looks for airport of user choice
    ** Parameters: string flight_num - user choice of flight_num
    ** Pre-Conditions: Needs flight_num from user
    ** Post-Conditions: Returns boolean value of true and prints Flight found! if found.
    *********************************************************************/
    bool look_for_airport(string flight_num);

    /********************************************************************* 
    ** Function: look_for_availability
    ** Description: Checks if num_flights in specified airport is full or not.
    ** Parameters: int choice - user choice of airports
    ** Pre-Conditions: Needs valid choice, A, B, or C
    ** Post-Conditions: returns true if flight_nums is less than 4, returns false
    if cannot add more flights to this airport.
    *********************************************************************/
    bool look_for_availability(int choice);

    /********************************************************************* 
    ** Function: write_airport
    ** Description: Based on a_arr elements, will write using that information to airport.txt
    file. 
    ** Parameters: ofstream& fout - referenced object value to writing to file
    ** Pre-Conditions: airport.txt file is opened, and is writing from a_arr array elements
    ** Post-Conditions: Writes over file with new txt.
    *********************************************************************/
    void write_airport(ofstream& fout);

    // ----------------------------Accessors------------------------------

    /********************************************************************* 
    ** Function: get_name
    ** Description: Gets value of name from Airport Class
    ** Parameters: none
    ** Pre-Conditions: Initialized to be "" at start of program.
    ** Post-Conditions: none
    *********************************************************************/
    string get_name() const;

    /********************************************************************* 
    ** Function: get_NumFlights
    ** Description: Gets value of NumFlights from Airport Class
    ** Parameters: none
    ** Pre-Conditions: Initialized to be 0 at start of program.
    ** Post-Conditions: none
    *********************************************************************/
    int get_NumFlights() const;

    /********************************************************************* 
    ** Function: get_cap
    ** Description: Gets value of cap from Airport Class
    ** Parameters: none
    ** Pre-Conditions: Initialized to be 0 at start of program.
    ** Post-Conditions: none
    *********************************************************************/
    int get_cap() const;

    /********************************************************************* 
    ** Function: get_f_arr
    ** Description: Gets value of f_arr from Airport Class
    ** Parameters: none
    ** Pre-Conditions: Initialized to be null at start of program
    ** Post-Conditions: none
    *********************************************************************/
    Flight* get_f_arr() const;

    // ----------------------------Mutators------------------------------

    /********************************************************************* 
    ** Function: set_name
    ** Description: Sets value of name by taking in new value
    ** Parameters: const string newname - unmodified const string var
    ** Pre-Conditions: none
    ** Post-Conditions: Sets name equal to value passed in
    *********************************************************************/
    void set_name(const string newname);

    /********************************************************************* 
    ** Function: set_NumFlights
    ** Description: Sets value of NumFlights by taking in new value
    ** Parameters: const int newNumFlights - unmodified const int var
    ** Pre-Conditions: none
    ** Post-Conditions: Sets NumFlights to value passed in
    *********************************************************************/
    void set_NumFlights(const int newNumFlights);

    /********************************************************************* 
    ** Function: set_cap
    ** Description: Sets value of cap by taking in new value
    ** Parameters: const int newcap - unmodified const int var
    ** Pre-Conditions: none
    ** Post-Conditions: Sets cap to value passed in
    *********************************************************************/
    void set_cap(const int newcap);

    /********************************************************************* 
    ** Function: set_f_arr
    ** Description: Sets value of f_arr by taking in new value
    ** Parameters: const Flight* newf_arr - unmodified const Flight object var
    ** Pre-Conditions: none
    ** Post-Conditions: Sets f_arr equal to value passed in
    *********************************************************************/
    void set_f_arr(const Flight* newf_arr);

};
#endif
