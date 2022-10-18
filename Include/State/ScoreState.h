#ifndef SCORESTATE_H
#define SCORESTATE_H

#pragma once
#include "State.h"
#include "../Drawable/Text.h"
#include "../Drawable/Sprite.h"

class ScoreState : public State
{
public:
    // pass the game instance to allow the menu to change the game state
    ScoreState(Game* game, Player* player);

    // deconstructor
    ~ScoreState();

    // menu instance of update and render
    void update(sf::RenderWindow* window);
    void render(sf::RenderWindow* window);

private:
    // splash screen
    Sprite* splash;

    // events
    sf::Event event;

    // back button
    Sprite* s_back;
    Text* b_back;
    Text* w_back;

    // stat prompts
    Text* fastRun;
    Text* totalRun;
    Text* wins;
    Text* losses;

};

#endif