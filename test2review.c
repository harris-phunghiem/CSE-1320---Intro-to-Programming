#include <stdio.h>
#define MAXLEN 100

long power (long num, int nPow)
{
    if(nPow <= 0)
        return 1;
    return num * power(num, nPow-1);
}

int main (void)
{
    int pow;
    long res, num;
    printf("Enter a number: ");
    scanf("%ld", &num);
    printf("Enter power: ");
    scanf("%d", &pow);

    res = power(num, pow);
    printf("\n%ld to the power %d is: %ld", num, pow, res);

    return 0;

}
