/*
** EPITECH PROJECT, 2019
** Graphic_client
** File description:
** Map.hpp
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
class Map {
    public:
        Map();
        void init_x(int x) { if (x != 1) { _x = _x * x; } std::cout << _x << std::endl; };
        void init_y(int y) { if (y != 1) {_y = _y * y; } std::cout << _y << std::endl; };
        void init();
        sf::Sprite get_sprite();
        void setIndex(int index) { _index = index; };
        int getIndex() { return _index; };
        ~Map();
    protected:
    private:
        int _x;
        int _y;
        int _index;
        sf::Texture _Texture;
        sf::Sprite _Sprite;
};

#endif /* !MAP_HPP_ */