#include "sort.h"
#include "../MistakeHandling/myAssert.h"

inline void swap (void *a, void *b, size_t size)
{
    MY_ASSERT (a != nullptr, "pointer to a is equal to nullptr");
    MY_ASSERT (b != nullptr, "pointer to b is equal to nullptr");

    unsigned char temp = 0, *first = (unsigned char*)a, *second = (unsigned char*)b;

    for (size_t i = 0; i < size; i++)
    {
        temp = first[i];
        first[i] = second[i];
        second[i] = temp;
    }
}

// Formatted printing of integer massive
void dump_list(const char *tag, int *ptr, int left, int right)
{
    MY_ASSERT (tag != nullptr, "pointer to tag is equal to nullptr");
    MY_ASSERT (ptr != nullptr, "pointer to ptr is equal to nullptr");

    printf("%15s [%d..%d]: ", tag, left, right);
    for (int i = left; i <= right; i++)
        printf(" %5d", ptr[i]);
    putchar('\n');
}

// Partitioning algorithm used in qsort
int partition(void *array, int left, int right, size_t elementSize, int (*comparator) (const void*, const void*))
{
    MY_ASSERT (array != nullptr, "pointer to array is equal to nullptr");

    int pivot = left;
    //char* p_val = *(char**)(array + elementSize * pivot);
    void* p_val = calloc (1, elementSize); // if p_va; l == NULL Couldn't allocate memory

    if (p_val == nullptr)
        return 0;
    else
    {
        memcpy (p_val, (uc*)array + elementSize * pivot, elementSize);

        if (right - left > 1)
        {
            while (left < right)
            {
                while (comparator ((uc*)array + elementSize * left, p_val) <= 0/*array[left] <= p_val*/)
                    left++;

                while (comparator ((uc*)array + elementSize * right, p_val) > 0/*array[right] > p_val)*/)
                    right--;

                if (left < right)
                    swap ((uc*)array + elementSize * left, (uc*)array + elementSize * right, sizeof(elementSize));
            }

            swap ((uc*)array + elementSize * pivot, (uc*)array + elementSize * right, sizeof(elementSize));
        }
        else if (left < right)
        {
            if (comparator ((uc*)array + elementSize * left, (uc*)array + elementSize * right) > 0)
                swap ((uc*)array + elementSize * left, (uc*)array + elementSize * right, sizeof(elementSize));
        }


        free (p_val);
        return right;
    }

    free (p_val);

    return 0; // Later will improve to error code that means that we couldn't allocate memory
}

// Quicksort recursion
void quicksort(void *array, int start, int end, size_t elementSize, int (*comparator) (const void*, const void*))
{
    MY_ASSERT (array != nullptr, "pointer to array is equal to nullptr");

    if (start < end)
    {
        int splitPoint = partition(array, start, end, elementSize, comparator);

        quicksort(array, start, splitPoint - 1, elementSize, comparator);
        quicksort(array, splitPoint + 1, end, elementSize, comparator);
    }
}

void qsortMy (void *array, size_t nmemb, size_t elementSize, int (*comparator) (const void*, const void*))
{
    quicksort (array, 0, nmemb, elementSize, comparator);
}

bool isSortedInt (int* array, size_t arraySize)
{
    MY_ASSERT (array != nullptr, "pointer to array is equal to nullptr");

    bool isSorted = true;

    for (size_t i = 0; i < (arraySize - 1); i++)
        if (array[i] - array[i + 1] > stdError)
            isSorted = false;

    return isSorted;
}

// Comparator for integer values smallest to largest
int compareInt (const void* n1, const void* n2)
{
    MY_ASSERT (n1 != nullptr, "pointer to n1 is equal to nullptr");
    MY_ASSERT (n2 != nullptr, "pointer to n2 is equal to nullptr");

    //printf ("n1 = %d, n2 = %d, n1 - n2 = %d\n", *(int*)n1, *(uc*)n2, (*(int*)n1 - *(uc*)n2));

    return (*(int*)n1 - *(int*)n2);
}

// Comparator for integer values largest to smallest
int compareIntReverse (const void* n1, const void* n2)
{
    MY_ASSERT (n1 != nullptr, "pointer to n1 is equal to nullptr");
    MY_ASSERT (n2 != nullptr, "pointer to n2 is equal to nullptr");

    return (-(*(int*)n1 - *(int*)n2));
}

int compareDouble (const void* n1, const void* n2)
{
    MY_ASSERT (n1 != nullptr, "pointer to n1 is equal to nullptr");
    MY_ASSERT (n2 != nullptr, "pointer to n2 is equal to nullptr");

    return (*(double*)n1 - *(double*)n2);
}



