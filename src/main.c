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

    clock_t start;
    clock_t end;
    float seconds;

    start = clock();
    insertion_sort((void *)first, SIZE, sizeof(int), cmp);
    end = clock();
    seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("Inertion sort took: %f sedonds\n", seconds);

    start = clock();
    selection_sort((void *)second, SIZE, sizeof(int), cmp);
    end = clock();
    seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("Selection sort took: %f sedonds\n", seconds);

    start = clock();
    merge_sort((void *)third, SIZE, sizeof(int), cmp);
    end = clock();
    seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("Merge sort took: %f sedonds\n", seconds);

    free(first);
    free(second);
    free(third);

    return 0;
}
