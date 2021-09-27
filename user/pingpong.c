#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void pingpong()
{
    int pid = fork();
    int p[2];

    pipe(p);
    if (pid > 0)
    {
        // printf("In parent p[0]: %d\n", p[0]);
        // printf("In parent p[1]: %d\n", p[1]);
        // printf("parent: child=%d\n", pid);
        pid = wait(0);
        // printf("%d\n", p[0]);
        // printf("%d\n", p[1]);

        // I don't understand how to use pipe.
        printf("%d: received pong\n", pid);

        exit(0);
    }
    else if (pid == 0)
    {
        int p_pid = getpid();
        // printf("%d: received ping\n", p_pid);
        // write(p[1], "h", 1);
        // printf("In child p[1]:%d\n", p[1]);
        close(p[1]);
        exit(0);
    }
    else
    {
        printf("error occured");
    }
}
