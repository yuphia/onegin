#define $$$ printf ("line %d\n",  __LINE__);

#include <stdio.h>
#include <stdlib.h>
#include "../MistakeHandling/myAssert.h"
#include <cstring>

typedef unsigned char uc;
const double stdError = 1e-10;

inline void swap (void *a, void *b, size_t size);
void dump_list(const char *tag, int *ptr, int left, int right);

size_t partition(void *array, size_t left, size_t right, size_t elementSize, int (*comparator) (const void*, const void*));
void quicksort(void *array, size_t start, size_t end, size_t elementSize, int (*comparator) (const void*, const void*));
void qsortMy (void *array, size_t nmemb, size_t elementSize, int (*comparator) (const void*, const void*));

bool isSortedInt (int* array, size_t arraySize);

int compareInt (const void* n1, const void* n2);
int compareDouble (const void* n1, const void* n2);
int compareIntReverse (const void* n1, const void* n2);
int compareLineStruct (const void* n1, const void* n2);
int compareLineStructEnd (const void* n1, const void* n2);
int compareStr (const void* v1, const void* v2);
