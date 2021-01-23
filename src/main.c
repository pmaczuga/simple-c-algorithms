#include "sort.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void print_array(int *arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        if (arr[i]/10 == 0)
            printf("0");
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    srand((unsigned int) time(NULL));

    int a = 5;

    int *first = malloc(SIZE * sizeof(int));
    int *second = malloc(SIZE * sizeof(int));
    int *third = malloc(SIZE * sizeof(int));
    for (int i = 0; i < SIZE; i++)
    {
        int value = rand() % 10000;
        // int value = i;
        first[i] = value;
        second[i] = value;
        third[i] = value;
    }
    int arr[10] = {2,1,5,4,7,5,2,13,11,10};
    print_array(arr, 10);
    merge_sort(arr, 10, sizeof(int), cmp);
    print_array(arr, 10);

    return 0;
}
