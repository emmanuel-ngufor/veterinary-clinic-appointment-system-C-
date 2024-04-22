#define _CRT_SECURE_NO_WARNINGS          // Command to ignore unexepected behaviour from the scanf function
#include <stdio.h>                       // prinf and scanf identifiers
int main(void)                           // Point of Entry (BEGINING OF PROGRAM)
{
    
    // VARIABLES = 12
    int numApples, numOranges, numPears, numTomatoes, numCabbages;                                     // Variables to store needed quantity (data type = interger)
    int qtyOfapples = 0, qtyOforanges = 0, qtyOfpears = 0, qtyOftomatoes = 0, qtyOfcabbages = 0;       // Variables to hold quantities choosen (data type = interger)
    int buyMoreitems = 1, flagDone = 1;                                                                     // Variables to control process flow (See warning Email by Professor Gray on using Flag) (data type = interger)


    // PART - 1
    do
    {

        printf("Grocery Shopping\n");                                          // printf is the C language command to display output
        printf("================\n");

                        //APPLES
        printf("How many APPLES do you need? : ");
        scanf("%d", &numApples);                                               // Request input for Apples and store to address of numAPPLES  
        while (numApples < 0)                                                  // As long as number of Apples entered is less than 0, display error below and ask for new value
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many APPLES do you need? : ");                         // \n not needed because scanf function displays a new line
            scanf("%d", &numApples); 
        }

                        //ORANGES
        printf("\nHow many ORANGES do you need? : ");
        scanf("%d", &numOranges);                                              // Request input for Oranges and store to the address of numOranges
        while (numOranges < 0)                                                 // As long  number of Oranges entered is less than 0, display error below and ask for new value
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many ORANGES do you need? : ");                        // \n not needed because scanf function displays a new line
            scanf("%d", &numOranges);
        }

                        //PEARS
        printf("\nHow many PEARS do you need? : ");
        scanf("%d", &numPears);                                                // Request input for Pears and store to the address of numPears
        while (numPears < 0)                                                   // As long as number of Pears entered is less than 0, display error below and ask for new value
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many PEARS do you need? : ");                          // \n not needed because the scanf function displays a new line
            scanf("%d", &numPears);
        }

                        //TOMATOES
        printf("\nHow many TOMATOES do you need? : ");
        scanf("%d", &numTomatoes);                                             // Request input for Tomatoes and store to the address of numTomatoes
        while (numTomatoes < 0)                                                // As long as number of Tomatoes entered is less than 0, display error beloe and ask for new value
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many TOMATOES do you need? : ");                       // \n not needed because scanf function displays a new line
            scanf("%d", &numTomatoes);
        }

                        //CABBAGES
        printf("\nHow many CABBAGES do you need? : ");                         //Request input for Cabbages and store to the address of numCabbages
        scanf("%d", &numCabbages);                                             // As long as number of Cabbages entered is less than 0, display error and ask for new value
        while (numCabbages < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many CABBAGES do you need? : ");                       // \n not needed because scanf function displays a new line
            scanf("%d", &numCabbages);
        }








        // PART -2 
        printf("\n--------------------------\n");                               // \n is for new line.....  \n\n will means skip two next lines
        printf("Time to pick the products!\n");                                 // printf is the C Programming Language command to display output to the screen
        printf("--------------------------\n\n");                               // \n\n will means skip two next lines

   




                         //APPLES
        int remainderOfapples = numApples;                                      // remainderOf apples is an interger data type and ensure we don't enter a value more than what was needed in numApples
        flagDone = 1;                                                               // flag to control single entry and exit principle !! See Professor Email
        do 
        {
            if (numApples > 0) 
            {
                printf("Pick some APPLES... how many did you pick? : ");
                scanf("%d", &qtyOfapples);

                if (qtyOfapples > remainderOfapples)                             // if quantity choosen exceeds remainder, display error
                {
                    printf("You picked too many... only %d more APPLE(S) are needed.\n", remainderOfapples);
                }
                else if (qtyOfapples <= 0)                                       // quantity entered must be  > 0 ( Negative values and 0 inclusive ) display error
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if ((qtyOfapples > 0) && (qtyOfapples < remainderOfapples))  // To make sure we entere a quantity untill the needed qauntity condidtion is satisfied
                {
                    remainderOfapples -= qtyOfapples;                              // This is the short-hand Formular, The original is : remainderOfapples = remainderOfapples - qtyOfapples
                    printf("Looks like we still need some APPLES...\n");          
                                                                                  
                }
                else if (qtyOfapples == remainderOfapples)                         // Loop ends if needed quantity is is equal to balance
                {
                    printf("Great, that's the apples done!\n\n");
                    flagDone = 0;
                }
            }
            else
            {
                flagDone = 0;
            }
        } while (flagDone);








                          //ORANGES
        int remainderOforanges = numOranges;                                         // remainderOforanges is an interger data type and ensure we don't enter a value more than what was needed in numOranges
        flagDone = 1;                                                                    // flag to control single entry and exit principle !! See Professor Email
        do
        {
            if (numOranges > 0)
            {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf("%d", &qtyOforanges); 

                if (qtyOforanges > remainderOforanges)                                 // if quantity choosen exceeds remainder, display error
                {
                    printf("You picked too many... only %d more ORANGE(S) are needed.\n", remainderOforanges); 
                }
                else if (qtyOforanges <= 0)                                             // quantity entered must be  > 0 ( Negative values and 0 inclusive ) display error
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if ((qtyOforanges > 0) && (qtyOforanges < remainderOforanges))     // To make sure we entere a quantity untill the needed qauntity condidtion is satisfied
                {
                    remainderOforanges -= qtyOforanges;                                  // This is the short-hand Formular, The original is : remainderOforanges = remainderOfranges - qtyOforanges
                    printf("Looks like we still need some ORANGES...\n");
                                              
                }
                else if (qtyOforanges == remainderOforanges)                            // Loop ends if needed quantity is is equal to balance
                {
                    printf("Great, that's the oranges done!\n\n");
                    flagDone = 0;
                }
            }
            else 
            {
                flagDone = 0;
            }
        } while (flagDone);











                          //PEARS           
        int remainderOfpears = numPears;                                             // remainderOfPears is an interger data type and ensure we don't enter a value more than what was needed in numPears
        flagDone = 1;                                                                    // flag to control single entry and exit principle !! See Professor Email
        do
        {
            if (numPears > 0) 
            {
                printf("Pick some PEARS... how many did you pick? : ");
                scanf("%d", &qtyOfpears); 

                if (qtyOfpears > remainderOfpears)                                  // if quantity choosen exceeds remainder, display error
                { 
                    printf("You picked too many... only %d more PEAR(S) are needed.\n", remainderOfpears); 
                }
                else if (qtyOfpears <= 0)                                            // quantity entered must be  > 0 ( Negative values and 0 inclusive ) display error
                { 
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if ((qtyOfpears > 0) && (qtyOfpears < remainderOfpears))        // To make sure we entere a quantity untill the needed qauntity condidtion is satisfied
                {  
                    remainderOfpears -= qtyOfpears;                                  // This is the short-hand Formular, The original is : remainderOfpears = remainderOfpears - qtyOfpears
                    printf("Looks like we still need some PEARS...\n");
                    
                }
                else if (qtyOfpears == remainderOfpears)                             // Loop ends if needed quantity is is equal to balance
                { 
                    printf("Great, that's the pears done!\n\n");
                    flagDone = 0;
                }
            }
            else
            {
                flagDone = 0;
            }
        } while (flagDone);




                          //TOMATOES                                                 
        int remainderOftomatoes = numTomatoes;                                               // remainderOftomatoes is an interger data type and ensure we don't enter a value more than what was needed in numTomatoes
        flagDone = 1;                                                                            // flag to control single entry and exit principle !! See Professor Email
        do
        {
            if (numTomatoes > 0) 
            {
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf("%d", &qtyOftomatoes); 

                if (qtyOftomatoes > remainderOftomatoes)                                   // if quantity choosen exceeds remainder, display error
                {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n", remainderOftomatoes); 
                }
                else if (qtyOftomatoes <= 0)                                               // quantity entered must be  > 0 ( Negative values and 0 inclusive ) display error
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if ((qtyOftomatoes > 0) && (qtyOftomatoes < remainderOftomatoes))     // To make sure we entere a quantity untill the needed qauntity condidtion is satisfied
                {
                    remainderOftomatoes -= qtyOftomatoes;                                  // This is the short-hand Formular, The original is : remainderOftomatoes = remainderOftomatoes - qtyOftomatoes
                    printf("Looks like we still need some TOMATOES...\n");
                    
                }
                else if (qtyOftomatoes == remainderOftomatoes)                             // Loop ends if needed quantity is is equal to balance
                {
                    printf("Great, that's the tomatoes done!\n\n");
                    flagDone = 0;
                }
            }
            else 
            {
                flagDone = 0;
            }
        } while (flagDone);




                           //CABBAGES
        int remainderOfcabbages = numCabbages;                                             // remainderOfcabbages is an interger data type and ensure we don't enter a value more than what was needed in numCabbages
        flagDone = 1;                                                                          // flag to control single entry and exit principle !! See Professor Email
        do 
        {
            if (numCabbages > 0)
            {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf("%d", &qtyOfcabbages); 

                if (qtyOfcabbages > remainderOfcabbages)                                            // if quantity choosen exceeds remainder, display error
                {  
                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n", remainderOfcabbages); 
                }
                else if (qtyOfcabbages <= 0)                                                        // quantity entered must be  > 0 ( Negative values and 0 inclusive ) display error
                { 
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if ((qtyOfcabbages > 0) && (qtyOfcabbages < remainderOfcabbages))              // To make sure we entere a quantity untill the needed qauntity condidtion is satisfied
                {  
                    remainderOfcabbages -= qtyOfcabbages;                                           // This is the short-hand Formular, The original is : remainderOfcabbages = remainderOfcabbages - qtyOfcabbages
                    printf("Looks like we still need some CABBAGES...\n");
                   
                }
                else if (qtyOfcabbages == remainderOfcabbages)                                      // Loop ends if needed quantity is is equal to balance
                {  
                    printf("Great, that's the cabbages done!\n\n");
                    flagDone = 0;
                }
            }
            else 
            {
                flagDone = 0;
            }
        } while (flagDone);






        //PART - 3
        printf("All the items are picked!\n\n");

        printf("Do another shopping? (0=NO): ");                                            // Determine if more items want to be bought again?
        scanf("%d", &buyMoreitems);	// YES = 1 (Continue) and N0 = 0 (End iteration)
        
	printf("\n");

    } while (buyMoreitems == 1);                                                            


    printf("Your tasks are done for today - enjoy your free time!\n");                     

    return 0;                                                                               // return 0; means return control back to the Operating System After executing the Code
}


/*
Pseudocode
1. Declare Varaibles needed to store information
2. Display Grocery Shopping (printf)
3. Use While iteration Construct 
4. Request for input for various items and store to the address of the variables created
5. Include necessary errors to be displayed upon violation of given conditions
6. When an item has been successfully picked, the next outstanding item on the list should be picked.
7. When all the shopping items have been picked, the process should be repeated
   for another shopping session until the user inputs a zero (0) value to indicate all shopping is done.
8.
9.
10.

*/
