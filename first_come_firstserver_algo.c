#include <stdio.h>

// Structure to represent each process
struct Process {
    int pid;          // Process ID
    int burstTime;    // Burst time
    int waitingTime;  // Waiting time
};

// Function to calculate the waiting time
void findWaitingTime(struct Process proc[], int n) {
    proc[0].waitingTime = 0; // First process has 0 waiting time

    // Calculate waiting time for each process
    for (int i = 1; i < n; i++) {
        proc[i].waitingTime = proc[i - 1].waitingTime + proc[i - 1].burstTime;
    }
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

    // Calculate waiting time for each process
    findWaitingTime(proc, n);

    // Print the result
    printf("\nProcess ID\tBurst Time\tWaiting Time");
    for (int i = 0; i < n; i++) {
        printf("\nP%d\t\t%d\t\t%d", proc[i].pid, proc[i].burstTime, proc[i].waitingTime);
    }

    return 0;
}
