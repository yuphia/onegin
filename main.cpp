#include <stdio.h>
#include <iostream>
#include "strlibMy.h"
#include "sort.h"
#include <cstring>

const int MAXROWLENGTH = 100;
const int MAXROW = 27000;//27000;


int readFile (char *arrayText[], FILE* file, size_t* rows);

void arrayFree (char *arrayText[], size_t arraySize);

int comparatorStr (const void* v1, const void* v2);

bool checkSortStr (void **array, int size);

int main()
{
    FILE *input = nullptr;
    FILE *outputFile = nullptr;

    input = fopen ("input.txt", "rb");

    if (input != nullptr)
    {
        size_t rows = 0;
        char *arrayText [MAXROW] = {0};

        if (readFile (arrayText, input, &rows) == 0)
            perror ("An error in function readFile");
        else
        {
            outputFile = fopen ("output.txt", "wb");
            if (outputFile == nullptr)
            {
                arrayFree (arrayText, rows);
                return 0;
            }    

            printText (arrayText, rows, outputFile);
            printf ("\n");

                //qsort ((void*)arrayTextTest, rows, sizeof (char*), comparatorStr);
            quicksort ((void*)arrayText, 0, rows - 1, sizeof (char*), comparatorStr);

            printText (arrayText, rows, outputFile);
            
            fclose (outputFile);
        }

        printf ("%d\n", checkSortStr ((void**)arrayText, rows));

        arrayFree (arrayText, rows);
    }
    

    return 0;
}

int readFile (char *arrayText[], FILE* file, size_t *row)
{
    MY_ASSERT (arrayText != nullptr, "pointer to arrayText is equal to nullptr");
    MY_ASSERT (file != nullptr, "pointer to file is equal to nullptr");
    MY_ASSERT (row != nullptr, "pointer to row is equal to nullptr");

    *row = 0;
    while (*row < MAXROW)
    {
        size_t bufferSize = 25;
        char* strBuffer = (char*)calloc (bufferSize, sizeof(char));
        getline (&strBuffer, &bufferSize, file);

        if (feof (file))
        {
            free (strBuffer);
            break;
        }

        *(arrayText + *row) = strBuffer;
        //printf ("text: %s", *(arrayText + *row));
        (*row)++;
        printf ("rows = %ld\n", *row);
    }
    fclose (file);
    //(*row)++;
    return (ferror (file)) ? 0 : EOF;
}

void arrayFree (char *arrayText[], size_t arraySize)
{
    MY_ASSERT (arrayText != nullptr, "pointer to arrayText is equal to nullptr");
    printf ("rows = %ld\n", arraySize);

    for (size_t i = 0; i < arraySize; i++)
        {
        if (arrayText[i])
            free (arrayText [i]);
        }
}

int comparatorStr (const void* v1, const void* v2)
{
    MY_ASSERT (v1 != nullptr, "pointer to v1 is equal to nullptr");
    MY_ASSERT (v2 != nullptr, "pointer to v2 is equal to nullptr");
    //if v1 or v2 = null -> return error code

    return strcmpMy (*(char* const*)v1, *(char* const*)v2);
}

bool checkSortStr (void **array, int size)
{
    MY_ASSERT (array != nullptr, "pointer to array is equal to nullptr");

    for (int i = 0; i < size - 1; i++)
    {
        MY_ASSERT ((char**)array[i] != nullptr, "pointer to array[i] is equal to nullptr");

        if (strcmp ((char*)array[i], (char*)array[i + 1]) > 0)
            return false;
    }

    return true;
}










