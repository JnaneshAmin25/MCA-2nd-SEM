#include <stdio.h>

void calculateTimes(int n, int bt[], int wt[], int tat[])
{
    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}

void calculateAverageTimes(int n, int wt[], int tat[])
{
    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];
    }
    float avg_wt = total_wt / n;
    float avg_tat = total_tat / n;
    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turn-around Time: %.2f", avg_tat);
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bt[n];
    int wt[n];
    int tat[n];
    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    calculateTimes(n, bt, wt, tat);
    printf("\nProcess\tBurst Time\tWaiting Time\tTurn-around Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    calculateAverageTimes(n, wt, tat);
    return 0;
}
