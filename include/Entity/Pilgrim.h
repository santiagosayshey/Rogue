#ifndef PILGRIM_H
#define PILGRIM_H

#pragma once
#include "../Instance/Game.h"

typedef std::string action;

class Pilgrim : public Entity
{
public:
    Pilgrim(Game* g);
    ~Pilgrim();

    std::string attack(Entity* entity);

    // enemy attack patterns

        // pilgrim
        action a_pilgrim1   = "5 DMG";
        action a_pilgrim2   = "Fortify";
        action a_pilgrim3   = "10 DMG";
        action a_pilgrim4   = "Fortify";
        action a_pilgrim5   = "20 DMG";
        action a_pilgrim6   = "Fortify";
        action a_pilgrim7   = "20 DMG";
        action a_pilgrim8   = "Fortify";
        action a_pilgrim9   = "20 DMG";
        action a_pilgrim10  = "Fortify";
        action a_pilgrimDef = "20 DMG";


private:
    

};

#endif