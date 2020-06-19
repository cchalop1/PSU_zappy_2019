/*
** EPITECH PROJECT, 2019
** Graphic_client
** File description:
** Stone.hpp
*/

#ifndef STONE_HPP_
#define STONE_HPP_

#include <SFML/Graphics.hpp>

class Item {
    public:
        Item();
        void init();
        void set_can_draw() {can_draw = true; };
        bool get_can_draw() { return can_draw; };
        void display();
        ~Item();
    protected:
    private:
        int _x;
        int _y;
        bool can_draw;
        sf::Texture _Texture;
        sf::Sprite _Sprite;
};

#endif /* !STONE_HPP_ */