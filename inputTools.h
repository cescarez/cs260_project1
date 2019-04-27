//Christabel Escarez
//CS260 - Spring 2019
//Project #1 - inputTools.h
//header file for standard input tools

#ifndef INPUT_TOOLS_H
#define INPUT_TOOLS_H


const int MAX_SIZE = 100;
const int MAX_RESPONSE = 3;

//check for legal inputs; note overloaded checkInput
char checkInput (char &response);
int checkInput (int &response, const int &maxThreshold);
bool checkCstring(char response[]);
//display prompt for user input, returning the legal
//value back to the calling environment
int readInt (const char prompt[], const int &maxThreshold);
char readChar (const char prompt[]);
void readString (const char prompt[], char inputString[]);

#endif
