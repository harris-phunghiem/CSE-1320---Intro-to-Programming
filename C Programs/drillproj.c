#include <Windows.h>
#include <stdio.h>

int T_Time()

void main()
{
	SYSTEMTIME str_t;
	GetSystemTime(&str_t);

	printf("The date is: %d-%d-%d\nThe time is: %d:%d\n\n\n",str_t.wMonth,str_t.wDay,str_t.wYear,str_t.wHour,str_t.wMinute);

	int nStop = 0;
    int nStart = 0;
    int nTotal_Time = 0;
    int nInput = 0;

    printf("Type 1 to start drilling");
    scanf("%d", &nInput);

    if(nInput == 1)
        nStart = str_t.wSecond;

    printf("%d seconds\n", nStart);

	SYSTEMTIME str_w;
	GetSystemTime(&str_w);

    printf("Type 2 to stop drilling");
    scanf("%d", &nInput);

    if(nInput == 2)
        nStop = str_w.wSecond;

    nTotal_Time = nStop - nStart

    int nTotal_Hours=0, nTotal_Minutes =0, nTotal_Seconds=0;

    T_Time(

    printf("%d seconds\n", nStop);
    printf("Total time of drilling: %d", nTotal_Time);

}
