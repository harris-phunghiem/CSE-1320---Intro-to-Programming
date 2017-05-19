/*Highest number array*/

#include <stdio.h>

/*void Highest_Checker(int rgnExample[][2], int Row, int Column)
{
    int nHighest=0;

    if( rgnExample[Row][Column])

    printf("rgnA[%d][%d] = %d\n", Row, Column, rgnExample[Row][Column]);


}*/

int main(void)
{
    int rgnA[][2] = {
                        20,-6,
                        4,8,
                        3,2,
                        8,10};


    int nRows;
    int nColumns;
    int nHighest;
    int i;

    nHighest = rgnA[0][0];

    for(nRows=0;nRows<4;nRows++)
    {
        for(nColumns=1;nColumns<2;nColumns++)
        {
            if(rgnA[nRows][nColumns] > nHighest)
                nHighest = rgnA[nRows][nColumns];
        }
    }

    printf("%d", nHighest);



    return(0);
}


