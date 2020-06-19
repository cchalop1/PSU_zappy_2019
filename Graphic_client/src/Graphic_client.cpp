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
    _texture_item.reserve(7);
    if (!_texture_item[FOOD].loadFromFile("assets/food.png"))
        exit(84);
    if (!_texture_item[LINEMATE].loadFromFile("assets/linemate.png"))
        exit(84);
    if (!_texture_item[DERAUMERE].loadFromFile("assets/deraumere.png"))
        exit(84);
    if (!_texture_item[SIBUR].loadFromFile("assets/sibur.png"))
        exit(84);
    if (!_texture_item[MENDIANE].loadFromFile("assets/mendiane.png"))
        exit(84);
    if (!_texture_item[PHIRAS].loadFromFile("assets/phiras.png"))
        exit(84);
    if (!_texture_item[THYSTAME].loadFromFile("assets/thystame.png"))
        exit(84);
}

void Graphic_client::init_class_graphic(int nb, int statut)
{
    switch (statut)
    {
    case 1:
        _map[_map.size()-1]->init_x(nb + 1);
        break;
    case 2:
        _map[_map.size()-1]->init_y(nb + 1);
        break;
    case 3:
        _map[_map.size()-1]->set_item(FOOD, nb);
        break;
    case 4:
        _map[_map.size()-1]->set_item(LINEMATE, nb);
        break;
    case 5:
        _map[_map.size()-1]->set_item(DERAUMERE, nb);
        break;
    case 6:
        _map[_map.size()-1]->set_item(SIBUR, nb);
        break;
    case 7:
        _map[_map.size()-1]->set_item(MENDIANE, nb);
        break;
    case 8:
        _map[_map.size()-1]->set_item(PHIRAS, nb);
        break;
    case 9:
        _map[_map.size()-1]->set_item(THYSTAME, nb);
        break;
    default:
        break;
    }
}

void Graphic_client::create_tile(std::string command)
{
    int statut = 0;
    std::size_t found = 0;
    std::string value;

    _map.push_back(new Map(_texture_item));
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
    _map[_map.size()-1]->init();
}

void Graphic_client::create_all_tiles(std::string all_command)
{
    size_t pos = 0;
    std::string token;
    std::string all_command_copy = all_command;
    std::string delimiter = "\n";

    while ((pos = all_command_copy.find(delimiter)) != std::string::npos) {
        token = all_command_copy.substr(0, pos);
        create_tile(token);
        all_command_copy.erase(0, pos + delimiter.length());
    }
}

void Graphic_client::check_command(std::string command)
{

}

void Graphic_client::run(std::string command)
{
    create_tile(command);
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