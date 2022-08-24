#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 30

int main()
{
    int n, t, bt[max], p[max], tat[max], wt[max], temp, sq, qt, count = 0, rembt[max];

    printf("enter the no of process: \n");
    scanf("%d", &n);

    printf("enter the process no: \n");
    for (int i = 0; i < n; i++)
    {
        printf("process %d: ", i + 1);
        scanf("%d", &p[i]);
    }

    printf("enter the burst time for each process: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
        rembt[i] = bt[i];
    }

    printf("enter quantum time: \n");
    scanf("%d", &qt);

    while (1) 
    {
        for (int i = 0, count = 0; i < n; i++)
        {
            temp = qt;
            if (rembt[i] == 0)
            {
                count++;
                break;
            }
            if (rembt[i] > qt)
            {
                rembt[i] = rembt[i] - qt;
            }
            else
            {
                if (rembt[i] >= 0)
                {
                    temp = rembt[i];
                    rembt[i] = 0;
                }
            }
            sq = sq + temp;
            tat[i] = sq;
        }
        if (n == count)
        {
            break;
        }
    }
    printf("process\t wt\t bt\t tat \n");
    for (int i = 0; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;
        for (int j = 0; j < i; j++)
        {
            wt[i] = wt[i] + bt[j];
        }

        tat[i] = wt[i] + bt[i];
        printf("%d \t %d\t %d \t %d \n", p[i], wt[i], bt[i], tat[i]);
    }
    return 0;
}