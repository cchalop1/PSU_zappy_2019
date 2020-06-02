/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** start_server
*/

#include "server.h"

static int accept_client(server_t* server)
{
    struct sockaddr_in client;
    int fd_client;
    int len = sizeof(struct sockaddr_in);

    fd_client
        = accept(server->sockfd, (struct sockaddr*)&client, (socklen_t*)&len);
    if (fd_client < 0) {
        fprintf(stderr, "accept fail (%s)\n", strerror(errno));
        return -1;
    }
    return fd_client;
}

int start_server(server_t *server)
{
    int fd = accept_client(server);
    printf("new client = %d\n", fd);
    // struct pollfd fds[2];
    // int ret;

    // fds[0].fd = STDIN_FILENO;
    // fds[0].events = POLLIN;
}