/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** cmd_player2
*/

#include "server.h"

int broadcast(server_t* server, player_t* player, char* cmd)
{
    // TODO: implem
}

int connect_nbr(server_t* server, player_t* player, char* cmd)
{
    // TODO: implem
}

int fork_cmd_player(server_t* server, player_t* player, char* cmd)
{
    // TODO: implem
}

int eject(server_t* server, player_t* player, char* cmd)
{
    player_t* player_copy = server->players;
    bool player_is_eject = false;

    for (;player_copy; player_copy = player_copy->next) {
        if (player->pos_x == player_copy->pos_x
            && player->pos_y == player_copy->pos_y) {
                forward(server, player_copy, "");
                send_reply(player->fd, "ok\n");
                player_is_eject = true;
            }
    }
    if (!player_is_eject) {
        send_reply(player->fd, "ko\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int take(server_t* server, player_t* player, char* cmd)
{
    // TODO: implem
}
