#include "airport.h"
#include <iostream>
#include <string>

using namespace std;

// Constructor

Airport::Airport() 
{
    name = "";
    num_flights = 0;
    cap = 0;
    f_arr = nullptr;
}

// Destructor

Airport::~Airport() 
{
	if (f_arr != nullptr)
	{
		delete[] f_arr;
	}
}

void Airport::populate_airport(ifstream& fin, Airport* a_arr, int i)
{
    // Populating a_arr with txt file
    fin >> a_arr[i].name;
    set_name(a_arr[i].name);

    fin >> a_arr[i].num_flights;
    set_NumFlights(a_arr[i].num_flights);

    fin >> a_arr[i].cap;
    set_cap(a_arr[i].cap);

    // Setting f_arr to be size of cap instead of num_flights to allow for more flights in array
    f_arr = new Flight[get_cap()];

    // Looping for num_flights times to cover all flights
    for (int a = 0; a < get_NumFlights(); a++)
    {
        // Populating f_arr with flight info
        f_arr[a].populate_flight(fin, f_arr, a);
    }
	
	return; 
}

bool Airport::look_for_availability(int choice)
{
    // Checking each individual airport from user choice 
    if (choice == 1 && this->name == "A")
    {
        // if there is capacity, return true
        if (this->num_flights < 4) 
        {
            return true;
        }
        // else, tell user that flights cannot be added and return flase
        else
        {
            cout << endl;
            cout << "Cannot add more flights to this airport" << endl;
            return false;
        }
    }
    else if (choice == 2 && this->name == "B")
    {
        if (this->num_flights < 4) 
        {
            return true;
        }
        else
        {
            cout << endl;
            cout << "Cannot add more flights to this airport" << endl;
            return false;
        }
    }
    else if (choice == 3 && this->name == "C")
    {
        if (this->num_flights < 4)
        {
            return true;
        }
        else
        {
            cout << endl;
            cout << "Cannot add more flights to this airport." << endl;
            return false;
        }
    }
    else
    {
        // return false if bad input
        return false;
    }
}

int Airport::airport_flight_number()
{
    // returning num_flights at specified index
    return this->num_flights;
}

void Airport::add_a_flight(Flight& p)
{   
    if (num_flights < cap)
    {
        // Adding new flight at num_flights index in f_arr
        f_arr[num_flights] = p;

        // incrementing num_flights one
        num_flights++;
        
        cout << "Flight added." << endl;
    }
    else
    {
        cout << "Cannot add flight" << endl;
    }
	return; 
}

Flight Airport::remove_a_flight(int idx)
{
	Flight removeflight = f_arr[idx];

    // Shift flights to left after idx
    for (int i = idx + 1; i < num_flights; ++i) 
    {
        // copy flight array to prev index
        f_arr[i-1] = f_arr[i];
    }

    // decrement number of flights
    num_flights--;

    cout << "Flight removed." << endl;
    cout << endl;

    // Returning flight info
	return Flight();
}

Flight Airport::change_a_flight(int idx)
{
    // Setting destination to be equal to flights dest
    string destination = f_arr[idx].get_dest();

    // Set the current location to the destination
    f_arr[idx].set_curr_loc(destination);

    return Flight();
}

void Airport::print_airport() 
{
    // Printing airports info
	cout << "******Airport Name: " << this->name << "******" << endl;
    cout << "Capacity: " << this->cap << endl;
    
    // Printing all flights for num_flights times
    for (int a = 0; a < this->num_flights; a++)
    {
        f_arr[a].print_flight(a);
    }
	
	return; 
}

void Airport::print_single_airport(string choice)
{
    // Printing single airport and flight info in it
    if (choice == this->name)
    {
        cout << "******Airport Name: " << this->name << "******" << endl;
        cout << "Capacity: " << this->cap << endl;

        // Printing all flights for num_flights times
        for (int a = 0; a < this->num_flights; a++)
        {
            f_arr[a].print_flight(a);
        }
    }
    return;
}

void Airport::write_airport(ofstream& fout)
{
    // Writing to file with a_arr elements
    fout << this-> name << " " << this->num_flights << " " << this->cap << endl;
    
    // Writing all flights for num_flights times
    for (int a = 0; a < this->num_flights; a++)
    { 
        f_arr[a].write_flight(fout);
    }
}

void Airport::print_airport_only()
{
    // Printing airport info only
    cout << endl;
    cout << "Airport: " << this->name << endl;
    cout << "Capacity: " << this->cap << endl;
    cout << "Listed as destination: " << this->num_flights << endl;
    cout << endl;
}

bool Airport::look_for_airport(string flight_num)
{
    // Looping if flight_num exists, then printing flight at that index
    for (int a = 0; a < this-> num_flights; a++)
    {
        if (f_arr[a].get_flight_num() == flight_num)
        {
            cout << endl;
            cout << "Flight found!" << endl;
            f_arr[a].print_one_flight();
            return true;
        }
    }
}

// ----------------------------Accessors------------------------------

string Airport::get_name() const 
{
    return name;
}

int Airport::get_NumFlights() const 
{
    return num_flights;
}

int Airport::get_cap() const 
{
    return cap;
}

Flight* Airport::get_f_arr() const 
{
    return f_arr;
}

// ----------------------------Mutators------------------------------

void Airport::set_name(const string newname) 
{
    name = newname;
}

void Airport::set_NumFlights(const int newNumFlights) 
{
    num_flights = newNumFlights;
}

void Airport::set_cap(const int newcap) 
{
    cap = newcap;
}

void Airport::set_f_arr(const Flight* newf_arr) 
{
    newf_arr = f_arr; 
}


