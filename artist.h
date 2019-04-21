//Christabel Escarez
//CS260 - Spring 2019
//Project #1 - artist.h
//header file for Artist class

#ifndef ARTIST_H
#define ARTIST_H

#include "inputTools.h"
#include "songList.h"

class Artist {	
public:
	//constructor
	Artist();
	//destructor
	~Artist();
	//copy constructor
	Artist(const Artist &otherArtist);
	//overloaded assignment operator
	const Artist &operator= (const Artist &otherArtist);
	//overloaded ostream operator
	friend ostream &operator<< (ostream &output, const Artist &tempArtist);
	//accessor functions
	//returns local variable (argument) equal to private instance data member
	void printSong(const Song &aSong) const;
	void getName(char artistName[]) const;
	void getHeadline(char headline[]) const;
	void getGenre(artistGenre genre) const;
	void getJoinYear(int &artistJoinYear) const;
	void getSongList(SongList &aSongList) const;
	//mutator functions
	//sets local instance members to passed in values
	void setName(const char artistName[]);
	void setHeadline(const char headline[]);
	void setGenre(const artistGenre genre);
	void setJoinYear(const int &artistJoinYear);
	void setSongList(const SongList &aSongList);
private:
	char *artistName;
	char *artistHeadline;
	enum artistGenre { unknown, indie, rock, pop, r&b };
	int *artistJoinYear;
	SongList artistSongList;
};


#endif
