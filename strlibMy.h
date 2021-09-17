#pragma once

#define $$$ printf ("line %d\n",  __LINE__);

#define DEBUG_SOFT

#include <stdio.h>
#include <errno.h>
#include "myAssert.h"

int putsMy (char* str);
int strcmpMy (const char* str1, const char* str2);
size_t strlenMy (const char *str);

char* strcpyMy (char* destStr, const char* srcStr);
char* strncpyMy (char* destStr, const char* srcStr, size_t amount);

const char* strchrMy_c (const char *str, int symbol);
      char* strchrMy   (      char *str, int symbol);

char *fgetsMy (char *str, int maxSize, FILE* stream);
size_t getlineMy (char **lineptr, size_t *maxSize, FILE* stream);

int putsMy (char* str)
{
    MY_ASSERT (str != nullptr, "pointer to str equals nullptr");

    size_t counter = 0;
    printf ("%d", str [counter]);

    while (str [counter] != '\0')
    {
        //printf ("%d", str [counter]);
        putchar (str [counter]);
        counter++;
        printf ("123\n");
    }

    return (ferror (stdout)) ? EOF : 0;
}

int strcmpMy (const char* str1, const char* str2)
{
    MY_ASSERT (str1 != nullptr, "pointer to str1 equals nullptr");
    MY_ASSERT (str2 != nullptr, "pointer to str2 equals nullptr");

    while (*str1 == *str2 && *str1 != '\0')
    {
        //printf ("%d\n", ++testI);
        str1++, str2++;
    }

    return (int)(unsigned char)*str1 - (int)(unsigned char)*str2;
}

size_t strlenMy (const char *str)
{
<<<<<<< Updated upstream
<<<<<<< Updated upstream
    MY_ASSERT (str != nullptr, "pointer to str equals nullptr");

    int length = 0;
=======
    size_t length = 0;
>>>>>>> Stashed changes
=======
    size_t length = 0;
>>>>>>> Stashed changes
    for (; str [length] != '\0'; length++)
        ;

    return length;
}

const char* strchrMy_c (const char *str, int symbol)
{
    MY_ASSERT (str != nullptr, "pointer to str equals nullptr");

    for (; *str != '\0'; str++)
        if (*str == (char)symbol)
            return str;

    return NULL;
}

char* strchrMy (char *str, int symbol)
{
    MY_ASSERT (str != nullptr, "pointer to str equals nullptr");

    for (; *str != '\0'; str++)
        if (*str == (char)symbol)
            return str;

    if ((char) symbol == '\0')
        return str++;

    return NULL;
}

char* strcpyMy (char* destStr, const char* srcStr)
{
    MY_ASSERT (destStr != nullptr, "pointer to destStr equals nullptr");
    MY_ASSERT (srcStr  != nullptr, "pointer to srcStr  equals nullptr");

    size_t i = 0;
    for (; srcStr [i] != '\0';  i++)
        destStr [i] = srcStr[i];

    ++i;
    destStr [i] = srcStr [i];
    return destStr;
}

char* strncpyMy (char* destStr, const char* srcStr, size_t amount)
{
    MY_ASSERT (destStr != nullptr, "pointer to destStr equals nullptr");
    MY_ASSERT (srcStr  != nullptr, "pointer to srcStr  equals nullptr");

    if (destStr == nullptr || srcStr == nullptr)
    {
        errno = EINVAL;
        return (char*)-1;
    }

    size_t i = 0;

    for (; i < amount;  i++)
    {
        destStr [i] = srcStr[i];

        if (srcStr [i] == '\0')
        {
            destStr [i] = '\0';
            return destStr;
        }
    }

    return destStr;
}

char *strcatMy (char *destStr, const char *srcStr)
{
    MY_ASSERT (destStr != nullptr, "pointer to destStr equals nullptr");
    MY_ASSERT (srcStr  != nullptr, "pointer to srcStr  equals nullptr");

    int destStr_len = strlenMy (destStr);
    size_t i = 0;

    for (; srcStr[i] != '\0'; i++)
        destStr [destStr_len + i] = srcStr[i];

    destStr [destStr_len + i + 1] = '\0';
    return destStr;
}

