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

typedef struct map_s {
    int x_max;
    int y_max;
} map_t;

typedef struct server_s {
    char *ip;
    int port;
    int clients_nb;
    int sockfd;
    int freq;
    map_t map;
} server_t;

// argv
int parse_input(int argc, char* const argv[]);
server_t parse_server_input(int argc, const char** argv);

// server
int create_server(server_t* server);
int start_server(server_t* server);