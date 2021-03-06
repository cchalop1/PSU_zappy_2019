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
#include "Enum_Zappy_Client.hpp"
#include "Item.hpp"
class Map {
    public:
        Map(std::vector<sf::Texture> &_texture_item);
        void init_x(int x);
        void init_y(int y);
        void init();
        void draw(sf::RenderWindow *_window);
        void set_item(int item, int nb);
        void setIndex(int index) { _index = index; };
        int getIndex() { return _index; };
        void rezise_tile(float nb);
        ~Map();
    protected:
    private:
        int _x;
        int _y;
        int _index;
        sf::RenderWindow *_window;
        sf::Texture _Texture;
        sf::Sprite _Sprite;
        std::vector<sf::Texture> &_texture_item;
        std::vector<Item> _food;
        std::vector<Item> _linemate;
        std::vector<Item> _deraumere;
        std::vector<Item> _sibur;
        std::vector<Item> _mendiane;
        std::vector<Item> _phiras;
        std::vector<Item> _thystame;
        int _index_item;
};

#endif /* !MAP_HPP_ */