char *strncatMy (char *destStr, const char *srcStr, size_t amount)
{
    MY_ASSERT (destStr != nullptr, "pointer to destStr equals nullptr");
    MY_ASSERT (srcStr  != nullptr, "pointer to srcStr  equals nullptr");

    int destStr_len = strlenMy (destStr);
    size_t i = 0;

    for (; i < amount;  i++)
    {
        destStr [destStr_len + i] = srcStr[i];

        if (srcStr [i] == '\0')
        {
            destStr [destStr_len + i] = '\0';
            return destStr;
        }
    }

    return destStr;
}

char *fgetsMy (char *str, int maxSize, FILE* stream)
{
    if (str == nullptr || stream == nullptr || maxSize <= 0)
    {
        errno = EINVAL;
        return nullptr;
    }

    int character = '\0';
    char* str0 = str;

    printf ("%d, %ld", maxSize, str - str0);

    for (; str - str0 < maxSize; str++)
    {
        character = getc (stream);

        putc (character, stdout);

        if (character == '\n' || character == EOF)
        {
            break;
        }
        *str = character;
    }

    if (character != EOF)
        *(str) = '\n';

    *(str + 1) = '\0';
    return (character == EOF) ? NULL : str;
}

char* strdupMy (const char* srcStr)
{
    MY_ASSERT (srcStr != nullptr, "pointer to srcStr equals nullptr");

    if (srcStr == NULL)
        return nullptr;

    char* strCpy = (char*)calloc (sizeof srcStr, sizeof (char));

    size_t i = 0;
    for (; srcStr [i] != '\0';  i++)
        strCpy [i] = srcStr[i];

    ++i;
    strCpy [i] = srcStr [i];


    return strCpy;
}    /*

size_t getlineMy (char **lineptr, size_t *maxSize, FILE* stream)
{
    char *strEnd = NULL;
    char *strStart = NULL;

    if (*lineptr == 0)
    {
        size_t maxSizeSafe = 1;
        maxSize = &maxSizeSafe;
        //printf ("%ld\n", *maxSize);

        strStart = (char*)calloc (*maxSize, sizeof (char));
        strEnd = strStart + *maxSize;
    }
    else
    {
        strStart = *lineptr;
        strEnd = *lineptr + *maxSize;
    }

    if (strStart != NULL)
        //printf ("memory created successfully\n");

<<<<<<< Updated upstream
    char *currentElement = strStart;

<<<<<<< Updated upstream
    char character = 0;

    for (;; currentElement++)
=======
    size_t i = 0;
    char character = 0;

    for (; i < (size_t)*maxSize; i++)
>>>>>>> Stashed changes
=======
    size_t i = 0;
    char character = 0;

    for (; i < (size_t)*maxSize; i++)
>>>>>>> Stashed changes
    {
        character = getc (stream);

<<<<<<< Updated upstream
<<<<<<< Updated upstream
        if (true)
        {
            //printf ("maxSize = %ld\n", *maxSize);
            *maxSize *= 2;
            strStart = (char*)realloc (strStart, *maxSize);
            strEnd = strEnd + *maxSize;
            //printf ("maxSize = %ld\n", *maxSize);
        }

        //printf ("currentElement = %s\n", currentElement);

        *currentElement = character;

=======
        printf ("%s\n", str);
>>>>>>> Stashed changes
=======
        printf ("%s\n", str);
>>>>>>> Stashed changes
        if (character == '\n' || character == EOF)
        {
            break;
<<<<<<< Updated upstream
        }
=======

        if (currentBuffSize < sizeof (*(str + i)))
        {
            printf ("check\n");
            str = (char*)realloc (str, currentBuffSize*currentBuffSize);
        }

<<<<<<< Updated upstream
        *(str + i) = character;
>>>>>>> Stashed changes
=======
        if (currentBuffSize < sizeof (*(str + i)))
        {
            printf ("check\n");
            str = (char*)realloc (str, currentBuffSize*currentBuffSize);
        }

        *(str + i) = character;
>>>>>>> Stashed changes
    }

    currentElement++;

<<<<<<< Updated upstream
    if (currentElement > strEnd)
        currentElement = (char*)realloc (strStart, (size_t)(*maxSize)*2);

    *(currentElement) = '\0';

    *lineptr = strStart;
    return sizeof (*lineptr);
}        */
=======
    *lineptr = str;

    *lineptr = str;

    if (lineptr != NULL)
        return sizeof *lineptr;

    return sizeof str;
}
>>>>>>> Stashed changes
