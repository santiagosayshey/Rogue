#ifndef MENUSTATE_H
#define MENUSTATE_H

#pragma once
#include "State.h"
#include "../Drawable/Text.h"
#include "../Drawable/Sprite.h"

class MenuState : public State
{
public:

    // pass the game instance to allow the menu to change the game state
    MenuState(Game* game, Player* player);

    // deconstructor
    ~MenuState();

    // menu instance of update and render
    void update(sf::RenderWindow* window);
    void render(sf::RenderWindow* window);

private:
    // events needed for event manager within update
    sf::Event event;
    
    // sprites
    Sprite* splash; // splash screen

    Sprite* s_play;
    Sprite* s_quit;
    Sprite* s_stats;

    // text  
    Text* b_play;
    Text* w_play;
    
    Text* b_quit;
    Text* w_quit;

    Text* b_stats;
    Text* w_stats;

    Text* b_title;
    Text* w_title;

    // sounds
    sf::SoundBuffer buffer;

    sf::Sound UI;

    bool sound1 = true;
    bool sound2 = true;
    bool sound3 = true;
};

#endif