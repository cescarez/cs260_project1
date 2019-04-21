/**
 * Project CS260 Project 1
 */


#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

class linkedList {
public: 
    
void linkedList();
    
/**
 * @param linkedList &linkedList
 */
void linkedList(void linkedList &linkedList);
    
void addNode();
    
void removeNode();
    
/**
 * @param const char searchTerm[]
 */
bool searchList(void const char searchTerm[]);
    
void printList();
    
void displayNode();
    
int getSize();
protected: 
    
void linkedList();
private: 
    node *head;
    int size;
    
/**
 * @param const char storageFile[]
 */
void loadList(void const char storageFile[]);
    
/**
 * @param const char storageFile[]
 */
void saveList(void const char storageFile[]);
};

#endif //_LINKEDLIST_H