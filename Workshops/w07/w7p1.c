#define _CRT_SECURE_NO_WARNINGS

#define MAX_LENGTH 70
#define MIN_LENGTH 10
#define MAX_LIVES 10
#define MIN_LIVES 1
#define MULTIPLE 5

#include <stdio.h>


    // User defined data type 1 (PlayerInfo)
    struct PlayerInfo  
    {
        int nLives; 
        char playerCharacter;  
        int treasureCount;
        int historyPositions[MAX_LENGTH]; 
    };

    // User defined data type 2 (GameInfo)
    struct GameInfo 
    {
        int nMoves; 
        int pathLength; 
        int bombs[MAX_LENGTH]; 
        int treasure[MAX_LENGTH];
    };
   

    
    int main(void)
    {

        // Variable Declarations
        int doAgain, movesLimit, i, j, k;   


        // Allocating memory for PlayerInfo and GameInfo structures
        struct PlayerInfo player;
        struct GameInfo game;



        printf("================================\n");
        printf("         Treasure Hunt!\n");
        printf("================================\n\n");

        // Player Configuration
        printf("PLAYER Configuration\n");
        printf("--------------------\n");
        printf("Enter a single character to represent the player: ");
        scanf(" %c", &player.playerCharacter);

        do
        {
            printf("Set the number of lives: "); 
            scanf("%d", &player.nLives); 

            if (player.nLives >= MIN_LIVES && player.nLives <= MAX_LIVES)
            {
                printf("Player configuration set-up is complete\n\n");
                doAgain = 0;
            }
            else
            {
                printf("     Must be between %d and %d!\n", MIN_LIVES, MAX_LIVES); 
                doAgain = 1;
            }

        } while (doAgain);

        
        //player.historyPositions[MAX_LENGTH] = { 0 };

        // Game Configuration
        printf("GAME Configuration\n");
        printf("------------------\n");

        // Path Length
        do
        {
            printf("Set the path length (a multiple of %d between %d-%d): ", MULTIPLE, MIN_LENGTH, MAX_LENGTH); 
            scanf("%d", &game.pathLength);

            if ((game.pathLength >= MIN_LENGTH && game.pathLength <= MAX_LENGTH) && (game.pathLength % MULTIPLE == 0))
            {
                doAgain = 0;
            }
            else
            {
                printf("     Must be a multiple of %d and between %d-%d!!!\n", MULTIPLE, MIN_LENGTH, MAX_LENGTH); 
                doAgain = 1;
            }
           
        } while (doAgain);  
       

        // Number of moves
        movesLimit = (int) (0.75 * game.pathLength);    
        do
        {
            printf("Set the limit for number of moves allowed: "); 
            scanf("%d", &game.nMoves); 

            if (game.nMoves >= player.nLives && game.nMoves <= movesLimit) 
            { 
                doAgain = 0;
            }
            else
            {
                printf("    Value must be between %d and %d\n", player.nLives, movesLimit); 
                doAgain = 1;
            }

        } while (doAgain);   
       

        printf("\n");

        // Bomb Placement in Arrays
        printf("BOMB Placement\n");
        printf("--------------\n");
        printf("Enter the bomb positions in sets of %d where a value\n"
               "of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n", MULTIPLE); 
        printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);  


        // Prompting for bomb placement
        for (i = 0; i < game.pathLength; i += MULTIPLE)
        {
            printf("   Positions [%2d-%2d]: ", i + 1, i + MULTIPLE);  
            scanf("%d %d %d %d %d", &game.bombs[i], &game.bombs[i + 1], &game.bombs[i + 2], &game.bombs[i + 3], &game.bombs[i + 4]); 
        }
     

        printf("BOMB placement set\n\n");

        // Treasure Placement in Arrays
        printf("TREASURE Placement\n"); 
        printf("------------------\n");
        printf("Enter the treasure placements in sets of %d where a value\n"
               "of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n", MULTIPLE); 
        printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

        // Prompting for treasure placement
        for (i = 0; i < game.pathLength; i += MULTIPLE) 
        {
            printf("   Positions [%2d-%2d]: ", i + 1, i + MULTIPLE); 
            scanf("%d %d %d %d %d", &game.treasure[i], &game.treasure[i + 1], &game.treasure[i + 2], &game.treasure[i + 3], &game.treasure[i + 4]);  
        }

        printf("TREASURE placement set\n\n");

        printf("GAME configuration set-up is complete...\n\n");

        // Displaying the treasure hunt configuration settings
        printf("------------------------------------\n");
        printf("TREASURE HUNT Configuration Settings\n");
        printf("------------------------------------\n");

        // Player Details
        printf("Player:\n");
        printf("   Symbol     : %c\n", player.playerCharacter);
        printf("   Lives      : %d\n", player.nLives);
        printf("   Treasure   : [ready for gameplay]\n");
        printf("   History    : [ready for gameplay]\n\n");


        // Game Details
        printf("Game:\n");
        printf("   Path Length: %d\n", game.pathLength);

        // Bomb Locations
        printf("   Bombs      : ");
        // Displaying bombs array
        for (j = 0; j < game.pathLength; j++)
        {
            printf("%d", game.bombs[j]);
        }
        printf("\n"); 

        // Treasure Locations
        printf("   Treasure   : ");
        // Displaying treasure array
        for (k = 0; k < game.pathLength; k++)
        {
            printf("%d", game.treasure[k]);
        }

        printf("\n\n");
        
        // Exit Message
        printf("====================================\n");
        printf("~ Get ready to play TREASURE HUNT! ~\n");
        printf("====================================\n\n");

        return 0;
    }



