#include stdio.h;

void f1(int a)
{
    static int b = 2;
    b++;
    a = b++ + a;
    printf("%d ", a);
};

int main()
{
    int i = 0;
    int a = 2;
    for (; i < 3; i++)
    {
        f1(++a);
    }
    printf("%d", a);
    return 0;
};