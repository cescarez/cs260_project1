//Christabel Escarez
//CS260 - Spring 2019
//Project #1 - artistList.cpp
//implementation file for ArtistList class

#include "artist.h"
#include "artistList.h"

/*ARTIST_LIST CONSTRUCTOR*/
ArtistList() {
	head = nullptr;
	artistListSize = 0
}

ArtistList(int artistListSize, const char storageFile[]) {
	head = nullptr;
	artistListSize = 0;	
	loadArtistList(storageFile);
}

/*ARTIST_LIST DESTRUCTOR*/
~ArtistList() {
	node *currentArtist;
	currentArtist = head;
	if (head != nullptr) {
		while (currentSong != nullptr) {
			head = currentSong->nextSong;
			delete currentSong;
			currentSong = head;
		}	
		head = nullptr;
	}
}

/*ARTIST_LIST COPY CONSTRUCTOR*/
ArtistList::ArtistList(const ArtistList &ArtistList) {
	node *currentSong = nullptr;
	currentSong = otherSongList.head;	
	if (currentSong == nullptr) {
		cout << "List is empty. Nothing to copy." << endl;
	} else {
		while(currentSong != nullptr) {
			node *newNode = new node(currentSong);
			if (this->head == nullptr) {
				this->head = newNode;	
			}
			currentSong = currentSong->nextSong;
		}
		songListSize = otherSongList.songListSize;
	}	
}

/*ARTIST_LIST OVERLOADED OPERATORS*/
const ArtistList& operator= (const ArtistList &otherArtistList) {
	if (this == &otherArtistList) {
		return *this;
	}
	destroy(this->head);
	copyList(otherArtistList.head, this->head);
	return *this;
}

//-----------------------------------------//
/*ARTIST_LIST ACCESSOR FUNCTION DEFINITIONS*/
//-----------------------------------------//



//----------------------------------------//
/*ARTIST_LIST MUTATOR FUNCTION DEFINITIONS*/
//----------------------------------------//


