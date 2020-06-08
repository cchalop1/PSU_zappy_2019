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

int player_info(server_t* server, player_t* player, int fd_to_send)
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
    send_reply(fd_to_send, reply);
    return EXIT_SUCCESS;
}

int player_pos(server_t* server, player_t* player, char* cmd)
{
    char reply[BUFFER_SIZE];
    char** res = parse_string_delim(cmd, " \n");
    printf("%d\n", atoi(res[1]));
    player_t* player_find = find_player_by_fd(server, atoi(res[1]));

    reply[0] = 0;
    if (player_find == NULL) {
        send_reply(player->fd, "ko\n");
        return EXIT_FAILURE;
    }
    player_info(server, player_find, player->fd);
    return EXIT_SUCCESS;
}
