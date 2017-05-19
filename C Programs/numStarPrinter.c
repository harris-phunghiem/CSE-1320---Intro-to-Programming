#include <stdio.h>

int main()
{
    int nCurrentRow = 1;
    int nMaximumRow = 7;
    int nCounter = 1;
    while (nCurrentRow <= nMaximumRow)
    {
        while (nCounter<=nCurrentRow)

        {
            printf("%d",nCounter);
            nCounter++;
        }


        while (nCounter <= nMaximumRow)
        {
            printf("*");
            nCounter++;
        }


        nCurrentRow++;
        nCounter=1;
        printf("\n");                 //a new line at the end of every row
    }





}
