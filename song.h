//Christabel Escarez
//CS260 - Spring 2019
//Project #1 - song.h
//header file for Song class

#ifndef SONG_H
#define SONG_H

#include "inputTools.h"

const int MAX_SIZE = 100;

class Song {	
public:
	//constructor
	Song();
	//destructor
	~Song();
	//copy constructor
	Song(const Song &otherSong);
	//overloaded assignment operator
	const Song& operator= (const Song& otherSong);
	//overloaded ostream operator
	friend ostream &operator<< (ostream &output, const Song &tempSong);
	//accessor functions
	//returns local variable (argument) equal to private instance data member
	void printSong(const Song &aSong) const {
		cout << aSong;	//function relies on overloaded extraction operator
	}
	void getTitle(char songTitle[]) const;
	void getLength(int &songLengthMin, int &songLengthSec) const;
	void getViews(int &songViews) const;
	void getLikes(int &songLikes) const;
	//mutator functions
	//sets local instance members to passed in values
	void setTitle(const char songTitle[]);
	void setLength(const int &songLengthMin, const int &songLengthSec);
	void setViews(const int &songViews);
	void setLikes(const int &songLikes);
private:
	char *songTitle;
	int songLengthMin;
	int songLengthSec;	
	int songViews;
	int songLikes;
};

#endif
