#ifndef FLIGHT_H
#define FLIGHT_H 

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Airport;

class Flight
{
private: 
	string flight_num;		//flight number
	string curr_loc;		//current airport
	string dest;			//destination 
	int num_pilots;			//number of pilots
	string* pilots;			//pilot array

public:

    /********************************************************************* 
    ** Function: Flight
    ** Description: Constructor, initializes class member values when called.
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: none
    *********************************************************************/
    Flight();

    /********************************************************************* 
    ** Function: ~Flight
    ** Description: Destructor, frees dynamic memory when f_arr is out of scope.
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: none
    *********************************************************************/
    ~Flight();

    /********************************************************************* 
    ** Function: Flight
    ** Description: Sets num pilots and pilots equal to new values
    ** Parameters: int size - passing in defined size
    ** Pre-Conditions: none
    ** Post-Conditions: none
    *********************************************************************/
    Flight(int size);

    /********************************************************************* 
    ** Function: operator=
    ** Description: Assignment Operator Overload, copies member variables and allocates new mem for pilots.
    ** Parameters: const Flight & - unmodified const Flight reference var
    ** Pre-Conditions: none
    ** Post-Conditions: Returns dereferenced pointer
    *********************************************************************/
    Flight& operator=(const Flight &);

    /********************************************************************* 
    ** Function: Flight
    ** Description: Copy Constructor, copies member variables and allocated new mem for pilots
    ** Parameters: const Flight & - unmodified const Flight reference var
    ** Pre-Conditions: none
    ** Post-Conditions: none
    *********************************************************************/
    Flight(const Flight &);

    /********************************************************************* 
    ** Function: populate_flight
    ** Description: Fills the elements of flight array f_arr by reading the contents of the
    file and using a for loop to populate each f_arr element.
    ** Parameters: ifstream& fin - referenced object to reading file, Flight* f_arr - pointer to Flight
    member variables, int a - passing in index from for loop
    ** Pre-Conditions: A file is opened
    ** Post-Conditions: A file is closed
    *********************************************************************/
    void populate_flight(ifstream& fin, Flight* f_arr, int a);

    /********************************************************************* 
    ** Function: print_flight
    ** Description: Prints flight at specific index
    ** Parameters: int a - passing in index from for loop
    ** Pre-Conditions: Needs specific index from for loop to print flight info,
    passing in object a_arr
    ** Post-Conditions: Prints flight info at specific index
    *********************************************************************/
    void print_flight(int a);

    /********************************************************************* 
    ** Function: print_one_flight
    ** Description: Prints exactly on flight info
    ** Parameters: none
    ** Pre-Conditions: eeds specific index from for loop to print flight info,
    passing in object a_arr
    ** Post-Conditions: Prints specified flight info
    *********************************************************************/
    void print_one_flight();

    /********************************************************************* 
    ** Function: write_flight
    ** Description: Based on f_arr elements and pilots elements, will write using that info
    to airport.txt file.
    ** Parameters: ofstream& fout - referenced object to writing to file.
    ** Pre-Conditions: airport.txt file is opened, and is writing from f_arr array elements
    ** Post-Conditions: Writes over file with new txt.
    *********************************************************************/
    void write_flight(ofstream& fout);

    // ----------------------------Accessors------------------------------

    /********************************************************************* 
    ** Function: get_flight_num
    ** Description: Gets value of flight_num from Flight Class
    ** Parameters: none
    ** Pre-Conditions: Initialized to be "" at start of program
    ** Post-Conditions: none
    *********************************************************************/
    string get_flight_num() const;

    /********************************************************************* 
    ** Function: get_curr_loc
    ** Description: Gets value of curr_loc from Flight Class
    ** Parameters: none
    ** Pre-Conditions: Initialized to be "" at start of program
    ** Post-Conditions: none
    *********************************************************************/
    string get_curr_loc() const;

    /********************************************************************* 
    ** Function: get_dest
    ** Description: Gets value of dest from Flight Class
    ** Parameters: none
    ** Pre-Conditions: Initialized to be "" at start of program
    ** Post-Conditions: none
    *********************************************************************/
    string get_dest() const;

    /********************************************************************* 
    ** Function: get_num_pilots
    ** Description: Gets value of num_pilots from Flight Class
    ** Parameters: none
    ** Pre-Conditions: Initialized to be 0 at start of program
    ** Post-Conditions: none
    *********************************************************************/
    int get_num_pilots() const;

    /********************************************************************* 
    ** Function: get_pilots
    ** Description: Gets value of pilots from Flight Class
    ** Parameters: none
    ** Pre-Conditions: Initialized to be null at start of program
    ** Post-Conditions: none
    *********************************************************************/
    string* get_pilots() const;

    // ----------------------------Mutators------------------------------

    /********************************************************************* 
    ** Function: set_flight_num
    ** Description: Sets value of curr_loc by taking in new value
    ** Parameters: const string newflight_num - unmodified const string var
    ** Pre-Conditions: none
    ** Post-Conditions: Sets flight_num equal to value passed in 
    *********************************************************************/
    void set_flight_num(const string newflight_num);

    /********************************************************************* 
    ** Function: set_curr_loc
    ** Description: Sets value of curr_loc by taking in new value
    ** Parameters: const string newcurr_loc - unmodified const string var
    ** Pre-Conditions: none
    ** Post-Conditions: Sets value of curr_loc equal to value passed in
    *********************************************************************/
    void set_curr_loc(const string newcurr_loc);

    /********************************************************************* 
    ** Function: set_dest
    ** Description: Sets value of dest by taking in new value
    ** Parameters: const string dest - unmodified const string var
    ** Pre-Conditions: none
    ** Post-Conditions: Sets value of dest equal to value passed in
    *********************************************************************/
    void set_dest(const string dest);

    /********************************************************************* 
    ** Function: set_num_pilots
    ** Description: Sets value of num_pilots by taking in new value 
    ** Parameters: const int newnum_pilots - unmodified const int var
    ** Pre-Conditions: none
    ** Post-Conditions: Sets value of num_pilots equal to value passed in
    *********************************************************************/
    void set_num_pilots(const int newnum_pilots);

    /********************************************************************* 
    ** Function: set_pilots
    ** Description: Sets value of pilots by taking in new value
    ** Parameters: const string*& newpilots - unmodified const string object referenced var
    ** Pre-Conditions: none
    ** Post-Conditions: Sets value of pilots equal to value passed in
    *********************************************************************/
    void set_pilots(const string*& newpilots);

    /********************************************************************* 
    ** Function: set_user_pilots
    ** Description: Sets value of user_pilots by taking in new value
    ** Parameters: int num_pilots - unmodified int var
    ** Pre-Conditions: none
    ** Post-Conditions: Sets user_pilots to value passed in
    *********************************************************************/
    void set_user_pilots(int num_pilots);
	
};

#endif
