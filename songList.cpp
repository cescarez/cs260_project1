//Christabel Escarez
//CS260 - Spring 2019


//Project #1 - songList.cpp
//implementation file for SongList class

#include "songList.h"
#include "song.h"
#include <iostream>

using namespace std;

/*SONG_LIST CONSTRUCTORS*/
SongList::SongList() {
	head = nullptr;
	songListSize = 0;
}

SongList::SongList(int &songListSize, const char artistName[]) {
	char *storageFile
	head = nullptr;
	this->songListSize = songListSize;
	loadSongList(storageFile);
}

/*SONG_LIST DESTRUCTOR*/
SongList::~SongList() {
	node *currentSong;
	currentSong = head;
	if (head != nullptr) {
		while (currentSong != nullptr) {
			head = currentSong->nextSong;
			delete currentSong;
			currentSong = head;
		}	
		head = nullptr;
	}
}

/*SONG_LIST COPY CONSTRUCTOR*/
SongList::SongList(const SongList &otherSongList) {
	node *currentSong = nullptr;
	currentSong = otherSongList.head;	
	if (currentSong == nullptr) {
		cout << "List is empty. Nothing to copy." << endl;
	} else {
		while(currentSong != nullptr) {
			node *newNode = new node(currentSong);
			if (this->head == nullptr) {
				//newNode->nextSong = head;
				this->head = newNode;	
			}
			//delete newNode;
			currentSong = currentSong->nextSong;
		}
		songListSize = otherSongList.songListSize;
	}	
} 

/*SONG_LIST OVERLOADED OPERATORS*/
const SongList& SongList::operator= (const SongList& otherSongList) {
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
ostream &operator<< (ostream &output, const Song &tempSong) {
	output << tempSong.songTitle << tempSong.songLengthMin << tempSong.songLengthSec 
		   << tempSong.songViews << tempSong.songLikes << endl;  
	return output;
}


//---------------------------------------//
/*SONG_LIST ACCESSOR FUNCTION DEFINITIONS*/
//---------------------------------------//

int SongList::getSongListSize() {
	return songListSize;
}

//BELOW IS ATTEMPT AT RECURSIVE FN, 
//ERROR DUE TO MEMBER PUBLIC/PRIVATE SCOPE
void SongList::printSongList() const {
	node *currentSong = nullptr;
	currentSong = head;
	if(currentSong == nullptr) {
		cout << "List is empty." << endl;
	} else {
		cout << currentSong->songData << endl;
		printSongList(currentSong->nextSong);
	}
}
//BELOW IS printSongList() AS AN ITERATIVE FUNCTION
//void SongList::printSongList() const {	
	//node *currentSong;
	//currentSong = head;
	//if (head == nullptr) {
		//cout << "Library is empty." << endl;
	//} else {
		//while (currentSong != nullptr) {
			//cout << currentSong->songData << endl;
			//currentSong = currentSong->nextSong;
		//}	
	//}
//}

//--------------------------------------//
/*SONG_LIST MUTATOR FUNCTION DEFINITIONS*/
//--------------------------------------//
node SongList::*getSongListHead() const {
	return head;
}

void loadSongList(const char storageFile[]); 
	void addSong(const Song &aSong);
	void removeSong(const char *searchTerm[]);
	void filterSongList(const int &minViewCounts);
	void saveSongList(const char storageFile[]);

