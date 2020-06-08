/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** cmd2
*/

#include "server.h"

int time_unit_request(server_t* server, player_t* player, char* cmd)
{
    char reply[BUFFER_SIZE];
    char snum[6];

    reply[0] = 0;
    sprintf(snum, "%d", server->freq);
    strcat(reply, "sgt ");
    strcat(reply, snum);
    strcat(reply, "\n");
    send_reply(player->fd, reply);
    return EXIT_SUCCESS;
}

int player_info(server_t* server, player_t* player)
{
    char reply[BUFFER_SIZE];

    reply[0] = 0;

    strcat(reply, "pnw ");
    strcat(reply, int_to_string(player->fd));
    strcat(reply, " ");
    strcat(reply, int_to_string(player->pos_x));
    strcat(reply, " ");
    strcat(reply, int_to_string(player->pos_y));
    strcat(reply, " ");
    strcat(reply, int_to_string(player->orientation));
    strcat(reply, " ");
    strcat(reply, int_to_string(player->level));
    strcat(reply, " ");
    strcat(reply, player->team_name);
    strcat(reply, "\n");
    send_reply(player->fd, reply);
    return EXIT_SUCCESS;
}