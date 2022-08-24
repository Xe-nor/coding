#include <stdio.h>
#include <conio.h>
#define max 30

int main()
{

    int i, j;     // looping variable
    int n;        // no of processes
    int bt[max];  // burst time
    int at[max];  // arrival time
    int wt[max];  // waiting time
    int tat[max]; // turnaround time
    int temp[max];
    float awt = 0, atat = 0;

    // taking input

    printf("enter the no of processes");
    scanf("%d", &n);

    printf("enter the burst time of the processes");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }
    printf("enter the arrival time");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
    }
    temp[0] = 0;

    // printing table
    printf("process\t burst time\t arrival time\t waititng time\t turnaround time\n");

    for (i = 0; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;
        temp[i + 1] = temp[i] + bt[i];
        wt[i] = temp[i] - at[i];
        tat[i] = wt[i] + bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], at[i], wt[i], tat[i]);
    }
    awt = awt / n;
    atat = atat / n;
    printf("avg waiting and avg turnaround time is %f and %f", awt, atat);

    return 0;
}