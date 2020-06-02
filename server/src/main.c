/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** main
*/

#include "server.h"

int main(int argc, const char* argv[])
{
    server_t server;

    if (parse_input(argc, (char** const)argv))
        return EXIT_ERROR;
    server = parse_server_input(argc, argv);
    if (create_server(&server))
        return EXIT_ERROR;
    printf("server start...\n");
    if (start_server(&server))
        return EXIT_ERROR;
    return 0;
}