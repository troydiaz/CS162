#include "manager.h"
#include <iostream>
#include <string>

using namespace std;

// Constructor

Manager::Manager()
{
	num_airports = 0;
	a_arr = nullptr;
}

// Destructor

Manager::~Manager() 
{
	if (a_arr != nullptr)
	{
		delete[] a_arr;
	}
}

void Manager::populate(ifstream& fin) 
{
	// Reading first line of airport.txt file
	fin >> num_airports;
	set_num_airports(num_airports);

	// Setting a_arr as an Airport array of size num_airports
	a_arr = new Airport[num_airports];

	// Looping for num_airports to populate each element with flight info
	for (int i = 0; i < get_num_airports(); i++)
	{
		a_arr[i].populate_airport(fin, a_arr, i);
	}

	return; 
}

void Manager::write_to_file()
{
	// Opening airport.txt for writing
	ofstream fout;
	fout.open("airport.txt");

	// Looping for num_airports to write elements to file
	fout << get_num_airports() << endl;
	for (int i = 0; i < get_num_airports(); i++)
	{
		a_arr[i].write_airport(fout);
	}

	// Closing file after loops ends
	fout.close();
}

int Manager::init()
{
	// Opening airport.txt for reading
	ifstream fin("airport.txt"); 
	if (fin.is_open())
	{
		cout << endl;
		cout << "File opened." << endl;
	}
	else
	{
		cout << endl;
		cout << "File was not opened." << endl;
		// return 0 to end program
		return 0;
	}	

	// Calling populate function to fill in elements of a_arr
	Manager::populate(fin);

	// return 1 to continue program
	return 1;
}



void Manager::print_menu()
{
	// Printing out menu options
	cout << endl;
	cout << "1. View all Airports & Flights info" << endl;
	cout << "2. Check flight info" << endl;
	cout << "3. Add a new flight" << endl;
	cout << "4. Cancel a flight" << endl;
	cout << "5. Take off a flight" << endl;
	cout << "6. Print airport stats" << endl;
	cout << "7. Quit" << endl;

	cout << "Your choice: ";
}

int Manager::get_menu_choice() 
{
	int choice = 0;

	// Getting menu choice from user
	Manager::print_menu();
	cin >> choice;

	return choice;
}

void Manager::print_all()
{
	// Looping for num_airports and printing all airport info
	cout << endl;
	cout << "**********************************" << endl;
	for (int i = 0; i < get_num_airports(); i++)
	{
		a_arr[i].print_airport();
	}
	cout << "**********************************" << endl;
	cout << endl;

	return;
}

void Manager::check_flight_control() 
{
	string flight_num = "";
	bool check = false;

	cout << "Enter the flight number: ";
	cin >> flight_num;

	// Printing flight at specified flight_num, looping for num_airports times through a_arr array
	for (int i = 0; i < get_num_airports(); i++)
	{
		check = a_arr[i].look_for_airport(flight_num);
		if (check == false)
		{
			cout << endl;
			cout << "The flight entered wasn't found." << endl;
			break;
		}
		else 
		{
			continue;
		}
	}

	return; 
}

void Manager::display_airports()
{
	// Displaying available airports
	cout << endl;
	cout << "1: Airport A" << endl;
	cout << "2: Airport B" << endl;
	cout << "3: Airport C" << endl;
	cout << "Your choice: ";
}

int Manager::airport_choice()
{
	int choice = 0;

	// Choice bounds between 1-3
	while (choice < 1 || choice > 3)
	{
		cin >> choice;
		if (choice < 1 || choice > 3)
		{
			cout << "Please enter a number between 1-3: ";
		}
	}

	return choice;
}

bool Manager::check_flight_availabiliy(int choice, bool& check)
{
	// Checking if each airport has a num_flight either less than or equal to 4
	for (int i = 0; i < get_num_airports(); i++)
	{	
		// returing boolean value if airport is free
		check = a_arr[i].look_for_availability(choice);
		if (check == 0)
		{
			continue;
		}
		else
		{
			break;
		}
	}
	return check;
}

void Manager::add_flight_control() 
{
	int choice, pilots = -1;
	bool check = false;
	string x, dest, pilot_name, flight_number, curr_loc = "";
	Flight f;

	// displays airports to choose from
	cout << "Please enter a number between 1-3." << endl;
	Manager::display_airports();

	// getting airport choice from user
	choice = Manager::airport_choice();
	
	// checking if airport has any available spots
	check = Manager::check_flight_availabiliy(choice, check);

	if (check == 1)
	{
		cout << endl;
		cout << "Proceed with adding flight." << endl;
	}
	if (check == 0)
	{
		return;
	}

	// prompting user for flight information
    cout << "Enter the flight number: ";
    cin >> flight_number;
	f.set_flight_num(flight_number);

	cout << "Enter destination: ";
	while (dest != "A" && dest != "B" && dest != "C")
	{
		cin >> dest;
		if (dest != "A" && dest != "B" && dest != "C")
		{
			cout << "Please enter either 'A' 'B' or 'C': ";
		}
	}
	f.set_dest(dest);

	cout << "Enter current location: ";
	while (curr_loc != "A" && curr_loc != "B" && curr_loc != "C")
	{
		cin >> curr_loc;
		if (curr_loc != "A" && curr_loc != "B" && curr_loc != "C")
		{
			cout << "Please enter either 'A' 'B' or 'C': ";
		}
	}
	f.set_curr_loc(curr_loc);

	cout << "Number of pilots: ";
	while (pilots < 1)
	{
		cin >> pilots;
		if (pilots < 1)
		{
			cout << "Please enter a number greater than 0: ";
		}
	}
	f.set_num_pilots(pilots);

	//string* flightname_array = new string[pilots];

	f.set_user_pilots(pilots);
	
	// Finding user selected airport at this index
	Airport& a = a_arr[choice - 1];

	// Pass f objects into add a flight f
	a.add_a_flight(f);

	// after getting information from user, write over file
	Manager::write_to_file();

	return; 
}

