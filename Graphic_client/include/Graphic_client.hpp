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
#include "Item.hpp"
#include "Map.hpp"

class Graphic_client {
    public:
        Graphic_client();
        void init_graph(std::string command);
        void init_class_graphic(int nb, int statut);
        void run(std::string command);
        void check_command(std::string command);
        ~Graphic_client();
    protected:
    private:
        int _windowsize_x;
        int _windowsize_y;
        sf::RenderWindow _window;
        sf::Texture _backgroundTexture;
        sf::Sprite _backgroundSprite;
        sf::Event event;
        std::vector<Map *> _map;
        int _index_map;
};

#endif /* !GRAPHIC_CLIENT_H_ */
