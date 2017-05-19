/*Made by Harris Nghiem
Piglatin Program*/

#include <stdio.h>
#include <string.h>

//Function to check first letter. If it's a vowel, "way" will be added to the end of the string
int First_Letter_Check(char cFirst_Letter)
{
    if(cFirst_Letter == 'A' || cFirst_Letter == 'E' |cFirst_Letter == 'I' || cFirst_Letter == 'O' || cFirst_Letter == 'U' ||
       cFirst_Letter == 'a' || cFirst_Letter == 'e' |cFirst_Letter == 'i' || cFirst_Letter == 'o' || cFirst_Letter == 'u')
        return 1;
    return 0;
}


//Function to lower a letter before translation
char Lower_First(char szInput[])
{
    if (szInput[0] < 'Z')
    {
        szInput[0] += 32;
        return szInput;
    }
}


//Function to capitalize a letter after translation
char Capitalize_First(char szInput[])
{
    if (szInput[0] > 'Z')
    {
        szInput[0] -= 32;
        return szInput;
    }
}

//Function to bring consonants till first vowel to the back

char Bring_Consonants_Back(char szInput[30])
{
    char szNew_String1[30];
    char szNew_String2[10];
    char szAy[] = "ay";
    int i = 0, j=0, k=0, nSpot=0;
    int nLength_szString = strlen(szInput);


    for(i=0;i <= nLength_szString; i++)
    {
        if(szInput[i] == 'a' || szInput[i] == 'e' || szInput[i] == 'i' || szInput[i] == 'o' || szInput[i] == 'u' || szInput[i] == 'y')
        {
            nSpot = i;
            for (j=0;j <= nLength_szString-1;j++,i++)
            {
                szNew_String1[j] = szInput[i];
            }
            szNew_String1[j] = NULL;
        }
    }

    for(k=0; k<nSpot; k++)
    {
        szNew_String2[k] = szInput[k];

    }
    szNew_String2[k] = NULL;

    strcat(szNew_String1,szNew_String2);
    if(nSpot>0)
        strcat(szNew_String1, szAy);

    for (i = 0; szNew_String1[i] != NULL; i++)
        szInput[i] = szNew_String1[i];
    szInput[i] = NULL;

    return szInput;
}

char Move_Y_Back (char szInput[100])
{
    char szNew_String1[10];
    int i,j;
    char szAy[] = "yay";
    int nLength_szString = strlen(szInput);

    if(szInput[0] == 'y' || szInput[0] == 'Y')
    {

        for(i=0;i <= nLength_szString; i++)
        {
            if(szInput[i] == 'a' || szInput[i] == 'e' || szInput[i] == 'i' || szInput[i] == 'o' || szInput[i] == 'u')
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
        //printf("%s is szNew_String\n", szNew_String1);

        for (i = 0; szNew_String1[i] != NULL; i++)
            szInput[i] = szNew_String1[i];
        szInput[i] = NULL;

        return szInput;
    }

    return szInput;
}

int main(void)
{

    //Get user input
    char szUser_Input[100] = "";
    printf("Please enter in a few words: ");
    if (fgets(szUser_Input, sizeof szUser_Input, stdin) != NULL)
    {
        int len = strlen(szUser_Input);
        if (len > 0 && szUser_Input[len-1] == '\n') {
            szUser_Input[--len] = '\0';
        }
    }

    //Count how many words there are
    int ni = 0;
    int nWord_Count = 0;

    for(ni=0; ni <= strlen(szUser_Input); ni++)
    {
        if (szUser_Input[ni] == ' ')
            nWord_Count += 1;
    }
    nWord_Count += 1;

    //printf("%d is the amount of words in this program\n%d is strlen(szUser_Input)\n", nWord_Count, strlen(szUser_Input));

    //Finally, split the words in the user input into separate elements in an array
    char *finalArray[nWord_Count];  //array of words
    int maxSize = strlen(szUser_Input);
    char tempArray[100];

    int f = 0;
    for (f = 0; f<nWord_Count; f++)
    {
        finalArray[f] = malloc(sizeof(char)*100);
    }

    int i = 0; //temporary array iterator;
    int j = 0; //szUser_Input array iterator;
    int k = 0; //finalOut  array iterator;

    //printf("Input: %s\n",szUser_Input);

    while(1)
    {
        tempArray[i] = szUser_Input[j];

        if (szUser_Input[j] == ' ' || j == (maxSize-1))
        {
            if (j== (maxSize-1))
            {
                tempArray[i+1]='\0';
                strcpy(finalArray[k],tempArray);
                break;
            }
            tempArray[i]='\0';
            strcpy(finalArray[k],tempArray);
            j++;  //increase user input
            k++;  //go to next element in array
            i=0;  //set temp array back to 0



        }
        else
        {
            i++;
            j++;
        }

    }

    for (k = 0; k<nWord_Count; k++)
    {
        //printf("Element %d of finalArray is %s\n",k, finalArray[k]);
    }

    int nElement_Word =0;
    for(nElement_Word=0; nElement_Word<nWord_Count;nElement_Word++)
    {
        int nCapital=0;

        //If word starts with Y, bring it to the back
        if((*finalArray[nElement_Word]) == 'y'){
            Move_Y_Back(finalArray[nElement_Word]);
            printf("%s ", finalArray[nElement_Word]);
            nElement_Word++;}
        //Make first letter lowercase to start
        if(*finalArray[nElement_Word] < 'a')
            nCapital = 1;
        Lower_First(finalArray[nElement_Word]);
        //printf("%s is after function Lower_First\n", finalArray[nElement_Word]);

        //If first letter is vowel, add "way" to the end
        char szConsonant_End[] = "way";
        if (First_Letter_Check(*finalArray[nElement_Word]))
        {
            strcat(finalArray[nElement_Word], szConsonant_End);
        }


        //printf("%s is after function First_Letter_Check\n", finalArray[nElement_Word]);

        //Function to bring consonants till first vowel to the back
        Bring_Consonants_Back(finalArray[nElement_Word]);
        //printf("%s is after function Bring_Consonants_Back\n", finalArray[nElement_Word]);

        //Capitalize First Letter if needed after translation
        if(nCapital)
            Capitalize_First(finalArray[nElement_Word]);

        printf("%s ", finalArray[nElement_Word]);

    }
    return 0;
}
