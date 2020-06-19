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
    _x = x;
    _y = y;
    _Sprite.setPosition(x, y);
}

void Item::display(sf::RenderWindow *_window)
{
    _window->draw(_Sprite);
}

Item::~Item()
{
}