#ifndef PICKSTATE_H
#define PICKSTATE_H

#pragma once

#include "State.h"
#include "../Drawable/Text.h"
#include "../Drawable/Sprite.h"

class PickState : public State
{
public:
    PickState(Game* g, Player* player);
    ~PickState();

    void update(sf::RenderWindow* window);
    void render(sf::RenderWindow* window);

private:
    sf::Event event;

    Sprite* splash;
    Sprite* s_wiz;
    Text* b_wiz;
    Text* t_wiz;

    Sprite* s_pal;
    Text* b_pal;
    Text* t_pal;

    Sprite* s_nin;
    Text* b_nin;
    Text* t_nin;

    Sprite* s_emb;
    Text* b_emb;
    Text* t_emb;

    bool sound1 = true;
    bool sound2 = true;
    bool sound3 = true;
    bool sound4 = true;

    sf::SoundBuffer sb;
    sf::Sound UI;

    Sprite* spr_wiz;
    Sprite* spr_pal;
    Sprite* spr_nin;

    Sprite* spr_wiz_stats;
    Sprite* spr_pal_stats;
    Sprite* spr_nin_stats;

    Text* prompt;
    Text* b_prompt;

    int c=1;

};

#endif
