#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void readmatrix(int matrix[10][10], int n, int r)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void display(int matrix[10][10], int n, int r)
{

    for (int i = 0; i < n; i++)
    {
        printf("\n P%d", n);
        for (int j = 0; j < r; j++)
        {
            printf(" %d", matrix[i][j]);
        }
    }
}

int main()
{
    int Max[10][10], need[10][10], allocation[10][10], available[10], safeSequence[10], n, r;

    printf("\nenter the no of process: ");
    scanf("%d", &n);

    printf("\nenter the no of resources: ");
    scanf("%d", &r);

    printf("\nenter the initial allocation matrix: ");
    readmatrix(allocation, n, r);

    printf("\nenter the initial max matrix: ");
    readmatrix(Max, n, r);

    printf("\nenter the available resources: ");
    for (int i = 0; i < r; i++)
    {
        // scanf("%d", &available[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            need[i][j] = Max[i][j] - allocation[i][j];
        }
    }

    printf("\nmax matrix is :");
    display(Max, n, r);

    printf("\nallocation matrix is :");
    display(allocation, n, r);

    printf("\nneed matrix is :");
    display(need, n, r);

    printf("\navailble matrix is :");
    for (int i = 0; i < r; i++)
    {
        printf("\n %d", available[i]);
    }

    int k = 0, finish[10], flag;
    for (int i = 0; i < n; i++)
    {
        finish[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        flag = 0;

        if (finish[i] == 0)
        {
            for (int j = 0; j < r; i++)
            {
                if (need[i][j] > available[i])
                {
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
            {
                finish[i] = 1;
                safeSequence[k] = i;
                k++;

                for (int j = 0; j < r; j++)
                {
                    available[i] += allocation[i][j];
                }
                i = -1;
            }
        }
    }

    flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (finish[i] == 0)
        {
            printf("system is in deadlock");
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("safe sequence is : ");
        for (int i = 0; i < n; i++)
        {
            printf("%d", safeSequence[i]);
        }
    }

    return 0;
}
