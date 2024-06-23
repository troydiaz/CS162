#ifndef CATALOG_H
#define CATALOG_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// Required Struct Definitions

//a struct to hold info of a Playlist
struct Playlist {
	string name;        //name of the playlist, one word
	int num_song;       //number of songs in the playlist
	struct Song *s;     //an array that holds all songs in the playlist
	float total_len;    //total length of the playlist
};

//a struct to hold info of a Song
struct Song {
	string name;		//name of the song, one word
	string artist;		//name of the artist, one word
	int year_release;	//the year of release
	float length;		//length of the song
	string genre;		//genre of the song, one word
	string res;			//"E" or "none" for restriction level
};

// ----------- Required function definitions -----------

/**************************************************
 * Name: create_playlists()
 * Description: This function will dynamically allocate
				an array of playlists (of the requested size)
 * Parameters: int - size of the array
 * Pre-conditions: none
 * Post-conditions: a Playlist array of requested size is created and return
 ***********************************************/
Playlist* create_playlists(int);


/**************************************************
 * Name: populate_one_list()
 * Description: This function will fill a single playlist struct 
				with information that is read in from the file
 * Parameters:  Playlist* - pointer to the Playlist array
				int - index of the Playlist in the array to be filled 
				ifstream& - input file to get the Playlist information
 * Pre-conditions: Playlist array has been allocated; 
				 provided index is less than the array size
 * Post-conditions: a Playlist at provided index is populated
 ***********************************************/
void populate_one_list(Playlist*, int, ifstream &); 


/**************************************************
 * Name: create_songs()
 * Description: This function will dynamically allocate
				an array of songs (of the requested size)
 * Parameters: int - size of the array
 * Pre-conditions: none
 * Post-conditions: a Song array of requested size is created and return
 ***********************************************/
Song* create_songs(int);


/**************************************************
 * Name: populate_one_song()
 * Description: This function will fill a single song struct 
				with information that is read in from the file
 * Parameters:  Song* - pointer to the Song array
				int - index of the Song in the array to be filled 
				ifstream& - input file to get the Song information
 * Pre-conditions: Song array has been allocated; 
				 provided index is less than the array size
 * Post-conditions: a Song at provided index is populated
 ***********************************************/
void populate_one_song(Song*, int, ifstream &); 


/**************************************************
 * Name: delete_info()
 * Description: This function will  delete all the memory that was dynamically allocated
 * Parameters: Playlist* - the Playlist array
 * Pre-conditions: the provided Playlist array hasn't been freed yet
 * Post-conditions: the Playlist array, with all Songs inside, is freed
 ***********************************************/
void delete_info(Playlist*, int);

// ----------- Additional function definitions -----------

/**************************************************
 * Name: GetFileName()
 * Description: Takes user input for file name. 
 * Parameters: 
 *    ifstream & fin - input file stream object that opens the file
 * Pre-conditions: That the file, songs_playlist.txt exists and
 *    the user correctly enters the name of that file. 
 * Post-conditions: File opens and checks if file is open. If yes,
 *    program continues and stores FileName in main(). If not, program ends.
 ***********************************************/
string GetFileName(ifstream &fin);

/**************************************************
 * Name: GetUserAge()
 * Description: Receives user age, only stores if it is between (1-122)
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: Returns value of age.
 ***********************************************/
int GetUserAge();

/**************************************************
 * Name: DisplayOptions()
 * Description: Displays menu options. Performs based on users input (1-5)
 *    and calls functions to perform those actions.
 *    1. - Displays all songs in songs_playlist.txt
 *    2. - Searches for a song in songs_playlist.txt, given the option to print to screen, or to 
 *         a file name.
 *    3. - Searches for a genre in songs_playlist.txt, given the option to print to screen, or to 
 *         a file name.
 *    4. - Displays length of all playlists in songs_playlist.txt in mins.
 *    5. - Quits program. 
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: Returns OptionsChoice. 
 ***********************************************/
int DisplayOptions(); 


/**************************************************
 * Name: OptionstoChoose
 * Description: Based on the value of OptionsChoice (1-5), program will call onto different functions
 *    representing the menu options in Displayoptions().
 *    Option1(), Option2(), Option3(), Option4().
 * Parameters:
 *    int OptionChoice - Users choice from DisplayOptions().
 *    int age - Users age.
 *    Playlist *p_arr - Pointer to array of playlist objects.
 *    int NumberOfPlaylists - The first value in songs_playlist.txt indicating how many playlists there are
 *    in the txt file.
 * Pre-conditions: Needs values of age to restrict songs from User if <= 19, the information of songs in a playlist
 *    in array p_arr, and the NumberOfPlaylists read from the first line in songs_playlists.txt.
 * Post-conditions: Based on the users choice (1-5), this will either call: Option1(), Option2(), Option3(), Option4().
 ***********************************************/
void OptionstoChoose(int OptionChoice, int age, Playlist *p_arr, int NumberOfPlaylists); 


