/* -- httpd.c -- */

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

#define LISTENADDR "0.0.0.0"

/* Global */
char *error;

/* returns -1 if error occured, othewise the socket fd */
int serv_init(int port)
{
    int sockfd;
    sockaddr_in srv;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error = "socket() returned -1";
        return sockfd;
    }
    memset(&srv, 0, sizeof(srv));
    
    srv.sin_family = AF_INET;
    srv.sin_port = htons(port);
    srv.sin_addr.s_addr = inet_addr(LISTENADDR);

    if (bind(sockfd, &srv, sizeof(srv)) != 0) {
        error = "bind() != 0";
        return -1;
    }    
    return sockfd;
}

int main(int ac, char *av[])
{
    int s;
    char *port;

    if (ac != 2) {
        fprintf(stderr, "Usage: %s <listening port>\n", av[0]);
        return 1;
    }
    else port = av[1];
    s = serv_init(atoi(port));
    return 0;
}
