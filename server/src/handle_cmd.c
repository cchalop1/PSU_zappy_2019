/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** handle_cmd
*/

#include "server.h"

const int number_of_commands = 6;

static const command_t COMMANDS[] = { { "", error_cmd }, { "msz", map_size },
    { "bct", content_of_a_tile }, { "mct", content_of_all_tile },
    { "tna", name_of_all_teams }, { "sgt", time_unit_request } };

static command_t find_command(const char* buffer, int len)
{
    // char** str = parse_string_delim(buffer, " \n");
    int idx = 0;

    // for (int i = 0; i < number_of_commands; i++) {
    //     if (strcmp(str[0], COMMANDS[i].cmd) == 0) {
    //         idx = i;
    //         break;
    //     }
    // }
    // for (int i = 0; str[i]; i++)
    //     free(str[i]);
    // free(str);
    printf("player\n");
    return COMMANDS[idx];
    
}

static command_t find_command_graphic(const char* buffer, int len)
{
    char** str = parse_string_delim(buffer, " \n");
    int idx = 0;

    printf("grafic\n");

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

static int login_client(const char* buffer, player_t* player, server_t* server)
{
    char** str = parse_string_delim(buffer, " \n");

    if (strcmp(str[0], "GRAPHIC") == 0) {
        player->type = GRAPHIC;
        return EXIT_SUCCESS;
    }
    for (int i = 0; server->team_names[i]; i++) {
        if (strcmp(str[0], server->team_names[i]) == 0) {
            player->type = PLAYER;
            return EXIT_SUCCESS;
        }
    }
    for (int i = 0; str[i]; i++)
        free(str[i]);
    free(str);
    return EXIT_FAILURE;
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
    if (player->type == PLAYER)
        cmd = find_command(buffer, len);
    else if (player->type == GRAPHIC)
        cmd = find_command_graphic(buffer, len);
    else
        return login_client(buffer, player, server);
    if (cmd.exec(server, player, buffer))
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}