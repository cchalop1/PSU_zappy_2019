/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** client
*/

#include "server.h"

static player_t* fill_new_player(server_t* server, int fd)
{
    player_t* new_client = malloc(sizeof(struct player_s));

    new_client->fd = fd;
    new_client->team = 0;
    new_client->level = 1;
    new_client->name = NULL;
    new_client->life = 10;
    new_client->pos_x = rand() % server->map.x_max;
    new_client->pos_y = rand() % server->map.y_max;
    for (int x = 0; x < 6; x++)
        new_client->inventory[x] = 0;
}

int new_client(server_t* server)
{
    player_t* new_client
        = fill_new_player(server, server->fds[server->nb_fd].fd);
    player_t* player_copy = server->players;

    if (player_copy == NULL)
        player_copy = new_client;
    else {
        for (; player_copy->next; player_copy = player_copy->next)
            player_copy->next = new_client;
    }
    return EXIT_SUCCESS;
}