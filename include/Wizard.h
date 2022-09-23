#ifndef WIZARD_H
#define WIZARD_H

#pragma once
#include "Human.h"
#include "Button.h"

class Wizard : public Human
{
public:
    Wizard(std::string texture, int x, int y);
    ~Wizard();

    bool checkCollision(sf::RenderWindow* window);
    void update(sf::RenderWindow* window, Game* game);

    void setPos(int x, int y);

    void animation(int numFrames, int row);

    void draw(sf::RenderWindow* window);

private:
    int currentFrame = 0;
    int numFrames = 7;
    int row = 0;

    sf::Event event;
    sf::SoundBuffer buffer;
    sf::Sound click;

    Button* melee;
    Button* range;
    Button* die;
    Button* idle;
    Button* walk;

};

#endif