#include <time.h>
#include <stdio.h>

int main()
{
    time_t nowtime;
    struct tm *ptr_time;
    char buffer[15];

    //Get the current time
    time(&nowtime);

    //localtime returns a pointer to a tm structure
    ptr_time = localtime(&nowtime);

    //Convert time to specific string
    strftime(buffer, 15, “%d/%m/%Y”, ptr_time);
    printf(“%s\n”, buffer);

    //or the day and month turned around
    strftime(buffer, 15, “%m/%d/%Y”, ptr_time);
    printf(“%s\n”, buffer);

    return 0;
}
