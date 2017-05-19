#include <stdio.h>

char Move_Y_Back (char szInput[100])
{
    char szNew_String1[10];
    int i,j;
    char szAy[] = "yay";
    int nLength_szString = strlen(szInput);


    for(i=0;i <= nLength_szString; i++)
    {
        if(szInput[i] == 'a' || szInput[i] == 'e' || szInput[i] == 'i' || szInput[i] == 'o' || szInput[i] == 'u' || szInput[i] == 'y')
        {
            //nSpot = i;
            for (j=0;j <= nLength_szString-1;j++,i++)
            {
                szNew_String1[j] = szInput[i];
            }
            szNew_String1[j] = NULL;
        }
    }

    strcat(szNew_String1,szAy);
    printf("%s is szNew_String\n", szNew_String1);

    for (i = 0; szNew_String1[i] != NULL; i++)
        szInput[i] = szNew_String1[i];
    szInput[i] = NULL;

    return szInput;
}

int main(void)
{
    char szUser_Input[100] = "Yellow";
    if (szUser_Input[0] == 'Y');
    {
        printf("Does it go into the function?\n");
        Move_Y_Back(szUser_Input);
    }
    printf("%s is szUser_Input after Move_Y_Back", szUser_Input);
}
