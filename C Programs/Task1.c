/*Made By Harris Nghiem
Exponential function written by Taylor Series
*/

#include <stdio.h>
#include <math.h>


float Factorial(int nFactorial_Max)
{
    if (nFactorial_Max == 0)
        return (1);
    else
    {
        nFactorial_Max = nFactorial_Max * Factorial(nFactorial_Max-1);
        return (nFactorial_Max);
    }

}
int main(void)
{
    int nN;
    float nExponent;
    float nSum;

    //Prompt user for exponent
    printf("Please input 'X' for the program: ");
    scanf("%f", &nExponent);

    printf("exp(x) = %f\n\n", exp(nExponent));

    for(nN=1;nN<=9;nN++)
    {
        nSum += ((float)pow(nExponent,nN)/(float)Factorial(nN));
        printf("When n == %d, TaylorSeries(x,%d) = %f\n",nN, nN, (nSum +1));
    }

    return 0;
}
