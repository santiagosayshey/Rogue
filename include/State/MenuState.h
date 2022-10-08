#ifndef MENUSTATE_H
#define MENUSTATE_H

#pragma once
#include "State.h"
#include "../Drawable/Text.h"
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

    Text* b_play;
    Text* b_quit;

    Text* play;
    Text* quit;

    Text* b_title;
    Text* title;

    sf::SoundBuffer sb;
    sf::Sound UI;

    sf::SoundBuffer sb2;
    sf::Sound mus;

    bool sound1=true;
    bool sound2=true;


    Sprite* splash;


};

#endif