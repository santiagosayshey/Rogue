#ifndef GOLEM_H
#define GOLEM_H

#pragma once

#include "Entity.h"
#include "../Instance/Game.h"

typedef std::string action;
class Golem : public Entity
{
public:
    // constructor - game instance needed for paths
    Golem(Game* g);

    // destructor
    ~Golem();

    // overriden attack function to return next move
    std::string attack(Entity* entity);

private:

    // behaciours
    action a_golemDef  = "ZZZ";
    action a_golemDef2 = "999 DMG";
    action a_golemDeath = "Crumbles";
};

#endif