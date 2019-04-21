//Christabel Escarez
//CS260 - Spring 2019
//Project #1 - artist.cpp
//implementation file for Artist class


#include "artist.h"


/*ARTIST CONSTRUCTOR*/
Artist() {
	artistName = new char[strlen("I forget their name...")+1];
	strcpy(artistName, "I forget their name...");
	artistHeadline = new char[strlen("Still too underground for major media coverage.")+1];
	strcpy(artistHeadline, "Still too underground for major media coverage.");
	artistGenre = unknown;
	artistSongList.head = nullptr;
	artistSongList.size = 0;
}

/*ARTIST DESTRUCTOR*/

~Artist();

//*ARTIST COPY CONSTRUCTOR*/

/*ARTIST OVERLOADED OPERATORS*/

//------------------------------------//
/*ARTIST ACCESSOR FUNCTION DEFINITIONS*/
//------------------------------------//



//-----------------------------------//
/*ARTIST MUTATOR FUNCTION DEFINITIONS*/
//-----------------------------------//
void ArtistList::setName(const char artistName[]) {
	if (this->artistName) {
		delete [] this->artistName;
	}
}

void ArtistList::setHeadline(const char headline[]) {

}

void ArtistList::setGenre(const artistGenre genre) {

}

void ArtistList::setJoinYear(const int &artistJoinYear) {
	this->artistJoinYear = artistJoinYear;
}

void ArtistList:setSongList {
	this->artistSongList = aSongList;

}

