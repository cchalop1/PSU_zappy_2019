/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** argv
*/

#include "server.h"

static void print_help(void)
{
    printf("USAGE: ./zappy_server -p port -x width -y height -n name1 name2 "
    "... -c clientsNb-f freq\n");
    printf("port        is the port number\n");
    printf("width       is the width of the world\n");
    printf("height      is the height of the world\n");
    printf("nameX       is the name of the team X\n");
    printf("clientsNb   is the number of authorized clients per team\n");
    printf("freq        is the reciprocal of time unit for execution of "
    "actions\n");
    exit(EXIT_SUCCESS);
}

static void fill_team_names(server_t *server, const char **argv)
{
    for (int count = 0; argv[count + (optind - 1)] && \
    !strrchr(argv[count + (optind - 1)], '-'); count++) {
        server->team_names = realloc(server->team_names, sizeof(char *) * \
        (count + 2));
        server->team_names[count] = strdup(argv[count + (optind - 1)]);
        server->team_names[count + 1] = NULL;
        server->count_teams++;
    }
}

static int fill_server_struct(server_t* server, int opt, const char** argv)
{
    if (opt == 'p')
        server->port = atoi(optarg);
    if (opt == 'x')
        server->map.x_max = atoi(optarg);
    if (opt == 'y')
        server->map.y_max = atoi(optarg);
    if (opt == 'c')
        server->clients_nb = atoi(optarg);
    if (opt == 'f')
        server->freq = atoi(optarg);
    if (opt == 'n')
        fill_team_names(server, argv);
}

server_t parse_server_input(int argc, const char** argv)
{
    server_t server;
    int opt;

    server.ip = "127.0.0.1";
    server.team_names = NULL;
    server.nb_fd = 0;
    server.players = NULL;
    server.freq = 100;
    server.jobs = NULL;
    server.count_teams = 0;
    server.map.x_max = 10;
    server.map.y_max = 10;
    while ((opt = getopt(argc, (char** const)argv, "p:x:y:n:c:f:")) != -1) {
        fill_server_struct(&server, opt, argv);
    }
    return server;
}

int parse_input(int argc, char* const argv[])
{
    if (argc == 2 && strcmp(argv[1], "-help") == 0)
        print_help();
    return EXIT_SUCCESS;
}
