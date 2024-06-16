#include <stdio.h>

#define MAX_PROCESS 10

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
} Process;

void sortProcesses(Process processes[], int n) {
    int i, j;
    Process temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

int findShortestJob(Process processes[], int n, int current_time) {
    int shortest_job_index = -1;
    int shortest_job_time = __INT_MAX__;
    for (int i = 0; i < n; i++) {
        if (processes[i].arrival_time <= current_time && processes[i].remaining_time < shortest_job_time && processes[i].remaining_time > 0) {
            shortest_job_index = i;
            shortest_job_time = processes[i].remaining_time;
        }
    }
    return shortest_job_index;
}

void preemptiveSJF(Process processes[], int n) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int completed = 0;
    int current_time = 0;

    printf("Gantt Chart:\n");
    printf("-----------\n");

    while (completed < n) {
        int shortest_job_index = findShortestJob(processes, n, current_time);

        if (shortest_job_index == -1) {
            current_time++;
            continue;
        }

        Process *current_process = &processes[shortest_job_index];
        printf("| P%d ", current_process->pid);
        current_process->remaining_time--;

        if (current_process->remaining_time == 0) {
            completed++;
            int turnaround_time = current_time + 1 - current_process->arrival_time;
            int waiting_time = turnaround_time - current_process->burst_time;
            total_waiting_time += waiting_time;
            total_turnaround_time += turnaround_time;
        }

        current_time++;
    }

    printf("|\n");
    printf("\nAverage Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

int main() {
    int n;
    Process processes[MAX_PROCESS];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d arrival time: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Process %d burst time: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }

    sortProcesses(processes, n);
    preemptiveSJF(processes, n);

    return 0;
}
