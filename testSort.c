//#include "qsort.h"
#define $$$ printf ("loop %d\n",  __LINE__);

#include <stdio.h>

static inline void swap(int *a, int *b);
static void dump_list(const char *tag, int *ptr, int left, int right);
static int partition(int *array, int left, int right, void (*comparator) (const void*, const void*));
void quicksort(int *array, int start, int end, int (*comparator) (const void*, const void*));
bool isSorted (int* array, size_t arraySize);

// Comparators
int compareInt (const void* n1, const void* n2);

int main()
{
    int myList[] = {12, 43, -16, 0, 2, 5, 1, 13, 2, 2, -1};
    dump_list("UNSORTED LIST", myList, 0, 9);
    quicksort(myList, 0, 9, compareInt);
    dump_list("SORTED LIST", myList, 0, 9);

    printf ("array is sorted: %d\n", isSorted (myList, 10));

    return 0;
}


// Swapping algorithm
static inline void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void dump_list(const char *tag, int *ptr, int left, int right)
{
    printf("%15s [%d..%d]: ", tag, left, right);
    for (int i = left; i <= right; i++)
        printf(" %3d", ptr[i]);
    putchar('\n');
}

// Partitioning algorithm
static int partition(int *array, int left, int right, int (*comparator) (const void*, const void*))
{
    int pivot = left;
    int p_val = array[pivot];

    while (left < right)
    {
        while (comparator (array + left, &p_val) <= 0/*array[left] <= p_val*/)
            left++;

        while (comparator (array + right, &p_val) > 0/*array[right] > p_val)*/)
            right--;

        if (left < right)
            swap(&array[left], &array[right]);
    }

    swap(&array[pivot], &array[right]);
    return right;
}

// Quicksort recursion
void quicksort(int *array, int start, int end, int (*comparator) (const void*, const void*))
{
    if (start >= end)
        return;

    int splitPoint = partition(array, start, end, comparator);

    quicksort(array, start, splitPoint - 1, comparator);
    quicksort(array, splitPoint + 1, end, comparator);
}

bool isSorted (int* array, size_t arraySize)
{
    bool isSorted = true;

    for (int i = 0; i < (arraySize - 1); i++)
        if (array[i] > array[i + 1])
            isSorted = false;

    return isSorted;
}

int compareInt (const void* n1, const void* n2)
{
    return (*(int*)n1 - *(int*)n2);
}
