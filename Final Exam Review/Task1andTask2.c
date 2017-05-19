/*Made By Harris Nghiem
Bubble sort program*/
#include <stdio.h>

#define ELEMENTS 100

void Bubble_Sort_Ascending(int List[], int Elements)

{
    int iteration, //Number of times entire array will be checked
        i,          //element in Array
        temp;       //Temp variable to store higher value
    for(iteration=0;iteration<Elements-1;iteration++)      //Number of times to repeat process. Will be Elements - 1
    {
        for(i=0;i<Elements-iteration-1;i++)      //Swap Elements up to (Elements - steps - 1). Deduct steps because in if loop, highest element in array is at the end.
        {
            if(List[i]>List[i+1])           //Swap Elements if lower Element is larger than higher Element
            {
                temp=List[i];               //Stores the higher into a temp variable
                List[i]=List[i+1];          //Sets lower Element as value of higher Element
                List[i+1]=temp;             //Higher value is stored in upper Element
            }
        }
    }
    return List;

}

void Bubble_Sort_Descending(int List[], int Elements)

{
    int iteration,i,temp;
    for(iteration=0;iteration<Elements-1;iteration++)
    {
        for(i=0;i<Elements-iteration-1;i++)
        {
            if(List[i]<List[i+1])   //If value of lower element is less than swap elements
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
    int i=1,buff=0,j=0;

    for (; i < Elements; i++)
    {
        buff = List[i];
        j = i - 1;
        while ((buff < List[j]) && (j >= 0))
        {
            List[j + 1] = List[j];
            j -=  1;
        }
        List[j + 1] = buff;
    }
}

void Insertin_Sort_Descending(int List[], int Elements)
{
    int i=1,buff=0,j=0;

    for (; i < Elements; i++)
    {
        buff = List[i];
        j = i - 1;
        while ((buff > List[j]) && (j >= 0))
        {
            List[j + 1] = List[j];
            j -= 1;
        }
        List[j + 1] = buff;
    }
}

void Print_Results(int List[])
{
    int i=0;
    int nRows = 10;
    while(nRows <=100)
    {
        while(i<nRows)
        {
            printf("%-6d ", List[i]);
            i++;
        }
        printf("\n");
        nRows += 10;
    }
}


int main(void)

{
    int rgnUser_Inputs[ELEMENTS]= { 321,687,987,3,894,862,743,13,3842,6,
                                    65,87,18,6352,87,135,48,93,489,6387,
                                    984,354,897,6541,8,8,189,318,684,38,
                                    315,8798,31,868,687,61132,18,1351,43,15,
                                    521,654,87,415,879,13241,683,18,7913,68,
                                    9,68,57,459,58,569,58,936,9,68,5,
                                    149,7536,5478,69,8745,23,8,474,5,25,
                                    951,7899,8452,654,7865,1475,2145,3245,9874,
                                    325,2,148,65,489,654,7896,58,6,358,
                                    8,45,842,584,256,98542,6985,2145,6,3214};

    int i; //Counter for loops

    //CALL TO BUBBLE SORT ASCENDING
    Bubble_Sort_Ascending(rgnUser_Inputs,ELEMENTS);
    //Output list after bubble sort ascending has been completed
    printf("\nBubble Sort Ascending. Your list in ascending order is \n");
    Print_Results(rgnUser_Inputs);


    //CALL TO BUBBLE SORT DESCENDING
    Bubble_Sort_Descending(rgnUser_Inputs,ELEMENTS);
    //Output list after bubble sort descending has been completed
    printf("\n\nBubble Sort Descending. Your list in descending order is \n");
    Print_Results(rgnUser_Inputs);

    //CALL TO INSERTION SORT ASCENDING
    Insertin_Sort_Ascending(rgnUser_Inputs,ELEMENTS);
    //Output list after insertion sort has been completed
    printf("\n\nInsertion Sort Ascending. Your list in ascending order is \n");
    Print_Results(rgnUser_Inputs);

    //CALL TO INSERTION SORT DESCENDING
    Insertin_Sort_Descending(rgnUser_Inputs,ELEMENTS);
    //Output list after insertion sort has been completed
    printf("\n\nInsertion Sort Descending. Your list in descending order is \n");
    Print_Results(rgnUser_Inputs);

    return 0;

}
