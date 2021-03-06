//Christabel Escarez
//CS260 - Spring 2019
//Project #1 - song.cpp
//implementation file for Song class

#include "song.h"
#include <cstring>
#include <iostream>

using namespace std;

/*SONG CONSTRUCTOR*/
Song::Song() {
	songTitle = new char[strlen("unknown title")+1];
	strcpy(songTitle, "unknown title");
	songLengthMin = 0;
	songLengthSec = 0;	
	songViews = 0;
	songLikes = 0;

}

/*SONG DESTRUCTOR*/
Song::~Song() {
	if (songTitle != NULL) {
		delete [] songTitle;
	}
	songLengthMin = 0;
	songLengthSec = 0;	
	songViews = 0;
	songLikes = 0;
}

/*SONG COPY CONSTRUCTOR*/
Song::Song(const Song &otherSong) {
	this->songTitle = new char[strlen(otherSong.songTitle)+1];
	songTitle = otherSong.songTitle;
	songLengthMin = otherSong.songLengthMin;
	songLengthSec = otherSong.songLengthSec;
	songViews = otherSong.songViews;
	songLikes = otherSong.songLikes;
} 

/*SONG OVERLOADED OPERATORS*/
const Song& Song::operator= (const Song& otherSong) {
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

bool Song::operator==(const Song& otherSong) const {
	if (strcmp(this->songTitle, otherSong.songTitle) == 0) {
		return true;
	} else {
		return false;
	}
}

bool Song::operator<(const Song& otherSong) const {
	if (this->songViews < otherSong.songViews) {
		return true;
	} else {
		return false;
	}
}

/////////////format the below////////////////////////////////////////////////
ostream &operator<< (ostream &output, const Song &tempSong) {
	output << tempSong.songTitle << tempSong.songLengthMin << tempSong.songLengthSec 
		   << tempSong.songViews << tempSong.songLikes << endl;  
	return output;
}

//----------------------------------//
/*SONG ACCESSOR FUNCTION DEFINITIONS*/
//----------------------------------//
void Song::getTitle(char songTitle[]) const {
	strcpy(songTitle, this->songTitle);
}
const char * Song::getTitle() const {
	return this->songTitle;
}

void Song::getLength(int &songLengthMin, int &songLengthSec) const {
	songLengthMin = this->songLengthMin;
	songLengthSec = this->songLengthSec;
}

void Song::getViews(int &songViews) const {
	songViews = this->songViews;
}

void Song::getLikes(int &songLikes) const {
	songLikes = this->songLikes;
}

//---------------------------------//
/*SONG MUTATOR FUNCTION DEFINITIONS*/
//---------------------------------//

void Song::setTitle(const char title[]) {
	if (this->songTitle) {
		delete [] this->songTitle;
	}
	this->songTitle = new char[strlen(songTitle)+1];
	strcpy(this->songTitle, songTitle);	
}

void Song::setLength(const int &songLengthMin, const int &songLengthSec) {
	this->songLengthMin = songLengthMin;
	this->songLengthSec = songLengthSec;	
}

void Song::setViews(const int &songViews) {
	this->songViews = songViews;
}

void Song::setLikes(const int &songLikes) {
	this->songLikes = songLikes;
}

