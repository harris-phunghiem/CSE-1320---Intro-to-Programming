#include <stdio.h>
#include <string.h>

#define MAX_BUF 10
int main(void)
{
    char szUser_Input[10]="Charles";
    char szNew_String1[30];
    char szNew_String2[10];
    char szAy[] = "ay";
    int i = 0, j=0, k=0, nSpot=0;
    int nLength_szString = strlen(szUser_Input);

    for(i=0;i <= nLength_szString; i++)
    {
        if(szUser_Input[i] == 'a' || szUser_Input[i] == 'e' || szUser_Input[i] == 'i' || szUser_Input[i] == 'o' || szUser_Input[i] == 'u')
        {
            nSpot = i;
            for (j=0;j <= nLength_szString-1;j++)
            {
                szNew_String1[j] = szUser_Input[i];
                i++;
            }
            szNew_String1[j] = NULL;
        }
    }

    printf("szNew_String1: %s\n", szNew_String1);
    for(k=0; k<nSpot; k++)
    {
        szNew_String2[k] = szUser_Input[k];

    }
    szNew_String2[k] = NULL;
    printf("szNew_String2: %s\n", szNew_String2);

    strcat(szNew_String1,szNew_String2);
    strcat(szNew_String1, szAy);

    printf("%s is szNew_String1\n%s is szNew_String2\n%d is J\n%d is nSpot\n%d is nLength_szString", szNew_String1, szNew_String2, j,nSpot, nLength_szString);

    return szNew_String1;
}

