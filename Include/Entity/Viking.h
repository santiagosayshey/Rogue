#ifndef VIKING_H
#define VIKING_H

#pragma once
#include "../Instance/Game.h" 

typedef std::string action;

class Viking : public Entity
{
public:
    // constructor - game instance needed for paths
    Viking(Game* g);

    // destructor
    ~Viking();

    // overriden attack function to return next move
    std::string attack(Entity* entity);

private:
        // behaviours
        action a_viking1   = "20 DMG";
        action a_viking2   = "Fortify";
        action a_viking3   = "10 DMG";
        action a_viking4   = "Fortify";
        action a_viking5   = "5 DMG";
        action a_viking6   = "Fortify";
        action a_viking7   = "5 DMG";
        action a_viking8   = "Fortify";
        action a_viking9   = "5 DMG";
        action a_viking10  = "Fortify";
        action a_vikingDef = "5 DMG";

};

#endif