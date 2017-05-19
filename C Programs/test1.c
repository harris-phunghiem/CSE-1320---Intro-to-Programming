/*Made by Harris
Homework 7 - Library Manager*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

//Date Structure
typedef struct
{
    int nDay;
    int nMonth;
    int nYear;
}Due;

Due due[50];
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

int Book_Availability(int nBook_Num)
{

    //Check to see which book is available
    //return that book number

    int i;
    for(i=0;i<49;i++)
    {
        if(!(strcmp(book[i].szISBN, "a")))
        {
            nBook_Num = i;
            break;
        }
        else
            continue;

    }

    return nBook_Num;

}

void Show_All()
{
    system("cls");
    int i;
    for(i=0;i<=49;i++)
    {
        if((strcmp(book[i].szISBN, "a")))
        {
            printf("%s\t is the isbn of book %i\n",book[i].szISBN,i+1);
            printf("%s\t is the book name of book%i\n",book[i].szBook_Name,i+1);
            printf("%s\t is the type of book %i\n",book[i].szType,i+1);
            printf("%s\t is the publisher of book %i\n",book[i].szPublisher,i+1);
            printf("%d\t is the availability of the book %i",book[i].nAvailability,i+1);
            printf("%2d/%2d/%4d\t is the due date of the book %i\n\n\n",due[i].nDay,due[i].nMonth,due[i].nYear,book[i].nAvailability,i+1);

        }
    }
}

void Remove_Book(int a)
{
    strcpy(book[a-1].szISBN, "a");
}

void Check_Out(int a)
{
    book[a-1].nAvailability = 0;
}

void Check_In(int a)
{
    book[a-1].nAvailability = 1;
}

void Show_Checkedout_Books()
{
    system("cls");
    int i,b = 1;
    for(i=0;i<=49;i++)
    {
        if(book[i].nAvailability == 0)
        {
            printf("Book#[%d]\t%s\t is checked out.\n",i+1,book[i].szBook_Name);
            b = 0;
        }
    }
    if(b==1)
        printf("No books have been checked out");
    printf("\n\n\n");
}

void Show_Checkedin_Books()
{
    system("cls");
    int i;
    for(i=0;i<=49;i++)
    {
        if(book[i].nAvailability == 1)
        {
            printf("Book#[%d]\t%s\t is available.\n",i+1,book[i].szBook_Name);

        }
    }
    printf("\n\n\n");
}



int main(void)
{
    //Initialize all book ISBNS to null to show availability
    int b=0;
    for(b=0; b<=49; b++)
    {
        strcpy(book[b].szISBN, "a");
        book[b].nAvailability = -1;
    }


    //Ask which book the user would like to input/edit
    int nBook_Selection=0;

    //Variable to keep looping
    do
    {



        //Shows menu to user
        char *rgnMenu[500] = {
            "1. Add a new book",
            "2. Remove a book",
            "3. Check out a book",
            "4. Check in a book",
            "5. Display all available book details",
            "6. Display all checked-out books",
            "7. Exit program"};

        //Display the menu to the user
        int i;
        for(i=0;i<8;i++)
        {
            printf("%s\n", *(rgnMenu+i));
        }

        //Checks to see if the book is available
        nBook_Selection = Book_Availability(nBook_Selection);
        //printf("now nBook_Selection is %d\n", nBook_Selection);

        //Asks for user input from menu
        int nMenu_Selection =0;
        char szUser_Input[100] = "";
        printf("Please enter in a selection: ");
        scanf("%d", &nMenu_Selection);
        switch(nMenu_Selection)
        {
            case 1:
            {
                getchar();


                printf("What is the book ISBN? :");
                if (fgets(szUser_Input, sizeof szUser_Input, stdin) != NULL)
                {
                    int len = strlen(szUser_Input);
                    if (len > 0 && szUser_Input[len-1] == '\n') {
                        szUser_Input[--len] = '\0';
                    }
                }
                strcpy(book[nBook_Selection].szISBN,szUser_Input);

                printf("What is the book name? :");
                if (fgets(szUser_Input, sizeof szUser_Input, stdin) != NULL)
                {
                    int len = strlen(szUser_Input);
                    if (len > 0 && szUser_Input[len-1] == '\n') {
                        szUser_Input[--len] = '\0';
                    }
                }
                strcpy(book[nBook_Selection].szBook_Name,szUser_Input);

                printf("What is the book type? :");
                if (fgets(szUser_Input, sizeof szUser_Input, stdin) != NULL)
                {
                    int len = strlen(szUser_Input);
                    if (len > 0 && szUser_Input[len-1] == '\n') {
                        szUser_Input[--len] = '\0';
                    }
                }
                strcpy(book[nBook_Selection].szType,szUser_Input);

                printf("Who is the book publisher? :");
                if (fgets(szUser_Input, sizeof szUser_Input, stdin) != NULL)
                {
                    int len = strlen(szUser_Input);
                    if (len > 0 && szUser_Input[len-1] == '\n') {
                        szUser_Input[--len] = '\0';
                    }
                }
                strcpy(book[nBook_Selection].szPublisher,szUser_Input);

                printf("What day is it due?");
                scanf("%d", &due[nBook_Selection].nDay);
                printf("What month is it due?");
                scanf("%d", &due[nBook_Selection].nMonth);
                printf("What year is it due?");
                scanf("%d", &due[nBook_Selection].nYear);

                system("cls");
                printf("This was for book%i\n", nBook_Selection+1);

                book[nBook_Selection].nAvailability = 1;

                printf("Congrats! You've successfully entered a book.\n\n\n");
                break;
            }
            case 2:
            {
                printf("What book would you like to remove?");
                scanf("%d", &nBook_Selection);
                Remove_Book(nBook_Selection);
                printf("You have successfully removed Book %d", nBook_Selection);
                system("cls");
                break;
            }
            case 3:
            {
                Show_Checkedin_Books();
                printf("What book would you like to check out?");
                scanf("%d", &nBook_Selection);
                Check_Out(nBook_Selection);
                break;
            }
            case 4:
            {
                Show_Checkedout_Books();
                printf("What book would you like to check in?");
                scanf("%d", &nBook_Selection);
                Check_In(nBook_Selection);
                break;
            }
            case 5:
            {
                Show_All();
                break;
            }
            case 6:
            {
                Show_Checkedout_Books();
                break;
            }
            case 7:
                exit(0);
        }
    }while(1);
    return 0;
}
