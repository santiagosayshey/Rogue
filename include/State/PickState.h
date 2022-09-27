#ifndef PICKSTATE_H
#define PICKSTATE_H

#pragma once

#include "State.h"
#include "../Entity/Button.h"
#include "../Entity/Human.h"
#include <fstream>

class PickState : public State
{
public:
    PickState(Game* game);
    ~PickState();

    void update(sf::RenderWindow* window);
    void render(sf::RenderWindow* window);

private:
    sf::Event event;
    sf::Font font;

    Button* wizardButton;
    Button* paladinButton;
    Button* samuraiButton;

    Human* wizard;
    
    Human* paladin;
    sf::Text palDes;
    sf::Text palStat;
    


    Human* samurai;

    int currentSel;
    bool idle;

};

#endif