/******************************************************
** Program: catalog.cpp
** Author: Troy Diaz
** Date: 2/11/2024
** Description: Program that reads from a songs playlist file. Depending on user input, the program 
can 1) Display all songs, 2) Search for a song and either display or append to a file, 3) Search
for a genre of songs and either display or append to a file, 4) Display the total length of all
songs, and 5) Quit the program.
** Input: Getting file name, user age, menu options, song name, genre name, print to screen, print
to file, quit program.
** Output: Information of a single song, Information of a genre of songs, Appending information to 
file, invalid inputs, writing to file.
******************************************************/
#include "catalog.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib> 

using namespace std;

//function definitions go here

// ----------- Additional function definitions -----------

string GetFileName(ifstream &fin)
{
    string FileName;

    cout << "Enter the playlist info file name: ";
    cin >> FileName;

    // Opening fileName, then proceeding to check if it is open and if it exists
    fin.open(FileName);
    if (fin.is_open())
    {
        cout << "Opening File: " << FileName << endl;
    }
    else
    {
        cout << "This file doesn't exist." << endl;

        // Using exit() since no dynamic memory has been created yet.
        exit(0);
    }

    return FileName;
}

int GetUserAge()
{
    int age = -1;

    while (age < 1 || age > 122)
    {
        cout << "Enter your age: ";
        cin >> age;

        // User cannot be less than 1 yr old or older than 122 yrs.
        if (age < 1 || age > 122)
            cout << "Invalid input, try again." << endl;
    }
    
    cout << endl;

    return age;
}

int DisplayOptions()
{
    int OptionsChoice = -1;
    string NameOfSong;

    // Prompt user to choose an option until a valid option is chosen.
    cout << "Which option would you like to choose?" << endl;
    cout << "1. Display all songs (1)" << endl;
    cout << "2. Search for a song to play (2)" << endl;
    cout << "3. Search Songs by Genre (3)" << endl;
    cout << "4. Display length of all playlists (4)" << endl;
    cout << "5. Quit (5)" << endl;
    cout << "Your choice: ";

    cin >> OptionsChoice;
    cout << endl;

    return OptionsChoice;
}

void OptionstoChoose(int OptionsChoice, int age, Playlist *p_arr, int NumberOfPlaylists)
{
    // Passing in these values into functions below.
    // Reinitializing tempchoice to be 0, user might want to choose again Option2 or Option3.
    int tempchoice = 0;

    string NameOfSong;
    string filename;
 
    if (OptionsChoice == 1)
    {
        // Prints all available songs in txt file.
        Option1(age, p_arr, NumberOfPlaylists); 
    }
    else if (OptionsChoice == 2) 
    {
        // Searches and either displays to screen/appends req. song to req. file.
        Option2(tempchoice, NameOfSong, age, p_arr, NumberOfPlaylists);
    }
    else if (OptionsChoice == 3) 
    {
        // Searches songs by genre and either displays to screen/appends req. song to req. file.
        Option3(tempchoice, NumberOfPlaylists, p_arr, age);
    }
    else if (OptionsChoice == 4) 
    {
        // Prints out length of all playlists in mins.
        Option4(NumberOfPlaylists, p_arr, age);
    }
    else if (OptionsChoice == 5)
    {
        // Exits program.
        cout << "Bye!" << endl;
    }
}

void PrintToFile(int a, int b, int age, Playlist *p_arr, int NumberOfPlaylists, string filename)
{
    // Creating ofstream object 'f' for output operations of file.
    ofstream f;
    
    // Adding information to end of file if file previously exists.
    f.open(filename, ios::app);
    
    // At index b and a, write to filename the songs information.
    f << p_arr[b].s[a].name << " ";
    f << p_arr[b].s[a].artist << " ";
    f << p_arr[b].s[a].year_release << " ";
    f << p_arr[b].s[a].length << " ";
    f << p_arr[b].s[a].genre << " ";
    f << p_arr[b].s[a].res << " " << endl; 
    
    // Closing file after writing information.
    f.close();
}

void Option1(int age, Playlist *p_arr, int NumberOfPlaylists)
{
    // Searching through each playlist within p_arr. Looping for NumberOfPlaylists times.
    for (int b = 0; b < NumberOfPlaylists; b++)
    {
        cout << endl;
        cout << "----------------------------------" << endl;
        cout << "List name: " << p_arr[b].name << endl;
        
        // Through each playlist, loop for num_song times.
        for (int a = 0; a < p_arr[b].num_song; a++)
        {

            // If user age is less than or equal to 19 and song has "E" restriction, skip song.
            if (p_arr[b].s[a].res == "E" && age <= 19)
            {
                continue;
            }

            cout << "----------------------------------" << endl;

            // Accessing the playlist struct, then its member song s, then the information of a song. 
            cout << "Song name: " << p_arr[b].s[a].name << endl;
            cout << "Artist: " << p_arr[b].s[a].artist << endl;
            cout << "Year: " << p_arr[b].s[a].year_release << endl;
            cout << "Length: " << p_arr[b].s[a].length << endl;
            cout << "Genre: " << p_arr[b].s[a].genre << endl;
            cout << "Restriction: " << p_arr[b].s[a].res << endl; 
    
            cout << "----------------------------------" << endl;
        }
    }  
    
    cout << endl;
}

