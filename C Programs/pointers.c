/* Practice stuff on pointers and pointer arrays*/

#include <stdio.h>

int main(void)
{
/*
    char szString[] = "This is a String.";
    char *pszString = szString;
    char *pszPointer = szString;

    int i=0;

    for(i=0; i < strlen(szString);i++)
    {
        printf("%c %c %c\n",
               pszString[i], //pszString points to szString, and outputs i element
               *(pszString+i),//dereferencing a pointer. calls the value of the pointer
               *pszPointer);//dereference a pointer, while added to an element to the memory spot
        pszPointer++;
    }

*/
/*
    char *szString[] = {{"Hello"},{"Goodbye"}, {"Later"}};

    printf("%p is the memory address of szString\n", &szString);
    printf("%s is the first value of *szString which is Hello\n", *szString) ;
    printf("%s of *(szString+1) will print out Goodbye\n", *(szString+1));
    printf("%s of (*szString)+1 will print out ello\n", (*szString)+1) ;
    printf("%c \n", *(szString[1]+0)) ;


    szString[0] = "Hallelujah";

    printf("%s is the first value of *szString which is element 0 or szString[0]\n", *szString) ;
*/




    int a; //Integer allocates 2 bytes
    int b=10;
    float c=5.0;

    printf("%p is the address of the variable a\n", &a);
    printf("%p is the address of the variable b\n", &b);
    printf("%p is the address of the variable c\n", &c);


    int *p1; //the asterisk makes it a pointer, so this contains an address
    p1 = &a; //p1 pointer variable stores the address(&) of a

    p1 = 5;

    printf("%p is the address of a\n", p1);//will return memory address of a
    printf("The value of p1 is %d\n", *p1);//will return value of a

    int *p2 = &b;

    printf("%p is the address of b\n", p2);
    printf("The value of p2 is %d\n", *p2);

    float *p3 = &c;

    printf("%p is the address of c\n", p3);
    printf("The value of c is %1.3f\n", *p3);

    //How do we add a & b with pointers?

    printf("The sum of a and b is: %d\n", *p1 + *p2);


    char movie1[] = "The Dark Knight: Returns";

    char *movie2 = "Batman and Robin";

    printf("%s is movie1\n%s is movie2\n", *(&movie1), *(&movie2));

    movie2 = "This is a new movie";

    puts(movie2);

    return 0;

}
