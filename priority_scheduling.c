#include <stdio.h>

// Structure to represent each process
struct Process {
    int pid;            // Process ID
    int burstTime;      // Burst time
    int waitingTime;    // Waiting time
    int turnAroundTime; // Turnaround time
    int priority;       // Priority of the process
};

// Function to sort the processes based on their priority (ascending order)
void sortProcesses(struct Process proc[], int n) {
    struct Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (proc[i].priority > proc[j].priority) {
                // Swap the processes based on priority
                temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}

// Function to calculate the waiting time
void findWaitingTime(struct Process proc[], int n) {
    proc[0].waitingTime = 0; // First process has 0 waiting time

    // Calculate waiting time for each process
    for (int i = 1; i < n; i++) {
        proc[i].waitingTime = proc[i - 1].waitingTime + proc[i - 1].burstTime;
    }
}

// Function to calculate the turnaround time
void findTurnAroundTime(struct Process proc[], int n) {
    // Turnaround time is the sum of burst time and waiting time
    for (int i = 0; i < n; i++) {
        proc[i].turnAroundTime = proc[i].burstTime + proc[i].waitingTime;
    }
}

// Function to calculate the average waiting time and turnaround time
void calculateAverageTimes(struct Process proc[], int n, float* avgWaitingTime, float* avgTurnAroundTime) {
    int totalWaitingTime = 0, totalTurnAroundTime = 0;
    
    // Calculate total waiting time and total turnaround time
    for (int i = 0; i < n; i++) {
        totalWaitingTime += proc[i].waitingTime;
        totalTurnAroundTime += proc[i].turnAroundTime;
    }

    // Calculate average times
    *avgWaitingTime = (float)totalWaitingTime / n;
    *avgTurnAroundTime = (float)totalTurnAroundTime / n;
}

// Driver Code
int main() {
    int n;

    // Take number of processes as input
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];

    // Take process details as input
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for process %d:\n", i + 1);
        proc[i].pid = i + 1;
        printf("Burst Time: ");
        scanf("%d", &proc[i].burstTime);
        printf("Priority (lower number means higher priority): ");
        scanf("%d", &proc[i].priority);
    }

    // Sort processes based on priority (SJF with priority)
    sortProcesses(proc, n);

    // Calculate waiting time and turnaround time
    findWaitingTime(proc, n);
    findTurnAroundTime(proc, n);

    // Calculate average waiting time and turnaround time
    float avgWaitingTime, avgTurnAroundTime;
    calculateAverageTimes(proc, n, &avgWaitingTime, &avgTurnAroundTime);

    // Print the result table for processes
    printf("\nProcess ID\tBurst Time\tPriority\tWaiting Time\tTurnaround Time");
    for (int i = 0; i < n; i++) {
        printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d", proc[i].pid, proc[i].burstTime, proc[i].priority, proc[i].waitingTime, proc[i].turnAroundTime);
    }

    // Print the average times in a separate table
    printf("\nAverage Waiting Time: \t%.2f", avgWaitingTime);
    printf("\nAverage Turnaround Time: \t%.2f\n", avgTurnAroundTime);

    return 0;
}
