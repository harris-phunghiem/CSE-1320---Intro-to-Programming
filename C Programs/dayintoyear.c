#include <stdio.h>

int main(void)
{
    int month =12, day=25;
    int rgnMonths[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int nDays=0;
    int i;

    int Month = month;

    for(i=0;i<Month;i++)
        nDays += rgnMonths[i];
    nDays += day;

    printf("%d is days left", nDays);

    return 0;
}
