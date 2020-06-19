/*
** EPITECH PROJECT, 2019
** Graphic_client
** File description:
** Map.cpp
*/

#include "../include/Map.hpp"

Map::Map()
{
    if (!_Texture.loadFromFile("assets/map3.png"))
        exit(84);
    _Sprite.setTexture(_Texture);
    _x = 100;
    _y = 100;
}

void Map::init()
{
    std::cout << _x << " " << _y << std::endl;
    _Sprite.setPosition(_x, _y);
}

sf::Sprite Map::get_sprite()
{
    return _Sprite;
}

Map::~Map()
{
}