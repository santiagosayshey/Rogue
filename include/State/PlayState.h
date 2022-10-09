#ifndef PlayState_H
#define PlayState_H

#pragma once

#include "State.h"
#include "../Entity/Enemy.h"
#include "../Drawable/Text.h"
#include "../Drawable/Sprite.h"

class PlayState : public State
{
public:
    PlayState(Game* game, Player* player);
    ~PlayState();

    void update(sf::RenderWindow* window);
    void render(sf::RenderWindow* window);


private:
    sf::Event event;
    sf::Clock clock;

    Sprite* s_attack;
    Text* b_attack;
    Text* t_attack;

    Sprite* s_defend;
    Text* b_defend;
    Text* t_defend;

    Sprite* player_s_health;
    Text* player_b_health;
    Text* player_t_health;

    Sprite* player_s_armour;
    Text* player_b_armour;
    Text* player_t_armour;

    Sprite* player_s_power;
    Text* player_b_power;
    Text* player_t_power;

    Text* b_prompt_player;
    Text* t_prompt_player;
    Text* b_prompt_enemy;
    Text* t_prompt_enemy;

    bool currentTurn=true;

    int choice;
    bool decision;

    bool sound1 = true;
    bool sound2 = true;
    bool sound3 = true;
    bool sound4 = true;

    sf::SoundBuffer sb;
    sf::Sound UI;

};

#endif