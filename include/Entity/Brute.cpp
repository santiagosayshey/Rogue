#include "Brute.h"

Brute::Brute(Game* g)
{
    sprite = new DynamicSprite(g->p->s_brute,1500,350,288,288,2);
    sprite->updateAnimation(8,0);
    health = 100;
    armour = 10;
    power = 30;
    character = 3;
    originalPower=30;
}

Brute::~Brute()
{

}