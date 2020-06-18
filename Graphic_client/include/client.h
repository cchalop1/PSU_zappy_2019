/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** client
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

typedef struct t_client {
    int fd;
    char *username;
    char *password;
    char *uuid;
    char *work_path;
} t_client;

t_client init_client(void);
char *init_uuid(void);
#endif /* !CLIENT_H_ */
