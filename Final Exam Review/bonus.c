/*Homework 8
By Harris Nghiem
Linked List modification to Library Manager*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


struct book
{
    int nodeEmpty;  //determines whether the node has data or not (mainly useful for node 1)
    int entryNumber;  //which node is it in the list?  Useful for when you want to delete/check a node
    char szISBN[100];
    char szBook_Name[100];
    char szType[100];
    char szPublisher[100];
    int nPages;
    float fPrice;
    int nYear_Published; //MMYY
    int nAvailability; //0 for no, 1 for yes; also known as 'checked out'
    char szCustomer[100]; //Customer that checked out book
    int nDays_Left;
    char dueDate[8];
    struct book *next;
};

void printBooks(struct book *structRoot);
void addBooks(struct book *structRoot);
void deleteBooks(struct book *structRoot);
void checkOutBooks(struct book *structRoot);
void checkInBooks(struct book *structRoot);
void printCheckedBooks(struct book *structRoot, int inOrOut);  //this one has two parameters to let the function serve as a printer for both checked in and checked out
void enumerateList(struct book *structRoot);


void main()
{
    int flag = 0; //if flag equals 1, it means the node was already modified and may not be modified any more in this instance
    struct book *root;
    struct book *currentNode;
    char lolNewLine;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("It is currently: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

    //load data here


    //if there is no existing data (as determined by flag), create a root node

    if (flag == 0)
    {
        root = (struct book*)malloc(sizeof(struct book));
        root -> nodeEmpty = 1;
        root -> next = NULL;
    }


    //creates a menu array
        char *rgnMenu[500] = {
            "1. Add a new book",
            "2. Remove a book",
            "3. Check out a book",
            "4. Check in a book",
            "5. Display all available book details",
            "6. Display all checked-out books",
            "7. Display all checked-in books",
            "8. Exit program"};
        do
        {
            //Display the menu to the user
            int i;
            printf("MENU:\n");
            for(i=0;i<8;i++)
            {
                printf("%s\n", *(rgnMenu+i));
            }

            //Asks for user input from menu
            int nMenu_Selection =0;
            char szUser_Input[100] = "";
            printf("\n\nPlease enter in a selection from the menu: ");
            scanf("%d", &nMenu_Selection);
            switch(nMenu_Selection)
            {
                case 1:
                {
                    addBooks(root);
                    break;
                }

                case 2:
                {
                    deleteBooks(root);
                    break;

                }

                case 3:
                {
                    checkOutBooks(root);
                    break;
                }

                case 4:
                {
                    checkInBooks(root);
                    break;
                }
                case 5:
                {
                    printBooks(root);
                    break;
                }
                case 6:
                {
                    printCheckedBooks(root,1);
                    break;
                }
                case 7:
                {
                    printCheckedBooks(root,0);
                    break;
                }

                case 8:
                {
                    printf("Exited.\n");
                    return;
                }
            }
        }while(1);
}

void addBooks(struct book *structRoot)
{
    enumerateList(structRoot);
    struct book *currentNode;
    currentNode = structRoot;
    int flag = 0;  //if flag is equal to 1, we assume that the data has already been added earlier, and thus we no longer work with it in this instance
    char szUser_Input[100] = "";

    //if there is only one node, and that node is flagged as being empty,
    //we will want to fill the root node first
    if (currentNode -> next == NULL && currentNode ->nodeEmpty == 1)
    {
        currentNode -> nodeEmpty = 0;
        flag = 1;//mark the node as being used
        getchar();
        printf("What is the FIRST book's ISBN? ");
        if (fgets(szUser_Input, sizeof szUser_Input, stdin) != NULL)
        {
            int len = strlen(szUser_Input);
            if (len > 0 && szUser_Input[len-1] == '\n') {
                szUser_Input[--len] = '\0';
            }
        }
        strcpy(currentNode->szISBN,szUser_Input);
        printf("What is the book name? ");
        if (fgets(szUser_Input, sizeof szUser_Input, stdin) != NULL)
        {
            int len = strlen(szUser_Input);
            if (len > 0 && szUser_Input[len-1] == '\n') {
                szUser_Input[--len] = '\0';
            }
        }
        strcpy(currentNode->szBook_Name,szUser_Input);

        printf("What is the book type? ");
        if (fgets(szUser_Input, sizeof szUser_Input, stdin) != NULL)
        {
            int len = strlen(szUser_Input);
            if (len > 0 && szUser_Input[len-1] == '\n') {
                szUser_Input[--len] = '\0';
            }
        }
        strcpy(currentNode->szType,szUser_Input);

        printf("Who is the book publisher? ");
        if (fgets(szUser_Input, sizeof szUser_Input, stdin) != NULL)
        {
            int len = strlen(szUser_Input);
            if (len > 0 && szUser_Input[len-1] == '\n') {
                szUser_Input[--len] = '\0';
            }
        }
        strcpy(currentNode->szPublisher,szUser_Input);

        printf("How many pages are in the book? ");
        scanf("%d", &currentNode->nPages);

        printf("How much does the book cost? ");
        scanf("%f", &currentNode->fPrice);

        currentNode->nAvailability = 1;
        currentNode -> next = NULL;
        system("cls");
        printf("****Book added successfully.****\n");
    }

    else if(currentNode -> next == NULL && currentNode ->nodeEmpty == 0)
    {
        structRoot-> next = (struct book*)malloc(sizeof(struct book));
        currentNode = structRoot->next; //there are now two structs in the list, and is currently 'focusing' on the second one
        currentNode -> nodeEmpty = 0;
        flag = 1;//mark the node as being used
        getchar();
        printf("What is the second book's ISBN? ");
        if (fgets(szUser_Input, sizeof szUser_Input, stdin) != NULL)
        {
            int len = strlen(szUser_Input);
            if (len > 0 && szUser_Input[len-1] == '\n') {
                szUser_Input[--len] = '\0';
            }
        }
        strcpy(currentNode->szISBN,szUser_Input);
        printf("What is the book name? ");
        if (fgets(szUser_Input, sizeof szUser_Input, stdin) != NULL)
        {
            int len = strlen(szUser_Input);
            if (len > 0 && szUser_Input[len-1] == '\n') {
                szUser_Input[--len] = '\0';
            }
        }
        strcpy(currentNode->szBook_Name,szUser_Input);

        printf("What is the book type? ");
        if (fgets(szUser_Input, sizeof szUser_Input, stdin) != NULL)
        {
            int len = strlen(szUser_Input);
            if (len > 0 && szUser_Input[len-1] == '\n') {
                szUser_Input[--len] = '\0';
            }
        }
        strcpy(currentNode->szType,szUser_Input);

        printf("Who is the book publisher? ");
        if (fgets(szUser_Input, sizeof szUser_Input, stdin) != NULL)
        {
            int len = strlen(szUser_Input);
            if (len > 0 && szUser_Input[len-1] == '\n') {
                szUser_Input[--len] = '\0';
            }
        }
        strcpy(currentNode->szPublisher,szUser_Input);

        printf("How many pages are in the book? ");
        scanf("%d", &currentNode->nPages);

        printf("How much does the book cost? ");
        scanf("%f", &currentNode->fPrice);

        currentNode->nAvailability = 1;

        currentNode -> next = NULL;
        system("cls");
        printf("****Book added successfully.****\n");
    }

    //if we did not have an empty root, then we want to move to the end of the list
    while(currentNode -> next != NULL && flag == 0)
    {
        printf("iterating through list.\n");
        currentNode = currentNode -> next;

    }

    if (flag == 0)
    {
        currentNode-> next = (struct book*)malloc(sizeof(struct book));
        currentNode = currentNode -> next;
        currentNode -> nodeEmpty = 0;
        flag = 1;//mark the node as being used
        getchar();
        printf("What is the book ISBN? ");
        if (fgets(szUser_Input, sizeof szUser_Input, stdin) != NULL)
        {
            int len = strlen(szUser_Input);
            if (len > 0 && szUser_Input[len-1] == '\n') {
                szUser_Input[--len] = '\0';
            }
        }
        strcpy(currentNode->szISBN,szUser_Input);
        printf("What is the book name? ");
        if (fgets(szUser_Input, sizeof szUser_Input, stdin) != NULL)
        {
            int len = strlen(szUser_Input);
            if (len > 0 && szUser_Input[len-1] == '\n') {
                szUser_Input[--len] = '\0';
            }
        }
        strcpy(currentNode->szBook_Name,szUser_Input);

        printf("What is the book type? ");
        if (fgets(szUser_Input, sizeof szUser_Input, stdin) != NULL)
        {
            int len = strlen(szUser_Input);
            if (len > 0 && szUser_Input[len-1] == '\n') {
                szUser_Input[--len] = '\0';
            }
        }
        strcpy(currentNode->szType,szUser_Input);

        printf("Who is the book publisher? ");
        if (fgets(szUser_Input, sizeof szUser_Input, stdin) != NULL)
        {
            int len = strlen(szUser_Input);
            if (len > 0 && szUser_Input[len-1] == '\n') {
                szUser_Input[--len] = '\0';
            }
        }
        strcpy(currentNode->szPublisher,szUser_Input);

        printf("How many pages are in the book? ");
        scanf("%d", &currentNode->nPages);

        printf("How much does the book cost? ");
        scanf("%f", &currentNode->fPrice);

        currentNode->nAvailability = 1;

        currentNode -> next = NULL;
        system("cls");
        printf("****Book NUMBER 3 added successfully.****\n");
    }


}

void deleteBooks(struct book *structRoot)
{
    enumerateList(structRoot);
    struct book *currentNode;
    currentNode = structRoot;
    int userInput;
    char lolSpace;
    int i = 0;




    currentNode = structRoot;

    //if there is one node
    if (currentNode -> next == NULL && currentNode -> nAvailability == 0 )
    {
        currentNode->nodeEmpty = 1;
        printf("The list is already empty.\n");
        return;
    }

       while(1)
    {
        printf("What book would you like to delete?  (Type 0 for list.)");
        scanf("%d%c",&userInput,&lolSpace);
        if(userInput == 0)
        {
            printBooks(structRoot);
            continue;
        }
        else
        {
            break;
        }
    }

    //delete first node if two or more nodes exist
    if (userInput == 1 && structRoot -> next != NULL)
    {
        currentNode -> nodeEmpty  = currentNode -> next -> nodeEmpty;
        currentNode -> entryNumber = currentNode -> next -> entryNumber;
        strcpy(currentNode -> szISBN,currentNode -> next -> szISBN);
        strcpy(currentNode -> szBook_Name , currentNode -> next -> szBook_Name);
        strcpy(currentNode -> szType , currentNode -> next -> szType);
        strcpy(currentNode -> szPublisher , currentNode -> next -> szPublisher) ;
        currentNode -> nPages = currentNode -> next -> nPages;
        currentNode -> fPrice = currentNode -> next -> fPrice ;
        currentNode -> nYear_Published = currentNode -> next -> nYear_Published ; //MMYY
        currentNode -> nAvailability = currentNode -> next -> nAvailability ; //0 for no, 1 for yes; also known as 'checked out'
        strcpy(currentNode -> szCustomer , currentNode -> next -> szCustomer); //Customer that checked out book
        currentNode -> nDays_Left = currentNode -> next -> nDays_Left;
        strcpy(currentNode -> dueDate , currentNode -> next -> dueDate );
        structRoot-> next = structRoot -> next -> next;

        printf("Deleted!\n");
    }

    //delete 2nd node or higher
    if (userInput != currentNode->entryNumber &&  currentNode!= NULL )
    {
        while (userInput-1 != currentNode -> entryNumber)
        {
            currentNode = currentNode -> next;
        }

        currentNode -> nodeEmpty  = currentNode -> next -> nodeEmpty;
        currentNode -> entryNumber = currentNode -> next -> entryNumber;
        strcpy(currentNode -> szISBN,currentNode -> next -> szISBN);
        strcpy(currentNode -> szBook_Name , currentNode -> next -> szBook_Name);
        strcpy(currentNode -> szType , currentNode -> next -> szType);
        strcpy(currentNode -> szPublisher , currentNode -> next -> szPublisher) ;
        currentNode -> nPages = currentNode -> next -> nPages;
        currentNode -> fPrice = currentNode -> next -> fPrice ;
        currentNode -> nYear_Published = currentNode -> next -> nYear_Published ; //MMYY
        currentNode -> nAvailability = currentNode -> next -> nAvailability ; //0 for no, 1 for yes; also known as 'checked out'
        strcpy(currentNode -> szCustomer , currentNode -> next -> szCustomer); //Customer that checked out book
        currentNode -> nDays_Left = currentNode -> next -> nDays_Left;
        strcpy(currentNode -> dueDate , currentNode -> next -> dueDate );
        structRoot-> next = structRoot -> next -> next;
        return;
    }


}



void printBooks(struct book *structRoot)
{

    struct book *currentNode;
    currentNode = structRoot;
    int i = 1;

    if (currentNode->nodeEmpty == 1)
    {
        system("cls");
        printf("There are no books to show, silly.\n");
        return;
    }

    while (currentNode != NULL)
    {
        printf("Book number: %d\n",i);
        printf("Yer title is \"%s\".\n\n",currentNode->szBook_Name);
        printf("Book ISBN is: %s\n",currentNode->szISBN);
        printf("The publisher is: %s\n",currentNode->szPublisher);
        printf("Book costs $%.2f.\n",currentNode->fPrice);
        printf("Book has %d pages.\n",currentNode->nPages);

        if (currentNode -> nAvailability == 0)
        {
            printf("Due date is %s\n",currentNode->dueDate);
        }
        else
        {
            printf("Book is available.\n");
        }
        currentNode = currentNode -> next;
        i++;
    }
}

void enumerateList(struct book *structRoot)
{
    int i = 1;
    struct book *currentNode;
    currentNode = structRoot;

    while (currentNode != NULL)
    {
        currentNode->entryNumber = i;
        i++;
        currentNode = currentNode -> next;
    }

}

void checkOutBooks(struct book *structRoot)
{
    enumerateList(structRoot);
    struct book *currentNode;
    currentNode = structRoot;
    char lolSpace;
    int userInput;
    int i = 0;

    while(1)
    {
        printf("What book would you like to check out?  (Type 0 for list.)");
        scanf("%d%c",&userInput,&lolSpace);
        if(userInput == 0)
        {
            printBooks(structRoot);
            continue;
        }
        else
        {
            break;
        }
    }

    while (currentNode->entryNumber != userInput && currentNode != NULL)
    {

        currentNode = currentNode->next;

    }


    if (currentNode == NULL)
    {
        printf("An error occurred; returning to main menu to avoid potential damage.\n");
        return;
    }


    if (currentNode -> nAvailability != 0)
    {
        currentNode -> nAvailability = 0;
        printf("What is the due date?  Please type in the following format:  05142015\n");
        scanf("%s%c",&currentNode->dueDate,&lolSpace);
        printf("What is your name?\n");
        scanf("%s,%c",currentNode->szCustomer,&lolSpace);
        currentNode->nAvailability = 0;
        printf("Book checked out.\n");
        return;

    }
    else
    {
        printf("An error occurred; most likely, the book had been already checked out.\n");
        return;
    }

}

void checkInBooks(struct book *structRoot)
{
    enumerateList(structRoot);
    struct book *currentNode;
    currentNode = structRoot;
    char lolSpace;
    int userInput;
    int i = 0;

    while (1)
    {
        printf("Which book are we checking in?  (Type 0 for list)\n");
        scanf("%d%c", &userInput, &lolSpace);
        if (userInput == 0)
        {
            printBooks(structRoot);
            continue;
        }
        else break;
    }

    while (currentNode->entryNumber != userInput && currentNode != NULL)
    {
        currentNode = currentNode -> next;
    }
    if (currentNode == NULL)
    {
        printf("A fatal error has occurred; returning to main menu to avoid corruption.\n");
        return;
    }

    else
    {
        if (currentNode -> nAvailability == 0)
        {
            currentNode->nAvailability = 1;
            printf("BOOK HAS BEEN CHECKED IN.\n");
            return;
        }

        else if (currentNode -> nAvailability == 1)
        {
            printf("This book has already been checked in.\n");
            return;
        }
    }

}


void printCheckedBooks(struct book *structRoot, int inOrOut)
{
    struct book *currentNode;
    currentNode = structRoot;
    int i = 1;

    if (inOrOut == 0)  //print only checked IN books
    {
        system("cls");
        printf("***AVAILABLE/CHECKED IN BOOKS***\n");
        while (currentNode != NULL)
        {
            if (currentNode -> nAvailability == 1)
            {
                printf("Book %d",i);
                printf("%s\n\n",currentNode->szBook_Name);
            }
            currentNode = currentNode -> next;
            i++;
        }
    }

    if (inOrOut == 1)  //print only checked OUT books
    {
        system("cls");
        printf("***CHECKED OUT BOOKS***\n");
        while (currentNode != NULL)
        {
            if (currentNode -> nAvailability == 0)
            {
                printf("Book %d\n",i);
                printf("%s\n\n",currentNode->szBook_Name);
            }
            currentNode = currentNode -> next;
            i++;
        }
    }
}
