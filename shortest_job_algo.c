#include <stdio.h>

// Structure to represent each process
struct Process {
    int pid;          // Process ID
    int burstTime;    // Burst time
    int waitingTime;  // Waiting time
    int turnAroundTime; // Turnaround time
};

// Function to sort the processes based on burst time (Shortest Job First)
void sortProcesses(struct Process proc[], int n) {
    struct Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (proc[i].burstTime > proc[j].burstTime) {
                // Swap the processes
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
void calculateAverageTimes(struct Process proc[], int n) {
    int totalWaitingTime = 0, totalTurnAroundTime = 0;
    
    // Calculate total waiting time and total turnaround time
    for (int i = 0; i < n; i++) {
        totalWaitingTime += proc[i].waitingTime;
        totalTurnAroundTime += proc[i].turnAroundTime;
    }

    // Calculate and print average times
    float avgWaitingTime = (float)totalWaitingTime / n;
    float avgTurnAroundTime = (float)totalTurnAroundTime / n;
    
    printf("\nAverage Waiting Time: %.2f", avgWaitingTime);
    printf("\nAverage Turnaround Time: %.2f", avgTurnAroundTime);
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
    }

    // Sort processes based on burst time (SJF)
    sortProcesses(proc, n);

    // Calculate waiting time and turnaround time
    findWaitingTime(proc, n);
    findTurnAroundTime(proc, n);

    // Print the result
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time");
    for (int i = 0; i < n; i++) {
        printf("\nP%d\t\t%d\t\t%d\t\t%d", proc[i].pid, proc[i].burstTime, proc[i].waitingTime, proc[i].turnAroundTime);
    }

    // Calculate and display average times
    calculateAverageTimes(proc, n);

    return 0;
}
