#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//Defining Macros
#define MAX_ITEMS 10
#define MIN_ITEMS 1

int main(void)
{
    //Variable Declarations
    const double MIN_INCOME = 500.00, MAX_INCOME = 400000.00;  
    double monthlyIncome;
    int i, value = 1, numItems; 
    double totalCost = 0;
  

    //Displaying title
    printf("+--------------------------+\n"); 
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");


    //Prompting User for NET Monthly income 
    do
    {
        value = 1;
        printf("Enter your monthly NET income: $");
        scanf("%lf", &monthlyIncome);

        if (monthlyIncome < MIN_INCOME) 
        {
            printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n", MIN_INCOME); 
            value = 0;
        }
        if (monthlyIncome > MAX_INCOME) 
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n", MAX_INCOME); 
            value = 0; 
        }
        printf("\n");


    } while (!value); 
    
    

    // Prompting User for Wishlist items for forcasting
    do
    {
        value = 1;
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &numItems);

        if (numItems < MIN_ITEMS || numItems > MAX_ITEMS)  
        {
            printf("ERROR: List is restricted to between %d and %d items.\n", MIN_ITEMS, MAX_ITEMS); 
            value = 0;
        }

        printf("\n");  
           
    } while (!value);    
    //((numItems < 1 || numItems > MAX_ITEMS));



    //Arrays

    double costOfitem[MAX_ITEMS];
    int priorityOfitem[MAX_ITEMS];
    char finance[MAX_ITEMS];
    const double MIN_COST = 100.00;

  

    for (i = 0; i < numItems; i++)
    {
        printf("Item-%d Details:\n", i + 1);


        // Cost Array
        do
        {
            value = 1;
            printf("   Item cost: $");
            scanf("%lf", &costOfitem[i]);

            if (costOfitem[i] < MIN_COST)
            {
                printf("      ERROR: Cost must be at least $%.2lf\n", MIN_COST);
                value = 0;
            }
        } while (!value);

        // Priority Array
        do
        {
            value = 1;
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priorityOfitem[i]);


            if ((priorityOfitem[i] < 1) || (priorityOfitem[i] > 3))
            {
                printf("      ERROR: Value must be between 1 and 3\n");
                value = 0;
            }

        } while (!value); 

        // Finance Array
        do
        {
            value = 1;
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &finance[i]);

            if (!(finance[i] == 'n' || finance[i] == 'y')) 
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");  
                value = 0;
            }

        } while (!value); 

        printf("\n");
    }

    //Display in formatted table
    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    
    //Iteration for 03 outputs
    for (i = 0; i < numItems; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priorityOfitem[i], finance[i], costOfitem[i]); 
    }


    //Summary of the total cost of items
    printf("---- -------- -------- -----------\n"); 

    for (i = 0; i < numItems; i++)
    {
        totalCost += costOfitem[i];
    }
    printf("                      $%11.2lf\n\n", totalCost); 


    //Display Exit Message
    printf("Best of luck in all your future endeavours!\n");

    return 0;
}
