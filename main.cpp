#include <stdio.h>
#include <iostream>
#include "StrFuncs/strlibMy.h"
#include "SortingAlg/sort.h"
#include "fileInput/fileInputTreatment.h"
#include "fileInput/fileInputTreatment.h" 
#include <cstring>

const int MAXROWLENGTH = 100;
const int MAXROW = 27000;//27000;

void arrayFree (char *arrayText[], size_t arraySize);

bool checkSortStr (void **array, int size);

int main(int argc, char* argv[])
{
    if (argc != 3)
        return 0;

    FILE* inputFile = fopen (argv[1], "rb");

    if (inputFile == nullptr)
    {
        return 0;
    }

    FILE* outputFile = fopen (argv[2], "wb");

    if (outputFile == nullptr)
    {
        return 0;
    }

    struct Text text = {};

    transitFileToLineArray (inputFile, &text);

    printf ("total lines = %zu", text.nLines);
   
    qsort ((void*)text.lines, text.nLines, sizeof (struct Line), compareLineStruct);
    printLinesArray (outputFile, &text);

    qsort ((void*)text.lines, text.nLines, sizeof (struct Line), compareLineStructEnd);
    printLinesArray (outputFile, &text);
    
    runThroughText (text.textArray, text.textSize);
    printTextStruct (&text, outputFile);

    fclose (inputFile);
    fclose (outputFile);  

    free (text.textArray);

    freeArrayLines (text.lines);

    return 0;
}


void arrayFree (char *arrayText[], size_t arraySize)
{
    MY_ASSERT (arrayText != nullptr, "pointer to arrayText is equal to nullptr");
    printf ("rows = %zu\n", arraySize);

    for (size_t i = 0; i < arraySize; i++)
        {
        if (arrayText[i])
            free (arrayText [i]);
        }
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







