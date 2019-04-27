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
	artistJoinYear = 2019;
	artistSongList.head = nullptr;
	artistSongList.size = 0;
}

/*ARTIST DESTRUCTOR*/
~Artist() {
	if (artistName != nullptr) {
		delete artistName[];
	}
	if (artistHeadline != nullptr) {
		delete artistHeadline[];
	}
	artistGenre = unknown;
	artistJoinYear = 0;
}

//*ARTIST COPY CONSTRUCTOR*/
Artist(const Artist &otherArtist) {
	this->artistName = otherArtist.artistName; 
	this->artistHeadline = otherArtist.artistHeadline;
	this->artistGenre = otherArtist.artistGenre;
	this->artistJoinYear = otherArtist.artistJoinYear;
	this->artistSongList.head = otherArtist.artistSongList.head;
	this->artistSongList.size = otherArtist.artistSongList.size;
}

/*ARTIST OVERLOADED OPERATORS*/
const Artist &operator= (const Artist &otherArtist) {
	char tempName[MAX_SIZE];
	char tempHeadline[MAX_SIZE];
	if (this != &otherArtist) { //this if statement is to avoid self-assignment
		otherArtist.getName(tempName);
		otherArtist.getHeadline(tempHeadline);
		this->setName(tempName);	
		this->setHeadline(tempHeadline);	
		this->setGenre(otherArtist.artistGenre);
		this->setJoinYear(otherArtist.artistJoinYear);	
		this->artistSongList.head = 
	}
	return *this;
}

bool Artist::operator<(const Artist& otherArtist) const {
	if (strcmp(this->artistName, otherArtist.artistName) < 0) {
		return true;
	} else {
		return false;
	}
}

/////////////format the below////////////////////////////////////////////////
ostream &operator<< (ostream &output, const Artist &tempArtist) {
	output << tempArtist.artistName << tempArtist.artistHeadline << tempArtist.artistGenre 
		   << tempArtist.artistJoinYear<< tempArtist.songLikes;
	printSongList(output);
	cout << endl;  
	return output;
}

//------------------------------------//
/*ARTIST ACCESSOR FUNCTION DEFINITIONS*/
//------------------------------------//
void Artist::getName(char artistName[]) const {
	strcpy(artistName, this->artistName);
}

void Artist::getHeadline(char headline[]) const {
	strcpy(headline, this->artistHeadline);
}

void Artist::getGenre(genre artistGenre) const {
	artistGenre = this->artistGenre;
}

void Artist::getJoinYear(int &artistJoinYear) const {
	artistJoinYear = this->artistJoinYear;
}

void Artist::getSongList(SongList aSongList.head) const {
	this->artistSongList.head = aSongList.head;	
}

//-----------------------------------//
/*ARTIST MUTATOR FUNCTION DEFINITIONS*/
//-----------------------------------//
void ArtistList::setName(const char artistName[]) {
	if (this->artistName != nullptr) {
		delete [] this->artistName;
	}
	this->artistName = new char[strlen(artistName)+1];
	strcpy(this->artistName, artistName);	
}

void ArtistList::setHeadline(const char artistHeadline[]) {
	if (this->artistHeadline != nullptr) {
		delete [] artistHeadline;
	}
	this->artistHeadline = new char[strlen(artistHeadline)+1]
	strcpy(this->artistHeadline, headline);
}

void ArtistList::setGenre(const genre artistGenre) {
	this->artistGenre = artistGenre;
}

void ArtistList::setJoinYear(const int &artistJoinYear) {
	this->artistJoinYear = artistJoinYear;
}

void ArtistList:setSongList(const SongList &aSongList) {
	this->artistSongList = aSongList;

}

