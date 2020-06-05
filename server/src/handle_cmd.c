/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** handle_cmd
*/

#include "server.h"

const int number_of_commands = 5;

static const command_t COMMANDS[] = {
    { "", error_cmd },
    { "msz", map_size },
    { "bct", content_of_a_tile },
    { "mct", content_of_all_tile },
    { "tna", name_of_all_teams },
};

command_t find_command(const char* buffer, int len)
{
    char** str = parse_string_delim(buffer, " \n");
    int idx = 0;

    for (int i = 0; i < number_of_commands; i++) {
        if (strcmp(str[0], COMMANDS[i].cmd) == 0) {
            idx = i;
            break;
        }
    }
    for (int i = 0; str[i]; i++)
        free(str[i]);
    free(str);
    return COMMANDS[idx];
}

int handle_client_cmd(server_t* server, player_t* player)
{
    int len = -1;
    char buffer[BUFFER_SIZE];
    command_t cmd;

    len = read(player->fd, buffer, BUFFER_SIZE);
    buffer[len] = 0;
    if (len <= 0) {
        // remove client
        close(player->fd);
        return EXIT_SUCCESS;
    }
    cmd = find_command(buffer, len);
    if (cmd.exec(server, player, buffer))
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}