#include <stdio.h>
#include <unistd.h>

int main() {
    // Get the current process ID
    pid_t process_id = getpid();

    // Print the process ID
    printf("Current Process ID: %d\n", process_id);

    return 0;
}
