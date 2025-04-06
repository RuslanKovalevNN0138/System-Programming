#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#define BUFFER_SIZE 1024

int pipefds[2];
int status, pid;
char writemessage[BUFFER_SIZE];
char readmessage[BUFFER_SIZE];

void pipe_operation()
{
    pid = fork();
    if(pid == 0){
        read(pipefds[0], readmessage, sizeof(readmessage));
        printf("Child process: reading from pipe - message is %s",readmessage);
    }
    else
    {
        // Parent process to write the data
        printf("Parent Process: Writing to pipe - message is %s",writemessage);
        write(pipefds[1],writemessage,sizeof(writemessage));
    }
}

int main()
{
    status = pipe(pipefds);
    if(status == -1){
        printf("Unable to create pipe\n");
        return 1;
    }

    printf("Enter the message to write into pipe\n");
    printf("To exit type \"quit\"\n");
    fgets(writemessage, BUFSIZ, stdin);

    while(strcmp(writemessage, "quite\n")!=0){
        pipe_operation();
        fgets(writemessage, BUFSIZ, stdin);
        kill(pid, SIGKILL);
    }
    return 0;
}