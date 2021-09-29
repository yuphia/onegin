#include "sort.h"
#include "../StrFuncs/strlibMy.h"
#include "../fileInput/fileInputTreatment.h"

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
                //printf ("loop, left = %d, right = %d\n", left, right);
                while (comparator ((uc*)array + elementSize * left, p_val) <= 0/*array[left] <= p_val*/)
                    left++;
                printf ("%s\nlineSize = %ld \n%d, %d\n", ((struct Line*)((uc*)array + elementSize * right)) -> line, ((struct Line*)((const void*)((uc*)array + elementSize * right))) -> lineSize, left, right);
                $$$
                while (comparator ((const void*)((uc*)array + elementSize * right), p_val) > 0/*array[right] > p_val)*/)
                    right--;
                printf ("BEBRA %s\nlineSize = %ld \n%d, %d\n", ((struct Line*)((uc*)array + elementSize * right)) -> line, ((struct Line*)((const void*)((uc*)array + elementSize * right))) -> lineSize, left, right);

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
    quicksort (array, 0, nmemb - 1, elementSize, comparator);
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

int compareLineStruct (const void* n1, const void* n2)
{
    char* first_var_start     = ((struct Line*) n1)->line;
    char* first_var_ne_start  = ((struct Line*) n1)->line + ((struct Line*) n1)->lineSize;
    char* second_var_start    = ((struct Line*) n2)->line;
    char* second_var_ne_start = ((struct Line*) n2)->line + ((struct Line*) n2)->lineSize;
    
    printf ("left size  = %ld\n"
            "right size = %ld\n",
            ((struct Line*)n1) -> lineSize,
            ((struct Line*)n2) -> lineSize);

    printf ("line left  = %s\n"
            "line right = %s\n", 
            first_var_start, second_var_start);

    while (isalnum(*first_var_start ) == 0 && *first_var_start != '\0')   first_var_start++;
    while (isalnum(*second_var_start) == 0 && *second_var_start != '\0') second_var_start++;
   
    while (first_var_start != first_var_ne_start && second_var_start != second_var_ne_start && *first_var_start == *second_var_start)
    {
        first_var_start++;
        second_var_start++;

        while (isalnum((int)(unsigned char)*first_var_start ) == 0 && first_var_start != first_var_ne_start) first_var_start++;
        while (isalnum((int)(unsigned char)*second_var_start) == 0 && second_var_start != second_var_ne_start) second_var_start++;
    }

    printf ("line left  = %s\n"
            "line right = %s\n", 
            first_var_start, second_var_start);

    printf ("%d\n", ((int)(*first_var_start) - (int)(*second_var_start)));

    return ((int)(unsigned char)(*first_var_start) - (int)(unsigned char)(*second_var_start));
}
/*{
    MY_ASSERT (n1 != nullptr, "pointer to n1 is equal to nullptr");
    MY_ASSERT (n2 != nullptr, "pointer to n2 is equal to nullptr");

    char* line1 = ((struct Line*)n1) -> line;
    char* line2 = ((struct Line*)n2) -> line;

    printf ("%s\n %s\n", line1, line2);

    return compareStr (line1, line2);
}                                                              */

int compareStr (const void* v1, const void* v2)
{
    MY_ASSERT (v1 != nullptr, "pointer to v1 is equal to nullptr");
    MY_ASSERT (v2 != nullptr, "pointer to v2 is equal to nullptr");
    //if v1 or v2 = null -> return error code

    return strcmpMy (*(char* const*)v1, *(char* const*)v2);
}
