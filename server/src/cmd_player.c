/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** cmd_player
*/

#include "server.h"

int forward(server_t* server, player_t* player, char* cmd)
{
    if (player->orientation == N)
        player->pos_y -= 1;
    if (player->orientation == S)
        player->pos_y += 1;
    if (player->orientation == W)
        player->pos_x -= 1;
    if (player->orientation == E)
        player->pos_x += 1;
    if (player->pos_x < 0)
        player->pos_x = server->map.x_max - 1;
    if (player->pos_y < 0)
        player->pos_y = server->map.y_max - 1;
    if (player->pos_x >= server->map.x_max)
        player->pos_x = 0;
    if (player->pos_y >= server->map.y_max)
        player->pos_y = 0;
    send_reply(player->fd, "ok\n");
}

int right(server_t* server, player_t* player, char* cmd)
{
    if (player->orientation == W)
        player->orientation = N;
    else
        player->orientation += 1;
    send_reply(player->fd, "ok\n");
}

int left(server_t* server, player_t* player, char* cmd)
{
    if (player->orientation == N)
        player->orientation = W;
    else
        player->orientation -= 1;
    send_reply(player->fd, "ok\n");
}

int look(server_t* server, player_t* player, char* cmd)
{
    // TODO: implem
}

int inventory(server_t* server, player_t* player, char* cmd)
{
    // TODO: implem
}