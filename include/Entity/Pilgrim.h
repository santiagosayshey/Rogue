#ifndef PILGRIM_H
#define PILGRIM_H

#pragma once
#include "../Instance/Game.h"

class Pilgrim : public Entity
{
public:
    Pilgrim(Game* g);
    ~Pilgrim();

    int getOGPower();

private:
    

};

#endif