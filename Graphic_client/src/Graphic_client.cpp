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
    //_map.reserve(100);
    //_stone.reserve(6);
    //for (int i = 0; i != THYSTAME + 1; i++) {
    //    _stone[i].reserve(100);
    //}
}

void Graphic_client::init_map(std::string command)
{
    int statut = 0;
    std::size_t found = 0;

    found = command.find(" ");
    if (found != std::string::npos)
        command = command.substr(found, command.size());
    while (statut != 8) {
        found = command.find(" ");
        if (found != std::string::npos) {
            std::string value = command.substr(0, found);
            std::cout << command << std::endl;
            command = command.substr(found, command.size());
        }
        statut++;
    }
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
        _window.display();
    }
}

Graphic_client::~Graphic_client()
{
}