/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** server
*/

#include "server.h"

static int create_socket(server_t* server)
{
    server->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server->sockfd == -1) {
        fprintf(stderr, "socket fail (%s)\n", strerror(errno));
        return -1;
    }
    return 0;
}

static void fill_servaddr(struct sockaddr_in* servaddr, server_t* server)
{
    servaddr->sin_family = AF_INET;
    servaddr->sin_addr.s_addr = inet_addr(server->ip);
    servaddr->sin_port = htons(server->port);
}

int create_server(server_t* server)
{
    struct sockaddr_in servaddr;

    if (create_socket(server) != 0)
        return EXIT_FAILURE;
    fill_servaddr(&servaddr, server);
    if ((bind(server->sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)))
        != 0) {
        fprintf(stdout, "bind fail (%s)\n", strerror(errno));
        return EXIT_FAILURE;
    }
    // TODO: 
    if ((listen(server->sockfd, MAX_CLIENTS)) != 0) {
        fprintf(stdout, "listen fail (%s)\n", strerror(errno));
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
