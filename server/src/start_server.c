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

#define TIMEOUT 5000
int start_server(server_t* server)
{
    struct pollfd* fds
        = malloc(sizeof(struct pollfd) * (server->clients_nb + 1));
    int ret;
    fds[0].fd = server->sockfd;
    fds[0].events = POLLIN;

    while (1) {
        ret = poll(fds, server->clients_nb + 1, TIMEOUT);
        if (!ret) {
            printf("%d seconds elapsed.\n", TIMEOUT);
        }
        if (fds[0].revents & POLLIN) {
            fds[1].fd = accept_client(server);
            fds[1].events = POLLIN;
            printf("new client\n");
        }
        if (fds[1].revents & POLLIN) {
            char buf[BUFFER_SIZE];
            read(fds[1].fd, buf, BUFFER_SIZE);
            printf("%s\n", buf);
            printf("new client\n");
        }
    }
    return 0;
    // TODO: use poll for multiple connectin
    // init poll
    // while 1
    // int fd = accept_client(server);
    // printf("new client = %d\n", fd);
    // struct pollfd fds[2];
    // int ret;

    // fds[0].fd = STDIN_FILENO;
    // fds[0].events = POL;
}