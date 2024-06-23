#include "catalog.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    int age = -1; 
    int OptionsChoice = 1;
    int NumberOfPlaylists = 0;

    // Creating object "fin" and setting it to perform input operations on files
    ifstream fin;

    // Getting file name from user and storing it into fileName
    string fileName = GetFileName(fin);

    // Getting user age and storing it into age
    age = GetUserAge();

    // Reading first line of fileName, indicating the number of playlists in txt file
    fin >> NumberOfPlaylists;

    // Storing a dynamic array with the size of NumberOfPlaylists into p_arr, which is a 
    // pointer to an array of playlists.
    Playlist *p_arr = create_playlists(NumberOfPlaylists);

    // Looping through each playlist in p_arr.
    for (int i = 0; i < NumberOfPlaylists; i++)
    {
        // Storing name and num_song in playlist struct for each element of p_arr.
        // Accessing song struct and populating information for each song.
        populate_one_list(p_arr, i, fin);
    }

    // Loops until user exits with 5.
    while (OptionsChoice >= 1 && OptionsChoice <= 5)
    {
        // Storing user choice into OptionsChoice.
        OptionsChoice = DisplayOptions();

        // Based on OptionsChoice, pass prev. defined variables into OptionstoChoose
        OptionstoChoose(OptionsChoice, age, p_arr, NumberOfPlaylists);

        // Error checking if user has bad inputs.
        if (OptionsChoice < 1 || OptionsChoice > 5)
        {
            cout << "Invalid." << endl;
        }

        if (OptionsChoice == 5)
        {
            break;
        }
    }

    // Freeing memory on heap before program ends so no memory leaks occur.
    delete_info(p_arr, NumberOfPlaylists);

    return 0;
}

