/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** start_server
*/

#include "server.h"

int accept_client(server_t* server)
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

// int manage_client(server_t* server)
// {
//     player_t* player = NULL;

//     if (poll(server->fds, server->nb_fd, 100) == -1)
//         return EXIT_FAILURE;
//     if (server->fds[0].revents & POLLIN) {
//         server->fds[server->nb_fd].fd = accept_client(server);
//         server->fds[server->nb_fd].events = POLLIN;
//         new_client(server);
//         printf("new client\n");
//         server->nb_fd++;
//         return EXIT_SUCCESS;
//     }
//     for (int i = 1; i < server->nb_fd; i++) {
//         if (server->fds[i].revents & POLLIN) {
//             player = find_player_by_fd(server, server->fds[i].fd);
//             if (player == NULL)
//                 return EXIT_FAILURE;
//             handle_client_cmd(server, player);
//         }
//     }
//     return EXIT_SUCCESS;
// }

static int cmd_player(server_t* server, int fd_client)
{
    player_t* player = NULL;

    for (int i = 1; i < server->nb_fd; i++) {
        player = find_player_by_fd(server, fd_client);
        if (player == NULL)
            return EXIT_FAILURE;
        handle_client_cmd(server, player);
    }
}

bool manage_client(server_t* server)
{
    int fd_client;

    while (true) {
        if (!manage_select(server))
            return false;
        fd_client = get_fd_change(server);
        if (fd_client == server->sockfd) {
            // new_client(server);
            server->max_client++;
            printf("new client\n");
        } else {
            // cmd_player(server, fd_client);
        }
    }
    return true;
}

int start_server(server_t* server)
{
    init_select(server);
    while (1) {
        if (manage_client(server))
            return EXIT_FAILURE;
    }
    return 0;
}