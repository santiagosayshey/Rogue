#ifndef MENUSTATE_H
#define MENUSTATE_H

#pragma once
#include "State.h"
#include "../Drawable/Button.h"
#include "../Drawable/Sprite.h"

class MenuState : public State
{
public:
    MenuState(Game* game, Player* player);
    ~MenuState();

    void update(sf::RenderWindow* window);
    void render(sf::RenderWindow* window);

private:
    sf::Event event;
    
    Sprite* s_play;
    Sprite* s_quit;

    Button* b_play;
    Button* b_quit;

    Button* play;
    Button* quit;

    Button* b_title;
    Button* title;

    sf::SoundBuffer sb;
    sf::Sound UI;

    sf::SoundBuffer sb2;
    sf::Sound mus;

    bool sound1=true;
    bool sound2=true;
    bool sound3=true;


    Sprite* splash;


};

#endif