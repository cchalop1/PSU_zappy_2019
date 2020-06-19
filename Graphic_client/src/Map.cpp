/*
** EPITECH PROJECT, 2019
** Graphic_client
** File description:
** Map.cpp
*/

#include "../include/Map.hpp"

Map::Map(std::vector<sf::Texture> &texture_item) : _texture_item(texture_item)
{
    if (!_Texture.loadFromFile("assets/map3.png"))
        exit(84);
    _Sprite.setTexture(_Texture);
    _x = 100;
    _y = 100;
}

void Map::set_item(int item, int nb)
{
    switch (item)
    {
    case FOOD:
        _food.reserve(nb);
        std::cout << nb << std::endl;
        for (int i = 0; i != nb; i++) {
            Item food(_texture_item[FOOD]);
            food.set_position_item(_x, _y);
            _food.push_back(food);
        }
        break;
    case LINEMATE:
        _linemate.reserve(nb);
        for (int i = 0; i != nb; i++) {
            Item linemate(_texture_item[LINEMATE]);
            linemate.set_position_item(_x, _y);
            _linemate.push_back(linemate);
        }
        break;
    case DERAUMERE:
        _deraumere.reserve(nb);
        for (int i = 0; i != nb; i++) {
            Item deraumere(_texture_item[DERAUMERE]);
            deraumere.set_position_item(_x, _y);
            _deraumere.push_back(deraumere);
        }
    case SIBUR:
        _sibur.reserve(nb);
        for (int i = 0; i != nb; i++) {
            Item sibur(_texture_item[SIBUR]);
            sibur.set_position_item(_x, _y);
            _sibur.push_back(sibur);
        }
        break;
    case MENDIANE:
        _mendiane.reserve(nb);
        for (int i = 0; i != nb; i++) {
            Item mendiane(_texture_item[MENDIANE]);
            mendiane.set_position_item(_x, _y);
            _mendiane.push_back(mendiane);
        }
        break;
    case PHIRAS:
        _phiras.reserve(nb);
        for (int i = 0; i != nb; i++) {
            Item phiras(_texture_item[PHIRAS]);
            phiras.set_position_item(_x, _y);
            _phiras.push_back(phiras);
        }
        break;
    case THYSTAME:
        _thystame.reserve(nb);
        for (int i = 0; i != nb; i++) {
            Item thystame(_texture_item[THYSTAME]);
            thystame.set_position_item(_x, _y);
            _thystame.push_back(thystame);
        }
        break;
    default:
        exit (84);
        break;
    }
}

void Map::init()
{
    std::cout << _x << " " << _y << std::endl;
    _Sprite.setPosition(_x, _y);
}

void Map::draw(sf::RenderWindow *_window)
{
    _window->draw(_Sprite);
    for (int i = 0; i != _food.size(); i++)
        _food[i].display(_window);
    for (int i = 0; i != _linemate.size(); i++)
       _linemate[i].display(_window);
    for (int i = 0; i != _deraumere.size(); i++)
        _deraumere[i].display(_window);
    for (int i = 0; i != _sibur.size(); i++)
        _sibur[i].display(_window);
    for (int i = 0; i != _mendiane.size(); i++)
        _mendiane[i].display(_window);
    for (int i = 0; i != _phiras.size(); i++)
        _phiras[i].display(_window);
    for (int i = 0; i != _thystame.size(); i++)
        _thystame[i].display(_window);
}

Map::~Map()
{
}