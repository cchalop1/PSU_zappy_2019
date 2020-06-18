/*
** EPITECH PROJECT, 2019
** Graphic_client
** File description:
** Map.hpp
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include <SFML/Graphics.hpp>

class Map {
    public:
        Map();
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