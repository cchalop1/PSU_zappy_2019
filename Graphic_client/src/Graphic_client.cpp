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
    _texture_item.reserve(7);
    for (int i = 0; i != THYSTAME + 1; i++) {
        sf::Texture new_texture;
        _texture_item.push_back(new_texture);
    }
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
    if (!_backgroundTexture.loadFromFile("assets/background.jpg"))
        exit(84);
    _backgroundSprite.setTexture(_backgroundTexture);
    _index_map = 0;
}

void Graphic_client::init_class_graphic(int nb, int statut)
{
    switch (statut)
    {
    case 1:
        _map[_map.size()-1]->init_x(nb);
        break;
    case 2:
        _map[_map.size()-1]->init_y(nb);
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
    while (statut != 10) {
        found = command.find(" ");
        if (found != std::string::npos) {
            value = command.substr(0, found);
            if (value[0] != 0)
                init_class_graphic(atoi(value.c_str()), statut);
            command = command.substr(found + 1, command.size());
        }
        statut++;
    }
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
        _index_map++;
    }
}

void Graphic_client::rezise_tiles(float nb)
{
    for (int i = 0; i != _map.size(); i++)
        _map[i]->rezise_tile(nb);
}

Player *Graphic_client::find_player(int nbr)
{
    for (int i = 0; i != _player.size(); i++)
        if (_player[i]->getNbr() == nbr)
            return _player[i];
    return NULL;
}

void Graphic_client::manage_command(Client &client)
{
    std::size_t found;
    std::string command = client.receive_answer();
    std::cout << command << std::endl;
    std::string _substr;
    if (found = command.find("pnw") != std::string::npos) 
        _player.push_back(new Player(command.substr(found+3, command.size())));
    if (found = command.find("ppo") != std::string::npos) {
        _substr = command.substr(found + 5);
        command = _substr.substr(0, _substr.find(" ")-1);
        find_player(atoi(command.c_str()))->update_data(_substr.substr(_substr.find(" ")));
    }
    if (found = command.find("bct") != std::string::npos) {
        _map.clear();
        create_all_tiles(command);
    }
}

void Graphic_client::run(std::string command, Client client)
{
    struct pollfd fds[2];

    fds[0].fd = client.getSock();
    fds[0].events = POLLIN;

    if (_index_map > 100 && _index_map < 220)
        rezise_tiles(0.7);
    if (_index_map >= 225 && _index_map < 280)
        rezise_tiles(0.6);
    if (_index_map >= 280 && _index_map <= 400)
        rezise_tiles(0.5);
    if (_index_map > 400)
        rezise_tiles(0.4);
    while (_window.isOpen())
    {
        if (poll(fds, 2, 0) == -1)
            exit(84);
        if (fds[0].revents && POLLIN) {
            manage_command(client);
        } else {
            // fait ce que tu veux
        }
        //player_move(client);
        while (_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _window.close();
        }
        _window.clear();
        _window.draw(_backgroundSprite);
        for (int i = 0; i != _map.size(); i++)
            _map[i]->draw(&_window);
        for (int i = 0; i != _player.size(); i++)
            _player[i]->draw(&_window);
        _window.display();
    }
}

void Graphic_client::player_move(Client client)
{
    std::string to_send("ppo ");

    for (int i = 0; i != _player.size(); i++) {
        client.send_command(to_send + std::to_string(_player[i]->getNbr()));
        manage_command(client);
    }

}

Graphic_client::~Graphic_client()
{
}