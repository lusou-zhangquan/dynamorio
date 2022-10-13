#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = getpid();
    printf("Hello: pid %d\n", pid);
    pid_t ppid = getppid();
    printf("Hello: parent pid %d\n", ppid);
    /* sleep(3);
    printf("\nHello: sending SIGUSR1 to parent %d \n", ppid);
    kill(ppid, SIGUSR1); */
    printf("Hello World \n");
}
