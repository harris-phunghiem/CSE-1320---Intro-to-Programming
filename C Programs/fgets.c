#include <stdio.h>

//Define structure of book
typedef struct
{
    char szISBN[100];
    char szBook_Name[100];
    char szType[100];
    char szPublisher[100];
    int nPages;
    float fPRice;
    int nYear_Published; //MMYY
    int nAvailability; //0 for no, 1 for yes
    char szCustomer[100]; //Customer that checked out book

}Book;

//Array of structures. Max of 50 books
Book book[50];


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

    strcpy(book[0].szISBN,szUser_Input);

    printf("%s is the isbn", book[0].szISBN);
}
