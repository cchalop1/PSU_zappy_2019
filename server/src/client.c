/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** client
*/

#include "server.h"

player_t *new_client(server_t *s, int fd)
{
    player_t *new_client = malloc(sizeof(struct player_s));

    new_client->fd = fd;
    new_client->team = 0;
    new_client->level = 1;
    new_client->name = NULL;
    new_client->life = 10;
    new_client->pos_x = rand() % s->map.x_max;
    new_client->pos_y = rand() % s->map.y_max;
    for (int x = 0; x < 6; x++)
        new_client->inventory[x] = 0;
    return new_client;
}