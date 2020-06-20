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
    _x = 450;
    _y = 20;
    _index_item = 0;
}

void Map::init_x(int x)
{
    if (x != 0) {
        x = x * 100;
        _x = _x + x;
    }
}

void Map::init_y(int y)
{
    if (y != 0) {
        y = y * 100;
        _y = _y + y;
    }
}

void Map::rezise_tile(float nb)
{
    _Sprite.setScale(nb, nb);
    _x = _x * nb;
    _y = _y * nb;
    _Sprite.setPosition(_x, _y);
    for (int i = 0; i != _food.size(); i++)
        _food[i].resize_item(nb);
    for (int i = 0; i != _linemate.size(); i++)
        _linemate[i].resize_item(nb);
    for (int i = 0; i != _deraumere.size(); i++)
        _deraumere[i].resize_item(nb);
    for (int i = 0; i != _sibur.size(); i++)
        _sibur[i].resize_item(nb);
    for (int i = 0; i != _mendiane.size(); i++)
        _mendiane[i].resize_item(nb);
    for (int i = 0; i != _phiras.size(); i++)
        _phiras[i].resize_item(nb);
    for (int i = 0; i != _thystame.size(); i++)
        _thystame[i].resize_item(nb);
}

void Map::set_item(int item, int nb)
{
    switch (item)
    {
    case FOOD:
        _food.reserve(nb);
        for (int i = 0; i != nb; i++) {
            Item food(_texture_item[FOOD]);
            food.set_position_item(_x, _y, _index_item);
            _food.push_back(food);
            _index_item++;
        }
        break;
    case LINEMATE:
        _linemate.reserve(nb);
        for (int i = 0; i != nb; i++) {
            Item linemate(_texture_item[LINEMATE]);
            linemate.set_position_item(_x, _y, _index_item);
            _linemate.push_back(linemate);
            _index_item++;
        }
        break;
    case DERAUMERE:
        _deraumere.reserve(nb);
        for (int i = 0; i != nb; i++) {
            Item deraumere(_texture_item[DERAUMERE]);
            deraumere.set_position_item(_x, _y, _index_item);
            _deraumere.push_back(deraumere);
            _index_item++;
        }
    case SIBUR:
        _sibur.reserve(nb);
        for (int i = 0; i != nb; i++) {
            Item sibur(_texture_item[SIBUR]);
            sibur.set_position_item(_x, _y, _index_item);
            _sibur.push_back(sibur);
            _index_item++;
        }
        break;
    case MENDIANE:
        _mendiane.reserve(nb);
        for (int i = 0; i != nb; i++) {
            Item mendiane(_texture_item[MENDIANE]);
            mendiane.set_position_item(_x, _y, _index_item);
            _mendiane.push_back(mendiane);
            _index_item++;
        }
        break;
    case PHIRAS:
        _phiras.reserve(nb);
        for (int i = 0; i != nb; i++) {
            Item phiras(_texture_item[PHIRAS]);
            phiras.set_position_item(_x, _y, _index_item);
            _phiras.push_back(phiras);
            _index_item++;
        }
        break;
    case THYSTAME:
        _thystame.reserve(nb);
        for (int i = 0; i != nb; i++) {
            Item thystame(_texture_item[THYSTAME]);
            thystame.set_position_item(_x, _y, _index_item);
            _thystame.push_back(thystame);
            _index_item++;
        }
        break;
    default:
        exit (84);
        break;
    }
}

void Map::init()
{
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