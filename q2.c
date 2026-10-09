#include <stdio.h>
#include <unistd.h>

int main(){

    pid_t pid = fork();

    if (pid == 0) {
        printf("Child PID: %d\n", getpid());
        printf("Child PPID: %d\n", getppid());
    }
    else {
        printf("Parent PID: %d\n", getpid());
        printf("Parent PPID: %d\n", getppid());
    }

    return 0;
}
