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
    {
        printf ("\n FORMAT FOR RUNNING: ./onegin.out INPUTFILENAME OUTPUTFILENAME\n");
        return 0;
    }

    struct Text text = {};
    
    FILE* inputFile = fopen (argv[1], "rb");

    if (inputFile == nullptr)
    {
        return 0;
    }

    transitFileToLineArray (inputFile, &text);

    fclose (inputFile);

    FILE* outputFile = fopen (argv[2], "wb");

    if (outputFile == nullptr)
    {
        return 0;
    }

    qsort ((void*)text.lines, text.nLines, sizeof (struct Line), compareLineStruct);
    
    markerNormalSortStart (outputFile);
    printLinesArray (outputFile, &text);
    markerNormalSortEnd (outputFile);

    qsort ((void*)text.lines, text.nLines, sizeof (struct Line), compareLineStructEnd);

    markerReverseSortStart (outputFile);
    printLinesArray (outputFile, &text);
    markerReverseSortEnd (outputFile);
    
    runThroughText (text.textArray, text.textSize);

    markerNoSortStart (outputFile);
    printTextStruct (&text, outputFile);
    markerNoSortEnd (outputFile);

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







