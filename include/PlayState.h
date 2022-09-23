#ifndef PlayState_H
#define PlayState_H

#pragma once

#include "State.h"
#include "Wizard.h"

class PlayState : public State
{
public:
    PlayState(Game* game);
    ~PlayState();

    void update(sf::RenderWindow* window);
    void render(sf::RenderWindow* window);


private:
    sf::Event event;
    sf::Clock clock;
    float dt;

    Wizard* wizard;

};

#endif