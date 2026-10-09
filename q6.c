
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    pid_t p1 = fork();

    if(p1 == 0){

        int a = 0, b = 1, c;
        printf("Fibonacci: ");
        for (int i = 0;i < n;i++) {
            printf("%d ", a);
            c = a+b;
            a = b;
            b = c;
        }
        printf("\n");
        return 0;
    }

    pid_t p2 = fork();
    if(p2 == 0){
        int fact = 1;
        for (int i = 1; i <= n; i++)
            fact *= i;
        printf("Factorial: %d\n", fact);
        return 0;
    }

    int sum = 0;
    for (int i = 1;i <= n;i++)
        sum += i;
    printf("Sum: %d\n", sum);

    wait(NULL);
    wait(NULL);

    return 0;
}
