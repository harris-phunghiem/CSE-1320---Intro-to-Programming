/*Made by Harris
Homework 7 - Library Manager*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//Define structure of book
typedef Book
{
    long long szISBN[100];
    char szBook_Name[100];
    char szString[100];
    char szPublisher[100];
    int nPages;
    float fPRice;
    int nYear_Published; //MMYY
    int nAvailability; //0 for no, 1 for yes
    char szCustomer[100]; //Customer that checked out book

};


//Input for menu selection
int Menu_Input(int nMenu)
{
    while(1){
        printf("\n\nPlease enter a number as your selection: ");
        scanf("%d", &nMenu);
        if (nMenu < 0 || nMenu > 7)
            printf("Please enter another selection");
        else
            break;
    }
    return nMenu;
}

//Function to call other functions depending on Menu_Input
void Menu_Selector(int nMenu_Input)
{
    int nInput;
    nInput = nMenu_Input;

    switch(nInput)
    {
    case 1:
        Add_Book();//call to function Add a new book
 /*   case 2:
        Remove_Book();//Call to function Remove a book
    case 3:
        Checkout_Book();//Check out a book
    case 4:
        Checkin_Book();//Check in a book
    case 5:
        Display_Details();//Calls to function to Display all book details
    case 6:
        Available_Book_Details();//Calls to function to display all checked-out books
    case 7:
        Checkedout_Books();//Function to display all checked out books*/
    }
}

//Add a new book function
void Add_Book()
{

    printf("Please enter in the ISBN# for the new book ");
    scanf("%s", &book.szISBN);
    printf("%s is the ISBN\n", book.szISBN);

    char szUser_Input[100];
    printf("What is the name of the book? :");
    scanf(&szUser_Input);
    printf("%s is szUser_Input\n", szUser_Input);

    strcat(*book.szBook_Name,szUser_Input);
    printf("%s is name", *book.szBook_Name);

}

int main(void)
{
    //Menu for user to make changes to book depending on ISBN
    char *rgnMenu[500] = {
        "1. Add a new book",
        "2. Remove a book",
        "3. Check out a book",
        "4. Check in a book",
        "5. Display all available book details",
        "6. Display all checked-out books",
        "7. Exit program"};

    Book book[50];

    //Display the menu to the user
    int i;
    for(i=0;i<8;i++)
        printf("%s\n", *(rgnMenu+i));

    //Ask user for selection
    int nMenu_Input;    //Integer input for menu selection
    nMenu_Input = Menu_Input(nMenu_Input);//Stores input and checks if input is within range ( 0 < input < 8)
    printf("You have selected:\n\t%s\n", *(rgnMenu+(nMenu_Input-1)));

    //Function to call different functions of menu options
    Menu_Selector(nMenu_Input);

    return 0;

}

