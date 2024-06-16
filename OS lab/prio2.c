#include <stdio.h>

#define MAX_PROCESS 10

// Structure to represent a process
struct Process {
    int id;
    int burst_time;
    int priority;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
};

// Function to sort processes based on priority
void sortProcesses(struct Process processes[], int n) {
    int i, j;
    struct Process temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, i, time = 0, total_waiting_time = 0, total_turnaround_time = 0;
    struct Process processes[MAX_PROCESS];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input burst time and priority for each process
    printf("Enter burst time and priority for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d burst time: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        printf("Process %d priority: ", i + 1);
        scanf("%d", &processes[i].priority);
        processes[i].id = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    // Execute processes
    while (1) {
        int done = 1;

        // Check if all processes are executed
        for (i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                done = 0;

                // Check if there's a process with higher priority
                // that needs to be executed
                for (int j = 0; j < n; j++) {
                    if (processes[j].remaining_time > 0 && processes[j].priority < processes[i].priority) {
                        done = 0;
                        time++;
                        processes[j].remaining_time--;
                        for (int k = 0; k < n; k++) {
                            if (k != j && processes[k].remaining_time > 0) {
                                processes[k].waiting_time++;
                            }
                        }
                        break;
                    }
                }

                if (done == 1) {
                    time++;
                    processes[i].remaining_time--;
                    for (int k = 0; k < n; k++) {
                        if (k != i && processes[k].remaining_time > 0) {
                            processes[k].waiting_time++;
                        }
                    }
                }

                if (processes[i].remaining_time == 0) {
                    processes[i].turnaround_time = time;
                }
            }
        }

        if (done == 1) {
            break;
        }
    }

    // Calculate total waiting time and turnaround time
    for (i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    // Print average waiting time and turnaround time
    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);

    // Print waiting time and turnaround time for each process
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].priority, processes[i].waiting_time, processes[i].turnaround_time);
    }

    return 0;
}
