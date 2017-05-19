/*Harris Nghiem
ID: 1000572896
Task 2 in COMS*/

//Declare libraries
#include <stdio.h>


//Main body
int main(void)
{

    int nNumbers=1;
    int nStars=0;
    char cStar='*';

    for(;nNumbers<8;nNumbers++)
    {
        printf("%d", nNumbers);
        for(nStars=0;nStars < 8;nStars++)
        {
            printf("%c", cStar);
        }
        printf("\n");

    }
    return(0);
}
