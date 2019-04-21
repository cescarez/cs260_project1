//Christabel Escarez
//CS260 - Spring 2019
//Project #1 - songList.h
//header file for SongList class

#ifndef SONG_LIST_H
#define SONG_LIST_H

#include "song.h"

class SongList {

public:
	//constructors
	SongList();
	SongList(int &songListSize, const char storageFile[]);
	//destructor
	~SongList();
	//copy constructor
	SongList(const SongList &otherSongList);
	//overloaded functions
	const SongList& operator= (const SongList& otherSongList);

	//accessor functions
	int getSongListSize();
	void printSongList() const;
	//mutator functions
	void loadSongList(const char storageFile[]); 
	void addSong(const Song &aSong);
	void removeSong(const char *searchTerm[]);
	void filterSongList(const int &minViewCounts);
	void saveSongList(const char storageFile[]);
	//node definition made public to allow functions to return node value(s)
	struct node {
		Song songData;
		node *nextSong;
		//node constructor
		node(const Song &aSong) {
			this->songData = aSong;
			nextSong = nullptr;
		};
		//node copy constructor
		node(const node *otherNode) {
			this->songData = otherNode->songData;
			this->nextSong = otherNode->nextSong;
		};
	};

private:
	node *head;
	int songListSize;
	//function returns pointer node = head 
	node *getSongListHead() const;
};


#endif
