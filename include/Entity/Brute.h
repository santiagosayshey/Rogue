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
        action a_brute1   = "15 DMG";
        action a_brute2   = "15 DMG";
        action a_brute3   = "15 DMG";
        action a_brute4   = "15 DMG";
        action a_bruteDef = "Fortify";
        
private:
    

};

#endif