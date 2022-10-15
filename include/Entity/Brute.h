#ifndef BRUTE_H
#define BRUTE_H

#pragma once
#include "../Instance/Game.h" 

typedef std::string action;
class Brute : public Entity
{
public:
    Brute(Game* g);
    ~Brute();

    std::string attack(Entity* entity);

    // enemy attack patterns

        // brute
        action a_brute1   = "AttacK - 15 DMG";
        action a_brute2   = "AttacK - 15 DMG";
        action a_brute3   = "AttacK - 15 DMG";
        action a_brute4   = "AttacK - 15 DMG";
        action a_bruteDef = "Forify";
        
private:
    

};

#endif