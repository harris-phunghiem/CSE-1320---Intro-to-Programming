#include <stdio.h>

int main(void)
{
    // Example 3
    FILE *file;
    char szInput[100];
    int i;
    file = fopen("test.txt", "a");
    if (file == NULL)
    {
        printf("An error occurs when opening the file");
        return 1;
    }
    fgets(szInput, 100, stdin);

    printf("%s", szInput);
    for (i = 0; i < strlen(szInput); i++)
    {
        if (szInput[i] != '\n')
            putc(szInput[i], file);
    }

    fclose(file);

    return 0;

}
