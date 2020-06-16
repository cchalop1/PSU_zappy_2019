/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** jobs
*/

#include "server.h"

int add_job(server_t* server, command_t cmd, player_t* player, char *buffer)
{
    jobs_t* new_jobs = malloc(sizeof(jobs_t));
    jobs_t* jobs_copy = server->jobs;

    new_jobs->exec = cmd.exec;
    new_jobs->time = cmd.settime;
    new_jobs->end = (clock() * 1000 / CLOCKS_PER_SEC) + ((new_jobs->time / server->freq) * 1000);
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

int manage_jobs(server_t *server)
{
    jobs_t *current_jobs = server->jobs;

    if (current_jobs == NULL)
        return EXIT_FAILURE;
    if ((unsigned long)(clock() * 1000 / CLOCKS_PER_SEC) * 1000 > current_jobs->end) {
        server->jobs->exec(server, current_jobs->player, current_jobs->buffer);
        server->jobs = server->jobs->next;
    }
    return EXIT_SUCCESS;
}