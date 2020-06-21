/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** Client
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <string.h>
#include <string>
#include <iostream>
#include <fstream>
#include <fcntl.h>

#define SA struct sockaddr

class Client {
    public:
        Client(char const **argv);
        ~Client();
        void send_command(std::string command);
        std::string receive_answer();
        int getSock();

    protected:
    private:
        int sock;
        struct sockaddr_in sin;
        int fd;
};

#endif /* !CLIENT_HPP_ */
