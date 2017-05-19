/*Rock, Paper, Scissors Game
By Harris Nghiem
February 16th, 2015
By Harris Nghiem
CSE 1320*/

#include <stdio.h>
#include <string.h>

int main (void)
{
    //User input variable
    char cInput;

    //Print welcome
    printf("Welcome to the game of Rock-Paper-Scissors!\n\n");


    do
    {
        //Get selection from User
        printf("What is your selection?\nRock(R), Paper(P), or Scissors(S) or to Quit(Q):\n");
        cInput = getchar();
        getchar();

        //Randomized Variable
        int nRandom;

        //Statement to randomize the int nRandom
        srand((unsigned) time(NULL));
        nRandom = (rand()%100)+1;

        if (cInput  == 'R' || cInput == 'r')
        {
            if (nRandom > 0)
                {
                    if (nRandom <= 33)
                    {
                        printf("The computer has chosen 'Rock' also. You have tied!\n");
                    }
                    if (nRandom > 33)
                    {
                        if (nRandom < 66)
                            printf("The computer has chosen 'Paper'. You have lost!\n");
                    }
                    if (nRandom >= 66)
                    {
                        if (nRandom < 100)
                            printf("The computer has chosen 'Scissors'. You have won!\n");
                    }
                }
        }

        if (cInput  == 'P' || cInput == 'p')
        {
                if (nRandom <= 33)
                {
                    printf("The computer has chosen 'Rock' . You have won!\n");
                }
                if (nRandom > 33)
                {
                    if (nRandom < 66)
                        printf("The computer has chosen 'Paper' also. You have tied!\n");
                }
                if (nRandom >= 66)
                {
                    if (nRandom < 100)
                        printf("The computer has chosen 'Scissors'. You have lost!\n");
                }
        }

        if (cInput  == 'S' || cInput == 's')
        {

            if (nRandom <= 33)
            {
                printf("The computer has chosen 'Rock' . You have lost!\n");
            }
            if (nRandom > 33)
            {
                if (nRandom < 66)
                    printf("The computer has chosen 'Paper'. You have won!\n");
            }
            if (nRandom >= 66)
            {
                if (nRandom < 100)
                    printf("The computer has chosen 'Scissors' also. You have tied!\n");
            }
        }

        //Q or q to terminate loop
        if (cInput == 'Q' || cInput == 'q')
        {
            break;
        }
    }while (1);
    return 0;
}
