/*Written by Harris Nghiem
ID: 1000572896
CSE 1320-005
Homework 3 - Task 3
Use functions in our Paper-Rock-Scissors game*/

//Define libraries
#include <stdio.h>
#include <string.h>

//Function to randomize the number
int Random_Number(int nRandom)
{
    int nReturn;
    srand((unsigned) time(NULL));
    nReturn = (rand()%100)+1;
    return nReturn;

}

//Test if the User beats the Computer, and outputs the results
void Print_Results(char cInput, int nRandom)
{
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

}

int main(void)
{
    do
    {
        //Variable for Random number
        int nRandom=0;

        //Get selection from User
        char cInput;
        printf("What is your selection?\nRock(R), Paper(P), or Scissors(S) or to Quit(Q):\n");
        cInput = getchar();
        getchar();

        Print_Results(cInput,Random_Number(nRandom));

    //Q or q to terminate loop
    if (cInput == 'Q' || cInput == 'q')
    {
        break;
    }
    }while (1);
    return 0;
}


