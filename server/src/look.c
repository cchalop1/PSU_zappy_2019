/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** look
*/

#include "server.h"

static tile_t *check_tile(server_t *s, int x, int y)
{
    x = x < 0 ? s->map.x_max + x : x;
    y = y < 0 ? s->map.y_max + y : y;
    return &s->map.tiles[y][x];
}

static tile_t *get_tile(server_t *s, player_t *p, int x, int y)
{
    switch (p->orientation) {
        case N:
            return check_tile(s, p->pos_y - x, p->pos_x + y);
        case E:
            return check_tile(s, p->pos_y + y, p->pos_x + x);
        case S:
            return check_tile(s, p->pos_y + x, p->pos_x - y);
        case W:
            return check_tile(s, p->pos_y - y, p->pos_x - x);
        default:
            return NULL;
    }
}

int vision(server_t *s, player_t *p)
{
    char res[MAX_BODY_LENGTH];
    char *temp = res;
    tile_t *tile = NULL;

    sprintf(temp, "[");
    for (int x = 0; x < p->level; x++)
        for (int y = 0; y < 2 * x + 1; y++) {
            tile = get_tile(s, p, x, y - x);
            sprintf(temp, "%s, ", content_for_one_tile(s, tile->x, tile->y));
        }
    sprintf(temp, "]\n");
    send_reply(p->fd, res);
    return EXIT_SUCCESS;
}