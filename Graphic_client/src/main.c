/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** main
*/

#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <string.h>

#define SA struct sockaddr

void client_loop(int sock)
{
    char *buff;
    int n = 0;

    while (1)
    {
        n = 0;
        buff = malloc(sizeof(char) * 160);
        while ((buff[n++] = getchar()) != '\n')
            ;
        buff[n] = '\0';
        send(sock, buff, strlen(buff), 0);
        read(sock, buff, 160);
        printf("%s\n", buff);
        buff = NULL;
        free(buff);
    }
}

int main(int argc, char const *argv[])
{
    int sock;
    struct sockaddr_in sin;
    int fd;

    if (argc != 3)
        return 84;
    sock = socket(AF_INET, SOCK_STREAM, 0); 
    if (sock == -1)
        exit(84);
    bzero(&sin, sizeof(sin)); 
    sin.sin_family = AF_INET; 
    sin.sin_addr.s_addr = inet_addr(argv[1]);
    sin.sin_port = htons(atoi(argv[2])); 
    if ((fd = connect(sock, (SA*)&sin, sizeof(sin))) != 0) 
        exit(84); 
    else
        client_loop(sock);
    return 0;
}