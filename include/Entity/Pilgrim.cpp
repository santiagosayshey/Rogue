#include "Pilgrim.h"

Pilgrim::Pilgrim(Game* g)
{
    sprite = new DynamicSprite(g->p->s_pilgrim,1500,350,32,32,16);
    health = 60;
    armour = 30;
    power = 20;
    character = 1;
    originalPower=20;
}

Pilgrim::~Pilgrim()
{

}

