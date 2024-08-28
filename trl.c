/* trl.c - timed read line */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/select.h>
#include <sys/types.h>

char *trl( int timeout )
{
    static char buf[512];
    fd_set fd;
    struct timeval tv;
    int ret;

    FD_ZERO(&fd);
    FD_SET(0, &fd);

    tv.tv_sec = timeout;
    tv.tv_usec = 0;

    ret = select(1, &fd, 0, 0, &tv);
    if (ret && FD_ISSET(0, &fd))
    {
        memset(buf, 0, 511);
        ret = read(0, buf, 511);
        if (ret < 1)
            return 0;
        ret--;
        buf[ret] = 0;
        return buf;
    }
    else return 0;
}

int main ( void )
{
    char *name;

    printf("what's your name, think fast!!\n");
    name = trl(3);
    if (name) printf("Hello %s\n", name);
    else printf("\ntooo slow\n");
}
