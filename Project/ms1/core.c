#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>

#include "core.h"

#include <ctype.h>


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


 // This function returns and interger and recieves no arguments. It ensures a valid interger is entered else it displays an error message if invalid value is entered
 int inputInt()
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
 int inputIntPositive()
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
         if(value < lowerBound || value > upperBound) 
         {
             printf("ERROR! Value must be between %d and %d inclusive: ", lowerBound, upperBound);
         }

     } while (value < lowerBound || value > upperBound); 

     return value; 
 }


 // This function guarantees a single character value is entered within the list of valid characters.
 char inputCharOption(const char* cString)
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
 void inputCString(char* cString, int minLength, int maxLength)
 {
     int stringSize;
     int doAgain = 0;
     char charInput = 'x';   

     while (doAgain == 0)
     {
         stringSize = 0;

         while (charInput != '\n' && stringSize <= maxLength) 
         {
             scanf("%c", &charInput); 

             cString[stringSize] = charInput; 
             stringSize++;
         };

         if (charInput == '\n' && stringSize <= (maxLength + 1))   
         {
             stringSize--;
             cString[stringSize] = '\0';
         }
         else
         {
             cString[maxLength] = '\0';
             clearInputBuffer();
         }

         if (minLength == maxLength && stringSize != minLength)
         {
             printf("ERROR: String length must be exactly %d chars: ", minLength);
             charInput = 'x';  
         }
         else if (stringSize < minLength || stringSize > maxLength)
         {
             if (stringSize > maxLength)
             {
                 printf("ERROR: String length must be no more than %d chars: ", maxLength); 
                 charInput = 'x'; 
             }
             else if (stringSize < minLength)
             {
                 printf("ERROR: String length must be between %d and %d chars: ", minLength, maxLength);
                 charInput = 'x'; 
             }
         }
         else
         {
             doAgain = 1;
         }
     };

 }




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