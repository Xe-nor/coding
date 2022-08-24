// #include <stdio.h>

// int main()
// {
//     int size,temp;
//     scanf("%d", &size);
//     int a[size]; 

//     for (int i = 0; i < size; i++)
//     {
//         scanf("%d", &a[i]);
//     }

//     for (int i = 0; i < size / 2; i++)
//     {
//         temp = a[0];
//         a[0] = a[size - i - 1];
//         a[size - i - 1] = temp;
//     }
//     for (int i = 0; i < size; i++)
//     {
//         printf("%d ", a[i]);
//     }
// }

#include <stdio.h>

int main()
{
    int temp, n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
}