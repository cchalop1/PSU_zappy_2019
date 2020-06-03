/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** start_server
*/

#include "server.h"

#define TIMEOUT 5000

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

int init_poll(server_t* server)
{
    server->fds = NULL;
    server->fds = realloc(server->fds, sizeof(struct pollfd));
    server->fds[0].fd = server->sockfd;
    server->fds[0].events = POLLIN;
}

int manage_client(server_t* server)
{
    // TODO: nb client
    int ret = poll(server->fds, 3, TIMEOUT);

    if (server->fds[0].revents & POLLIN) {
        // new client
        // TODO: realloc fds
        // fds[1].fd = accept_client(server);
        // fds[1].events = POLLIN;
        // new_client(fds[1].fd, server);
    }
    return EXIT_SUCCESS;
}

int start_server(server_t* server)
{
    init_poll(server);

    while (1) {
        if (manage_client(server))
            return EXIT_FAILURE;
    }
    return 0;
}