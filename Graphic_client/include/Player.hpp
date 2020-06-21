/*
** EPITECH PROJECT, 2020
** Graphic_client
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>

class Player {
    public:
        Player(std::string player_data);
        ~Player();
        void update_data(std::string data);
        int getNbr();
        void draw(sf::RenderWindow *window);
    protected:
        void setOrientation(int status);
    private:
        std::vector<float> pos;
        int player_nbr;
        int orientation;
        int team_nbr;
        int level;
        sf::Sprite spr;
        sf::Texture text;
        sf::Rect<int> rect;
};

#endif /* !PLAYER_HPP_ */
