#include <stdio.h>
#include <iostream>
#include "strlibMy.h"
#include "sort.h"
#include <cstring>

const int MAXROWLENGTH = 100;
const int MAXROW = 27000;//27000;


int readFile (char *arrayText[], FILE* file, int* rows);

void arrayFree (char *arrayText[], size_t arraySize);

int comparatorStr (const void* v1, const void* v2);

bool checkSortStr (void **array, int size);

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
        printText (arrayTextTest, rows);
        printf ("\n");

        //qsort ((void*)arrayTextTest, rows, sizeof (char*), comparatorStr);
        quicksort ((void*)arrayTextTest, 0, rows - 1, sizeof (char*), comparatorStr);

        printText (arrayTextTest, rows);
    }

    printf ("%d\n", checkSortStr ((void**)arrayTextTest, rows));

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

void arrayFree (char *arrayText[], size_t arraySize)
{
    for (size_t i = 0; i < arraySize; i++)
        {
        if (arrayText[i])
            free (arrayText [i]);
        }
}

int comparatorStr (const void* v1, const void* v2)
{
    //printf ("%s%sstrCmp = %d\n", *(char* const*)v1, *(char* const*)v2, strcmpMy (*(char* const*)v1, *(char* const*)v2)); //if v1 or v2 = null -> return error code

    return strcmpMy (*(char* const*)v1, *(char* const*)v2);
}

bool checkSortStr (void **array, int size)
{
    for (int i = 0; i < size - 1; i++)
        if (strcmp ((char*)array[i], (char*)array[i + 1]) > 0)
            return false;

    return true;
}










