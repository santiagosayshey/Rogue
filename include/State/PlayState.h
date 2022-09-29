#ifndef PlayState_H
#define PlayState_H

#pragma once

#include "State.h"
#include "../Drawable/Button.h"
#include "../Drawable/Human.h"

class PlayState : public State
{
public:
    PlayState(Game* game, Player* player);
    ~PlayState();

    void update(sf::RenderWindow* window);
    void render(sf::RenderWindow* window);


private:
    sf::Event event;

    Human* wizard;
    Human* paladin;
    Human* necrom;
    Human* golem;

    Button* melee;
    Button* range;
    Button* die;
    Button* idle;
    Button* walk;

};

#endif