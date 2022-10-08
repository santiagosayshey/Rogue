#ifndef PICKSTATE_H
#define PICKSTATE_H

#pragma once

#include "State.h"
#include "../Drawable/Text.h"
#include "../Drawable/Sprite.h"
#include <fstream>

class PickState : public State
{
public:
    PickState(Game* game, Player* player);
    ~PickState();

    void update(sf::RenderWindow* window);
    void render(sf::RenderWindow* window);

private:
    sf::Event event;
    sf::Font font;

    Text* wizardText;
    Text* paladinText;
    Text* samuraiText;
    Text* embark;

    Sprite* wizard;
    Sprite* paladin;
    Sprite* samurai;

    sf::Text paladinStats;
    sf::Text wizardStats;
    sf::Text samuraiStats;

    int currentSel=1;

};

#endif