#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void findwt(int processes[], int bt[], int n, int wt[])
{
    wt[0] = 0;

    for (int i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}
void findtat(int processes[], int bt[], int n, int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
    }
}
void findavg(int processes[], int bt[], int n)
{
    int avgwt = 0, avgtat = 0;
    int wt[n], tat[n];

    findwt(processes, bt, n, wt);
    findtat(processes, bt, n, wt, tat);

    printf("process \t\t wt\t\t bt\t\t tat");

    for (int i = 0; i < n; i++)
    {
        avgtat = avgtat + tat[i];
        avgwt = avgwt + wt[i];
        printf("\n%d \t\t\t %d \t\t %d\t\t %d", i + 1, wt[i], bt[i], tat[i]);
    }
}

int main()
{

    int n;
    int bt[10];
    int processes[10];

    printf("enter the no of processes: ");
    scanf("%d", &n);

    printf("enter each process: \n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d: \n", i+1);
        scanf("%d", &processes[i]);
    }
    
    
    printf("enter burst time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("process %d : \n", i + 1);
        scanf("%d", &bt[i]);
    }

    findavg(processes, bt, n);

    return 0;
}