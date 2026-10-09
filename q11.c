#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

    pid_t pid = fork();
    if(pid == 0){
        printf("Child exiting...\n");
        exit(0);
    }
    else{
        printf("Parent sleeping...\n");
        sleep(10);
        printf("Parent exiting...\n");
    }
    return 0;
}
