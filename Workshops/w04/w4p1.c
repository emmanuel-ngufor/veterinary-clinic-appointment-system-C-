#define _CRT_SECURE_NO_WARNINGS             // To ignore scanf warnings

#include <stdio.h>                          // printf abd scanf identifier

int main(void)                              // Entry point of our program
{


   //Variable Declarations
	char loopType;
	int numOfiterations; 
	int flag = 0, i;


	//Display Title
	printf("+----------------------+\n"); 
	printf("Loop application STARTED\n"); 
	printf("+----------------------+\n\n");

	do
	{
		//Prompting User for loopType and number of interations
		printf("D = do/while | W = while | F = for | Q = quit\n");
		printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
		scanf(" %c%d", &loopType, &numOfiterations);

		if (!(loopType == 'D' || loopType == 'W' || loopType == 'F' || loopType == 'Q'))
		{
			printf("ERROR: Invalid entered value(s)!\n\n");
		}
		else if ((loopType == 'D' || loopType == 'W' || loopType == 'F') && (numOfiterations < 3 || numOfiterations > 20))
		{
			printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
		}
		else if ((loopType == 'Q') && (numOfiterations != 0))
		{
			printf("ERROR: To quit, the number of iterations should be 0!\n\n");
		}
		else if (loopType == 'Q' && numOfiterations == 0)
		{
			flag = 1;
		}

		//DO-WHILE LOOP
		else if (loopType == 'D')
		{
			printf("DO-WHILE: ");
			i = numOfiterations;
			do
			{
				printf("D");
				i--;
			} while (i > 0);
			printf("\n\n");
		}

		//WHILE LOOP
		else if (loopType == 'W')
		{
			printf("WHILE   : ");
			i = numOfiterations;
			while (i > 0)
			{
				printf("W");
				i--;
			}
			printf("\n\n");
		}

		//FOR LOOP
		else if (loopType == 'F')
		{
			printf("FOR     : ");
			for (i = numOfiterations; i > 0; i--)
			{
				printf("F");
			}
			printf("\n\n"); 
		}

	} while (flag == 0);

	//Display Closing Message
	printf("\n+----------------------+\n"); 
	printf("Loop application ENDED\n");  
	printf("+----------------------+\n\n"); 
    return 0;
}
