/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** take
*/

#include "server.h"

static int player_eat_food(server_t* server, player_t* player)
{
    if (server->map.tiles[player->pos_y][player->pos_x].fruit) {
        player->life += (126.0 / server->freq) * 1000.0;
        send_reply(player->fd, "ok\n");
    } else {
        send_reply(player->fd, "ko\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int take(server_t* server, player_t* player, char* cmd)
{
    char** res = parse_string_delim(cmd, " \n");
    int stone = 0;

    if (res[1] == NULL) {
        send_reply(player->fd, "ko\n");
        return EXIT_FAILURE;
    }
    if (strcmp(res[1], "food") == 0)
        player_eat_food(server, player);
    for (int i = 0; i < 6; i++) {
        if (strcmp(res[1], objects[i]) == 0) {
            stone = server->map.tiles[player->pos_y][player->pos_x].stones[i];
            if (stone > 0) {
                server->map.tiles[player->pos_y][player->pos_x].stones[i]--;
                player->inventory[i]++;
                send_reply(player->fd, "ok\n");
                break;
            } else
                send_reply(player->fd, "ko\n");
        }
    }
    return EXIT_SUCCESS;
}