void Gettempchoice(int &tempchoice)
{
    while (tempchoice < 1 || tempchoice > 2) 
    {
        // Prompting user for how they would like the info displayed, stored into tempchoice.
        cout << "How would you like the information displayed? " << endl;
        cout << "1. Print to screen (1) " << endl;
        cout << "2. Print to file (2) " << endl;
        cout << "Your Choice: ";
        cin >> tempchoice;  
        
        // Error checking for bad user input, only accepting values 1 or 2.
        if (tempchoice < 1 || tempchoice > 2)
        {
            cout << "Invalid input." << endl;
        }
    }
}

string GetFileNameFromUser()
{
    string filename;
    cout << "Enter desired file name: ";
    cin >> filename;

    // Returning filename, doesn't need any specified format. Used for creating a file. 
    return filename;
}

void Option2(int &tempchoice, string &NameOfSong, int age, Playlist *p_arr, int NumberOfPlaylists)
{
    // Initializing songFound to be 0. If 0, at end of for loop, then song doesn't exist.
    int songFound = 0; 

    string filename;

    Gettempchoice(tempchoice);

    if (tempchoice == 2)
    {
        // Storing filename for creating file and appending info to that file.
        filename = GetFileNameFromUser();
    }

    // NameOfSong must be exactly how the song is listed in txt file.
    cout << "Enter the name of the song: ";
    cin >> NameOfSong; 
    
    // Searching through each playlist within p_arr. Looping for NumberOfPlaylists times.
    for (int b = 0; b < NumberOfPlaylists; b++)
    {
        // Through each playlist, loop for num_song times.
        for (int a = 0; a < p_arr[b].num_song; a++)
        {   
            
            // If user age is less than or equal to 19 and song has "E" restriction, skip song.
            if(p_arr[b].s[a].res == "E" && age <= 19 && p_arr[b].s[a].name == NameOfSong)
            {
                cout << endl;
                cout << "You don't have access to this song." << endl; 
                cout << endl;

                // Adding 1 so that if statement below doesn't print song not found.
                songFound = 1; 

                // Exits for loop.
                break;
            }
            
            // If name of song is within playlist.
            else if((p_arr[b].s[a].name == NameOfSong) && tempchoice == 1)
            {
                cout << endl;
                cout << "----------------------------------" << endl;
                cout << "Song name: " << p_arr[b].s[a].name << endl;
                cout << "Artist: " << p_arr[b].s[a].artist << endl;
                cout << "Year: " << p_arr[b].s[a].year_release << endl;
                cout << "Length: " << p_arr[b].s[a].length << endl;
                cout << "Genre: " << p_arr[b].s[a].genre << endl;
                cout << "Restriction: " << p_arr[b].s[a].res << endl;
                cout << "----------------------------------" << endl;
                cout << endl;

                songFound = 1;
            }

            // Appending information to filename if user chose to print to file.
            else if((p_arr[b].s[a].name == NameOfSong) && tempchoice == 2)
            {
                // If at this index a and b for nameofsong, pass those values into PrintToFile().
                PrintToFile(a, b, age, p_arr, NumberOfPlaylists, filename);
                
                cout << endl;
                cout << "Appended requested information to file." << endl;
                cout << endl;

                songFound = 1;
            }
        }
    } 

    // If no song exists.
    if (songFound == 0)
        {
            cout << endl;
            cout << "This song doesn't exist or was worded wrong." << endl; 
            cout << endl;
        }
}

