#ifndef SORT_H_
#define SORT_H_H

#include <stddef.h>

void insertion_sort(void *arr, size_t size, size_t elem_size, int compare(const void  *a, const void *b));

void selection_sort(void *arr, size_t size, size_t elem_size, int compare(const void  *a, const void *b));

void merge_sort(void *arr, size_t size, size_t elem_size, int compare(const void  *a, const void *b));

#endif
