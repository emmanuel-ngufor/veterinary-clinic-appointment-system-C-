#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Macros
#define MIN_YEAR 2012
#define MAX_YEAR 2022

int main(void)
{
    // Declaring Variables
    const int JAN = 1, DEC = 12;
    int currentYear, currentMonth;
    int valid = 1;

    //Displaying the title for the well-being log application
    printf("General Well-being Log\n");
    printf("======================\n");

    //Iteration Construct
    do
    {
        //flag variable
        valid = 1;
        
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &currentYear, &currentMonth);

        // Input Validation
        if (currentYear > MAX_YEAR || currentYear < MIN_YEAR)
        {
            valid = 0;
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
        }
        if (currentMonth > 12 || currentMonth < 1)
        {
            valid = 0;
            printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
        }

    } while (!valid);
    // continue Looping untill flag becomes invalid

    printf("\n*** Log date set! ***\n\n");
    printf("Log starting date: %d-", currentYear); 
     
    // Switch to map the month interger value to the respective 3- Character month representation
    switch (currentMonth)
    {

    case 1:
        printf("JAN");
        break;
    case 2:
        printf("FEB");
        break;
    case 3:
        printf("MAR");
        break;
    case 4:
        printf("APR");
        break;
    case 5:
        printf("MAY");
        break;
    case 6:
        printf("JUN");
        break;
    case 7:
        printf("JUL");
        break;
    case 8:
        printf("AUG");
        break;
    case 9:
        printf("SEPT");
        break;
    case 10:
        printf("OCT");
        break;
    case 11:
        printf("NOV");
        break;
    case 12:
        printf("DEC");
        break;

    }
    printf("-01\n\n");

    return 0;
}
