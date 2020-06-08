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
    char res[MAX_BODY_LENGTH];
    int size = server->map.x_max * server->map.y_max;

    sprintf(res, "%d", size);
    printf("CMD map size\n");
    send_reply(player->fd, res);
}

int content_of_a_tile(server_t* server, player_t* player, char* cmd)
{
    printf("CMD content_of_a_tile\n");
}

int content_of_all_tile(server_t* server, player_t* player, char* cmd)
{
    printf("CMD content_of_all_tile\n");
}

int name_of_all_teams(server_t* server, player_t* player, char* cmd)
{
    char res[MAX_BODY_LENGTH] = {0};

    printf("CMD name_of_all_teams\n");
    for (int x = 0; server->team_names[x]; x++) {
        strcat(res, server->team_names[x]);
        strcat(res, "\n");
    }
    send_reply(player->fd, res);
}
