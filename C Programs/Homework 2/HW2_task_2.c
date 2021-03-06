/*Written by Harris Nghiem
ID: 1000572896
Homework 2 - Task 2
This program generates a random number, and allows the user to guess it with a user-selected amount of guesses*/

//Define libraries
#include <stdio.h>

int main(void)
{
    //Variable for Game Loop
    char cLoop_Game;

    //Difficulty of Game
    int nDifficulty = 1;

    printf("Choose your difficulty setting.\nEasy\t(10 Tries):\tEnter 1\nMedium\t(8 Tries):\tEnter 2\nHard\t(6 Tries):\tEnter 3\n");
    scanf("%d", &nDifficulty);

    switch(nDifficulty)//Allows the user to choose how many guesses they get
    {
    case 1:
        {
            nDifficulty = 10;
            break;
        }
    case 2:
        {
            nDifficulty = 8;
            break;
        }
    case 3:
        {
            nDifficulty = 6;
            break;
        }
    }

    do//main loop
    {
        //Randomized Variable generated by time
        int nRandom;

        //Variable for six guesses
        int nSix_Guess = 0;

        //Variable for User's guess
        int nUser_Guess;

        //Statement to randomize the int nRandom with range from 1 - 100
        srand((unsigned) time(NULL));
        nRandom = (rand()%100)+1;

        do  //Loop allows six guesses, and will exit when nSix_Guess =6
        {
            printf("Please enter your guess as an integer\n");
            scanf("%d", &nUser_Guess);

            if (nUser_Guess > 0 && nUser_Guess < 101)
            {
                nSix_Guess++;

                if(nUser_Guess>nRandom)//Tells the user if the number is too high
                {
                    if (nSix_Guess == nDifficulty)
                        break;
                    printf("Your selection is too high, try again. Guess %d of %d\n", nSix_Guess, nDifficulty);
                }

                if(nUser_Guess<nRandom)//Tells the user if the number is too low
                {
                    printf("Your selection is too low, try again. Guess %d of %d\n", nSix_Guess, nDifficulty);
                }
            }
            if (nUser_Guess < 0 || nUser_Guess>100)//If the user inputs a guess less than 0 or greater than 100. Does not count as a guess
            {
                printf("Invalid selection. Please try again.\n");
            }

            else if (nRandom == nUser_Guess) //If User guesses random number before nSix_Guess reaches nDifficutly, they have won
            {
                printf("Congratulations! You have won! Would you like to play again? Yes(Y) or No(N)\n");
                cLoop_Game = getch();
            }

            else if (nSix_Guess == nDifficulty) //If User guesses reaches nDifficulty, user has lost
            {
                printf("You have lost... The number was %d\nWould you like to play again? Yes(Y) or No(N)\n", nRandom);
                cLoop_Game = getch();
            }

        }while(nRandom != nUser_Guess && nSix_Guess < nDifficulty);
    }while(cLoop_Game == 'Y' || cLoop_Game == 'y');
    return 0;
}
