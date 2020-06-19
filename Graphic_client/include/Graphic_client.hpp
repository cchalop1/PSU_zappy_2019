/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** client
*/

#ifndef GRAPHIC_CLIENT_H_
#define GRAPHIC_CLIENT_H_

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Enum_Zappy_Client.hpp"
#include "Stone.hpp"
#include "Map.hpp"

class Graphic_client {
    public:
        Graphic_client();
        void init_map(std::string command);
        void init_class_graphic(int nb, int statut);
        void run();
        ~Graphic_client();
    protected:
    private:
        int _windowsize_x;
        int _windowsize_y;
        sf::RenderWindow _window;
        sf::Texture _backgroundTexture;
        sf::Sprite _backgroundSprite;
        sf::Event event;
        std::vector<Map> _map;
        std::vector<Stone> _food;
        std::vector<Stone> _linemate;
        std::vector<Stone> _deraumere;
        std::vector<Stone> _sibur;
        std::vector<Stone> _mendiane;
        std::vector<Stone> _phiras;
        std::vector<Stone> _thystame;
        int _index_map;
        int _index_stone;
};

#endif /* !GRAPHIC_CLIENT_H_ */
