/*Made By Harris Nghiem
Bubble sort program*/

void Bubble_Sort_Ascending(int List[], int Elements)

{
    int step,i,temp;
    for(step=0;step<Elements-1;++step)
    {
        printf("%d is %d iteration of bubble sort ascending \n", step, step);
        for(i=0;i<Elements-step-1;++i)
        {
            if(List[i]>List[i+1])
            {
                temp=List[i];
                List[i]=List[i+1];
                List[i+1]=temp;
            }
        }
    }
    return List;

}

void Bubble_Sort_Descending(int List[], int Elements)

{
    int step,i,temp;
    for(step=0;step<Elements-1;++step)
    {
        for(i=0;i<Elements-step-1;++i)
        {
            if(List[i]<List[i+1])
            {
                temp=List[i];
                List[i]=List[i+1];
                List[i+1]=temp;
            }
        }
    }
    return List;

}

void Insertin_Sort_Ascending(int List[], int Elements)
{
    int i=0,temp=0,j=0;

    for (i = 1; i < Elements; i++)
    {
        temp = List[i];
        j = i - 1;
        while ((temp < List[j]) && (j >= 0))
        {
            List[j + 1] = List[j];
            j = j - 1;
        }
        List[j + 1] = temp;
    }
}

void Insertin_Sort_Descending(int List[], int Elements)
{
    int i=0,temp=0,j=0;

    for (i = 1; i < Elements; i++)
    {
        temp = List[i];
        j = i - 1;
        while ((temp > List[j]) && (j >= 0))
        {
            List[j + 1] = List[j];
            j = j - 1;
        }
        List[j + 1] = temp;
    }
}

#include <stdio.h>

int main(void)

{
    int rgnUser_Inputs[100];    //Allows the user to input 100 different numbers
    int nElements;              //Number of elements user would like to input
    int i;                      //Counter for loops

    printf("How many numbers would you like to enter? ");
    scanf("%d", &nElements);

    for (i=0;i < nElements;i++)
    {
        scanf("%d", &rgnUser_Inputs[i]);
    }

    Bubble_Sort_Ascending(rgnUser_Inputs,nElements);
    //Output list after bubble sort ascending has been completed
    printf("\nBubble Sort Ascending.\nYourYour list in ascending order is \n");
    for (i=0; i < nElements; i++)
    {
        printf("%d\n", rgnUser_Inputs[i]);
    }

    Bubble_Sort_Descending(rgnUser_Inputs,nElements);
    //Output list after bubble sort descending has been completed
    printf("\n\nBubble Sort Descending.\nYour list in descending order is \n");
    for (i=0; i < nElements; i++)
    {
        printf("%d\n", rgnUser_Inputs[i]);
    }

    Insertin_Sort_Ascending(rgnUser_Inputs,nElements);
    //Output list after insertion sort has been completed
    printf("\n\nInsertion Sort Ascending. Your list in ascending order is \n");
    for (i=0; i < nElements; i++)
    {
        printf("%d\n", rgnUser_Inputs[i]);
    }

    Insertin_Sort_Descending(rgnUser_Inputs,nElements);
    //Output list after insertion sort has been completed
    printf("\n\nInsertion Sort Descending. Your list in descending order is \n");
    for (i=0; i < nElements; i++)
    {
        printf("%d\n", rgnUser_Inputs[i]);
    }



    return 0;

}
