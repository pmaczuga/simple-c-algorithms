#include "sort.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main(int argc, char *argv[])
{
    int arr[10] = {3,2,6,3,10,20,1,3,7,13};
    size_t size = 10;

    for(int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertion_sort((void *)arr, size, sizeof(int), cmp);

    for(int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
