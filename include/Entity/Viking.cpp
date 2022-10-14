#include "Viking.h"

Viking::Viking(Game* g)
{
    sprite = new DynamicSprite(g->p->s_viking,1500,350,32,32,16);
    sprite->updateAnimation(6,0);
    health = 40;
    armour = 20;
    power = 40;
    character = 2;
    originalPower=30;
}

Viking::~Viking()
{

}