#include <stdio.h>

void sortProcesses(int processes[], int n, int burst_time[])
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (burst_time[j] > burst_time[j + 1])
            {
                temp = burst_time[j];
                burst_time[j] = burst_time[j + 1];
                burst_time[j + 1] = temp;

                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void findWaitingTimeTurnaroundTime(int processes[], int n, int burst_time[], int waiting_time[], int turnaround_time[])
{
    int i, total_waiting_time = 0, total_turnaround_time = 0;

    waiting_time[0] = 0;

    for (i = 1; i < n; i++)
    {
        waiting_time[i] = burst_time[i - 1] + waiting_time[i - 1];
        total_waiting_time += waiting_time[i];
    }

    for (i = 0; i < n; i++)
    {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

int main()
{
    int n, i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burst_time[n], waiting_time[n], turnaround_time[n];

    printf("Enter burst time for each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        processes[i] = i + 1;
    }

    sortProcesses(processes, n, burst_time);
    findWaitingTimeTurnaroundTime(processes, n, burst_time, waiting_time, turnaround_time);

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    return 0;
}
