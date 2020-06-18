/*
** EPITECH PROJECT, 2019
** Graphic_client
** File description:
** Stone.hpp
*/

#ifndef STONE_HPP_
#define STONE_HPP_

#include <SFML/Graphics.hpp>

class Stone {
    public:
        Stone();
        void init();
        void display();
        ~Stone();
    protected:
    private:
        int _x;
        int _y;
        int _index;
        sf::Texture _Texture;
        sf::Sprite _Sprite;
};

#endif /* !STONE_HPP_ */