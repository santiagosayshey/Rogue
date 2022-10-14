#ifndef VIKING_H
#define VIKING_H

#pragma once
#include "../Instance/Game.h" 

class Viking : public Entity
{
public:
    Viking(Game* g);
    ~Viking();

    int getOGPower();


private:
    

};

#endif