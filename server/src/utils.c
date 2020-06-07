/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** utils
*/

#include "server.h"

void print_error(const char* messages) { printf("ERROR: (%s)\n", messages); }

void send_reply(int fd, const char* messages)
{
    write(fd, messages, strlen(messages));
}

char* int_to_string(int nb)
{
    char *snum = malloc(sizeof(char) * 6);

    sprintf(snum, "%d", nb);
    return snum;
}