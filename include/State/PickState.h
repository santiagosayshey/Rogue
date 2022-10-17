#ifndef PICKSTATE_H
#define PICKSTATE_H

#pragma once

#include "State.h"
#include "../Drawable/Text.h"
#include "../Drawable/Sprite.h"
#include "../Drawable/DynamicSprite.h"

class PickState : public State
{
public:
    // pass the game instance to allow the character select to change the game state
    PickState(Game* g, Player* player);

    // deconstructor
    ~PickState();

    // menu instance of update and render
    void update(sf::RenderWindow* window);
    void render(sf::RenderWindow* window);

private:
    // events needed for event manager within update
    sf::Event event;

    // sprites

        // splash screem
        Sprite* splash;

        // buttons
        Sprite* s_wiz;
        Sprite* s_pal;
        Sprite* s_nin;
        Sprite* s_emb;

        // stats
        Sprite* spr_wiz_stats;
        Sprite* spr_pal_stats;
        Sprite* spr_nin_stats;

    // dynamic sprites
    DynamicSprite* spr_wiz;
    DynamicSprite* spr_pal;
    DynamicSprite* spr_nin;

    // text
        // buttons
        Text* b_wiz;
        Text* w_wiz;

        Text* b_pal;
        Text* w_pal;

        Text* b_nin;
        Text* w_nin;

        Text* b_emb;
        Text* w_emb;

    Text* w_prompt;
    Text* b_prompt;

    // int choice to switch character states within selector
    int choice;

};

#endif
