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
    int pivot = first + 1 + (last - first)/2;
    printf ("pivot = %s\n", (char*)array[pivot]);
    //swap (array, pivot, last);

    //pivot = last;
    int i = first;
    int j = last - 1;



    if (first < last)
    {
        //printText ((char**)array, 10);

        while (i < j)
        {
            //printf ("array[pivot = %d] = %s\n", pivot, (char*)array[pivot]);

            while ((*comparator) (array[pivot], array[i]) >= 0 && i < last)
            {
                i++;
            }
            //printf ("array[i = %d] = %s\n", i, (char*)array[i]);

            while (!((*comparator) (array[pivot], array[j]) >= 0))
            {
                j--;
            }
            //printf ("array[j = %d] = %s\n", j, (char*)array[j]);

            if (i < j)
            {
                //printf ("swapping\n");
                swap (array, i, j);
            }
        }

        //printf ("RECURSE\n");

        swap (array, pivot, j);

        //printText ((char**)array, 10);

        if (j > 0)
        {   /*
            printf ("first = %d, last = %d"
                    "\n"
                    "first = %d, last = %d\n", first, j - 1, j + 1, last);*/

            qsortMy (array, first, j - 1, comparator);
            qsortMy (array, j + 1, last, comparator);
        }
    }
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
