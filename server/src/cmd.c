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

int content_of_a_tile(server_t* server, player_t* player, char* cmd)
{
    char* reply = NULL;
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
    for (int y = 0; y < server->map.y_max; y++) {
        for (int x = 0; x < server->map.x_max; x++) {
            send_reply(player->fd, content_for_one_tile(server, x, y));
        }
    }
    return EXIT_SUCCESS;
}

int name_of_all_teams(server_t* server, player_t* player, char* cmd)
{
    char reply [BUFFER_SIZE];

    reply[0] = 0;
    for (int i = 0; server->team_names[i] != NULL; i++) {
        strcat(reply, "tna ");
        strcat(reply, server->team_names[i]);
        strcat(reply, "\n");
    }
    send_reply(player->fd, reply);
    return EXIT_SUCCESS;
}
