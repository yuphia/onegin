#define $$$ printf ("line %d\n",  __LINE__);

#include <stdio.h>
#include <stdlib.h>
#include <cstring>

typedef unsigned char uc;
const double stdError = 1e-10;

inline void swap (void *a, void *b, size_t size);
static void dump_list(const char *tag, int *ptr, int left, int right);
void printText (char* text[], size_t rows, FILE* outputFile);

int partition(void *array, int left, int right, size_t elementSize, int (*comparator) (const void*, const void*));
void quicksort(void *array, int start, int end, size_t elementSize, int (*comparator) (const void*, const void*));

bool isSortedInt (int* array, size_t arraySize);

int compareInt (const void* n1, const void* n2);
int compareIntReverse (const void* n1, const void* n2);

