#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Macros 
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main(void)
{
    // Variables Declarations
    const int JAN = 1, DEC = 12;
    int currentYear, currentMonth, valid = 1, i;
    double morningRate, eveningRate, morningTotal = 0, eveningTotal = 0, morningAverage, eveningAverage;

    //Displaying the title for the well-being log application
    printf("General Well-being Log\n");
    printf("======================\n");

    //Iteration Construct
    do
    {
        valid = 1;

        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &currentYear, &currentMonth);

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




    for (i = 0; i < LOG_DAYS; i++)
    {
        printf("%d-", currentYear);

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

        // Condition to Check and satisfy 0 print out
      
        printf("-%02d\n", i + 1);
        //Loop for Morning Rating
        do
        {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &morningRate);

            // Input Validation
            if (morningRate < 0.0 || morningRate > 5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }

        } while ((morningRate < 0.0) || (morningRate > 5.0));
        morningTotal += morningRate;
        //Loop for Evening Rating
        do
        {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &eveningRate);

            // Input Validation
            if (eveningRate < 0.0 || eveningRate > 5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }


        } while ((eveningRate < 0.0 || eveningRate > 5.0));
        eveningTotal += eveningRate;

        printf("\n");

    }

    
    printf("Summary\n");
    printf("=======\n");

    //Determining Totals and Averages
    printf("Morning total rating: %6.3lf\n", morningTotal);
    printf("Evening total rating: %6.3lf\n", eveningTotal);
    printf("----------------------------\n");
    printf("Overall total rating: %6.3lf\n\n", morningTotal + eveningTotal);

    morningAverage = morningTotal / LOG_DAYS;
    printf("Average morning rating:  %3.1lf\n", morningAverage);

    eveningAverage = eveningTotal / LOG_DAYS;
    printf("Average evening rating:  %3.1lf\n", eveningAverage);

    printf("----------------------------\n");
    printf("Average overall rating:  %3.1lf\n", (morningAverage + eveningAverage) / 2);




    return 0;
}
