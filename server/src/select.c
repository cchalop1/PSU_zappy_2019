/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** select
*/

#include "server.h"

void init_select(server_t* server)
{
    FD_ZERO(&server->current_sockets);
    FD_SET(server->sockfd, &server->current_sockets);
    server->max_client = server->sockfd;
}

bool manage_select(server_t* server)
{
    server->ready_socket = server->current_sockets;
    if (select(
            server->max_client + 1, &server->current_sockets, NULL, NULL, NULL)
        < 0) {
        fprintf(stderr, "select fail (%s)\n", strerror(errno));
        return false;
    }
    return true;
}

int get_fd_change(server_t* server)
{
    for (int i = 0; i <= server->max_client; i++) {
        if (FD_ISSET(i, &server->ready_socket))
            return i;
    }
    return -1;
}