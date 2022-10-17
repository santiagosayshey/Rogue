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
    // pass the game instance to allow the play state to change the game state
    PlayState(Game* game, Player* player);

    // deconstructor
    ~PlayState();

    // menu instance of update and render
    void update(sf::RenderWindow* window);
    void render(sf::RenderWindow* window);


private:
    // events needed for event manager within update
    sf::Event event;

    // DRAWABLES //

        // splash screen
        Sprite* splash;
        
        // BUTTONS // 

            // attack
            Sprite* s_attack;
            Text* b_attack;
            Text* t_attack;

            // fortify
            Sprite* s_fortify;
            Text* b_fortify;
            Text* t_fortify;

            // end turn
            Sprite* s_endTurn;
            Text* b_endTurn;
            Text* t_endTurn;

        // PROMPTS
        Text* b_prompt;
        Text* t_prompt;

        Text* b_endPrompt;
        Text* t_endPrompt;

        // OVER SCREENS

        Text* b_gameOver;
        Text* t_gameOver;

        Text* b_gameWon;
        Text* t_gameWon;

        // INTENTS

        Text* b_player_choice;
        Text* t_player_choice;
        
        Text* b_enemy_nextMove;
        Text* t_enemy_nextMove;

    
    // INSTANCE

        // states that control whos turn it is during the play state
        int state = 0;

        // timers to delay state switching
        int enemyCount = 0;
        int playerDeadCount = 0;
        int enemyDeadCount = 0;

    // ENTITY SPECIFIC // 

    // PLAYER

        // stats
        Text* player_b_health;
        Text* player_t_health;

        Text* player_b_armour;
        Text* player_t_armour;

        // boolean to tell if the player is dead, ie. playerhealth = 0
        bool playerDead = false;

        // current player choice used to change player behaviour
        std::string currentChoice = "AttacK";

    // ENEMY

        // forward declaration overriden by current enemy in array
        Entity* enemy;

        // stats
        Sprite* enemy_s_health;
        Text* enemy_b_health;
        Text* enemy_t_health;

        Sprite* enemy_s_armour;
        Text* enemy_b_armour;
        Text* enemy_t_armour;

        // boolean to tell if the enemy is dead, ie. playerhealth = 0
        bool enemyDead = false;

        // next enemy move saved as a string. changed through enemy behaviour
        std::string enemyNextMove;

};

#endif