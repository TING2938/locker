#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sighandle(int);

int main()
{
    signal(SIGINT, sighandle);

    while (1)
    {
        printf("wait ...\n");
        sleep(1);
    }
    return 0;
}

void sighandle(int signum)
{
    printf("get sighal: %d\n", signum);
}
