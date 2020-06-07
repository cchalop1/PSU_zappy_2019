/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** cmd
*/

#include "server.h"

int error_cmd(server_t* server, player_t* player, char* cmd)
{
    send_reply(player->fd, "ko\n");
}

int map_size(server_t* server, player_t* player, char* cmd)
{
    char reply[BUFFER_SIZE];
    char snum[6];

    reply[0] = 0;
    sprintf(snum, "%d", server->map.x_max);
    strcat(reply, "msz ");
    strcat(reply, snum);
    strcat(reply, " ");
    sprintf(snum, "%d", server->map.y_max);
    strcat(reply, snum);
    strcat(reply, "\n");
    send_reply(player->fd, reply);
    return EXIT_SUCCESS;
}

static char *content_for_one_tile(server_t* server, int x, int y)
{
    char *reply = malloc(sizeof(char) * BUFFER_SIZE);
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

int content_of_a_tile(server_t* server, player_t* player, char* cmd)
{
    char *reply = NULL;
    char** res = parse_string_delim(cmd, " \n");

    if (res[0] && res[1] && res[2])
        reply = content_for_one_tile(server, atoi(res[1]), atoi(res[2]));
    if (reply == NULL) {
        send_reply(player->fd, "ko\n");
        return EXIT_FAILURE;
    }
    send_reply(player->fd, reply);
    return EXIT_SUCCESS;
}

int content_of_all_tile(server_t* server, player_t* player, char* cmd)
{
    printf("CMD content_of_all_tile\n");
}

int name_of_all_teams(server_t* server, player_t* player, char* cmd)
{
    printf("CMD name_of_all_teams\n");
}
