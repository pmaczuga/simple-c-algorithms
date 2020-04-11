#include "sort.h"

#include "utils.h"

#include <stdlib.h>
#include <stddef.h>

void *get_elem(void *arr, size_t elem_size, int index)
{
    char *a = arr;
    return a + index * elem_size;
}


void insertion_sort(void *arr, size_t size, size_t elem_size, int compare(const void *a, const void *b))
{
    void *key = malloc(size);
    for (unsigned int i = 1; i < size; i++)
    {
        copy_to(get_elem(arr, elem_size, i), key, elem_size);

        int j = i - 1;
        while (j >=0 && compare(get_elem(arr, elem_size, j), key) > 0)
        {
            void *a = get_elem(arr, elem_size, j);
            void *b = get_elem(arr, elem_size, j + 1);
            copy_to(a, b, elem_size);
            j--;
        }
        void *pos = get_elem(arr, elem_size, j+1);
        copy_to(key, pos, elem_size);
    }
    free(key);
}
