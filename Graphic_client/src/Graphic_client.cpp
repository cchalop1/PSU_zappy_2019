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
    _food.reserve(10);
    _linemate.reserve(10);
    _deraumere.reserve(10);
    _sibur.reserve(10);
    _mendiane.reserve(10);
    _phiras.reserve(10);
    _index_map = 0;
    _index_stone = 0;
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
        _food[_index_stone].set_can_draw(nb);
        break;
    case 4:
        _linemate[_index_stone].set_can_draw(nb);
        break;
    case 5:
        _deraumere[_index_stone].set_can_draw(nb);
        break;
    case 6:
        _sibur[_index_stone].set_can_draw(nb);
        break;
    case 7:
        _mendiane[_index_stone].set_can_draw(nb);
        break;
    case 8:
        _phiras[_index_stone].set_can_draw(nb);
        break;
    default:
        break;
    }
}

void Graphic_client::init_map(std::string command)
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
            if (value[0] != 0) {
                _map[_index_map] = new Map;
                init_class_graphic(atoi(value.c_str()), statut);
            }
            command = command.substr(found + 1, command.size());
        }
        statut++;
    }
    std::cout << command << std::endl;
    _map[_index_map]->init();
    _index_map++;
    _index_stone++;
}

void Graphic_client::run()
{
    while (_window.isOpen())
    {
        while (_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _window.close();
        }
        _window.clear();
        _window.draw(_backgroundSprite);
        _window.draw(_map[_index_map]->get_sprite());
        _window.display();
    }
}

Graphic_client::~Graphic_client()
{
}