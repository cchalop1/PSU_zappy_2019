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

// TODO: norm
static int fill_server_struct(server_t* server, int opt, const char** argv)
{
    switch (opt) {
    case 'p':
        server->port = atoi(optarg);
        break;
    case 'x':
        server->map.x_max = atoi(optarg);
        break;
    case 'y':
        server->map.y_max = atoi(optarg);
        break;
    case 'c':
        server->clients_nb = atoi(optarg);
        break;
    case 'f':
        server->freq = atoi(optarg);
        break;
    case 'n':
        for (int count = 0;
             count + (optind - 1) < (server->clients_nb + (optind - 1));
             count++) {
            server->team_names
                = realloc(server->team_names, sizeof(char*) * (count + 1));
            server->team_names[count] = strdup(argv[count + (optind - 1)]);
        }
        break;
    default:
        print_help();
    }
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
    while ((opt = getopt(argc, (char** const)argv, "p:x:y:n:c:f:")) != -1) {
        fill_server_struct(&server, opt, argv);
    }
    return server;
}

int parse_input(int argc, char* const argv[])
{
    if (argc == 2 && strcmp(argv[1], "-help") == 0)
        print_help();
    // if (argc < 12)
    // return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
