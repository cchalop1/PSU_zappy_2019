/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** broadcast
*/

#include "server.h"

static const int offset[5] = {0, 4, 2, 0, 6};

static int simple_dir(player_t *r, player_t *s)
{
    if (s->pos_x == r->pos_x)
        return s->pos_y < r->pos_y ? 5 : 1;
    if (s->pos_y == r->pos_y)
        return s->pos_x < r->pos_x ? 3 : 7;
    if (s->pos_x < r->pos_x && s->pos_y > r->pos_y)
        return 2;
    if (s->pos_x < r->pos_x && s->pos_y > r->pos_y)
        return 4;
    if (s->pos_x > r->pos_x && s->pos_y < r->pos_y)
        return 6;
    if (s->pos_x > r->pos_x && s->pos_y > r->pos_y)
        return 8;
}

int find_broadcast_dir(player_t *receiver, player_t *sender)
{
    int res;

    if (receiver->pos_x == sender->pos_x && receiver->pos_y == sender->pos_y)
        return 0;
    res = simple_dir(receiver, sender) + offset[receiver->orientation];
    return res % 8 != 0 ? res % 8 : 8;
}