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

	//mutator functions (aka "setters")
	void loadSongList(const char storageFile[]); //loads song file
	void addSong(Song &aSong);
	void optionAddSong();
	int selectRemove(); //this function does not modify any objects, 
						 //but enables user to access removeSong function
	void removeSong(int removeIndex);
	void writeLibrary(const char storageFile[]);
	
private:
	struct node {
		Song data;
		node *next;
		//deep copy passed in song data to this->data
		node(const Song& aSong) {
			this->data = Song& aSong;
			//set next to null
			next = nullptr;
		}
	};
	node *head, *tail;
	int librarySize;
	void compareTerms(char searchTerm[]) const;
};


#endif
