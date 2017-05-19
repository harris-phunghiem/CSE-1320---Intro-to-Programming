/*Made by Harris Nghiem
Task 1
Write a swap function that exchanges the values of an array*/

void Swap_Elements(int *rgnInput[10], int nSwap1, int nSwap2)
{
    //Declare temp variables to store values of rngInput[nSwap1] and rngInput[nSwap2]
    int nBuffer1, nBuffer2;

    nBuffer1 = rgnInput[nSwap1-1];
    nBuffer2 = rgnInput[nSwap2-1];

    rgnInput[nSwap1-1] = nBuffer2;
    rgnInput[nSwap2-1] = nBuffer1;

    return rgnInput;

}

int main(void)
{
    int rgnUser_Input[10];//Array that holds the user inputs
    int nCounter=0;//Element counter
    int nIndex1 = 0;//First element the user would like to exchange
    int nIndex2 = 0;//Second element the user would like to exchange

    printf("Please enter in 10 integer values\n");


    //Input for 10 elements into array rgnUser_Array
    for(;nCounter <= 9; nCounter++)
    {
        printf("Please enter in integer value %d: ", nCounter+1);
        scanf("%d", &rgnUser_Input[nCounter]);

    }

    //Ask which two elements the user would like to exchange
    printf("\nPlease enter two indexes that you would like to exchange.\n\n");
    printf("Please enter the number of the first index you would like to change: ");
    scanf("%d", &nIndex1);
    printf("Please enter the number of the second index you would like to change: ");
    scanf("%d", &nIndex2);

    //Call function to swap elements that user prompts
    Swap_Elements(rgnUser_Input, nIndex1,nIndex2);

    //Print new array with swapped elements
    printf("\nCongratulations, you've successfuly swapped elements %d and %d \n", nIndex1, nIndex2);
        for(nCounter=0;nCounter <= 9; nCounter++)
    {
        printf("Element[%d] is now: %d\n", nCounter+1, rgnUser_Input[nCounter]);

    }

    return 0;
}
