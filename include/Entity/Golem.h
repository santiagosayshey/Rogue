#ifndef GOLEM_H
#define GOLEM_H

#pragma once

#include "Entity.h"
#include "../Instance/Game.h"

typedef std::string action;
class Golem : public Entity
{
public:
    Golem(Game* g);
    ~Golem();

    std::string attack(Entity* entity);

    // enemy attack patterns

        // golem
        action a_golemDef  = "ZZZ";
        action a_golemDef2 = "999 DMG";
        action a_golemDeath = "Crumbles";

private:

};

#endif