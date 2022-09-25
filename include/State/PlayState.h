#ifndef PlayState_H
#define PlayState_H

#pragma once

#include "State.h"
#include "../Entity/Button.h"
#include "../Entity/Human.h"

class PlayState : public State
{
public:
    PlayState(Game* game);
    ~PlayState();

    void update(sf::RenderWindow* window);
    void render(sf::RenderWindow* window);


private:
    sf::Event event;

    Human* wizard;
    Human* paladin;
    Human* necrom;

    Button* melee;
    Button* range;
    Button* die;
    Button* idle;
    Button* walk;

};

#endif