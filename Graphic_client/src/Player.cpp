/*
** EPITECH PROJECT, 2020
** Graphic_client
** File description:
** Player
*/

#include "../include/Player.hpp"

Player::Player(std::string player_data)
{
    std::size_t found = 0;
    int status = 0;
    std::string _substr;

    if (player_data[0] != ' ')
        player_data.insert(0, " ");
    for (int status = 0; status != 6; status++)
    {
        found = player_data.find(" ") + 1;
        player_data = player_data.substr(found);
        _substr = player_data.substr(0, player_data.find(" "));
        switch (status) {
            case 0:
                player_nbr = atoi(_substr.c_str());
                break;
            case 1:
                pos.push_back(atof(_substr.c_str()));
                break;
            case 2:
                pos.push_back(atof(_substr.c_str()));
                break;
            case 3:
                orientation = atoi(_substr.c_str());
                break;
            case 4:
                level = atoi(_substr.c_str());
                break;
            case 5:
                team_nbr = atoi(_substr.c_str());
                break;
        }
    }
    text.loadFromFile("assets/character.png");
    spr.setTexture(text);
    rect.top = 0;
    rect.left = 0;
    rect.width = 100;
    rect.height = 100;
    spr.setTextureRect(rect);
    spr.setPosition((sf::Vector2f){450 + (pos[0] * 100), 20 + (pos[1] * 100)});
    setOrientation(orientation);
}

Player::~Player()
{
}

void Player::setOrientation(int status)
{
    rect.left = 0;
    switch (status) {
        case 1:
            rect.top = 200;
        case 2:
            rect.top = 100;
        case 3:
            rect.top = 0;
        case 4:
            rect.top = 300;
    }
    spr.setTextureRect(rect);
}

void Player::update_data(std::string data)
{
    std::size_t found = 0;
    int status = 0;
    std::string _substr;

    if (data[0] != ' ')
        data.insert(0, " ");
    for (int status = 0; status != 3; status++)
    {
        found = data.find(" ") + 1;
        data = data.substr(found);
        _substr = data.substr(0, data.find(" "));
        switch (status) {
            case 0:
                pos[0] = atof(_substr.c_str());
                break;
            case 1:
                pos[1] = atof(_substr.c_str());
                break;
            case 2:
                orientation = atoi(_substr.c_str());
                break;
        }
    }
    spr.setPosition((sf::Vector2f){450 + (pos[0] * 100), 20 + (pos[1] * 100)});
    setOrientation(orientation);
}

void Player::draw(sf::RenderWindow *window)
{
    window->draw(spr);
}

int Player::getNbr()
{
    return player_nbr;
}