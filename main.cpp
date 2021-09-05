#include <stdio.h>
#include <iostream>
#include "myAssert.h"
#include "strlibMy.h"
#include "qsort.h"

const int MAXROWLENGTH = 100;
const int MAXROW = 27000;



//void printText (char* text[], int rows);

int readFile (char *arrayText[], FILE* file, int* rows);

void arrayFree (char *arrayText[], size_t arraySize);

int cmpstr (void* v1, void* v2);

int main()
{
    FILE *input = nullptr;
    input = fopen ("input.txt", "rb");

    int rows = 0;
    char *arrayTextTest [MAXROW] = {0};

    if (readFile (arrayTextTest, input, &rows) == 0)
        perror ("An error in function readFile");
    else
    {
        qsortMy ((void**)arrayTextTest, 0, rows-1, cmpstr);
        printText (arrayTextTest, rows);
    }

    arrayFree (arrayTextTest, rows);
    fclose (input);

    return 0;
}

int readFile (char *arrayText[], FILE* file, int *row)
{
    *row = 0;
    while (*row < MAXROW)
    {
        size_t bufferSize = 25;
        char* strBuffer = (char*)calloc (bufferSize, sizeof(char));
        getline (&strBuffer, &bufferSize, file);

        if (feof (file))
            break;

        *(arrayText + *row) = strBuffer;
        //printf ("text: %s", *(arrayText + *row));
        (*row)++;
    }

    return (ferror (file)) ? 0 : EOF;
}

 /*void printText (char* text[], int rows)
{
    for (int counter = 0; counter < rows;  counter++)
        printf ("%s", text [counter]);
} */

void arrayFree (char *arrayText[], size_t arraySize)
{

    for (size_t i = 0; i < arraySize; i++)
        {
        if (arrayText[i])
            free (arrayText [i]);
        }
}

int cmpstr (void* v1, void* v2)
{
    //printf ("enter cmpstr\n");
    //printf ("v2 = %s", (char*)v2);

    char *a1 = (char*)v1;
    char *a2 = (char*)v2;

    return strcmpMy(a1, a2);
}












