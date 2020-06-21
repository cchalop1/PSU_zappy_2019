/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** handle_cmd
*/

#include "server.h"

const int number_of_commands_graph = 7;
const int number_of_commands = 13;

static const command_t COMMANDS_GRAPH[] = { { "", error_cmd, 0 },
    { "msz", map_size, 0 }, { "bct", content_of_a_tile, 0 },
    { "mct", content_of_all_tile, 0 }, { "tna", name_of_all_teams, 0 },
    { "sgt", time_unit_request, 0 }, { "ppo", player_pos, 0 } };

static const command_t COMMANDS[] = { { "", error_cmd, 0 },
    { "Forward", forward, 7 }, { "Right", right, 7 }, { "Left", left, 7 },
    { "Look", look, 7 }, { "Inventory", inventory, 1 },
    { "Broadcast", broadcast, 7 }, { "Connect_nbr", connect_nbr, 0 },
    { "Fork", fork_cmd_player, 42 }, { "Eject", eject, 7 }, { "Take", take, 7 },
    { "Set", set, 7 }, { "Incantation", incantation, 300 } };

static command_t find_command(const char* buffer, int len)
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

static command_t find_command_graphic(const char* buffer, int len)
{
    char** str = parse_string_delim(buffer, " \n");
    int idx = 0;

    for (int i = 0; i < number_of_commands_graph; i++) {
        if (strcmp(str[0], COMMANDS_GRAPH[i].cmd) == 0) {
            idx = i;
            break;
        }
    }
    for (int i = 0; str[i]; i++)
        free(str[i]);
    free(str);
    return COMMANDS_GRAPH[idx];
}

static void new_player(server_t* server, player_t* player, int i)
{
    player_t* graphic_player = find_player_graphic(server);

    player->type = PLAYER;
    player->team_name = strdup(server->team_names[i]);
    player->life = (((float)clock() / CLOCKS_PER_SEC) * 1000.0)
        + ((1260.0 / server->freq) * 1000.0);
    player->inventory[0] = 0;
    player->inventory[1] = 0;
    player->inventory[2] = 0;
    player->inventory[3] = 0;
    player->inventory[4] = 0;
    player->inventory[5] = 0;
    send_reply(player->fd, int_to_string(player->fd));
    send_reply(player->fd, "\n");
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
            if (check_max_client(server, str[0]) == EXIT_FAILURE)
                break;
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
    if (len <= 1) {
        remove_player(server, player);
        return EXIT_SUCCESS;
    }
    if (player->type == PLAYER) {
        cmd = find_command(buffer, len);
        add_job(server, cmd, player, buffer);
    } else if (player->type == GRAPHIC) {
        cmd = find_command_graphic(buffer, len);
        cmd.exec(server, player, buffer);
    } else
        return login_client(buffer, player, server);
    return EXIT_SUCCESS;
}