/*Made by Harris Nghiem
Homework 6, Task 2*/

#include <stdio.h>

int main(void)
{
    char *pszMessage[5] = {
        "Please add a record.",
        "Please change a record.",
        "Please delete a record.",
        "Please show all records.",
        "Bye Bye!"};

    int rgnRecords[10];

    int i=0;
    int nUser_Input =0;
    int nInteger_Spot = 0;

    while(nUser_Input != 5)
    {
        for(;i<5;i++)
        {
            printf("%d - %s\n",i+1, pszMessage[i]);

        }
        printf("Enter a selection: ");
        scanf("%d", &nUser_Input);

        if(nUser_Input == 1)
        {
            printf("You have chosen Please add a record\n");
            printf("What integer would you like to add to Record[%d]\n",nInteger_Spot+1);
            scanf("%d", &nUser_Input);
            rgnRecords[nInteger_Spot] = nUser_Input;
            nUser_Input = 0;
            nInteger_Spot++;
        }

        else if(nUser_Input == 4)
        {
            i=0;
            while(i<nInteger_Spot)
            {
                    printf("rgnRecords[%d] is: %d\n",i+1, rgnRecords[i]);
                    i++;
            }
        }

        i=0;
        printf("\nPress any key to continue");
        getch();
        printf("\n");
    }



    return 0;
}
