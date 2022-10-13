#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// function declaration
void sighup();
void sigint();
void sigquit();

void main()
{
    int pid;

    /* get child process */
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }

    if (pid > 0) {
        printf("My pid %d, my son id %d \n", getpid(), pid);
        signal(SIGHUP, sighup);
        signal(SIGINT, sigint);
        signal(SIGQUIT, sigquit);
        for (;;)
            ; /* loop for ever */
    } else
    { /* pid hold id of child */
        pid_t ppid = getppid();
        printf("\nSon: sending SIGHUP\n\n");
        kill(ppid, SIGHUP);

        sleep(3); /* pause for 3 secs */
        printf("\nSon: sending SIGINT\n\n");
        kill(ppid, SIGINT);

        sleep(3); /* pause for 3 secs */
        printf("\nSon: sending SIGQUIT\n\n");
        kill(ppid, SIGQUIT);
        sleep(3);
    }
}

// sighup() function definition
void sighup()
{
    signal(SIGHUP, sighup); /* reset signal */
    printf("Parent: I have received a SIGHUP\n");
}

// sigint() function definition
void sigint()
{
    signal(SIGINT, sigint); /* reset signal */
    printf("Parent: I have received a SIGINT\n");
}

// sigquit() function definition
void sigquit()
{
    printf("My son has Killed me!!!\n");
    exit(0);
}
