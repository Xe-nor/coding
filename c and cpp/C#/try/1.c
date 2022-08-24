#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a[] = {5, 6, *(a + 1), a[2]};
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", a[i--]);
    }
    return 0;
}
