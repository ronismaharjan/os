#include <stdio.h>
#include <stdbool.h>

#define MAX 10

// Function to check if a process can finish with the current available resources
bool isSafe(int n, int m, int avail[], int max[][m], int allot[][m], int safeSeq[]) {
    int work[m];
    bool finish[n];
    
    // Copy available resources to work[]
    for (int i = 0; i < m; i++) {
        work[i] = avail[i];
    }

    // Initialize finish[] as false
    for (int i = 0; i < n; i++) {
        finish[i] = false;
    }

    int count = 0; // Number of processes that have finished

    // Try to find a process that can be completed
    while (count < n) {
        bool found = false;
        for (int p = 0; p < n; p++) {
            if (!finish[p]) {
                // Check if all resources needed by the process can be allocated
                bool canFinish = true;
                for (int r = 0; r < m; r++) {
                    if (max[p][r] - allot[p][r] > work[r]) {
                        canFinish = false;
                        break;
                    }
                }

                // If the process can finish, add its resources to work[]
                if (canFinish) {
                    for (int r = 0; r < m; r++) {
                        work[r] += allot[p][r];
                    }
                    finish[p] = true;
                    safeSeq[count] = p; // Store the process ID in the safe sequence
                    count++;
                    found = true;
                    break;
                }
            }
        }

        // If no process can finish, the system is in an unsafe state
        if (!found) {
            return false;
        }
    }

    // If all processes can finish, return true
    return true;
}

int main() {
    int n, m;

    // Get the number of processes (n) and resources (m)
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int avail[m];
    int max[n][m];
    int allot[n][m];
    int safeSeq[n];

    // Get the available resources
    printf("Enter the available resources (space separated):\n");
    for (int i = 0; i < m; i++) {
        printf("Resource %d: ", i);
        scanf("%d", &avail[i]);
    }

    // Get the maximum demand matrix
    printf("Enter the maximum demand matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Get the allocation matrix
    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &allot[i][j]);
        }
    }

    // Calculate the total allocation for each resource
    int totalAlloc[m];
    for (int j = 0; j < m; j++) {
        totalAlloc[j] = 0;
        for (int i = 0; i < n; i++) {
            totalAlloc[j] += allot[i][j];
        }
    }

    // Display the available resources and total allocation
    printf("\nAvailable Resources: ");
    for (int i = 0; i < m; i++) {
        printf("R%d: %d ", i, avail[i]);
    }
    printf("\n");

    printf("Total Allocation of Resources: ");
    for (int i = 0; i < m; i++) {
        printf("R%d: %d ", i, totalAlloc[i]);
    }
    printf("\n");

    // Check system safety and display the safe sequence
    if (isSafe(n, m, avail, max, allot, safeSeq)) {
        printf("The system is in a safe state.\n");
        printf("Safe Sequence: ");
        for (int i = 0; i < n; i++) {
            printf("P%d ", safeSeq[i]);
        }
        printf("\n");
    } else {
        printf("The system is in an unsafe state.\n");
    }

    return 0;
}
