/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** cmd_utils
*/

#include "server.h"

char* content_for_one_tile(server_t* server, int x, int y)
{
    char* reply = malloc(sizeof(char) * BUFFER_SIZE);
    tile_t tile;

    if (x < 0 || y < 0)
        return NULL;
    if (x >= server->map.x_max || x >= server->map.y_max)
        return NULL;
    tile = server->map.tiles[y][x];
    reply[0] = 0;
    strcat(reply, "bct ");
    strcat(reply, int_to_string(x));
    strcat(reply, " ");
    strcat(reply, int_to_string(y));
    if (tile.fruit)
        strcat(reply, " 1 ");
    else
        strcat(reply, " 0 ");
    for (int i = 0; i < 6; i++) {
        strcat(reply, int_to_string(tile.stones[i]));
        strcat(reply, " ");
    }
    strcat(reply, "\n");
    return reply;
}
