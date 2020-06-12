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
    char* snum = malloc(sizeof(char) * 6);

    sprintf(snum, "%d", nb);
    return snum;
}

int check_max_client(server_t* s, char* team_name)
{
    player_t* player_copy = s->players;
    int count = 0;

    for (; player_copy; player_copy = player_copy->next) {
        if (player_copy->team_name
            && strcmp(team_name, player_copy->team_name) == 0)
            count++;
    }
    if (count >= s->clients_nb)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}