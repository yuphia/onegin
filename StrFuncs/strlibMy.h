#pragma once

#define $$$ printf ("line %d\n",  __LINE__);

#define DEBUG_SOFT

#include <stdio.h>
#include <errno.h>
#include "../MistakeHandling/myAssert.h"

int putsMy (char* str);
int strcmpMy (const char* str1, const char* str2);
size_t strlenMy (const char *str);

char* strcpyMy (char* destStr, const char* srcStr);
char* strncpyMy (char* destStr, const char* srcStr, size_t amount);

const char* strchrMy_c (const char *str, int symbol);
      char* strchrMy   (      char *str, int symbol);

char *fgetsMy (char *str, int maxSize, FILE* stream);
size_t getlineMy (char **lineptr, size_t *maxSize, FILE* stream);

void printText (char* text[], size_t rows, FILE* outputFile);
char* strdupMy (const char* srcStr);

char *strncatMy (char *destStr, const char *srcStr, size_t amount);
char *strcatMy (char *destStr, const char *srcStr);



