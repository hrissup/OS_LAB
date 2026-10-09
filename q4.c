#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

    pid_t pid = fork();

    if(pid == 0){
        for(int i = 1; i <= 5; i++)
            printf("%d ", i);
        printf("\n");
    }
    else{
        wait(NULL);
        printf("Child completed.\n");
    }
    return 0;
}
