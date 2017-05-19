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
    float fPrice;
    int nYear_Published; //MMYY
    int nAvailability; //0 for no, 1 for yes
    char szCustomer[100]; //Customer that checked out book

}Book;

//Array of structures. Max of 50 books
Book book[50];
int bookTracker[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

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
    int i,b=0;
    for(i=0;i<=49;i++)
    {
        if( book[i].nAvailability == 1 || book[i].nAvailability == 0 )
        {
            printf("Book Name: %-30s   Book # %d\n\n", book[i].szBook_Name, i+1);
            printf("%-14s%-10s%-20s%-30s\n", "ISBN", "Type", "Publisher", "Customer");
            printf("%-14s%-10s%-20s%-30s\n\n", book[i].szISBN, book[i].szType, book[i].szPublisher, book[i].szCustomer);
            printf("%-10s%8s%18s%16s\n", "Pages", "Cost","Availability", "Due Date");
            printf("%-14d$%5.2f", book[i].nPages, book[i].fPrice);
            if(book[i].nAvailability == 1)
                printf("\tYES\t\t");
            if(book[i].nAvailability == 0)
                printf("\tNO\t\t");
            printf("%6d/%2d/%4d\t \n\n\n",due[i].nDay,due[i].nMonth,due[i].nYear,book[i].nAvailability,i+1);
            printf("---------------------------------------------------------------------\n");
            b=1;

        }
    }
    if(b == 0)
        printf("Sorry! There are no books in the system\n\n\n");

}

void Remove_Book(int a)
{
    strcpy(book[a-1].szISBN, "a");
    book[a-1].nAvailability = -1;
}

int Show_Removable_Books(int z)
{
    system("cls");
    int i,b = 1;
    for(i=0;i<=49;i++)
    {
        if(book[i].nAvailability == 1 || book[i].nAvailability == 0)
        {
            printf("Book #%d - %-35s is available to be removed.\n",i+1,book[i].szBook_Name);
            b = 0;
        }
    }
    if(b==1)
    {
        printf("Sorry! There are no books in the system.\n\n");
        return 2;
    }
    printf("\n\n\n");
}

void Check_Out(int a)
{
    getchar();
    char Input[50] = "";
    book[a-1].nAvailability = 0;
    printf("Who rented the book?: ");
    if (fgets(Input, sizeof Input, stdin) != NULL)
    {
        int len = strlen(Input);
        if (len > 0 && Input[len-1] == '\n') {
            Input[--len] = '\0';
        }
    }

    strcpy(book[a-1].szCustomer,Input);

        FILE * file= fopen("libData", "wb");
    if (file != NULL)
    {
        fwrite(book, sizeof(book[0]), 50, file);
        fclose(file);
    }

    FILE * file1= fopen("DueDates", "wb");
    if (file1 != NULL)
    {
        fwrite(due, sizeof(due[0]), 50, file1);
        fclose(file1);
    }
}

void Check_In(int a)
{
    book[a-1].nAvailability = 1;
    strcpy(book[a-1].szCustomer, "");
    FILE * file= fopen("libData", "wb");
    if (file != NULL)
    {
        fwrite(book, sizeof(book[0]), 50, file);
        fclose(file);
    }

    FILE * file1= fopen("DueDates", "wb");
    if (file1 != NULL)
    {
        fwrite(due, sizeof(due[0]), 50, file1);
        fclose(file1);
    }
}

int Show_Checkedout_Books(int z)
{
    system("cls");
    int i,b=0;
    for(i=0;i<=49;i++)
    {
        if( book[i].nAvailability == 0 )
        {
            printf("Book Name: %-30s   Book # %d\n\n", book[i].szBook_Name, i+1);
            printf("%-14s%-10s%-20s%-30s\n", "ISBN", "Type", "Publisher", "Customer");
            printf("%-14s%-10s%-20s%-30s\n\n", book[i].szISBN, book[i].szType, book[i].szPublisher, book[i].szCustomer);
            printf("%-10s%8s%18s%16s\n", "Pages", "Cost","Availability", "Due Date");
            printf("%-14d$%5.2f", book[i].nPages, book[i].fPrice);
            if(book[i].nAvailability == 1)
                printf("\tYES\t\t");
            if(book[i].nAvailability == 0)
                printf("\tNO\t\t");
            printf("%6d/%2d/%4d\t \n\n\n",due[i].nDay,due[i].nMonth,due[i].nYear,book[i].nAvailability,i+1);
            printf("---------------------------------------------------------------------\n");
            b=1;

        }
    }
    if(b == 0)
    {
        printf("There are no books that have been checked out\n\n\n");
        return 2;
    }
}

