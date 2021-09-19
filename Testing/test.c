#include "myAssert.h"
#include "sort.h"

int main()
{
    int myList[10];

    for (int i = 0; i < 10; i++)
    {
        myList[i] = rand() % 300;
    }

    dump_list("UNSORTED LIST", myList, 0, 9);
    quicksort(myList, 0, 9, sizeof (int), compareInt);
    dump_list("SORTED LIST", myList, 0, 9);

    printf ("array is sorted: %d\n", isSortedInt (myList, 10));

    return 0;
}
