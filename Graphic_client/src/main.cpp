/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** main
*/

#include "../include/Graphic_client.hpp"
#include "../include/Client.hpp"

void client_loop(Client client)
{
    Graphic_client graphic;

    std::string command = "bct 0 0 0 0 1 0 0 1 0";
    //std::string command;
    //client.send_command("GRAPHIC");
    //client.send_command("GRAPHIC");
        //command.clear();
    //command = client.receive_answer();
    std::cout << command << std::endl;
    graphic.run(command);
    /*while (command.size() != 0)
    {
        std::cout << command;
        command.clear();
        command = client.receive_answer();
        std::cout << "Finished\n";
    }*/
    //std::cout << "Finished\n";
}

int main(int argc, char const *argv[])
{
    if (argc != 3)
        return 84;
    Client client(argv);
    client_loop(client);
    return 0;
}