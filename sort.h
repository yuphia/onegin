#define $$$ printf ("line %d\n",  __LINE__);

typedef unsigned char uc;

#include <stdio.h>
#include <stdlib.h>
#include <cstring>

static inline void swap (void *a, void *b, size_t size);
static void dump_list(const char *tag, int *ptr, int left, int right);
void printText (char* text[], int rows);

static int partition(void *array, int left, int right, size_t elementSize, int (*comparator) (const void*, const void*));
void quicksort(void *array, int start, int end, size_t elementSize, int (*comparator) (const void*, const void*));

bool isSorted (int* array, size_t arraySize);
static inline void swap (void *a, void *b, size_t size);

// Comparators
int compareInt (const void* n1, const void* n2);
int compareIntReverse (const void* n1, const void* n2);

/*
} */


// Swapping algorithm
static inline void swap (void *a, void *b, size_t size)
{
    unsigned char temp = 0, *first = (unsigned char*)a, *second = (unsigned char*)b;

    for (size_t i = 0; i < size; i++)
    {
        //printf ("swapping\n");
        temp = first[i];
        first[i] = second[i];
        second[i] = temp;
    }
}

static void dump_list(const char *tag, int *ptr, int left, int right)
{
    printf("%15s [%d..%d]: ", tag, left, right);
    for (int i = left; i <= right; i++)
        printf(" %5d", ptr[i]);
    putchar('\n');
}

// Partitioning algorithm

static int partition(void *array, int left, int right, size_t elementSize, int (*comparator) (const void*, const void*))
{
    int pivot = left;
    //char* p_val = *(char**)(array + elementSize * pivot);
    void* p_val = calloc (1, elementSize);
    memcpy (p_val, array + elementSize * pivot, elementSize);

    if (right - left > 1)
    {
        while (left < right)
        {
            while (comparator (array + elementSize * left, p_val) <= 0/*array[left] <= p_val*/)
                left++;

            while (comparator (array + elementSize * right, p_val) > 0/*array[right] > p_val)*/)
                right--;

            if (left < right)
                swap (array + elementSize * left, array + elementSize * right, sizeof(elementSize));
        }

        swap (array + elementSize * pivot, array + elementSize * right, sizeof(elementSize));
    }
    else if (left < right)
    {
        if (comparator (array + elementSize * left, array + elementSize * right) > 0)
            swap (array + elementSize * left, array + elementSize * right, sizeof(elementSize));
    }

    free (p_val);

    return right;
}

// Quicksort recursion
void quicksort(void *array, int start, int end, size_t elementSize, int (*comparator) (const void*, const void*))
{
    if (start < end)
    {
        int splitPoint = partition(array, start, end, elementSize, comparator);

        quicksort(array, start, splitPoint - 1, elementSize, comparator);
        quicksort(array, splitPoint + 1, end, elementSize, comparator);
    }
}

bool isSorted (int* array, size_t arraySize)
{
    bool isSorted = true;

    for (size_t i = 0; i < (arraySize - 1); i++)
        if (array[i] - array[i + 1] > 1e-10)
            isSorted = false;

    return isSorted;
}

int compareInt (const void* n1, const void* n2)
{
    //printf ("n1 = %d, n2 = %d, n1 - n2 = %d\n", *(int*)n1, *(uc*)n2, (*(int*)n1 - *(uc*)n2));

    return (*(int*)n1 - *(int*)n2);
}

int compareIntReverse (const void* n1, const void* n2)
{
    return (-(*(int*)n1 - *(int*)n2));
}

int compareDouble (const void* n1, const void* n2)
{
    return (*(double*)n1 - *(double*)n2);
}


void printText (char* text[], int rows)
{
    for (int counter = 0; counter < rows;  counter++)
        printf ("%s", text [counter]);
}
