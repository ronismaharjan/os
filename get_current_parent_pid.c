#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = getpid();
    pid_t ppid = getppid();
    
    printf("Current Process ID: %d\n", pid);
    printf("Parent Process ID: %d\n", ppid);  // Corrected this line
    
    return 0;
}

