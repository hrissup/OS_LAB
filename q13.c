#include <stdio.h>
#include <unistd.h>

int main(){

    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    pid_t pid = fork();

    if (pid == 0) {
        int a = 0, b = 1, c;
        printf("Fibonacci: ");
        while (a <= n) {
            printf("%d ", a);
            c = a+b;
            a = b;
            b = c;
        }
        printf("\n");
    }
    else{
        printf("Armstrong numbers: ");
        for (int num = 1; num <= n; num++) {
            int temp = num;
            int sum = 0;
            int digits = 0;
            while(temp > 0) {
                digits++;
                temp /= 10;
            }
            temp = num;
            while (temp > 0) {
                int digit = temp % 10;
                int power = 1;
                for (int i = 0; i < digits; i++)
                    power *= digit;
                sum += power;
                temp /= 10;
            }
            if (sum == num)
                printf("%d ", num);
        }
        printf("\n");
    }

    return 0;
}
