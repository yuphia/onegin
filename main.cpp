#include <stdio.h>
#include <iostream>
#include "myAssert.h"
#include "strlibMy.h"

const int MAXLINE = 100;
const int MAXROW = 27000;

void printText (char* text, int rows);

int readFile (char *arrayText, FILE* file, int* rows);

int putsMy (char* str);


int main()
{
    FILE *input = nullptr;
    input = fopen ("input.txt", "r");

    int rows = 0;
    char arrayText [MAXLINE*MAXROW] = {0};

    if (readFile (arrayText, input, &rows) == 0)
        perror ("An error in function readFile");
    else
        printText (arrayText, rows);

    fclose (input);

    return 0;
}

int readFile (char *arrayText, FILE* file, int *rows)
{
    char *checkPtr = nullptr;
    *rows = 0;
    int i = 0;

    char *pointer = NULL;
    ///////
    int lineMaxSize = MAXLINE;

    do
    {
        checkPtr = fgetsMy (arrayText + i, MAXLINE, file);

        pointer = arrayText + i;
        //getlineMy (&pointer, &lineMaxSize, file);

        (*rows)++;
        i += MAXLINE;
    }
    while (checkPtr != nullptr);
    ///////
    //free (pointer);

    return (ferror (file)) ? 0 : EOF;
}

 void printText (char* text, int rows)
{
    int checkPutsOutput = 0, currentRow = 0;

    for (int counter = 0; currentRow <= rows; currentRow++, counter += MAXLINE)
    {
        checkPutsOutput = putsMy (text + counter);
    }
}
















