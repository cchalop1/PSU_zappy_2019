/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** take
*/

#include "server.h"

static void populate_map(server_t* server, bool is_fruit)
{
    int x = rand() % server->map.x_max;
    int y = rand() % server->map.y_max;

    if (is_fruit && server->map.tiles[y][x].fruit)
        populate_map(server, is_fruit);
    else if (is_fruit)
        server->map.tiles[y][x].fruit = true;
    else
        server->map.tiles[y][x].stones[rand() % 6] += 1;
    return;
}

static int player_eat_food(server_t* server, player_t* player)
{
    if (server->map.tiles[player->pos_y][player->pos_x].fruit) {
        player->life += (126.0 / server->freq) * 1000.0;
        send_reply(player->fd, "ok\n");
        server->map.tiles[player->pos_y][player->pos_x].fruit = false;
        populate_map(server, true);
    } else {
        send_reply(player->fd, "ko\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int take(server_t* server, player_t* player, char* cmd)
{
    char** res = parse_string_delim(cmd, " \n");

    if (res[1] == NULL) {
        send_reply(player->fd, "ko\n");
        return EXIT_FAILURE;
    }
    if (strcmp(res[1], "food") == 0)
        player_eat_food(server, player);
    for (int i = 0; i < 6; i++) {
        if (strcmp(res[1], objects[i]) == 0) {
            if (server->map.tiles[player->pos_y][player->pos_x].stones[i] > 0) {
                server->map.tiles[player->pos_y][player->pos_x].stones[i]--;
                player->inventory[i]++;
                send_reply(player->fd, "ok\n");
                populate_map(server, true);
                break;
            } else
                send_reply(player->fd, "ko\n");
        }
    }
    return EXIT_SUCCESS;
}
