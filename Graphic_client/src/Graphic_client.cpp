/*
** EPITECH PROJECT, 2019
** Graphic_client
** File description:
** Graphic_client.cpp
*/

#include "../include/Graphic_client.hpp"

Graphic_client::Graphic_client()
{
    _windowsize_x = sf::VideoMode::getDesktopMode().width;
    _windowsize_y = sf::VideoMode::getDesktopMode().height;
    _window.create(sf::VideoMode(_windowsize_x, _windowsize_y), "Zappy Graphic");
    if (!_backgroundTexture.loadFromFile("assets/background.jpg"))
        exit(84);
    _backgroundSprite.setTexture(_backgroundTexture);
    _map.reserve(100);
    for (int i = 0; i != 100; i++)
        _map[i] = new Map;
    _index_map = 0;
}

void Graphic_client::init_class_graphic(int nb, int statut)
{
    switch (statut)
    {
    case 1:
        _map[_index_map]->init_x(nb + 1);
        break;
    case 2:
        _map[_index_map]->init_y(nb + 1);
        break;
    case 3:
        _map[_index_map]->set_item(FOOD, nb);
        break;
    case 4:
        _map[_index_map]->set_item(LINEMATE, nb);
        break;
    case 5:
        _map[_index_map]->set_item(DERAUMERE, nb);
        break;
    case 6:
        _map[_index_map]->set_item(SIBUR, nb);
        break;
    case 7:
        _map[_index_map]->set_item(MENDIANE, nb);
        break;
    case 8:
        _map[_index_map]->set_item(PHIRAS, nb);
        break;
    case 9:
        _map[_index_map]->set_item(THYSTAME, nb);
        break;
    default:
        break;
    }
}

void Graphic_client::init_graph(std::string command)
{
    int statut = 0;
    std::size_t found = 0;
    std::string value;

    found = command.find(" ");
    if (found != std::string::npos)
        command = command.substr(found, command.size());
    while (statut != 9) {
        found = command.find(" ");
        if (found != std::string::npos) {
            value = command.substr(0, found);
            if (value[0] != 0)
                init_class_graphic(atoi(value.c_str()), statut);
            command = command.substr(found + 1, command.size());
        }
        statut++;
    }
    std::cout << command << std::endl;
    _map[_index_map]->init();
    _index_map++;
}

void Graphic_client::check_command(std::string command)
{

}

void Graphic_client::run(std::string command)
{
    init_graph(command);
    while (_window.isOpen())
    {
        check_command(command);
        while (_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _window.close();
        }
        _window.clear();
        _window.draw(_backgroundSprite);
        _map[_index_map]->draw(&_window);
        _window.display();
    }
}

Graphic_client::~Graphic_client()
{
}