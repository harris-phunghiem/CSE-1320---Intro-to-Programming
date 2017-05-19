/*Made by Harris Nghiem
ID: 1000572896
Intermediate Programming
February 16, 2015*/

#include <stdio.h>

int main()

{
printf("DEC\tOCT\tHEX\tSymbol\n");//Label for different format specifiers

int nCounter;//Counter for loop.

//Loop to print first 126 characters of each DEC, OCT, HEX, and SYMBOL
for(nCounter=0;nCounter<=126;nCounter++)
{
    printf("%d\t%o\t%x\t%c\n",nCounter,nCounter,nCounter,nCounter);
}

return 0;
}