/**************************************************
 * Name: PrintToFile()
 * Description: Creates an ofstream object to append information to the file. Accesses the playlist struct members
 *    song s, and accesses the songs struct members name, artist, year_release, length, genre, and res. Writes to filename,
 *    the user's choice of the name of filename, and closes once appending one song to the file. Can reopen the file if filename
 *    is the same.
 * Parameters:
 *    int a - Passing value of index a.
 *    int b - Passing value of index b.
 *    int age - Users age.
 *    Playlist *p_arr - Pointer to array of playlist objects.
 *    int NumberOfPlaylists - The first value in songs_playlist.txt indicating how many playlists there are
 *    in the txt file.
 *    string filename - The users choice of the desired file name to append song info to.
 * Pre-conditions: Needs values of a and b, where the specific index of the song is, the values in the array p_arr,
 *    and filename, the users choice of where to append the songs information to.
 * Post-conditions: Information of the song is appended to the file.
 ***********************************************/
void PrintToFile(int a, int b, int age, Playlist *p_arr, int NumberOfPlaylists, string filename);


/**************************************************
 * Name: Gettempchoice()
 * Description: Displays choice, either to 1. print to screen or 2. print to file. Doesn't accept any value 
 *    other than 1-2. Stores user choice into tempchoice.
 * Parameters:
 *    int &tempchoice - Reference to tempchoice, passing changes of values between functions with tempchoice.
 * Pre-conditions: None.
 * Post-conditions: Stores the value of tempchoice.
 ***********************************************/
void Gettempchoice(int &tempchoice);


/**************************************************
 * Name: GetFileNameFromUser()
 * Description: Asks user to enter desired file name. Not to be confused with previous function, GetFileName().
 *    This function is used to store and return filename if user chose 2 in Gettempchoice.
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions: Returns filename.
 ***********************************************/
string GetFileNameFromUser();


/**************************************************
 * Name: Option1()
 * Description: Prints out information of every song in songs_playlist.txt. Including their Playlist name, 
 *    name, artist, year_release, length, genre, and res. Loops for the number of playlists in a file, and loops for the number of 
 *    songs in a given playlist. Doesn't print out songs with E in res if age is <= 19.
 * Parameters: 
 *    int age - Users age.
 *    Playlist *p_arr - Pointer to array of playlist objects.
 *    int NumberOfPlaylists - The first value in songs_playlist.txt indicating how many playlists there are
 *    in the txt file.
 * Pre-conditions: Needs value of user age, the information of songs in a playlist
 *    in array p_arr, and the NumberOfPlaylists read from the first line in songs_playlists.txt.
 * Post-conditions: Prints out all songs from songs_playlist.txt. 
 ***********************************************/
void Option1(int age, Playlist *p_arr, int NumberOfPlaylists);


/**************************************************
 * Name: Option2()
 * Description: Assuming user correctly types in song name (if not then prints out song doesn't exist), the function will
 *    look through each song in the songs_playlist.txt. First, it calls Gettempchoice if user wants to print to screen or to file. If print to file, then call GetFileNameFromUser();.
 *    If printing to screen, the program will print out the requested song's information.
 *    If printing to file, then call PrintToFile(). Doesn't print out songs with E in res if age is <= 19.
 * Parameters: 
 *    int &tempchoice - Reference to tempchoice, users choice between printing to file or screen.
 *    string &NameOfSong - Name of file that user wants to open and append. 
 *    int age - Users age.
 *    Playlist *p_arr - Pointer to array of playlist objects.
 *    int NumberOfPlaylists - The first value in songs_playlist.txt indicating how many playlists there are
 *    in the txt file.
 * Pre-conditions: Needs value of user age, the information of songs in a playlist
 *    in array p_arr, and the NumberOfPlaylists read from the first line in songs_playlists.txt. 
 * Post-conditions: Either prints out songs information to screen or appends information to a given file name. 
 ***********************************************/
void Option2(int &tempchoice, string &NameOfSong, int age, Playlist *p_arr, int NumberOfPlaylists);

/**************************************************
 * Name: Option3()
 * Description: Assuming user correctly types in genre name, the function will look through each genre in the songs_playlist.txt.
 *    First calls Gettempchoice() if user wants to print to screen or to file. If print to file, then call GetFileNameFromUser() to get filename to 
 *    print to. Asks for genre name, and will either append all songs of selected genre to file or print to screen.
 *    Doesn't print out songs with E in res if age is <= 19.
 * Parameters:  
 *    int &tempchoice - Reference to tempchoice, users choice between printing to file or screen.
 *    int NumberOfPlaylists - The first value in songs_playlist.txt indicating how many playlists there are
 *    in the txt file.
 *    Playlist *p_arr - Pointer to array of playlist objects.
 *    int age - Users age.
 * Pre-conditions: Needs value of user age, the information of songs in a playlist
 *    in array p_arr, and the NumberOfPlaylists read from the first line in songs_playlists.txt. 
 * Post-conditions: Either prints out the information of songs of requested genre to screen or appends them to given
 *    file name.
 ***********************************************/
void Option3(int &tempchoice, int NumberOfPlaylists, Playlist *p_arr, int age);


/**************************************************
 * Name: Option4()
 * Description: Displays total length of all songs in songs_playlist.txt
 * Parameters: 
 *    int NumberOfPlaylists - The first value in songs_playlist.txt indicating how many playlists there are
 *    in the txt file.
 *    Playlist *p_arr - Pointer to array of playlist objects.
 *    int age - Users age.
 * Pre-conditions: Needs the information of songs in a playlist in array p_arr, the NumberOfPlaylists read from the first line
 *    in songs_playlists.txt.
 * Post-conditions: Prints out total length of playlists. 
 ***********************************************/
void Option4(int NumberOfPlaylists, Playlist *p_arr, int age);


#endif