#include "utils.h"

int main()
{
    int a = 4;
    int b = 5;
    swap(&a, &b, sizeof(int));
    if (a==5 && b==4)
        return 0;

    return 1;
}