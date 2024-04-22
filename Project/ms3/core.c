#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "core.h"

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//

// This function returns and interger and recieves no arguments. It ensures a valid interger is entered else it displays an error message if invalid value is entered
int inputInt(void) 
{
    int value;
    char secondCharacter = ' ';

    do
    {
        scanf("%d%c", &value, &secondCharacter);

        if (secondCharacter != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }

    } while (secondCharacter != '\n');

    return value;
}


// This function guarantees a positive interger value is entered and returned. Otherwise it displays and error message if the interger is not positive
int inputIntPositive(void)
{
    int value;

    do
    {
        value = inputInt();
        if (value <= 0)
        {
            printf("ERROR! Value must be > 0: ");
        }

    } while (value <= 0);

    return value;
}


// This function guarantees an interger value is entered within the range(inclusive) and returned. Otherwise it displays and error message
int inputIntRange(int lowerBound, int upperBound)
{
    int value;
    do
    {
        value = inputInt();
        if (value < lowerBound || value > upperBound)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", lowerBound, upperBound);
        }

    } while (value < lowerBound || value > upperBound);

    return value;
}


char inputCharOption(char* cString)
{
    char character;
    int i, count = 0;
    do
    {
        scanf(" %c", &character);

        for (i = 0; cString[i] != '\0'; i++)
        {
            if (character == cString[i])
            {
                count++;
            }
        }
        if (count == 0)
        {
            clearInputBuffer();
            printf("ERROR: Character must be one of [%s]: ", cString);
        }

    } while (count == 0);

    clearInputBuffer();
    return character;
}


// This function guarantees a C string value is entered containing the number of characters within the range specified by the 2nd and 3rd arguments
void inputCString(char* str, int minChar, int maxChar) {
    int flag = 1;
    char ch = 'a';

    while (flag) {
        int len = 0;
        // Takes a string as input until it sees a newline character
        while (ch != '\n' && len <= maxChar) {
            ch = getchar();
            str[len] = ch;
            len++;
        };

        // If the string is less than or equal to the maxChars we will just add '\0' to the end to mark the end of the string
        if (ch == '\n' && len <= (maxChar + 1)) {
            len--;
            str[len] = '\0';
        }
        // If length is more than maxChar, we will add '\0' to the end and ignore the extra characters. We will also remove the extra characters from the buffer.
        else {
            str[maxChar] = '\0';
            clearInputBuffer();
        }

        if (minChar == maxChar && len != minChar) {
            printf("ERROR: String length must be exactly %d chars: ", minChar);
            ch = 'a';
        }
        else if (len < minChar || len > maxChar) {
            if (len > maxChar) {
                printf("ERROR: String length must be no more than %d chars: ", maxChar);
                ch = 'a';
            }
            else if (len < minChar) {
                printf("ERROR: String length must be between %d and %d chars: ", minChar, maxChar);
                ch = 'a';
            }
        }
        else {
            flag = 0;
        }
    }
}

// This function is the same as inputCString but is exclusively for numbers
void inputCStringNumbers(char* str, int minChar, int maxChar) {
    int flag = 1;
    char ch = 'a';

    while (flag) {
        int len = 0;
        // Takes a string as input until it sees a newline character
        while (ch != '\n' && len <= maxChar) {
            ch = getchar();
            str[len] = ch;
            len++;
        };

        // If the string is less than or equal to the maxChars we will just add '\0' to the end to mark the end of the string
        if (ch == '\n' && len <= (maxChar + 1)) {
            len--;
            str[len] = '\0';
        }
        // If length is more than maxChar, we will add '\0' to the end and ignore the extra characters. We will also remove the extra characters from the buffer.
        else {
            str[maxChar] = '\0';
            clearInputBuffer();
        }

        if (minChar == maxChar && len != minChar) {
            printf("Invalid 10-digit number! Number: ");
            ch = 'a';
        }
        else {
            flag = 0;
        }
    }
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// This function displays an array of 10 character digits as a formatted phone number.
void displayFormattedPhone(const char* phoneNumber)
{
    int i, size = 0;

    while (phoneNumber != NULL && isdigit(phoneNumber[size]))
    {
        size++;
    }

    if (size == 10)
    {
        printf("(");
        for (i = 0; i < 3; i++)
            printf("%c", phoneNumber[i]);
        printf(")");
        for (i = 3; i < 6; i++)
            printf("%c", phoneNumber[i]);
        printf("-");
        for (i = 6; i < 10; i++)
            printf("%c", phoneNumber[i]);

    }
    else printf("(___)___-____");

    if (phoneNumber != 0)
    {
        for (i = 0; phoneNumber[i] != '\0'; i++)
            size++;
    }
}