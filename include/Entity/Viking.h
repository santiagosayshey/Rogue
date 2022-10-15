#ifndef VIKING_H
#define VIKING_H

#pragma once
#include "../Instance/Game.h" 

typedef std::string action;

class Viking : public Entity
{
public:
    Viking(Game* g);
    ~Viking();

    std::string attack(Entity* entity);

    // enemy attack patterns
    
        // viking
        action a_viking1   = "AttacK - 20 DMG";
        action a_viking2   = "Fortify";
        action a_viking3   = "AttacK - 10 DMG";
        action a_viking4   = "Fortify";
        action a_viking5   = "AttacK - 5 DMG";
        action a_viking6   = "Fortify";
        action a_viking7   = "AttacK - 5 DMG";
        action a_viking8   = "Fortify";
        action a_viking9   = "AttacK - 5 DMG";
        action a_viking10  = "Fortify";
        action a_vikingDef = "AttacK - 5 DMG";

private:
    

};

#endif