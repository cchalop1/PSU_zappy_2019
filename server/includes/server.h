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
#include <signal.h>
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

enum PLAYER_TYPE { NONE, PLAYER, GRAPHIC };

enum orientation { N = 1, E = 2, S = 3, W = 4 };

typedef struct player_s {
    int fd;
    int level;
    char* team_name;
    float life;
    int pos_x;
    int pos_y;
    enum orientation orientation;
    int inventory[6];
    enum PLAYER_TYPE type;
    struct player_s* next;
    bool is_egg;
} player_t;

typedef struct tile_s {
    int stones[6];
    int x;
    int y;
    bool fruit;
} tile_t;

typedef struct map_s {
    int x_max;
    int y_max;
    tile_t** tiles;
} map_t;

typedef struct server_s {
    char* ip;
    int port;
    int clients_nb;
    int sockfd;
    int freq;
    char** team_names;
    int count_teams;
    player_t* players;
    map_t map;
    struct pollfd fds[MAX_CLIENTS];
    int nb_fd;
    struct jobs_s* jobs;
} server_t;

typedef int (*exec_cmd)(server_t* server, player_t* player, char* cmd);

typedef struct command_s {
    char* cmd;
    exec_cmd exec;
    int settime;
} command_t;

typedef struct hierarchy_s {
    int lvl;
    int nb_player;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
} hierarchy_t;

static const char* objects[6]
    = { "linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame" };

typedef struct jobs_s {
    exec_cmd exec;
    char* buffer;
    player_t* player;
    float end;
    int time;
    struct jobs_s* next;
} jobs_t;

// argv
int parse_input(int argc, char* const argv[]);
server_t parse_server_input(int argc, const char** argv);

// server
int create_server(server_t* server);
int start_server(server_t* server);

// client
int new_client(server_t* server);
int remove_player(server_t *, player_t *);
player_t* find_player_by_fd(server_t* server, int fd_find);
player_t* find_player_graphic(server_t* server);
int check_max_client(server_t* s, char* team_name);
int add_job(server_t* server, command_t cmd, player_t* player, char* buffer);
int manage_jobs(server_t* server);

// utils
char** parse_string_delim(const char* raw_str, const char* delim_raw);
void print_error(const char* messages);
void send_reply(int fd, const char* messages);
char* int_to_string(int nb);
char* content_for_one_tile(server_t* server, int x, int y);
void remove_fd_list(server_t *, int);

// cmd graph
int handle_client_cmd(server_t* server, player_t* player);
int error_cmd(server_t* server, player_t* player, char* cmd);
int map_size(server_t* server, player_t* player, char* cmd);
int content_of_a_tile(server_t* server, player_t* player, char* cmd);
int content_of_all_tile(server_t* server, player_t* player, char* cmd);
int name_of_all_teams(server_t* server, player_t* player, char* cmd);
int time_unit_request(server_t* server, player_t* player, char* cmd);
int player_info(server_t* server, player_t* player, int fd_to_send);
int player_pos(server_t* server, player_t* player, char* cmd);

// cmd player
int forward(server_t* server, player_t* player, char* cmd);
int right(server_t* server, player_t* player, char* cmd);
int left(server_t* server, player_t* player, char* cmd);
int look(server_t* server, player_t* player, char* cmd);
int inventory(server_t* server, player_t* player, char* cmd);
int broadcast(server_t* server, player_t* player, char* cmd);
int connect_nbr(server_t* server, player_t* player, char* cmd);
int fork_cmd_player(server_t* server, player_t* player, char* cmd);
int eject(server_t* server, player_t* player, char* cmd);
int take(server_t* server, player_t* player, char* cmd);
int set(server_t* server, player_t* player, char* cmd);
int incantation(server_t* server, player_t* player, char* cmd);

// other
int vision(server_t*, player_t*);
int find_broadcast_dir(player_t *, player_t *);

// map
void generate_map(server_t* server);
