#include <stdio.h>

void sortProcesses(int processes[], int n, int burst_time[], int priority[]) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (priority[j] > priority[j + 1]) {
                temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;

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

void findWaitingTimeTurnaroundTime(int processes[], int n, int burst_time[], int priority[], int waiting_time[], int turnaround_time[]) {
    int i, total_waiting_time = 0, total_turnaround_time = 0;

    waiting_time[0] = 0;

    for (i = 1; i < n; i++) {
        waiting_time[i] = burst_time[i - 1] + waiting_time[i - 1];
        total_waiting_time += waiting_time[i];
    }

    for (i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

int main() {
    int n, i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burst_time[n], priority[n], waiting_time[n], turnaround_time[n];

    printf("Enter burst time and priority for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d burst time: ", i + 1);
        scanf("%d", &burst_time[i]);
        printf("Process %d priority: ", i + 1);
        scanf("%d", &priority[i]);
        processes[i] = i + 1; // Process IDs
    }

    sortProcesses(processes, n, burst_time, priority);
    findWaitingTimeTurnaroundTime(processes, n, burst_time, priority, waiting_time, turnaround_time);

    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], priority[i], waiting_time[i], turnaround_time[i]);
    }

    return 0;
}
