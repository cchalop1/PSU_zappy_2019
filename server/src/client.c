/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** client
*/

#include "server.h"

static player_t* fill_new_player(server_t* server, int fd)
{
    player_t* new_client = malloc(sizeof(struct player_s));

    new_client->fd = fd;
    new_client->team = 0;
    new_client->level = 1;
    new_client->life = 0;
    new_client->team_name = NULL;
    new_client->next = NULL;
    new_client->type = NONE;
    new_client->is_egg = false;
    new_client->orientation = (rand() % 4) + 1;
    new_client->pos_x = rand() % server->map.x_max;
    new_client->pos_y = rand() % server->map.y_max;
    for (int x = 0; x < 6; x++)
        new_client->inventory[x] = 0;
}

int new_client(server_t* server)
{
    player_t* new_client
        = fill_new_player(server, server->fds[server->nb_fd].fd);
    player_t* player_copy = server->players;

    if (player_copy == NULL)
        server->players = new_client;
    else {
        for (; player_copy->next; player_copy = player_copy->next)
            ;
        player_copy->next = new_client;
    }
    send_reply(server->fds[server->nb_fd].fd, "WELCOME\n");
    return EXIT_SUCCESS;
}

player_t* find_player_by_fd(server_t* server, int fd_find)
{
    player_t* player_copy = server->players;

    if (fd_find == -1)
        return NULL;
    for (; player_copy; player_copy = player_copy->next) {
        if (player_copy->fd == fd_find) {
            return player_copy;
        }
    }
    print_error("find player");
    return NULL;
}

player_t* find_player_graphic(server_t* server)
{
    player_t* player_copy = server->players;

    for (; player_copy; player_copy = player_copy->next) {
        if (player_copy->type == GRAPHIC) {
            return player_copy;
        }
    }
    return NULL;
}