
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

    int fd[2];
    pipe(fd);
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    pid_t pid = fork();
    if (pid == 0) {

        close(fd[1]);
        int sum;
        read(fd[0], &sum, sizeof(sum));
        printf("Child received sum = %d\n", sum);
        int prime = 1;
        if (sum < 2)
            prime = 0;

        for (int i = 2; i * i <= sum; i++) {
            if (sum % i == 0) {
                prime = 0;
                break;
            }
        }
        if (prime)
            printf("Sum is Prime\n");
        else
            printf("Sum is Not Prime\n");

        close(fd[0]);
    }
    else {
        close(fd[0]);

        int sum = 0;

        for (int i = 0; i < n; i++)
            sum += arr[i];
        write(fd[1], &sum, sizeof(sum));
        close(fd[1]);
        wait(NULL);
    }

    return 0;
}
