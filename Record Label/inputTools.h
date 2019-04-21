/**
 * Project CS260 Project 1
 */


#ifndef _INPUTTOOLS_H
#define _INPUTTOOLS_H

class inputTools {
public: 
    
/**
 * @param const char prompt[]
 */
void readInt(void const char prompt[]);
    
/**
 * @param const char prompt[]
 */
void readChar(void const char prompt[]);
    
/**
 * @param const char prompt[]
 * @param char inputStrimg
 */
void readString(void const char prompt[], void char inputStrimg);
    
/**
 * @param const int &response
 */
void checkInput(void const int &response);
    
/**
 * @param char response[]
 */
void checkInput(void char response[]);
};

#endif //_INPUTTOOLS_H