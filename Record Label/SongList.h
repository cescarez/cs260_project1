/**
 * Project CS260 Project 1
 */


#ifndef _SONGLIST_H
#define _SONGLIST_H

class SongList {
public: 
    
void SongList();
    
/**
 * @param SongList &aSongList
 */
void SongList(void SongList &aSongList);
    
node getSongListHead();
    
int getSongListSize();
    
void printSongList();
    
/**
 * @param Song &aSong
 */
void addSong(void Song &aSong);
    
void removeSong();
    
/**
 * @param const char searchTerm[]
 */
bool searchSongList(void const char searchTerm[]);
    
/**
 * @param const int &minViewCounts
 */
void filterSongList(void const int &minViewCounts);
protected: 
    
void SongList();
private: 
    node *head;
    int songListSize;
    
/**
 * @param const char storageFile
 */
void loadSongList(void const char storageFile);
    
/**
 * @param const char storageFile
 */
void saveSongList(void const char storageFile);
};

#endif //_SONGLIST_H