#ifndef MENUSTATE_H
#define MENUSTATE_H

#pragma once
#include "GameState.h"

class MenuState : public GameState
{
public:
    MenuState(Game* game);
    ~MenuState();

    void update(sf::RenderWindow* window);
    void render(sf::RenderWindow* window);

private:
    sf::Event event;
    sf::Texture t_splash;
    sf::Sprite s_splash;

};

#endif