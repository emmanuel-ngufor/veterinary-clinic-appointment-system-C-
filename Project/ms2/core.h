// SAFE-GUARD: 
// It is good practice to apply safe-guards to header files
// Safe-guard's ensures only 1 copy of the header file is used in the project build
// The macro name should be mirroring the file name with _ for spaces, dots, etc.

// !!! DO NOT DELETE THE BELOW 2 LINES !!!
#ifndef CORE_H
#define CORE_H

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 
// Copy your work done from Milestone #1 (core.h) into this file
// 
// NOTE:
// - Organize your functions into the below categories
// - Make sure the core.c file also lists these functions in the same order!
// - Be sure to provide a BRIEF comment for each function prototype
// - The comment should also be copied to the core.c function definition
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);



//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// This function returns and interger and recieves no arguments. It ensures a valid interger is entered else it displays an error message if invalid value is entered
int inputInt(void);

// This function guarantees a positive interger value is entered and returned. Otherwise it displays and error message if the interger value entered is less than or equal to zero
int inputIntPositive();

// This function guarantees an interger value is entered within the range(inclusive) and returned. Otherwise it displays and error message
int inputIntRange(int lowerBound, int upperBound);

// This function guarantees a single character value is entered within the list of valid characters.
char inputCharOption(const char* cString);

// This function guarantees a C string value is entered containing the number of characters within the range specified by the 2nd and 3rd arguments
void inputCString(char* cString, int minLength, int maxLength);

// This function dis[lays an array of 10 character digits as a formatted phone number.
void displayFormattedPhone(const char* cString);


// !!! DO NOT DELETE THE BELOW LINE !!!
#endif // !CORE_H
