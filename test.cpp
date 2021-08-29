#include <stdio.h>
#include <string.h>
#include "strlibMy.h"

int main()
{
    //printf ("123");
    char stringTest[] = "23000000";
    char stringTest2[200] = "CHECK111";

    strncatMy (stringTest2, stringTest, 4);
    char *p = strchrMy (stringTest2, '\0');

    printf ("%s\n%s\n%ld\n", stringTest, stringTest2,  p - stringTest2);
    return 0;
}



