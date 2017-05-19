#include <stdio.h>
#include <stdlib.h>

int dayLegalityCheck(int month1, int day1, int year1);

void main()
{

    //add a minimal and maximum year for realism
    int minYear = 2015;
    int maxYear = 2099;


    //set a value not equal to 1 or 0 intentionally for testing
    int result = 10;
    int year = 1981;  //debugging year manually chosen
    char lolSpace;  //for catching stray newlines
    int month1, day1, year1, month2, day2, year2;

    printf("Please enter the following information in numerical format: \n");

    while (1)
    {

        printf("\nCheck out year (YYYY) ");
        scanf("%d%c",&year1,&lolSpace);

        if (year1 < minYear || year1 > maxYear)
        {
            printf("Sorry, year is out of bounds.  Are you a time traveler, perhaps? Go back to a reasonable year.\n");
            continue;
        }
        break;

    }


    while (1)
    {
        printf("Check out month (MM) ");
        scanf("%d%c",&month1,&lolSpace);
        if (month1 < 1 || month1 >12)
        {
            printf("Invalid month.  Try again.\n");
            continue;
        }
        break;
    }

    while (1)
    {
        printf("\nCheck out day (DD) ");
        scanf("%d%c",&day1,&lolSpace);

        if (dayLegalityCheck(month1,day1,year1) == 0)
        {
            printf("This day cannot exist on this month.");
            continue;
        }
        break;
    }

        printf("%d %d %d",month1,day1,year1);


    printf("Due month (MM) ");
    scanf("%d%c",&month2,&lolSpace);
    printf("\nDue day (DD) ");
    scanf("%d%c",&day2,&lolSpace);
    printf("\nDue year (YYYY) ");
    scanf("%d%c",&year2,&lolSpace);
    printf("%d %d %d",month2,day2,year2);


}

int dayLegalityCheck(int month1, int day1, int year1)
{
    //takes care of months that are supposed to have 31 days
    if ( (month1 == 1 || month1 ==  3 || month1 ==  5, month1 ==  7, month1 ==  8, month1 ==  10, month1 ==  12) && ( day1 > 0 && day1 < 32) )
        return 1;

    //takes care of months that are supposed to have 30 days
    else if ( (month1 == 4 || month1 ==  6 || month1 ==  9, month1 ==  11) && ( day1 > 0 && day1 < 31) )
        return 1;

    //takes care of February
    else if ( (month1 == 2))
    {
        //leap year feb 29
        if (day1 == 29 && year1%4 == 0)
            return 1;

        //feb 29 on a non leap year
        else if (day1 == 29 && year1%4 !=0)
            return 0;

        //any other legal day in february
        else if (day1 > 0 && day1 < 29)
            return 1;

        //all other results (less than 1 or greater than 29)
        else return 0;
    }

    //all other results are automatically illegal
    else return 0;
}
