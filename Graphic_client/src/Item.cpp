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

void Item::set_position_item(int x, int y)
{
    _Sprite.setPosition(x, y);
}

void Item::display(sf::RenderWindow *_window)
{
    _window->draw(_Sprite);
}

Item::~Item()
{
}