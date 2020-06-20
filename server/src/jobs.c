/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** jobs
*/

#include "server.h"

int add_job(server_t* server, command_t cmd, player_t* player, char* buffer)
{
    jobs_t* new_jobs = malloc(sizeof(jobs_t));
    jobs_t* jobs_copy = server->jobs;

    new_jobs->exec = cmd.exec;
    new_jobs->time = cmd.settime;
    new_jobs->end = (((float)clock() / CLOCKS_PER_SEC) * 1000.0)
        + ((new_jobs->time / server->freq) * 1000.0);
    new_jobs->player = player;
    new_jobs->buffer = strdup(buffer);
    new_jobs->next = NULL;

    if (jobs_copy == NULL)
        server->jobs = new_jobs;
    else {
        for (; jobs_copy->next; jobs_copy = jobs_copy->next)
            ;
        jobs_copy->next = new_jobs;
    }
    return EXIT_SUCCESS;
}

static void manage_life_player(server_t* server)
{
    player_t* copy_player = server->players;

    for (; copy_player; copy_player = copy_player->next) {
        if (copy_player->life != 0
            && (((float)clock() / CLOCKS_PER_SEC) * 1000.0)
                > copy_player->life) {
            send_reply(copy_player->fd, "dead\n");
            close(copy_player->fd);
        }
    }
}

// static int check_win(server_t* server)
// {
//     player_t* copy_player = server->players;
//     int temp[server->count_teams] = { 0 };

//     for (int i = 0; server->team_names[i] != NULL; i++) {
//         copy_player = server->players;
//         for (; copy_player; copy_player = copy_player->next) {
//             if (strcmp(server->team_names[i], copy_player->team_name) == 0
//                 && copy_player->level > 7) {
//                 temp[i]++;
//             }
//         }
//     }
//     for (int i = 0; i < server->count_teams; i++) {
//         if (temp[i] >= server->clients_nb) {
//             printf("%d\n", i);
//             send_reply()
//         }
//     }
// }

int manage_jobs(server_t* server)
{
    jobs_t* current_jobs = server->jobs;

    manage_life_player(server);
    // check_win(server);
    if (current_jobs == NULL)
        return EXIT_FAILURE;
    if (((float)clock() / CLOCKS_PER_SEC) * 1000.0 > current_jobs->end) {
        server->jobs->exec(server, current_jobs->player, current_jobs->buffer);
        server->jobs = server->jobs->next;
    }
    return EXIT_SUCCESS;
}