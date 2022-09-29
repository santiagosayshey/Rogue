#ifndef MENUSTATE_H
#define MENUSTATE_H

#pragma once
#include "State.h"
#include "../Drawable/Button.h"

class MenuState : public State
{
public:
    MenuState(Game* game, Player* player);
    ~MenuState();

    void update(sf::RenderWindow* window);
    void render(sf::RenderWindow* window);

private:
    sf::Event event;
    
    Button* play;
    Button* quit;


};

#endif