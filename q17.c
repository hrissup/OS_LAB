#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    FILE *file;
    file = fopen("input.txt", "w");
    fprintf(file, "Name: Hrishu\n");
    fprintf(file, "Roll Number: 12345\n");
    fprintf(file, "Class: BTECH CSE\n");
    fclose(file);
    pid_t pid = fork();

    if (pid == 0) {
        file = fopen("input.txt", "r");
        char line[100];
        printf("Child reading file:\n");
        while (fgets(line, sizeof(line), file))
            printf("%s", line);
        fclose(file);
    }
    else {
        wait(NULL);
    }
    return 0;
}
