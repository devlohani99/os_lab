#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid;
    int status;
    child_pid = fork();
 
    if (child_pid == -1) { 
        perror("Fork failed");
        exit(1);
    }

    if (child_pid == 0) {
        printf("Child process: My PID is %d\n", getpid());
        char *args[] = {"ls", "-l", NULL};
        if (execvp("ls", args) == -1) {
            perror("Exec failed");
            exit(1);
        }
    } 
    else {
        printf("Parent process: My PID is %d\n", getpid());
        wait(&status);
        if (WIFEXITED(status)) {
            printf("Child process terminated with status %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Child process terminated due to signal %d\n", WTERMSIG(status));
        }
    }

    return 0;
}
