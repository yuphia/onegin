#define $$$ printf ("line %d\n",  __LINE__);

typedef unsigned char uc;

#include <stdio.h>
#include <stdlib.h>
#include <cstring>

static inline void swap (void *a, void *b, size_t size);
static void dump_list(const char *tag, int *ptr, int left, int right);

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
        printf ("swapping\n");
        temp = first[i];
        first[i] = second[i];
        second[i] = temp;
    }
}

static void dump_list(const char *tag, int *ptr, int left, int right)
{
    printf("%15s [%d..%d]: ", tag, left, right);
    for (int i = left; i <= right; i++)
        printf(" %3d", ptr[i]);
    putchar('\n');
}

// Partitioning algorithm

static int partition(void *array, int left, int right, size_t elementSize, int (*comparator) (const void*, const void*))
{
    int pivot = left;
    uc p_val = *((uc*)array + elementSize * pivot);

    while (left < right)
    {
        $$$

        while (comparator ((uc*)array + elementSize * left, &p_val) <= 0/*array[left] <= p_val*/)
            left++;

        $$$

        while (comparator ((uc*)array + elementSize * right, &p_val) > 0/*array[right] > p_val)*/)
            right--;

        $$$

        if (left < right)
            swap ((uc*)array + elementSize * left, (uc*)array + elementSize * right, sizeof(int));
    }

    swap ((uc*) array + elementSize * pivot, (uc*) array + elementSize * right, sizeof(int));
    return right;
}

// Quicksort recursion
void quicksort(void *array, int start, int end, size_t elementSize, int (*comparator) (const void*, const void*))
{
    if (start < end)
    {
        //printf ("start = %d, end = %d, elSize = %ld\n", start, end, elementSize);
        int splitPoint = partition(array, start, end, elementSize, comparator);
        //printf ("start = %d, end = %d, elSize = %ld\n", start, end, elementSize);

        quicksort(array, start, splitPoint - 1, elementSize, comparator);
        quicksort(array, splitPoint + 1, end, elementSize, comparator);
        //$$$
    }
}

bool isSorted (int* array, size_t arraySize)
{
    bool isSorted = true;

    for (size_t i = 0; i < (arraySize - 1); i++)
        if (array[i] > array[i + 1])
            isSorted = false;

    return isSorted;
}

int compareInt (const void* n1, const void* n2)
{
    return (*(int*)n1 - *(uc*)n2);
}

int compareIntReverse (const void* n1, const void* n2)
{
    return (-(*(int*)n1 - *(uc*)n2));
}
