#include <stdio.h>
#include <iostream>

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

    ///////
    do
    {
        checkPtr = fgets (arrayText + i, MAXLINE, file);
        (*rows)++;
        i += MAXLINE;
    }
    while (checkPtr != nullptr);
    ///////

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

int putsMy (char* str)
{
    int character = 0;
    int counter = 0;

    do
    {
        character = putchar (str [counter]);
        counter++;
    }
    while (character != '\0');

    putchar ('\n');

    return (ferror (stdout)) ? EOF : 0;
}


