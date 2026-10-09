#include <stdio.h>
#include <unistd.h>

int main(){

    int n, fact = 1;

    printf("Enter n: ");
    scanf("%d", &n);

    pid_t pid = fork();

    if(pid == 0){

        int a = 0, b = 1, c;
        printf("Fibonacci: ");
        for (int i = 0;i < n;i++) {
            printf("%d ", a);
            c = a + b;
            a = b;
            b = c;
        }
        printf("\n");
    }
    else{
        for (int i = 1; i <= n; i++)
            fact *= i;
        printf("Factorial: %d\n", fact);
    }
    return 0;
}
