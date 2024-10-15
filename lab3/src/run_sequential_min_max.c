#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork(); //Создание дочернего процесса
    if (pid == -1) { //Обработка ошибок при создании процесса
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { //Обработка дочернего процесса
        char *args[] = {"./sequential_min_max", "1334", "10000", NULL};
        execvp(args[0], args);
        perror("execvp failed");
        exit(EXIT_FAILURE);
    } else {
        //Обработка родительского процесса
        printf("Child process ID: %d\n", pid);
    }
    return 0;
}