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
    std::string command;
    client.send_command("GRAPHIC");
    //client.send_command("GRAPHIC");
        //command.clear();
    command = client.receive_answer();
    command.append(client.receive_answer());
    std::cout << command << std::endl;


    Graphic_client graphic;
    graphic.create_all_tiles(command);
    //graphic.run(command);
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