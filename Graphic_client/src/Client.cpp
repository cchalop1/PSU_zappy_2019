/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** Client
*/

#include "../include/Client.hpp"

Client::Client(char const **argv)
{
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
        exit(84);
    bzero(&sin, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(argv[1]);
    sin.sin_port = htons(atoi(argv[2]));
    if ((fd = connect(sock, (SA*)&sin, sizeof(sin))) != 0)
        exit(84);
    else
        std::cout << receive_answer();
}

Client::~Client()
{
}

void Client::send_command(std::string command)
{
    send(sock, command.c_str() , command.size(), 0);
}

std::string Client::receive_answer()
{
    char *buff = (char *) malloc(sizeof(char) * 10000);
    recv(sock, buff, 10000, 0);
    std::string answer(buff);
    free(buff);
    return answer;
}

int Client::getSock()
{
    return sock;
}
