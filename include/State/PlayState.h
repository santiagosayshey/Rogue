#ifndef PlayState_H
#define PlayState_H

#pragma once

#include "State.h"
#include "../Entity/Golem.h"
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
    // player
        sf::Event event;
        sf::Clock clock;

        Sprite* s_attack;
        Text* b_attack;
        Text* t_attack;

        Sprite* s_dodge;
        Text* b_dodge;
        Text* t_dodge;

        Sprite* s_endTurn;
        Text* b_endTurn;
        Text* t_endTurn;

        Sprite* player_s_health;
        Text* player_b_health;
        Text* player_t_health;

        Sprite* player_s_armour;
        Text* player_b_armour;
        Text* player_t_armour;

        Sprite* player_s_power;
        Text* player_b_power;
        Text* player_t_power;

        Text* b_prompt;
        Text* t_prompt;


        bool currentTurn=true;

        int choice;
        bool decision;

        bool sound1 = true;
        bool sound2 = true;
        bool sound3 = true;
        bool sound4 = true;

        sf::SoundBuffer sb;
        sf::Sound UI;
        int count = 1;

        int state = 0;
        bool playerChoice = true;

        std::string currentChoice = "AttacK";

        bool playerDead = false;

    // enemy
        Golem* enemy;

        Sprite* enemy_s_health;
        Text* enemy_b_health;
        Text* enemy_t_health;

        Sprite* enemy_s_armour;
        Text* enemy_b_armour;
        Text* enemy_t_armour;

        Sprite* enemy_s_power;
        Text* enemy_b_power;
        Text* enemy_t_power;

        bool enemyDead = false;

        int enemyCount = 0;
        int playerDeadCount = 0;
        int enemyDeadCount = 0;

        Text* b_player_choice;
        Text* t_player_choice;
        Text* b_enemy_choice;
        Text* t_enemy_choice;


        Text* b_gameOver;
        Text* t_gameOver;

};

#endif