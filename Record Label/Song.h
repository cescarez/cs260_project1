/**
 * Project CS260 Project 1
 */


#ifndef _SONG_H
#define _SONG_H

class Song {
public: 
    
void Song();
    
/**
 * @param Song &aSong
 */
void Song(void Song &aSong);
    
/**
 * precondition:
 * 
 * postcondition:
 */
void printSong();
    
/**
 * @param char title[]
 */
void getTitle(void char title[]);
    
/**
 * @param int &lengthMin
 * @param int &lengthSec
 */
void getLength(void int &lengthMin, void int &lengthSec);
    
/**
 * @param int &viewCount
 */
void getViews(void int &viewCount);
    
/**
 * @param int &likeCount
 */
void getLikes(void int &likeCount);
    
/**
 * @param const char title[]
 */
void setTitle(void const char title[]);
    
/**
 * @param const int &lengthMin
 * @param const int &lengthSec
 */
void setLength(void const int &lengthMin, void const int &lengthSec);
    
/**
 * @param const int &viewCount
 */
void setViews(void const int &viewCount);
    
/**
 * @param const int &viewCount
 */
void setLikes(void const int &viewCount);
protected: 
    
void Song();
private: 
    cstring songTitle;
    int songLengthMinL;
    int songLengthSec;
    int songViews;
    int songLikes;
};

#endif //_SONG_H