/*Written by Harris Nghiem
ID: 1000572896
CSE 1320-005
Homework 3 - Task 1
Write a program that outputs the multiplication tablet*/

#include <stdio.h>

int main (void)
{
    //Print Title
    printf("Welcome! This is the multiplication table from 0 through 12!\n\n\n");

    //Declare variables for Rows and Columns, from 0-12
    int nRows=0;
    int nColumns=0;

    //print the columns
    for(;nColumns<13;nColumns++)
    {
        printf("%5d",nColumns);
    }

    printf("\n");
    for(nRows=1;nRows <= 12; nRows++)
    {
        printf("%5d", nRows);
        for(nColumns=1;nColumns <=12; nColumns++)
        {
            printf("%5d", nColumns*nRows);
            if(nColumns == 12)
            {
                printf("\n");
            }
        }
    }

    return(0);
}
