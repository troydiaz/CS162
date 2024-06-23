#ifndef MANAGER_H
#define MANAGER_H 

#include <iostream>
#include <fstream>
#include <string>

#include "airport.h"

using namespace std;

class Airport;

class Manager
{
private:

	int num_airports;	//number of airports
	Airport* a_arr;		//airport array

public:

    /********************************************************************* 
    ** Function: Manager
    ** Description: Constructor, initializes class member values when called
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: none
    *********************************************************************/
    Manager();

    /********************************************************************* 
    ** Function: ~Manager
    ** Description: Destructor, frees dynamic memory when a_arr is out of scope.
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: none
    *********************************************************************/
    ~Manager();

    /********************************************************************* 
    ** Function: populate
    ** Description: Fills the elements of the airport array a_arr by reading the 
	contents of the file and using a for loop to populate each airport element.
    ** Parameters: ifstream& fin - referenced object to reading file
    ** Pre-Conditions: A file is opened
    ** Post-Conditions: A file is closed
    *********************************************************************/
    void populate(ifstream& fin);

    /********************************************************************* 
    ** Function: init
    ** Description: Opens airport.txt for reading to a file. Passes object
	fin to Manager::populate(); 
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: none
    *********************************************************************/
    int init();

    /********************************************************************* 
    ** Function: print_menu
    ** Description: Displays menu options, from 1-7
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: none
    *********************************************************************/
    void print_menu();

    /********************************************************************* 
    ** Function: get_menu_choice
    ** Description: Takes in user input for menu choice
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: none
    *********************************************************************/
    int get_menu_choice();

    /********************************************************************* 
    ** Function: display_airports
    ** Description: Displays airport choices A, B, and C.
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: none
    *********************************************************************/
    void display_airports();

    /********************************************************************* 
    ** Function: airport_choice
    ** Description: Takes in user input for airport choice, valid input only between
	1-3.
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: none
    *********************************************************************/
    int airport_choice();

    /********************************************************************* 
    ** Function: check_flight_availabiliy
    ** Description: Looks through each element in a_arr, calls look_for_avaiability func
	that returns either true or false if airport is "available" for taking in more flights.
    ** Parameters: int choice - passes by value, bool& check - referenced to bool to make changes
	to check
    ** Pre-Conditions: a_arr array is populated, set_num_airports()
    ** Post-Conditions: returns check boolean value
    *********************************************************************/
    bool check_flight_availabiliy(int choice, bool& check);

    /********************************************************************* 
    ** Function: print_airport_flights
    ** Description: Prints airport of users choice and only that information
	of req airport.
    ** Parameters: string choice - passing in value of user choice
    ** Pre-Conditions: user inputs choice
    ** Post-Conditions: prints out selected airport information
    *********************************************************************/
    void print_airport_flights(string choice);

    /********************************************************************* 
    ** Function: write_to_file
    ** Description: Based on a_arr elements, will write using that information
	to airport.txt file. 
    ** Parameters: none
    ** Pre-Conditions: Opens airport.txt file
    ** Post-Conditions: Closes file after writing competely.
    *********************************************************************/
    void write_to_file();

    /********************************************************************* 
    ** Function: print_all
    ** Description: 1st user choice, prints all airports and all their information.
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: Prints all airports and all their info.
    *********************************************************************/
    void print_all();

    /********************************************************************* 
    ** Function: check_flight_control
    ** Description: 2nd user choice, prints requested flight from airport
    ** Parameters: none
    ** Pre-Conditions: Checks if user choice is within a_arr
    ** Post-Conditions: Breaks out of for loop if flight not found, continues
	until end of for loop and returns.
    *********************************************************************/
    void check_flight_control();

    /********************************************************************* 
    ** Function: add_flight_control
    ** Description: 3rd user choice, adds flight to f_arr by creating a Flight object
	f to pass into add_a_flight.
    ** Parameters: none
    ** Pre-Conditions: Values of dest, curr_loc, and pilots must be within bounds
    ** Post-Conditions: Passes f object to add_a_flight, adding one to the f_arr array
	and calling write_to_file to update airport.txt file.
    *********************************************************************/
    void add_flight_control();

    /********************************************************************* 
    ** Function: cancel_flight_control
    ** Description: 4th user choice, removes a flight from f_arr by decrementing 
	num_flights by 1 and returning that f_arr array. 
    ** Parameters: none
    ** Pre-Conditions: Value of choice must be in bounds
    ** Post-Conditions: Passes a_arr index, then at that element removes a flight from
	f_arr array. Writes to file to update airport.txt file.
    *********************************************************************/
    void cancel_flight_control();

    /********************************************************************* 
    ** Function: take_off_control
    ** Description: 5th user choice, updates flights information by setting
	curr_loc to dest.
    ** Parameters: none
    ** Pre-Conditions: Value of choice must be in bounds.
    ** Post-Conditions: Passes flight_choice into change_a_flight func, updates
	flight information by setting curr_loc to dest. Writes to file to update airport.txt
	file.
    *********************************************************************/
    void take_off_control();

    /********************************************************************* 
    ** Function: stats_control
    ** Description: Prints out Airports information.
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: Prints out the airports name, cap, and listed dest (num of flights).
    *********************************************************************/
    void stats_control();

    /********************************************************************* 
    ** Function: run
    ** Description: "Starts" the program. Takes in user input from 1-7, 1-6 being menu
	options and 7 being quit option.
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: Based on user input, can operate print_all, check_flight_control,
	add_flight_control, cancel_flight_control, take_off_control, stats_control, and quit.
    *********************************************************************/
    void run();

    // ----------------------------Accessors------------------------------

    /********************************************************************* 
    ** Function: get_num_airports
    ** Description: Gets value of num_airports from Manager Class.
    ** Parameters: none
    ** Pre-Conditions: Initialized to be 0 at start of program.
    ** Post-Conditions: none
    *********************************************************************/
    int get_num_airports() const;

    /********************************************************************* 
    ** Function: get_a_arr
    ** Description: Gets value of a_arr from Manager Class
    ** Parameters: none
    ** Pre-Conditions: Initialized to be null at start of program
    ** Post-Conditions: none
    *********************************************************************/
    Airport* get_a_arr() const;

    // ----------------------------Mutators------------------------------

    /********************************************************************* 
    ** Function: set_num_airports
    ** Description: Sets value of num_airports by taking in new value.
    ** Parameters: const int newnum_airports - unmodified const int var
    ** Pre-Conditions: none
    ** Post-Conditions: Sets num_airports equal to value passed in.
    *********************************************************************/
    void set_num_airports(const int newnum_airports);

    /********************************************************************* 
    ** Function: set_a_arr
    ** Description: Sets value of a_arr by taking in new value.
    ** Parameters: const Airport* new_a_arr - unmodified const Airport object var
    ** Pre-Conditions: none
    ** Post-Conditions: Sets a_arr equal to value passed in.
    *********************************************************************/
    void set_a_arr(const Airport* new_a_arr);

};
#endif