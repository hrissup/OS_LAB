#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    pid_t pid = fork();
    if(pid == 0){
        int prime = 1;
        if(n < 2)
            prime = 0;
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0){
                prime = 0;
                break;
            }
        }
        if(prime)
            printf("%d is Prime\n", n);
        else
            printf("%d is Not Prime\n", n);
    }
    else {
        wait(NULL);
        long long fact = 1;
        for (int i = 1;i <= n;i++)
            fact *= i;
        printf("Factorial: %lld\n", fact);
    }
    return 0;
}
