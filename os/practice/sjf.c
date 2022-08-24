#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 30

int main()
{
    int n, t, bt[max], p[max], tat[max], wt[max];

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
    }

    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (bt[j]>bt[j+1])
            {
                t = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = t;

                t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;
            }
            
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