#ifndef BRUTE_H
#define BRUTE_H

#pragma once
#include "../Instance/Game.h" 

typedef std::string action;
class Brute : public Entity
{
public:
    // constructor - game instance needed for paths
    Brute(Game* g);

    // destructor
    ~Brute();

    // overriden attack function to return next move
    std::string attack(Entity* entity);
        
private:

    // behaviours
    action a_brute1   = "15 DMG";
    action a_brute2   = "15 DMG";
    action a_brute3   = "15 DMG";
    action a_brute4   = "15 DMG";
    action a_bruteDef = "Fortify";

};

#endif