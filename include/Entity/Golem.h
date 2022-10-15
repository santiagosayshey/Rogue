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
        action a_golemDef  = "AttacK - 1 DMG";
        action a_golemDef2 = "AttacK - 999 DMG";

private:

};

#endif