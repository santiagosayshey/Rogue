#ifndef MENUSTATE_H
#define MENUSTATE_H

#pragma once
#include "State.h"

class MenuState : public State
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

    sf::Texture t_playButton;
    sf::Texture t_optionsButton;
    sf::Texture t_quitButton;

    sf::Sprite s_playButton;
    sf::Sprite s_optionsButton;
    sf::Sprite s_quitButton;

    sf::Text text;
    sf::Font font;
};

#endif