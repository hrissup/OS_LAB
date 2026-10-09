#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    int n;
    printf("Enter size: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    pid_t pid = fork();
    if (pid == 0){
        int sum = 0;

        for (int i = 0; i < n; i++)
            sum += arr[i];
        printf("Sum = %d\n", sum);
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
    }
    else {
        wait(NULL);
        printf("Child completed.\n");
    }
    return 0;
}
