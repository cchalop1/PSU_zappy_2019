/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** cmd_player2
*/

#include "server.h"

int broadcast(server_t* server, player_t* player, char* cmd)
{
    player_t *list = server->players;
    cmd[strlen(cmd) - 1] = '\0';
    char *temp = cmd + 10;
    char res[MAX_BODY_LENGTH];
    char *s = res;

    for (; list; list = list->next) {
        if (list->fd != player->fd && list->type == EGG) {
            sprintf(s, "messages %d, %s\n",
            find_broadcast_dir(list, player), temp);
            send_reply(list->fd, res);
        }
    }
    return EXIT_SUCCESS;
}

int connect_nbr(server_t* server, player_t* player, char* cmd)
{
    player_t* player_copy = server->players;
    int player_nb_co = 0;
    char reply[BUFFER_SIZE];

    for (; player_copy; player_copy = player_copy->next) {
        if (strcmp(player_copy->team_name, player->team_name) == 0)
            player_nb_co++;
    }
    reply[0] = 0;
    strcat(reply, int_to_string(server->clients_nb - player_nb_co));
    strcat(reply, "\n");
    send_reply(player->fd, reply);
    return EXIT_SUCCESS;
}

int fork_cmd_player(server_t* server, player_t* player, char* cmd)
{
    server->clients_nb++;
    send_reply(player->fd, "ok\n");
    return EXIT_SUCCESS;
}

int eject(server_t* server, player_t* player, char* cmd)
{
    player_t* player_copy = server->players;
    bool player_is_eject = false;

    // TODO: send to other plyer eject
    for (; player_copy; player_copy = player_copy->next) {
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
    char** res = parse_string_delim(cmd, " \n");
    int stone = 0;

    if (res[1] == NULL) {
        send_reply(player->fd, "ko\n");
        return EXIT_FAILURE;
    }
    // TODO: when player take fruit add time life
    for (int i = 0; i < 6; i++) {
        if (strcmp(res[1], objects[i]) == 0) {
            stone = server->map.tiles[player->pos_y][player->pos_x].stones[i];
            if (stone > 0) {
                server->map.tiles[player->pos_y][player->pos_x].stones[i]--;
                player->inventory[i]++;
                send_reply(player->fd, "ok\n");
                break;
            } else {
                send_reply(player->fd, "ko\n");
            }
        }
    }
    return EXIT_SUCCESS;
}
