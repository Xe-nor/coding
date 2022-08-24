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
        for (int i = 0,count=0; i < n; i++)
        {
            /* code */
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
            else{
                if (rembt>=0)
                {
                    /* code */ temp = rembt[i];
                    rembt[i] = 0;
                }
                
            }
            sq = sq + temp;
            tat[i] = tat[i] + sq;
        }
        if (n==count)  
        {
            /* code */ break;
        }
        
    }
}
