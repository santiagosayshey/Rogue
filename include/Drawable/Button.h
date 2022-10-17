#ifndef BUTTON_H
#define BUTTON_H

#pragma once

#include "Sprite.h"
#include "Text.h"
#include "../Instance/Game.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

typedef sf::Color c;
typedef sf::Text t;

class Button : public Drawable
{
public:
    Button(int type, std::string string, int fSize, Game* game);
    ~Button();

    void setPosition(int x, int y);
    void setTextPosition(int x, int y);

    void draw(sf::RenderWindow* window);

    bool checkCollision(sf::RenderWindow* window);

private:
    Sprite* background;

    Text* black;
    Text* white;

    int x;
    int y;

    int width;
    int height;

    int ID;

};

#endif