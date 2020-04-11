#include "utils.h"

#include <stdlib.h>

void copy_to(void *from, void *to, size_t size)
{
    unsigned char *p = from;
    unsigned char *q = to;
    for (unsigned int i = 0; i < size; i++)
    {
        q[i] = p[i];
    }
}

void swap(void *a, void *b, size_t size)
{
    unsigned char *p = a;
    unsigned char *q = b;
    unsigned char tmp;
    for(unsigned int i = 0; i < size; i++)
    {
        tmp = p[i];
        p[i] = q[i];
        q[i] = tmp;
    }
}
