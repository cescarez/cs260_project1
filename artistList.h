//Christabel Escarez
//CS260 - Spring 2019
//Project #1 - artistList.h
//header file for ArtistList class

#ifndef ARTIST_LIST_H
#define ARTIST_LIST_H

#include "artist.h"

class ArtistList {
public:
	//constructors
	ArtistList();
	ArtistList(int artistListSize, const char storageFile[]);
	//destructor
	~ArtistList();
	//copy constructor
	ArtistList(const ArtistList &otherArtistList);
	//overloaded functions
	const ArtistList& operator= (const ArtistList &otherArtistList);
	//accessor functions (aka "getters")
	node getArtistListHead() const;
	int getArtistListSize();
	void printArtistList() const;
	//mutator functions (aka "setters")
	void loadArtistList(const char storageFile[]); 
	void addArtist(const Artist &anArtist);
	void removeArtist(const char *searchTerm[]);
	void saveArtistList(const char storageFile[]);
	//update linked list sort (for use following Song view count update)
	void refreshArtistList();	
private:
	node *head;
	int artistListSize;
	struct node {
		Artist artistData;
		node *nextArtist;
		//deep copy passed in to this. Relies on overloaded assignment operator.
		node(const Artist &anArtist) {
			this->artistData = anArtist;
			//set next to null
			nextArtist = nullptr;
		}
	};
};


#endif
