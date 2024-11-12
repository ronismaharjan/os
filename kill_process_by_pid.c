#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    // Create a child process
    pid_t pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        printf("Child Process:\n");
        printf(" - Child Process ID: %d\n", getpid());
        printf(" - Parent Process ID: %d\n", getppid());
    }
    else {
        // Parent process
        printf("Parent Process:\n");
        printf(" - Parent Process ID: %d\n", getpid());
        printf(" - Created Child Process ID: %d\n", pid);
    }

    return 0;
}
