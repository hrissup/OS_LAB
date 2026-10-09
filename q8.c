#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

    for(int i = 1;i <= 3;i++) {

        pid_t pid = fork();
        if (pid == 0){
            printf("Child %d\n", i);
            printf("PID: %d\n", getpid());
            printf("PPID: %d\n\n", getppid());
            exit(0);
        }
    }
    
    wait(NULL);
    wait(NULL);
    wait(NULL);

    printf("All children finished.\n");

    return 0;
}
