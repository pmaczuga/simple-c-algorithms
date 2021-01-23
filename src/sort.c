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
        memcpy(key, get_elem(arr, elem_size, i), elem_size);

        int j = i - 1;
        while (j >=0 && compare(get_elem(arr, elem_size, j), key) > 0)
        {
            void *a = get_elem(arr, elem_size, j);
            void *b = get_elem(arr, elem_size, j + 1);
            memcpy(b, a, elem_size);
            j--;
        }
        void *pos = get_elem(arr, elem_size, j+1);
        memcpy(pos, key, elem_size);
    }
    free(key);
}


void selection_sort(void *arr, size_t size, size_t elem_size, int compare(const void  *a, const void *b))
{  
    for (unsigned int i = 0; i < size - 1; i++)
    {
        void *min_elem = get_elem(arr, elem_size, i);
        for (unsigned int j = i + 1; j < size; j++)
        {
            if (compare(get_elem(arr, elem_size, j), min_elem) < 0)
            {
                min_elem = get_elem(arr, elem_size, j);
            }
        }
        if (min_elem != get_elem(arr, elem_size, i))
            swap(min_elem, get_elem(arr, elem_size, i), elem_size);
    }
}


void bubble_sort(void *arr, size_t size, size_t elem_size, int compare(const void *a, const void *b))
{
    for (unsigned int i = 0; i < size - 1; i++)
    {
        for (unsigned int j = 0; j < size-i-1; j++)
        {
            void *a = get_elem(arr, elem_size, j);
            void *b = get_elem(arr, elem_size, j+1);
            if (compare(a, b) > 0)
                swap(a, b, elem_size);
        }
    }
}


void _merge_sort(void *arr, int p, int q, size_t elem_size, int compare(const void  *a, const void *b));
void _merge(void *arr, int p, int q, int r, size_t elem_size, int compare(const void  *a, const void *b));

void merge_sort(void *arr, size_t size, size_t elem_size, int compare(const void  *a, const void *b))
{
    _merge_sort(arr, 0, size-1, elem_size, compare);
}

void _merge_sort(void *arr, int p, int r, size_t elem_size, int compare(const void  *a, const void *b))
{
    if (p < r)
    {
        int q = (p+r)/2;
        _merge_sort(arr, p, q, elem_size, compare);
        _merge_sort(arr, q+1, r, elem_size, compare);
        _merge(arr, p, q, r, elem_size, compare);
    }
}

void _merge(void *arr, int p, int q, int r, size_t elem_size, int compare(const void  *a, const void *b))
{
    int left_size = q-p+1;
    int right_size = r-q;
    void *left = malloc(left_size * elem_size);
    void *right = malloc(right_size * elem_size);
    int j = 0;
    for (int i = p; i <= q; i++)
    {
        memcpy(get_elem(left, elem_size, j), get_elem(arr, elem_size, i), elem_size);
        j++;
    }
    j = 0;
    for (int i = q+1; i <= r; i++)
    {
        memcpy(get_elem(right, elem_size, j), get_elem(arr, elem_size, i), elem_size);
        j++;
    }

    int i = p;
    int left_i = 0;
    int right_i = 0;
    while (left_i < left_size && right_i < right_size)
    {
        void *left_elem = get_elem(left, elem_size, left_i);
        void *right_elem = get_elem(right, elem_size, right_i);
        void *next_in_arr = get_elem(arr, elem_size, i);
        if (compare(left_elem, right_elem) < 0)
        {
            memcpy(next_in_arr, left_elem, elem_size);
            left_i++;
        }
        else
        {
            memcpy(next_in_arr, right_elem, elem_size);
            right_i++;
        }
        i++;
    }

    void *not_empty;
    int not_empty_i;
    if (left_i == left_size)
    {
        not_empty = right;
        not_empty_i = right_i;
    }
    else if (right_i == right_size)
    {   
        not_empty = left;
        not_empty_i = left_i;
    }

    void *elem;
    while (i <= r)
    {
        elem = get_elem(not_empty, elem_size, not_empty_i);
        void *next_in_arr = get_elem(arr, elem_size, i);
        memcpy(next_in_arr, elem, elem_size);
        not_empty_i++;
        i++;
    }

    free(left);
    free(right);
}
