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
	SongList(int songListSize, const char storageFile[]);
	//destructor
	~SongList();
	//accessor functions (aka "getters")
	node getSongListHead() const;
	int getSongListSize();
	void printSongList() const;
	//mutator functions (aka "setters")
	void loadSongList(const char storageFile[]); 
	void addSong(const Song &aSong);
	void removeSong(const char *searchTerm[]);
	void filterSongList(const int &minViewCounts);
	void saveSongList(const char storageFile[]);
	
private:
	node *head;
	int songListSize;
	struct node {
		Song songData;
		node *nextSong;
		//deep copy passed in to this. Relies on overloaded assignment operator.
		node(const Song& aSong) {
			this->songData = aSong;
			//set next to null
			nextSong = nullptr;
		}
	};
};


#endif
