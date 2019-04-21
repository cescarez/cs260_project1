/**
 * Project CS260 Project 1
 */


#ifndef _ARTIST_H
#define _ARTIST_H

class Artist {
public: 
    
void Artist();
    
/**
 * @param Artist &anArtist
 */
void Artist(void Artist &anArtist);
    
void printArtist();
    
/**
 * @param char name[]
 */
void getName(void char name[]);
    
/**
 * @param char headline[]
 */
void getHeadline(void char headline[]);
    
/**
 * @param char genre[]
 */
void getGenre(void char genre[]);
    
/**
 * @param int &joinYear
 */
void getJoinYear(void int &joinYear);
    
/**
 * @param const char name[]
 */
void setName(void const char name[]);
    
/**
 * @param const char headline[]
 */
void setHeadline(void const char headline[]);
    
/**
 * @param const char genre[]
 */
void setGenre(void const char genre[]);
    
/**
 * @param const int &joinYear
 */
void setJoinYear(void const int &joinYear);
protected: 
    
void Artist();
private: 
    void artistName;
    void artistHeadline;
    void artistGenre;
    void artistJoinYear;
    void SongList;
};

#endif //_ARTIST_H