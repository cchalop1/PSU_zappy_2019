/*
** EPITECH PROJECT, 2019
** Graphic_client
** File description:
** Stone.hpp
*/

#ifndef STONE_HPP_
#define STONE_HPP_

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Enum_Zappy_Client.hpp"
class Item {
    public:
        Item(sf::Texture &Texture);
        void init();
        void set_can_draw(int nb) { if (nb == 1) {can_draw = true; } };
        bool get_can_draw() { return can_draw; };
        void display(sf::RenderWindow *_window);
        void set_position_item(int x, int y, int nb);
        void resize_item(float nb);
        ~Item();
    protected:
    private:
        int _x;
        int _y;
        bool can_draw;
        sf::Texture &_Texture;
        sf::Sprite _Sprite;
};

#endif /* !STONE_HPP_ */