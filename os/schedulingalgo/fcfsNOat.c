#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define max 30

void main()
{
    int i, j, n, bt[max], wt[max], tat[max];
    float atat = 0, awt = 0;
    printf("enter the no. of process(s):");
    scanf("%d", &n);
    printf("enter the BT of process(s):");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }
    printf("process_no.\t burst_time\t waiting_time\t turn_around_time\n");
    for (i = 0; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;
        for (j = 0; j < i; j++)
        {
            wt[i] = wt[i] + bt[j];
        }
        tat[i] = wt[i] + bt[i];
        atat = atat + tat[i];
        awt = awt + wt[i];
        printf("%d\t\t%d\t\t\t%d\t\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    awt = awt / n;
    atat = atat / n;
    printf("awt and atat are:%2f and %2f", awt, atat);
    getch();
}