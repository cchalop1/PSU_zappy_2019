/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** server
*/

#pragma once

#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <linux/limits.h>
#include <netdb.h>
#include <netinet/in.h>
#include <poll.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <uuid/uuid.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define EXIT_ERROR 84
#define MAX_CLIENTS 255
#define MAX_BODY_LENGTH 512
#define BUFFER_SIZE 5000
// #define NB_COMMANDS 8

enum stone_e { LINEMATE, DERAUMERE, SIBUR, MENDIANE, PHIRAS, THYSTAME };

typedef struct player_s {
    int fd;
    int team;
    int level;
    char* name;
    int life;
    int pos_x;
    int pos_y;
    int inventory[6];
} player_t;

typedef struct tile_s {

} tile_t;

typedef struct map_s {
    int x_max;
    int y_max;
    tile_t* tile;
} map_t;

typedef struct server_s {
    char* ip;
    int port;
    int clients_nb;
    int sockfd;
    int freq;
    char** team_names;
    map_t map;
    struct pollfd* fds;
} server_t;

typedef int (*exec_cmd)(server_t* server, player_t* player, char* cmd);

typedef struct command_s {
    char* cmd;
    exec_cmd exec;
    // TODO: add more info
} command_t;

// argv
int parse_input(int argc, char* const argv[]);
server_t parse_server_input(int argc, const char** argv);

// server
int create_server(server_t* server);
int start_server(server_t* server);

// utils
char** parse_string_delim(const char* raw_str, const char* delim_raw);
command_t find_command(const char* buffer, int len);
void print_error(const char* messages);

// cmd
int error_cmd(server_t* server, player_t* player, char* cmd);
int map_size(server_t* server, player_t* player, char* cmd);
int content_of_a_tile(server_t* server, player_t* player, char* cmd);
int content_of_all_tile(server_t* server, player_t* player, char* cmd);
int name_of_all_teams(server_t* server, player_t* player, char* cmd);
