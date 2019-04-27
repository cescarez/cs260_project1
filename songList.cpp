//Christabel Escarez
//CS260 - Spring 2019
//Project #1 - songList.cpp
//implementation file for SongList class

#include "songList.h"
#include "song.h"
#include <iostream>
#include <fstream>

using namespace std;

/*SONG_LIST CONSTRUCTORS*/
SongList::SongList() {
	head = nullptr;
	songListSize = 0;
}

SongList::SongList(int &songListSize, const char artistName[]) {
	char *storageFile;
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
	if (this == &otherSongList) {
		return *this;
	}
	destroy(this->head);
	copyList(otherSongList.head, this->head);
	return *this;
} 
 
///////////////////////////////////////////////////////////////////////////format output
ostream &operator<< (ostream &output, const Song &tempSong) {
	output << tempSong.songTitle << tempSong.songLengthMin << tempSong.songLengthSec 
		   << tempSong.songViews << tempSong.songLikes << endl;  
	return output;
}


//---------------------------------------//
/*SONG_LIST ACCESSOR FUNCTION DEFINITIONS*/
//---------------------------------------//
int SongList::getSongListSize() const{
	return songListSize;
}

void SongList::printSongList(ostream &output) const {
	printSongList(output, head);
}

//--------------------------------------//
/*SONG_LIST MUTATOR FUNCTION DEFINITIONS*/
//--------------------------------------//
void SongList::loadSongList(const char storageFile[]) {
	//create temporary variables to store values retrieved from accessor functions
	char tempSongTitle[MAX_SIZE];
	int tempLengthMin = 0, tempLengthSec = 0, tempLikes = 0, tempViews = 0;
	//create local Song object to store the above inputs for addSong() to add to end of list
	Song tempSong;
	ifstream songsFile;
	songsFile.open(storageFile);
	//check for correct file name in main program
	while(!songsFile) {
		songsFile.clear();
		cout << "Error. Library file failed to open. Exiting CS260 Record Label Artist Roster." << endl;
		exit(1);
	}
	//read file into library[]
	songsFile.get(tempSongTitle, MAX_SIZE, ';');
	while(!songsFile.eof()) {
		songsFile.get();
		songsFile >> tempLengthMin;
		songsFile.get();
		songsFile >> tempLengthSec;
		songsFile.get();
		songsFile >> tempViews;
		songsFile.get();
		songsFile >> tempLikes;
		songsFile.get();
		songsFile.ignore(100, '\n');
		songsFile.clear();
		//associate inputs with temp Song instance
		tempSong.setTitle(tempSongTitle);
		tempSong.setLength(tempLengthMin, tempLengthSec);
		tempSong.setViews(tempViews);
		tempSong.setLikes(tempLikes);
		//add the song instance to the library
		addSong(tempSong); 
		//start next song record
		songsFile.get(tempSongTitle, MAX_SIZE, ';');
	}
	songsFile.close();
}

void SongList::addSong(const Song &aSong) {
	addSong(aSong, head);
	songListSize++;
}

bool SongList::removeSong(const char *searchTerm) {
	return removeSong(searchTerm, head);
}

//void SongList::filterSongList(const int &minViewCounts) {

//}

void SongList::saveSongList(const char storageFile[]) {

}

//--------------------------------------//
/*SONG_LIST HELPER FUNCTION DEFINITIONS*/
//--------------------------------------//
void SongList::printSongList(ostream &output, node *currHead) const {
	if (currHead == nullptr) {
		return;
	}
	output << *(currHead->songData) << " ";
	printSongList(output, currHead->nextSong);
	
}

void SongList::addSong(const Song& aSong, node *&currHead)
{
	if (currHead == nullptr) {
		currHead = new node(aSong);
	} else {
		if (aSong < *(currHead->songData)) { //linked list sorted by view count
			node * newNode = new node(aSong);
			newNode->nextSong = currHead;
			currHead = newNode;
		} else {
			addSong(aSong, currHead->nextSong);
		}
	}
}

bool SongList::removeSong(const char *searchTerm, node *&currHead) {
	if (currHead == nullptr) {
		cout << "List is empty. No nodes left to remove." << endl;
		return false;
	} else {
		//check node for song title to compare against search term
		char *currentSong = new char[strlen(currHead->songData->getTitle())+1];
		if (strcmp(currentSong, searchTerm) == 0) {
			node *temp = currHead; 
			currHead = currHead->nextSong; 
			delete temp->songData; 
			delete temp;
			temp = nullptr;
			return true;
		} else {
			//if song title doesn't match current node, repeat function on next node
			return removeSong(searchTerm, currHead->nextSong);
		}
	}
}

void SongList::destroy(node *&currHead) {
	if (currHead != nullptr) {
		destroy(currHead->nextSong);
		delete currHead;
	}
}

void SongList::copyList(node *sourceHead, node *&destHead) {
	if (sourceHead) {
		destHead = new node(*(sourceHead->songData));
		copyList(sourceHead->nextSong, destHead->nextSong);
	}
}
