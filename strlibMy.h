#include <stdio.h>
#include <errno.h>

int putsMy (char* str);
int strcmpMy (char* str1, char* str2);
size_t strlenMy (const char *str);

char* strcpyMy (char* destStr, const char* srcStr);
char* strncpyMy (char* destStr, const char* srcStr, size_t amount);

const char* strchrMy_c (const char *str, int symbol);
      char* strchrMy   (      char *str, int symbol);

char *fgetsMy (char *str, int maxSize, FILE* stream);
size_t getlineMy (char **lineptr, size_t *maxSize, FILE* stream);

int putsMy (char* str)
{
    size_t counter = 0;
    printf ("%d", str [counter]);

    while (str [counter] != '\0')
    {
        printf ("%d", str [counter]);
        putchar (str [counter]);
        counter++;
        printf ("123\n");
    }

    return (ferror (stdout)) ? EOF : 0;
}

int strcmpMy (char* str1, char* str2)
{
    while (*str1 == *str2 && *str1 != '\0')
        str1++, str2++;

    return *str1 - *str2;
}

size_t strlenMy (const char *str)
{
    int length = 0;
    for (; str [length] != '\0'; length++)
        ;

    return length;
}

const char* strchrMy_c (const char *str, int symbol)
{
    for (; *str != '\0'; str++)
        if (*str == (char)symbol)
            return str;

    return NULL;
}

char* strchrMy (char *str, int symbol)
{
    for (; *str != '\0'; str++)
        if (*str == (char)symbol)
            return str;

    if ((char) symbol == '\0')
        return str++;

    return NULL;
}

char* strcpyMy (char* destStr, const char* srcStr)
{
    size_t i = 0;
    for (; srcStr [i] != '\0';  i++)
        destStr [i] = srcStr[i];

    ++i;
    destStr [i] = srcStr [i];
    return destStr;
}

char* strncpyMy (char* destStr, const char* srcStr, size_t amount)
{
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
    int destStr_len = strlenMy (destStr);
    size_t i = 0;

    for (; srcStr[i] != '\0'; i++)
        destStr [destStr_len + i] = srcStr[i];

    destStr [destStr_len + i + 1] = '\0';
    return destStr;
}

char *strncatMy (char *destStr, const char *srcStr, size_t amount)
{
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

    for (; str - str0 < maxSize; str++)
    {
        //printf ("%d\n", i);
        character = getc (stream);

        //putc (character, stdout);

        if (character == '\n' || character == EOF)
            break;

        *str = character;
    }

    if (character != EOF)
        *(str) = '\n';

    *(str + 1) = '\0';
    return (character == EOF) ? NULL : str;
}

char* strdupMy (const char* srcStr)
{
    if (srcStr == NULL)
        return nullptr;

    char* strCpy = (char*)malloc (sizeof srcStr);

    size_t i = 0;
    for (; srcStr [i] != '\0';  i++)
        strCpy [i] = srcStr[i];

    ++i;
    strCpy [i] = srcStr [i];


    return strCpy;
}

size_t getlineMy (char **lineptr, size_t *maxSize, FILE* stream)
{
    char *strEnd = NULL;
    char *strStart = NULL;

    if (*lineptr == 0)
    {
        size_t maxSizeSafe = 1;
        maxSize = &maxSizeSafe;
        printf ("%ld\n", *maxSize);

        strStart = (char*)calloc (*maxSize, sizeof (char));
        strEnd = strStart + *maxSize;
    }
    else
    {
        strStart = *lineptr;
        strEnd = *lineptr + *maxSize;
    }

    if (strStart != NULL)
        printf ("memory created successfully\n");

    char *currentElement = strStart;

    char character = 0;

    for (;; currentElement++)
    {
        character = getc (stream);

        if (true)
        {
            printf ("maxSize = %ld\n", *maxSize);
            *maxSize *= 2;
            strStart = (char*)realloc (strStart, *maxSize);
            strEnd = strEnd + *maxSize;
            printf ("maxSize = %ld\n", *maxSize);
        }

        printf ("currentElement = %s\n", currentElement);

        *currentElement = character;

        if (character == '\n' || character == EOF)
        {
            break;
        }
    }

    currentElement++;

    if (currentElement > strEnd)
        currentElement = (char*)realloc (strStart, (size_t)(*maxSize)*2);

    *(currentElement) = '\0';

    printf ("x%sx\n", *lineptr);
    *lineptr = strStart;
    printf ("y%sy\n", *lineptr);
    return sizeof (*lineptr);
}
