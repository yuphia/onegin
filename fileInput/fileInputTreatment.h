#ifndef FILEINPUTTREATMENT_H

#define FILEINPUTTREATMENT_H

#include "../MistakeHandling/myAssert.h"
#include <stdio.h>
#include <cstring>
#include <iostream>

struct Text
    {
        struct Line* lines;
        char* textArray;
        size_t textSize;
        size_t nLines;
    };

struct Line
    {
        char* line;
        size_t lineSize;
    };

bool isLineEmpty (char* line);
size_t getFileSize (FILE* inputFile);
bool isFile (FILE* file);
void transitFileToText (FILE* inputFile, struct Text* text);
void fillText (FILE* inputFile, struct Text* text);
size_t countLines (char* text, size_t textSize);
struct Line* transitTextToLineArray (size_t* lineAmount, char* text);
void printTextStruct (struct Text* text, FILE* fileOut);
void freeArrayLines (struct Line* lines);
void transitFileToLineArray (FILE* inputFile, struct Text* text);
void printLinesArray (FILE* file, struct Text* text);
void runThroughText (char* text, size_t textSize);

#endif
