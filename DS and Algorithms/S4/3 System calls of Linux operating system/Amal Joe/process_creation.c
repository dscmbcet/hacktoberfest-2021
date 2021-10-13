#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
    printf("WELCOME TO SIMPLE CALCULATOR, my pid = %d\n\n", getpid());
    // fork will return 0 to child process and pid of child process to parent process.
    // if fork failed, it will return a negative number
    pid_t f = fork();
    if(f == 0) {
        // child will execute this block of code
        execlp("./calculator.sh", "calculator.sh", NULL);
    } else if (f > 0) {
        // parent will execute this block of code
        // parent will wait for the child process to complete its execution
        wait(NULL);
        printf("\nThank you for using our program. Have a nice day :)\n");
        return 0;
    } else {
        // this will be executed by parent if fork failed
        printf("An error occured while forking. This shouldn't be happening :(\n");
        return 1;
    }
}