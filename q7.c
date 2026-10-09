#include <stdio.h>
#include <unistd.h>

int main(){

    pid_t pid = fork();

    if (pid == 0){
        printf("Odd: ");
        for (int i = 1; i <= 19; i += 2)
            printf("%d ", i);
    }
    else{
        printf("Even: ");
        for (int i = 2;i <= 20;i += 2)
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}
