/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** cmd_player3
*/

#include "server.h"

static const int HIERARCHY[8][7] = { { 0, 0, 0, 0, 0, 0, 0 },
    { 1, 1, 0, 0, 0, 0, 0 }, { 2, 1, 1, 1, 0, 0, 0 }, { 2, 2, 0, 1, 0, 2, 0 },
    { 4, 1, 1, 2, 0, 1, 0 }, { 4, 1, 2, 1, 3, 0, 0 }, { 6, 1, 2, 3, 0, 1, 0 },
    { 6, 1, 2, 3, 0, 1, 0 } };

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

static void send_incarnation_to_server(server_t* server, player_t* player)
{
    player_t* graphic_player = find_player_graphic(server);
    char reply[BUFFER_SIZE];

    if (!graphic_player)
        return;
    reply[0] = 0;
    strcat(reply, "pic ");
    strcat(reply, int_to_string(player->pos_x));
    strcat(reply, " ");
    strcat(reply, int_to_string(player->pos_y));
    strcat(reply, " ");
    strcat(reply, int_to_string(player->level));
    strcat(reply, " ");
    strcat(reply, int_to_string(player->fd));
    strcat(reply, "\n");
    send_reply(graphic_player->fd, reply);
}

int incantation(server_t* server, player_t* player, char* cmd)
{
    player_t* player_copy = server->players;
    int nb_player_tile = 1;

    for (; player_copy; player_copy = player_copy->next) {
        if (player->pos_x == player_copy->pos_x
            && player->pos_y == player_copy->pos_y
            && strcmp(player_copy->team_name, player->team_name) == 0)
            nb_player_tile++;
    }
    if (nb_player_tile == HIERARCHY[player->level][1]
        && player->inventory[LINEMATE] >= HIERARCHY[player->level][LINEMATE + 1]
        && player->inventory[DERAUMERE]
            >= HIERARCHY[player->level][DERAUMERE + 1]
        && player->inventory[SIBUR] >= HIERARCHY[player->level][SIBUR + 1]
        && player->inventory[MENDIANE] >= HIERARCHY[player->level][MENDIANE + 1]
        && player->inventory[PHIRAS] >= HIERARCHY[player->level][PHIRAS + 1]
        && player->inventory[THYSTAME]
            >= HIERARCHY[player->level][THYSTAME + 1]) {
        player->level++;
        send_reply(player->fd, "ok\n");
        send_incarnation_to_server(server, player);
    } else {
        send_reply(player->fd, "ko\n");
    }
}
