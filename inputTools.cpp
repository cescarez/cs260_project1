//Christabel Escarez
//CS260 - Spring 2019
//Project #1 - inputTools.cpp
//Sources: CS162 addressBookE example program
//implementation file for standard input tools

#include "inputTools.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

char checkInput (char &response) {
	int responseCount = 0;
	//check for valid input, reobtain user input
	while (response != 'n' && response != 'y') {
		//check for valid char input 
		while (!response) {
			//clear error from input stream
			cin.clear();
			//ignore the rest of the input that triggered the istream error
			cin.ignore(100, '\n');
			cout << "Invalid input. Please respond with either 'y' or 'n': " << endl;
			//case insensitive response
			response = tolower(response);	
		}
		//check for 'y' or 'n' response, with up to three attempts for valid input
		if(responseCount < MAX_RESPONSE) {
			cout << "Invalid input. Please respond with either 'y' or 'n': " << endl;
			cin >> response;
			response = tolower(response);	
			responseCount++;
		} else {
			//exit program when invalid inputs > MAX_RESPONSE
			cout << "Error. Too many invalid inputs. Exiting MusicBox." << endl;
			exit(1);
		}
	}
	//ignore the newline from user input
	cin.ignore (100, '\n');
	//return char to calling environment
	return response;
}


int checkInput(int &response, const int &maxThreshold) {
	int responseCount = 0;
	//check for valid input, reobtain user input
	while (!response || response < 0 || response > maxThreshold) {
		//check for non-integer inputs
		while (!response) {
			//clear error from input stream
			cin.clear();
			//ignore the rest of the input that triggered the istream error
			cin.ignore(100, '\n');
			cout << "Invalid input. Please enter a number between 0 and " << maxThreshold
				 << ": " << endl;
			cin >> response;
		}
		//check for integer is a positive real number and below the maxThreshold parameter,
		//with up to three attempts for valid input
		if(responseCount < MAX_RESPONSE) {
			cout << "Invalid input. Please enter a number between 0 and " << maxThreshold
				 << ": " << endl;
			cin >> response;
			responseCount++;
		} else {
			//exit program when invalid inputs > MAX_RESPONSE
			cout << "Error. Too many invalid inputs. Exiting MusicBox." << endl;
			exit(1);
		}
	}
	//ignore the newline from user input
	cin.ignore (100, '\n');
	//return int to calling environment
	return response;
}

bool checkCString(char response[]) {
	int responseCount = 0;
	//check for valid input stream
	while (!response) {
		//clear error from input stream
		cin.clear();
		//ignore the rest of the input that triggered the istream error
		cin.ignore(100, '\n');
		//re-obtain response from user, with up to three attempts for valid input
		if(responseCount < MAX_RESPONSE){
			cout << "Invalid input. Please re-enter response: " << endl;
			cin >> response;
			responseCount++;
		} else {
			//exit program when invalid inputs > MAX_RESPONSE
			cout << "Error. Too many invalid inputs. Exiting MusicBox." << endl;
			exit(1);
		}
	}	
	//ignore the newline from user input
	cin.ignore (100, '\n');
	//return bool to calling environment
	if (!response) 
		return false;
	else
		return true;
}


int readInt(const char prompt[],  const int &maxThreshold)
{
	int	response;
	int responseCount;

	//prompt user for input
	cout << endl << prompt;
	cin >> response;

	//check if a valid integer is entered
	response = checkInput(response, maxThreshold);
	//return int to calling environment 
	return response;
}

void readString (const char prompt[], char response[])
{
	cout << endl << prompt;

	cin.get(response, MAX_SIZE, '\n');
	if(!checkCString(response)) {
		cout << "Error. Input failure. Exiting MusicBox." << endl;
	}
	//no value returned in this function; function modifies parameter, 
	//char response[], in calling environment

}



