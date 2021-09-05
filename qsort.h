#include <stdio.h>

void printMassive (int *array, int size);
void qsortMy (void *array[], int first, int last, int (*comparator) (void*, void*));
void swap (void* array, int i, int j);
int compareInt (int* n1, int* n2);
void printText (char* text[], int rows);

/*int main ()
{
    //printf ("123");

    int bolvanka[] = {1, 123, 1, 121, 312, 9, 8, 7, 6, 5};
    int* array[] = {bolvanka, bolvanka + 1, bolvanka + 2, bolvanka + 3, bolvanka + 4, bolvanka + 5, bolvanka + 6, bolvanka + 7, bolvanka + 8, bolvanka + 9};

    //printf ("123");

    printMassive (bolvanka, 10);

    qsortMy ((void**)array, 5, 9, (int (*) (void*, void*)) compareInt);

    return 0;
}*/

void swap (void* array[], int i, int j)
{
    void *tempPointer;
    tempPointer = array [i];
    array [i] = array [j];
    array [j] = tempPointer;
}

void qsortMy (void *array[], int first, int last, int (*comparator) (void*, void*))
{
    int pivot, i, j = 0;
    pivot = first + 1 + (last - first)/2;

    if (1 < last - first)
    {
    swap (array, pivot, last);
    pivot = last;

    i = first;
    j = last - 1;

        while (i < j)
        {
            while ((*comparator) (array[pivot], array[i]) >= 0 && i < last - 1)
                i++;

            while (!( (*comparator) (array[pivot], array[j]) >= 0) && i < j)  // j > pivot
                j--;

            if (i < j)
                swap (array, i, j);
        }

        swap (array, j, pivot);

        printText ((char**)array, 10);

        if (j > 0)
        {
            qsortMy (array, first, j - 1, comparator);
            qsortMy (array, j + 1, last, comparator);
        }
    }
    else
        if ((*comparator) (array[last], array[first]) < 0)
            swap (array, last, first);

}

void printMassive (int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf ("%d ", array[i]);
    }

    printf ("\n");
}

int compareInt (int* n1, int* n2)
{
    printf ("comparing %d >= %d -> %d\n", *n1, *n2, (*n1 >= *n2) ? 1 : 0);

    return (*n1 >= *n2) ? 1 : 0;
}

void printText (char* text[], int rows)
{
    for (int counter = 0; counter < rows;  counter++)
        printf ("%s", text [counter]);
}
