/**
 * Project CS260 Project 1
 */


#ifndef _ARTISTLIST_H
#define _ARTISTLIST_H

class ArtistList {
public: 
    int artistListSize;
    
void ArtistList();
    
/**
 * @param ArtistList &anArtistList
 */
void ArtistList(void ArtistList &anArtistList);
    
node getArtistListHead();
    
int getArtistListSize();
    
void printArtistList();
    
/**
 * @param Artist &anArtist
 */
void addArtist(void Artist &anArtist);
    
void removeArtist();
    
/**
 * @param const char searchTerm[]
 */
bool searchArtistList(void const char searchTerm[]);
    
/**
 * @param const char storageFile[]
 */
void loadArtistList(void const char storageFile[]);
    
/**
 * @param const char storageFile[]
 */
void saveArtistList(void const char storageFile[]);
protected: 
    
void ArtistList();
private: 
    node *head;
    
void refreshArtistList();
};

#endif //_ARTISTLIST_H