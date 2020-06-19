/*
** EPITECH PROJECT, 2019
** Graphic_client
** File description:
** Stone.cpp
*/

#include "../include/Item.hpp"

Item::Item(int nb)
{
    switch (nb)
    {
    case FOOD:
        if (!_Texture.loadFromFile("assets/food.png"))
            exit(84);
        _Sprite.setTexture(_Texture);
        break;
    case LINEMATE:
        if (!_Texture.loadFromFile("assets/linemate.png"))
            exit(84);
        _Sprite.setTexture(_Texture);
        break;
    case DERAUMERE:
        if (!_Texture.loadFromFile("assets/deraumere.png"))
            exit(84);
        _Sprite.setTexture(_Texture);
        break;
    case SIBUR:
        if (!_Texture.loadFromFile("assets/sibur.png"))
            exit(84);
        _Sprite.setTexture(_Texture);
        break;
    case MENDIANE:
        if (!_Texture.loadFromFile("assets/mendiane.png"))
            exit(84);
        _Sprite.setTexture(_Texture);
        break;
    case PHIRAS:
        if (!_Texture.loadFromFile("assets/phiras.png"))
            exit(84);
        _Sprite.setTexture(_Texture);
        break;
    case THYSTAME:
        if (!_Texture.loadFromFile("assets/thystame.png"))
            exit(84);
        _Sprite.setTexture(_Texture);
        break;
    default:
        exit (84);
        break;
    }
    can_draw = false;
}

void Item::init()
{

}

void Item::display(sf::RenderWindow *_window)
{
    _window->draw(_Sprite);
}

Item::~Item()
{
}