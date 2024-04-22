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
    int doAgain, movesLimit, i, j, k, 
        movesLeft, livesLeft, movePosition = MAX_LENGTH + 1, 
        characterCount = 0;



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
    movesLimit = (int)(0.75 * game.pathLength); 
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
    printf("====================================\n");


    // Part - 2

    // Assigning Values for previous inputs
    movesLeft = game.nMoves; 
    livesLeft = player.nLives; 
    player.treasureCount = 0; 
   


    char currentPosition[MAX_LENGTH];
    char positionItem[MAX_LENGTH];

    for (i = 0; i < game.pathLength; i++)
    {
        player.historyPositions[j] = 0;
    }

    for (j = 0; j < game.pathLength; j++)
    {
        positionItem[j] = '-';
    }

    for (k = 0; k < game.pathLength; k++)
    {
        currentPosition[k] = ' '; 
    }

    // Display Table
    do
    {
        // Line 1
        for (k = 0; k < game.pathLength; k++)
        {
            if (currentPosition[k] == player.playerCharacter) 
            {
                characterCount++; 
            }
        }

        if (characterCount == 0) 
        {
            printf("\n");
        }
        else
        {
            printf("  ");
            for (k = 0; k < game.pathLength; k++) 
            {
                if (currentPosition[k] == player.playerCharacter)
                {
                    printf("%c\n", currentPosition[k]);  
                    break;
                }
                else
                {
                    printf("%c", currentPosition[k]); 
                }
            }
        }


        // Tracking current position requires the previous pointer to dissapear
        for (k = 0; k < game.pathLength; k++)
        {
            currentPosition[k] = ' ';
        }

        //  Line 2
        printf("  ");
        for (k = 0; k < game.pathLength; k++)
        {
            printf("%c", positionItem[k]);
        }
        printf("\n");

        // Line 3
        printf("  ");
        for (i = 1; i <= game.pathLength; i++)
        {
            if (i % 10 == 0)
            {
                printf("%d", (int)i / 10);
            }
            else
            {
                printf("|");
            }
        }
        printf("\n");

        // Fourth Line
        printf("  ");
        for (i = 0; i < game.pathLength; i += 10)
        {
            printf("1234567890");
        }
        printf("\n");

        // Displaying Player Statistics
        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", livesLeft, player.treasureCount, movesLeft); 
        printf("+---------------------------------------------------+\n");

        // Quit loop if the remaining lives equal zero
        if (livesLeft == 0) 
        {
            break;
        }

        // Quit loop if the remaining moves are zero
        if (movesLeft == 0) 
        {
            break;
        }

        // Promptiing for the player's the next move
        do {
            printf("Next Move [%d-%d]: ", MIN_LIVES, game.pathLength); 
            scanf("%d", &movePosition);

            if (movePosition < 1 || movePosition > game.pathLength)
            {
                printf("  Out of Range!!!\n");
            }

        } while (movePosition < 1 || movePosition > game.pathLength);
        printf("\n");

        if (player.historyPositions[movePosition - 1] == 1) 
        {
            printf("===============> Dope! You've been here before!\n\n");
            currentPosition[movePosition - 1] = 'V';
            movesLeft++; // This ensures there is no effect after the increment
        }

        else if (game.bombs[movePosition - 1] == 1 && game.treasure[movePosition - 1] == 1)
        {
            printf("===============> [&] !!! BOOOOOM !!! [&]\n");
            printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
            positionItem[movePosition - 1] = '&';
            currentPosition[movePosition - 1] = 'V';
            livesLeft--;
            player.treasureCount++; 
        }

        else if (game.bombs[movePosition - 1] == 1)
        {
            printf("===============> [!] !!! BOOOOOM !!! [!]\n\n");
            positionItem[movePosition - 1] = '!';
            currentPosition[movePosition - 1] = 'V';
            livesLeft--;  
        }

        else if (game.treasure[movePosition - 1] == 1)
        {
            printf("===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
            positionItem[movePosition - 1] = '$';
            currentPosition[movePosition - 1] = 'V';
            player.treasureCount++;
        }

        // else if (game.treasureLocations[movePosition - 1] == 0 && game.bombLocations[movePosition - 1] == 0)
        else
        {
            printf("===============> [.] ...Nothing found here... [.]\n\n");
            positionItem[movePosition - 1] = '.';
            currentPosition[movePosition - 1] = 'V';
        }

        // Storing the position in history array
        player.historyPositions[movePosition - 1] = 1; 

        // Decrementing the number of moves left
        movesLeft--; 

        if (livesLeft == 0) 
        {
            printf("No more LIVES remaining!\n\n");
        }
        if (movesLeft == 0) 
        {
            printf("No more MOVES remaining!\n\n");
        }


    } while (livesLeft >= 0 && movesLeft >= 0); 

    printf("\n"); 


    // Exit Message
    printf("##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n\n");
   
    printf("You should play again and try to beat your score!\n\n");
    

    return 0;
}



