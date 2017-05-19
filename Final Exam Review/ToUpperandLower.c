/*Function to make all letters UPPERCASE*/

#include <stdio.h>

char ToUpper (char szInput[100])
{
    int i;
    int length;

    length = strlen(szInput);
    for(i=0;i<length;i++)
    {
        if (szInput[i] >= 'a' && szInput[i] <= 'z')
        {
            szInput[i] -= 'a' - 'A';
        }
    }
    return szInput;
}


char ToLower (char szInput[100])
{
    int i;
    int length;

    length = strlen(szInput);
    for(i=0;i<length;i++)
    {
        if (szInput[i] >= 'A' && szInput[i] <= 'Z')
        {
            szInput[i] += 'a' - 'A';
        }
    }
    return szInput;
}


int main(void)
{
    char szUser_Input[100];
    char Temp[100];

    printf("Please enter in a word you'd like to capitalize: ");
    scanf("%s", &szUser_Input);

    ToUpper(szUser_Input);

    printf("After ToUpper, the string is now %s \n\n", szUser_Input);

    ToLower(szUser_Input);

    printf("After ToLower, the string is now %s ", szUser_Input);


    printf("%d is A - a", 'A' - 'a');

    return 0;
}
