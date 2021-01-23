#include "sort.h"

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int arr[10] = {2,1,5,4,7,5,2,13,11,10};
    selection_sort(arr, 10, sizeof(int), cmp);
    int properly_sorted[10] = {1,2,2,4,5,5,7,10,11,13};
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] != properly_sorted[i])
            return 1;
    }

    return 0;
}
