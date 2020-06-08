/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** handle_cmd
*/

#include "server.h"

const int number_of_commands = 7;

static const command_t COMMANDS[]
    = { { "", error_cmd }, { "msz", map_size }, { "bct", content_of_a_tile },
          { "mct", content_of_all_tile }, { "tna", name_of_all_teams },
          { "sgt", time_unit_request }, { "ppo", player_pos } };

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

static void new_player(server_t* server, player_t *player, int i)
{
    player_t* graphic_player = find_player_graphic(server);

    player->type = PLAYER;
    player->team_name = strdup(server->team_names[i]);
    map_size(server, player, "");
    if (graphic_player != NULL)
        player_info(server, player, graphic_player->fd);
}

static int login_client(const char* buffer, player_t* player, server_t* server)
{
    char** str = parse_string_delim(buffer, " \n");

    if (strcmp(str[0], "GRAPHIC") == 0) {
        player->type = GRAPHIC;
        content_of_all_tile(server, player, "");
        return EXIT_SUCCESS;
    }
    for (int i = 0; server->team_names[i]; i++) {
        if (strcmp(str[0], server->team_names[i]) == 0) {
            new_player(server, player, i);
            return EXIT_SUCCESS;
        }
    }
    send_reply(player->fd, "ko\n");
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
        // TODO: remove client
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