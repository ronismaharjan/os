#include <stdio.h>

struct Process {
    int pid;            // Process ID
    int burstTime;      // Burst time
    int remainingTime;  // Remaining time for the process to finish execution
    int waitingTime;    // Waiting time
    int turnAroundTime; // Turnaround time
};

void findWaitingTime(struct Process proc[], int n, int time_slice) {
    int time = 0;
    int remainingProcesses = n;
    
    while (remainingProcesses) {
        for (int i = 0; i < n; i++) {
            if (proc[i].remainingTime > 0) {
                if (proc[i].remainingTime > time_slice) {
                    time += time_slice;
                    proc[i].remainingTime -= time_slice;
                } else {
                    time += proc[i].remainingTime;
                    proc[i].waitingTime = time - proc[i].burstTime;
                    proc[i].remainingTime = 0;
                    remainingProcesses--;
                }
            }
        }
    }
}

void findTurnAroundTime(struct Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turnAroundTime = proc[i].burstTime + proc[i].waitingTime;
    }
}

void calculateAverageTimes(struct Process proc[], int n, float *avgWaitingTime, float *avgTurnAroundTime) {
    int totalWaitingTime = 0, totalTurnAroundTime = 0;

    for (int i = 0; i < n; i++) {
        totalWaitingTime += proc[i].waitingTime;
        totalTurnAroundTime += proc[i].turnAroundTime;
    }

    *avgWaitingTime = (float)totalWaitingTime / n;
    *avgTurnAroundTime = (float)totalTurnAroundTime / n;
}

int main() {
    int n, time_slice;

    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];

    // Input burst times for each process
    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        printf("Enter burst time for Process P%d: ", proc[i].pid);
        scanf("%d", &proc[i].burstTime);
        proc[i].remainingTime = proc[i].burstTime; // Initially remaining time is the burst time
    }

    // Input the  time_slice
    printf("Enter time slice: ");
    scanf("%d", &time_slice);

    // Calculate waiting times and turnaround times using round robin scheduling
    findWaitingTime(proc, n, time_slice);
    findTurnAroundTime(proc, n);

    // Calculate average waiting time and average turnaround time
    float avgWaitingTime, avgTurnAroundTime;
    calculateAverageTimes(proc, n, &avgWaitingTime, &avgTurnAroundTime);

    // Print process details in a table format
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burstTime, proc[i].waitingTime, proc[i].turnAroundTime);
    }

    // Print average times
    printf("\nAverage Waiting Time: %.2f", avgWaitingTime);
    printf("\nAverage Turnaround Time: %.2f", avgTurnAroundTime);

    return 0;
}
