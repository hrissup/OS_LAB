#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

    pid_t pid = fork();
    if(pid == 0){
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());
        sleep(5);
        printf("After parent exits:\n");
        printf("Parent PID: %d\n", getppid());

    }
    else{
        printf("Parent exiting...\n");
        exit(0);
    }
    return 0;
}
