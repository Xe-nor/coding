#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int x = 2;
    int y;
    x = y;
    for (y = 6; x <= 6; x++, y--)
    {
        if (x < y)
            continue;
        if (x > y)
            break;
        else
            printf("%d\t%d\n", x, y);
    };
};