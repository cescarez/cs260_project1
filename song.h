//Christabel Escarez
//CS260 - Spring 2019
//Project #1 - song.h
//header file for Song class

#ifndef SONG_H
#define SONG_H

using namespace std;

const int MAX_SIZE = 100;

class Song {	
public:
	//constructor
	Song();
	//destructor
	~Song();
	//copy constructor
	Song(const Song &otherSong);
	//overloaded assignment operator
	const Song& operator= (const Song& otherSong);
	//overloaded ostream operator
	friend ostream &operator<< (ostream &output, const Song &tempSong);
	//accessor functions
	//returns local variable (argument) equal to private instance data member
	void getTitle(char title[]) const;
	void getLength(int &lengthMin, int &lengthSec) const;
	void getViews(int &viewCount) const;
	void getLikes(int &likeCount) const;
	//mutator functions
	//sets local instance members to passed in values
	void setTitle(const char title[]);
	void setLength(const int &lengthMin, const int &lengthSec);
	void setViews(const int &viewCount);
	void setLikes(const int &likeCount);
	int editViews(const int &newViewCount); 
private:
	char *songTitle;
	int songLengthMin;
	int songLengthSec;	
	int songViews;
	int songLikes;
};

#endif
