#ifndef WIZARD_H
#define WIZARD_H

#pragma once
#include "Human.h"

class Wizard : public Human
{
public:
    Wizard(std::string texture, int x, int y);
    ~Wizard();

    bool checkCollision(sf::RenderWindow* window);
    void update(sf::RenderWindow* window, Game* game);

    void setPos(int x, int y);

    void animation(int row);

private:
    int currentFrame = 0;
    int row = 0;
    sf::Event event;

};

#endif