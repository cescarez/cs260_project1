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
	int getSongListSize() const;
	void printSongList(ostream &output) const; //recursive
	//mutator functions
	void loadSongList(const char storageFile[]); 
	void addSong(const Song &aSong); //recursive
	bool removeSong(const char *searchTerm); //recursive
	//void filterSongList(const int &minViewCounts);
	void saveSongList(const char storageFile[]);

private:
	struct node {
		Song *songData;
		node *nextSong;
		//node constructor
		node(Song aSong) {
			this->songData = aSong;
			nextSong = nullptr;
		};
		//node copy constructor
		node(const node *otherNode) {
			this->songData = otherNode->songData;
			this->nextSong = otherNode->nextSong;
		};
	};
	node *head;
	int songListSize;
	//helper functions
	void printSongList(ostream &output, node *currHead) const;
	void addSong(const Song &aSong, node *&currHead);
	bool removeSong(const char *searchTearm, node *&currHead);
	void destroy(node *& currHead);
	void copyList(node *sourceHead, node *&destHead);
};


#endif