void Manager::print_airport_flights(string choice)
{
	// Printing out one airport info based on user choice
	cout << endl;
	cout << "**********************************" << endl;
	for (int i = 0; i < get_num_airports(); i++)
	{
		a_arr[i].print_single_airport(choice);
	}
	cout << "**********************************" << endl;
	cout << endl;
}

void Manager::cancel_flight_control() 
{
	string choice = ""; 
	int flight_choice, airportIndex, flight_limit = 0;
	bool check = false;

	cout << "Please enter a letter: A, B, or C" << endl;
	display_airports();
	while (choice != "A" && choice != "B" && choice != "C")
	{
		cin >> choice;
		if (choice != "A" && choice != "B" && choice != "C")
		{
			cout << "Please enter either 'A' 'B' or 'C': ";
		}
	}
	
	print_airport_flights(choice); 

	// Converting user input of string to specified a_arr index for airport name
    for (int i = 0; i < get_num_airports(); ++i) 
	{
        if (a_arr[i].get_name() == choice) 
		{
            airportIndex = i;
			flight_limit = a_arr[i].airport_flight_number();
            break;
        }
    }

	cout << "Choose a flight: ";
	while (flight_choice <= 0 || flight_choice > flight_limit)
	{
		cin >> flight_choice;
		if (flight_choice <= 0 || flight_choice > flight_limit)
		{
			cout << "Please enter a number between 0 and " << flight_limit << ": ";
		}
	}

	Manager::check_flight_availabiliy(flight_choice, check);

	// Removes a flight based on flight_choice. Passing in a_arr info at specified index
	a_arr[airportIndex].remove_a_flight(flight_choice - 1);

	// after getting information from user, write over file
	Manager::write_to_file();

	return;
}

void Manager::take_off_control() 
{
	string choice = "";
	int flight_choice, airportIndex, flight_limit = 0;

	cout << "Please enter a letter: A, B, or C" << endl;
	display_airports();

	cin >> choice;
	while (choice != "A" && choice != "B" && choice != "C")
	{
		cin >> choice;
		if (choice != "A" && choice != "B" && choice != "C")
		{
			cout << "Please enter either 'A' 'B' or 'C': ";
		}
	}

	print_airport_flights(choice);

    for (int i = 0; i < get_num_airports(); ++i) 
	{
        if (a_arr[i].get_name() == choice) 
		{
            airportIndex = i;
			flight_limit = a_arr[i].airport_flight_number();
            break;
        }
    }

	cout << "Choose a flight: ";
	while (flight_choice <= 0 || flight_choice > flight_limit)
	{
		cin >> flight_choice;
		if (flight_choice <= 0 || flight_choice > flight_limit)
		{
			cout << "Please enter a number between 0 and " << flight_limit << ": ";
		}
	}

	cout << "Flight " << flight_choice << " has taken off." << endl;
	cout << endl;
	
	// Changing curr_loc to dest
	a_arr[airportIndex].change_a_flight(flight_choice - 1);

	// after getting information from user, write over file
	Manager::write_to_file();
	
	return; 
}

void Manager::stats_control() 
{
	for (int i = 0; i < get_num_airports(); i++)
	{
		//Prints only airport info
		a_arr[i].print_airport_only();
	}

	return; 
}

void Manager::run() 
{
	cout << endl;
	cout << "Welcome to Flight Manager!!" << endl;
	if (Manager::init() != 1)
		return;

	int choice = -1;
	while (choice != 7)
	{
		choice = Manager::get_menu_choice();

		//print all
		if (choice == 1) 
			Manager::print_all();

		//flight info
		else if (choice == 2){
			Manager::check_flight_control();
		}
		//add a new flight
		else if (choice == 3) {
			Manager::add_flight_control();
		}
		//cancel a flight
		else if (choice == 4) {
			Manager::cancel_flight_control();
		}
		//take off a flight
		if (choice == 5){
			Manager::take_off_control();
		} 
		//airport stats
		else if (choice == 6) {
			Manager::stats_control();
		}
	}

	cout << "Bye!" << endl << endl;

	return;
}

// ----------------------------Accessors------------------------------

int Manager::get_num_airports() const
{
	return num_airports;
}
Airport* Manager::get_a_arr() const
{
	return a_arr;
}

// ----------------------------Mutators------------------------------

void Manager::set_num_airports(const int newnum_airports)
{
	num_airports = newnum_airports;
}
void Manager::set_a_arr(const Airport* new_a_arr)
{
	new_a_arr = a_arr;
}