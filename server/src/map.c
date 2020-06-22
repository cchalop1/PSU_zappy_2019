/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** map
*/

#include "server.h"

// void print_map(server_t* server)
// {
//     for (int y = 0; y < server->map.y_max; y++) {
//         for (int x = 0; x < server->map.x_max; x++) {
//             printf("[%d] ", server->map.tiles[y][x].fruit);
//         }
//         printf("\n");
//     }
// }

static void fill_map_fruits(server_t* server)
{
    for (int y = 0; y < server->map.y_max; y++) {
        for (int x = 0; x < server->map.x_max; x++) {
            if (server->map.tiles[y][x].fruit == false && (rand() % 100 < 20))
                server->map.tiles[y][x].fruit = true;
        }
    }
}

static void fill_map_stones(server_t* server)
{
    int nb_stones = (server->map.x_max * server->map.y_max) / 2;

    while (nb_stones > 0) {
        for (int y = 0; y < server->map.y_max && nb_stones > 0; y++) {
            for (int x = 0; x < server->map.x_max; x++) {
                if ((rand() % 2) == 1) {
                    server->map.tiles[y][x].stones[rand() % 6] += 1;
                    nb_stones -= 1;
                }
            }
        }
    }
}

static void fill_map(server_t* server)
{
    fill_map_fruits(server);
    fill_map_stones(server);
}

void generate_map(server_t* server)
{
    server->map.tiles = malloc(sizeof(tile_t*) * server->map.y_max);

    for (int y = 0; y < server->map.y_max; y++) {
        server->map.tiles[y] = malloc(sizeof(tile_t) * server->map.x_max);
        for (int x = 0; x < server->map.x_max; x++) {
            server->map.tiles[y][x].y = y;
            server->map.tiles[y][x].x = x;
            server->map.tiles[y][x].fruit = false;
            server->map.tiles[y][x].stones[0] = 0;
            server->map.tiles[y][x].stones[1] = 0;
            server->map.tiles[y][x].stones[2] = 0;
            server->map.tiles[y][x].stones[3] = 0;
            server->map.tiles[y][x].stones[4] = 0;
            server->map.tiles[y][x].stones[5] = 0;
        }
    }
    fill_map(server);
}