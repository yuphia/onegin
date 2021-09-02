#include <stdio.h>
#include <iostream>
#include "myAssert.h"
#include "strlibMy.h"

const int MAXLINE = 100;
const int MAXROW = 27000;



void printText (char* text[], int rows);

int readFile (char *arrayText[], FILE* file, int* rows);

void arrayFree (char *arrayText[], size_t arraySize);

int main()
{
    FILE *input = nullptr;
    input = fopen ("input.txt", "r");

    int rows = 0;
    char *arrayTextTest [MAXLINE] = {0};

    if (readFile (arrayTextTest, input, &rows) == 0)
        perror ("An error in function readFile");
    else
        printText (arrayTextTest, rows);

    arrayFree (arrayTextTest, rows);
    fclose (input);

    return 0;
}

int readFile (char *arrayText[], FILE* file, int *row)
{
    *row = 0;
    while (true)
    {
        getline (arrayText + *row, 0, file);
        (*row)++;
    }

    return (ferror (file)) ? 0 : EOF;
}

 void printText (char* text[], int rows)
{
    for (int counter = 0; counter < rows;  counter++)
    {
        printf ("%s\n", text [counter]);
    }
}

void arrayFree (char *arrayText[], size_t arraySize)
{

    for (size_t i = 0; i < arraySize; i++)
        {
        if (arrayText[i])
            free (arrayText [i]);
        }
}














