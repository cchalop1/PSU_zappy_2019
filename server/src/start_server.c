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

int init_poll(server_t* server)
{
    server->fds[0].fd = server->sockfd;
    server->fds[0].events = POLLIN;
    server->nb_fd = 1;
}

int manage_client(server_t* server)
{
    player_t *player = NULL;

    if (poll(server->fds, server->nb_fd, 100) == -1)
        return EXIT_FAILURE;
    manage_jobs(server);
    if (server->fds[0].revents & POLLIN) {
        server->fds[server->nb_fd].fd = accept_client(server);
        server->fds[server->nb_fd].events = POLLIN;
        new_client(server);
        printf("new client\n");
        server->nb_fd++;
        return EXIT_SUCCESS;
    }
    for (int i = 1; i < server->nb_fd; i++) {
        if (server->fds[i].revents & POLLIN) {
            player = find_player_by_fd(server, server->fds[i].fd);
            if (player == NULL)
                return EXIT_FAILURE;
            handle_client_cmd(server, player);
        }
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