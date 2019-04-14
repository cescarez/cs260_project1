//Christabel Escarez
//CS260 - Spring 2019
//Project #1 - song.cpp
//implementation file for Song class

#include "song.h"
#include <cstring>
#include <iostream>

using namespace std;

/*CONSTRUCTOR*/
Song::Song() 
{
	songTitle = new char[strlen("unknown title")+1];
	strcpy(songTitle, "unknown title");
	songLengthMin = 0;
	songLengthSec = 0;	
	songViews = 0;
	songLikes = 0;

}

/*DESTRUCTOR*/
Song::~Song()
{
	if (songTitle != NULL) {
		delete [] songTitle;
	}
	songLengthMin = 0;
	songLengthSec = 0;	
	songViews = 0;
	songLikes = 0;
}

/*COPY CONSTRUCTOR*/
Song::Song(const Song &otherSong)
{
	this->songTitle = new char[strlen(otherSong.songTitle)+1];
	songTitle = otherSong.songTitle;
	songLengthMin = otherSong.songLengthMin;
	songLengthSec = otherSong.songLengthSec;
	songViews = otherSong.songViews;
	songLikes = otherSong.songLikes;
} 

/*OVERLOADED OPERATORS*/
const Song& Song::operator= (const Song& otherSong)
{
	//create temporary local variable to store private value retrieved via accessor function
	char tempTitle[MAX_SIZE];
	
	//local variables created to remove possibility of invalidating the dynamic arrays
	//during variable setting (when "this" values are deleted)
	if (this != &otherSong) { //this if statement is to avoid self-assignment
		/*access private variables and return local variables*/
		otherSong.getTitle(tempTitle);
		//set the received local variables as the member values	
		this->setTitle(tempTitle);	
		this->setLength(otherSong.songLengthMin, otherSong.songLengthSec);
		this->setViews(otherSong.songViews);	
		this->setLikes(otherSong.songLikes);
	}
	return *this;
} 

//overloaded extraction operator is a Song FRIEND (nonmember function)
ostream& operator<< (ostream &output, const Song &tempSong) {
	output << tempSong.songTitle << tempSong.songLengthMin << tempSong.songLengthSec << tempSong.songViews << tempSong.songLikes << endl;  
	return output;
}
