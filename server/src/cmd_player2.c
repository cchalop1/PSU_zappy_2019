/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** cmd_player2
*/

#include "server.h"

void print_list(player_t *p)
{
    if (!p) {
        printf("Null\n");
        return;
    }
    if (!p->next) {
        printf("%d\n", p->fd);
    }
    for (; p->next; p = p->next)
        printf("%d\n", p->fd);
}

int broadcast(server_t* server, player_t* player, char* cmd)
{
    player_t *list = server->players;
    cmd[strlen(cmd) - 1] = '\0';
    char *temp = cmd + 10;
    char res[MAX_BODY_LENGTH];
    char *s = res;

    print_list(list);
    s += sprintf(s, "messages %d, %s\n", rand() % 8 + 1, temp);
    for (; list; list = list->next) {
        if (list->fd != player->fd && !list->is_egg)
            send_reply(list->fd, res);
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
    player_t *new_egg = malloc(sizeof(struct player_s));

    new_egg->fd = -1;
    new_egg->team = player->team;
    new_egg->level = 1;
    new_egg->life = (clock() * 1000 / CLOCKS_PER_SEC) + ((600 / server->freq) \
    * 1000);
    new_egg->team_name = strdup(player->team_name);
    new_egg->pos_x = player->pos_x;
    new_egg->pos_y = player->pos_y;
    new_egg->orientation = (rand() % 4) + 1;
    for (int x = 0; x < 6; x++)
        new_egg->inventory[x] = 0;
    new_egg->is_egg = true;
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
    // TODO: implem
}
