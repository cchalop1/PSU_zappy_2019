/*
** EPITECH PROJECT, 2019
** Graphic_client
** File description:
** Stone.cpp
*/

#include "../include/Item.hpp"

Item::Item(sf::Texture &Texture)
{
    _Sprite.setTexture(Texture);
    can_draw = true;
}

void Item::init()
{

}

void Item::resize_item(float nb)
{
    _Sprite.setScale(nb, nb);
    _x = _x * nb;
    _y = _y * nb;
    _Sprite.setPosition(_x, _y);
}

void Item::set_position_item(int x, int y, int nb)
{
    switch (nb)
    {
    case 0:
        _x = x;
        _y = y;
        break;
    case 1:
        _x = x + 20;
        _y = y;
        break;
    case 2:
        _x = x + 40;
        _y = y;
        break;
    case 3:
        _x = x + 60;
        _y = y;
        break;
    case 4:
        _x = x;
        _y = y + 30;
        break;
    case 5:
        _x = x + 20;
        _y = y + 30;
        break;
    case 6:
        _x = x + 40;
        _y = y + 30;
        break;
    case 7:
        _x = x + 60;
        _y = y + 30;
    default:
        _x = x;
        _y = y;
    }
    _Sprite.setPosition(_x, _y);
}

void Item::display(sf::RenderWindow *_window)
{
    _window->draw(_Sprite);
}

Item::~Item()
{
}