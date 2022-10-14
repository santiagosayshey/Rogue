#ifndef PILGRIM_H
#define PILGRIM_H

#pragma once
#include "../Instance/Game.h"

class Pilgrim : public Entity
{
public:
    Pilgrim(Game* g);
    ~Pilgrim();

    void attack(Entity* entity);



private:
    

};

#endif