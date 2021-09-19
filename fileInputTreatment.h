#include "../myAssert.h"
#include <stdio.h>
#include <cstring>
#include <iostream>

struct Text 
    {
        char* textArray;
        size_t textSize; 
    };

struct Line 
    {
        char* line;
        size_t lineSize;
    };

size_t getFileSize (FILE* inputFile);    
bool isFile (FILE* file);
void transitFileToText (FILE* inputFile, struct Text* text);
void fillText (FILE* inputFile, struct Text* text);
size_t countLines (char* text);
struct Line* transitTextToLineArray (size_t lineAmount, char* text, struct Line* arrayOfStrings);
void printTextStruct (struct Text* text, FILE* fileOut);

size_t getFileSize (FILE* inputFile)
{
    MY_ASSERT (inputFile != 0, "Trying to reach for address nullptr")

    fseek (inputFile, 0, SEEK_END);
    int fileSize = ftell (inputFile);
    if (fileSize < 0)
        return 0;

    fseek (inputFile, 0, SEEK_SET);

    return (size_t)fileSize;
}

bool isFile (FILE* file)
{
    return (file != nullptr) ? true : false;
}

void transitFileToText (FILE* inputFile, struct Text* text)
{
    MY_ASSERT (isFile (inputFile), "Pointer to inputFile struct is nullptr");
    MY_ASSERT (text != nullptr, "Pointer to textArray is nullptr");

    text ->  textSize = getFileSize (inputFile);
    text -> textArray = (char*)calloc (text -> textSize + 1, sizeof(char));

    if (&(text -> textArray) == nullptr)
        return;

    fillText (inputFile, text);
}

void fillText (FILE* inputFile, struct Text* text)
{
    MY_ASSERT (isFile (inputFile), "Pointer to inputFile struct is nullptr");
    MY_ASSERT (text != nullptr, "Pointer to textArray is nullptr");

    fread (text -> textArray, sizeof(char), text -> textSize, inputFile);
    *(text -> textArray + text -> textSize) = '\n';
    fseek (inputFile, 0, SEEK_SET);
}

size_t countLines (char* text)
{
    MY_ASSERT (text != nullptr, "Pointer to text = nullptr");

    char* lineStartTrue = text;
    char* lineStartCheck = text;
    size_t lineCount = 0;

    while ( ( lineStartCheck = strchr (lineStartTrue, '\n')) != NULL)
    {
        lineStartTrue = lineStartCheck + 1;
        lineCount++;
    }

    return lineCount;
}

struct Line* transitTextToLineArray (size_t lineAmount, char* text, struct Line* arrayOfStrings)
{
    MY_ASSERT (text != nullptr, "Pointer to text = nullptr"); 
    MY_ASSERT (text != nullptr, "Pointer to an array of structs Line = nullptr");   

    arrayOfStrings = (struct Line*) calloc (lineAmount, sizeof(struct Line)); //free
    
    char* endOfLine = text;
    char* startOfLine = text;
    size_t termChars = 0;

    for (size_t i = 0; i < lineAmount; i++)
    {
        endOfLine = strchr (text, '\n');

        if (*(endOfLine - 1) == '\r')
        {
            *(endOfLine - 1) = '\0';
            endOfLine--;
            termChars = 2;
        }
        else
        {
            *endOfLine = '\0';
            termChars = 1;
        }

        arrayOfStrings[i].line = startOfLine;
        arrayOfStrings[i].lineSize = endOfLine - startOfLine;
        startOfLine = endOfLine + termChars;
    }

    return arrayOfStrings;
}

void printTextStruct (struct Text* text, FILE* fileOut)
{
    MY_ASSERT (text != nullptr, "Pointer to text = nullptr");
    MY_ASSERT (fileOut != nullptr, "Pointer to output file = nullptr");

    for (size_t i = 0; i < (text -> textSize); i++)
    {
        fputc (text -> textArray[i], fileOut);
    }    
}