int Show_Checkedin_Books(int z)
{
    system("cls");
    int i,b=1;
    for(i=0;i<=49;i++)
    {
        if(book[i].nAvailability == 1)
        {
            printf("Book#[%d]\t%s\t is available.\n",i+1,book[i].szBook_Name);
            b=0;
        }
    }
    if(b==1)
    {
        printf("No books are available to be checked out.\n\n");
        return 2;
    }
    printf("\n\n\n");
}



int main(void)
{
    //Initialize all book ISBNS to null to show availability and set all book availability to -1
    int flag = 0;
    int b=0;
    for(b=0; b<=49; b++)
    {
        strcpy(book[b].szISBN, "a");
        book[b].nAvailability = -1;
    }

    //force load of file, if it exists
        FILE * file= fopen("libData", "rb");
        if (file != NULL)
        {
            flag = 1;
            fread(&book, sizeof(book[0]), 50, file);
            fclose(file);
        }
        FILE * file1= fopen("DueDates", "rb");
        if (file1 != NULL)
        {
            flag = 1;
            fread(&due, sizeof(due[0]), 50, file1);
            fclose(file1);
        }


    //Ask which book the user would like to input/edit
    int nBook_Selection=0;

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
        printf("\n\nPlease enter in a selection from the menu: ");
        scanf("%d", &nMenu_Selection);
        switch(nMenu_Selection)
        {
            case 1:
            {
                getchar();


                printf("What is the book ISBN? ");
                if (fgets(szUser_Input, sizeof szUser_Input, stdin) != NULL)
                {
                    int len = strlen(szUser_Input);
                    if (len > 0 && szUser_Input[len-1] == '\n') {
                        szUser_Input[--len] = '\0';
                    }
                }
                strcpy(book[nBook_Selection].szISBN,szUser_Input);


                printf("What is the book name? ");
                if (fgets(szUser_Input, sizeof szUser_Input, stdin) != NULL)
                {
                    int len = strlen(szUser_Input);
                    if (len > 0 && szUser_Input[len-1] == '\n') {
                        szUser_Input[--len] = '\0';
                    }
                }
                strcpy(book[nBook_Selection].szBook_Name,szUser_Input);

                printf("What is the book type? ");
                if (fgets(szUser_Input, sizeof szUser_Input, stdin) != NULL)
                {
                    int len = strlen(szUser_Input);
                    if (len > 0 && szUser_Input[len-1] == '\n') {
                        szUser_Input[--len] = '\0';
                    }
                }
                strcpy(book[nBook_Selection].szType,szUser_Input);

                printf("Who is the book publisher? ");
                if (fgets(szUser_Input, sizeof szUser_Input, stdin) != NULL)
                {
                    int len = strlen(szUser_Input);
                    if (len > 0 && szUser_Input[len-1] == '\n') {
                        szUser_Input[--len] = '\0';
                    }
                }
                strcpy(book[nBook_Selection].szPublisher,szUser_Input);

                printf("How many pages are in the book? ");
                scanf("%d", &book[nBook_Selection].nPages);

                printf("How much does the book cost? ");
                scanf("%f", &book[nBook_Selection].fPrice);


                printf("What day is it due? ");
                scanf("%d", &due[nBook_Selection].nDay);
                printf("What month is it due? ");
                scanf("%d", &due[nBook_Selection].nMonth);
                printf("What year is it due? ");
                scanf("%d", &due[nBook_Selection].nYear);

                system("cls");
                book[nBook_Selection].nAvailability = 1;

                FILE * file= fopen("libData", "wb");
                if (file != NULL)
                {
                    fwrite(book, sizeof(book[0]), 50, file);
                    fclose(file);
                }

                FILE * file1= fopen("DueDates", "wb");
                if (file1 != NULL)
                {
                    fwrite(due, sizeof(due[0]), 50, file1);
                    fclose(file1);
                }

                printf("Congrats! You've successfully entered a book.\n\n\n");
                break;
            }
            case 2:
            {
                int x;
                x = Show_Removable_Books(x);
                    if(x==2)
                        break;
                printf("What book # would you like to remove?");
                scanf("%d", &nBook_Selection);
                Remove_Book(nBook_Selection);
                printf("You have successfully removed Book %d", nBook_Selection);
                system("cls");
                break;
            }
            case 3:
            {
                int y;
                y = Show_Checkedin_Books(y);
                    if(y==2)
                        break;
                printf("What book would you like to check out?");
                scanf("%d", &nBook_Selection);
                Check_Out(nBook_Selection);
                break;
            }
            case 4:
            {
                int z;
                z = Show_Checkedout_Books(z);
                    if(z==2)
                        break;
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
                int e;
                e = Show_Checkedout_Books(e);
                break;
            }
            case 7:
                exit(0);
        }
    }while(1);
    return 0;
}
