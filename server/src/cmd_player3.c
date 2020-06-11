/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** cmd_player3
*/

#include "server.h"

int set(server_t* server, player_t* player, char* cmd)
{
    char** res = parse_string_delim(cmd, " \n");

    if (res[1] == NULL) {
        send_reply(player->fd, "ko\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < 6; i++) {
        if (strcmp(res[1], objects[i]) == 0) {
            if (player->inventory[i] > 0) {
                server->map.tiles[player->pos_y][player->pos_x].stones[i]++;
                player->inventory[i]--;
            }
        }
    }
    send_reply(player->fd, "ok\n");
}

int incantation(server_t* server, player_t* player, char* cmd)
{
    // TODO: implem
}