void Option3(int &tempchoice, int NumberOfPlaylists, Playlist *p_arr, int age)
{   
    string Genre;
    string filename;

    // Initializing counter to be 0. Used for outputting error to User only one time.
    int counter = 0;

    Gettempchoice(tempchoice);
    
    if (tempchoice == 2)
    {
        // Storing filename for creating file and appending info to that file.
        filename = GetFileNameFromUser();
    }

    // Assuming genre name is correctly typed in from available genres in txt file.
    cout << "Enter the genre: ";
    cin >> Genre;

    // Searching through each playlist within p_arr. Looping for NumberOfPlaylists times.
    for (int b = 0; b < NumberOfPlaylists; b++)
    {

        // Through each playlist, loop for num_song times.
        for (int a = 0; a < p_arr[b].num_song; a++)
        {

            // If user age is less than or equal to 19 and song has "E" restriction, skip song.
            if (p_arr[b].s[a].res == "E" && age <= 19)
            {
                
                // Adding 1 to counter for each loop. Used for conditional below so that it only runs once.
                counter += 1;
                if (a <= (p_arr[b].num_song) && counter == 1)
                {
                    counter += 1;
                    cout << endl;
                    cout << "Based on your choice of genre, it might not exist or your age restricts you from viewing certain songs." << endl;
                    cout << endl;
                }
                
                // Continues for loop if conditional above is false.
                continue;
            }

            // If genre exists and user wants to print to screen.
            if ((p_arr[b].s[a].genre == Genre) && tempchoice == 1)
            {
                cout << endl;
                cout << "----------------------------------" << endl;
                cout << "Song name: " << p_arr[b].s[a].name << endl;
                cout << "Artist: " << p_arr[b].s[a].artist << endl;
                cout << "Year: " << p_arr[b].s[a].year_release << endl;
                cout << "Length: " << p_arr[b].s[a].length << endl;
                cout << "Genre: " << p_arr[b].s[a].genre << endl;
                cout << "Restriction: " << p_arr[b].s[a].res << endl; 
                cout << "----------------------------------" << endl;
                cout << endl;
            }

            // If genre exists and user wants to print to file.
            else if((p_arr[b].s[a].genre == Genre) && tempchoice == 2)
            {
                // If at this index a and b for genre, pass those values into PrintToFile().
                PrintToFile(a, b, age, p_arr, NumberOfPlaylists, filename);

                cout << endl;
                cout << "Appended requested information to file." << endl;
                cout << endl;
            }      
        }
    }
}

void Option4(int NumberOfPlaylists, Playlist *p_arr, int age)
{
    cout << endl;
    cout << "---Displaying length of all playlists---" << endl;

    // Initializing TotalLength to be float, since length is in decimals.
    float TotalLength = 0;
    
    // Searching through each playlist within p_arr. Looping for NumberOfPlaylists times.
    for (int b = 0; b < NumberOfPlaylists; b++)
    {

        // Through each playlist, loop for num_song times.
        for (int a = 0; a < p_arr[b].num_song; a++)
        {

            // Adding each element of length for total length.
            TotalLength += p_arr[b].s[a].length;
        }
    } 
    
    cout << "Total Length all songs in file: " << TotalLength << " minutes" << endl;

    cout << "----------------------------------------" << endl;

    cout << endl;
}

// ----------- Required function definitions ----------- 

Playlist* create_playlists(int size)
{
    /*
    Passed in value of NumberOfPlaylists to size, in which this statement means
    I've created a dynamic array, p_arr, with the size of NumberOfPlaylists. 
    The type is a pointer to the Playlist struct members.
    */

    Playlist* p_arr = new Playlist[size];

    // Return value of p_arr to store in var in main(). 
    return p_arr;
}

void populate_one_list(Playlist* p_arr, int i, ifstream &fin)
{

    // Reading second and third line in txt file, storing values into Playlist 
    // struct members name and num_song. 
    fin >> p_arr[i].name;
    fin >> p_arr[i].num_song;
    
    // Accessing member song s, which points to the Song struct members.
    // p_arr[i].s is a dynamic array with the size of p_arr[i].num_song. 
    p_arr[i].s = create_songs(p_arr[i].num_song);

    // Reading each line after 2nd fin statement above for num_song times.
    for (int a = 0; a < p_arr[i].num_song; a++)
    {
        // Reads through each element of each line for the songs information. 
        populate_one_song(p_arr[i].s, a, fin);
    }
} 

Song* create_songs(int size)
{

    // Creating a dynamic array, s_arr, with the size of p_arr[i].num_song.
    // The type is a pointer to the Song struct member variables.
    Song* s_arr = new Song[size];

    // Returning value to populate_one_list.
    return s_arr;
}

void populate_one_song(Song* s_arr, int a, ifstream &fin)
{
    // Reading each element of a line in the txt file and stores values into struct member variables.
    fin >> s_arr[a].name;
    fin >> s_arr[a].artist;
    fin >> s_arr[a].year_release;
    fin >> s_arr[a].length;
    fin >> s_arr[a].genre;
    fin >> s_arr[a].res;
}

void delete_info(Playlist* p_arr, int size)
{
    // Deleting memory on heap, first deleting each element in p_arr.
    for (int i = 0; i < size; i++)
    {
        delete [] p_arr[i].s;
    }

    // Then, deleting entire array.
    delete [] p_arr;
}
