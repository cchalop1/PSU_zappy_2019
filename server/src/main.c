/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** main
*/

#include <time.h>
#include "server.h"

static int init_server_data(server_t *server)
{
    generate_map(server);
    // server->clock_start = clock();
    // printf("start = %ld\n", server->clock_start);
    signal(SIGINT, exit);
    return EXIT_SUCCESS;
}

int main(int argc, const char* argv[])
{
    server_t server;

    srand(time(NULL));
    if (parse_input(argc, (char** const)argv))
        return EXIT_ERROR;
    server = parse_server_input(argc, argv);
    if (init_server_data(&server))
        return EXIT_ERROR;
    if (create_server(&server))
        return EXIT_ERROR;
    printf("Port : %d\n", server.port);
    if (start_server(&server))
        return EXIT_ERROR;
    return 0;
}