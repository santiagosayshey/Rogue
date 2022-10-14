#include "Pilgrim.h"
#include <iostream>

Pilgrim::Pilgrim(Game* g)
{
    sprite = new DynamicSprite(g->p->s_pilgrim,1500,350,32,32,16);
    health = 60;
    armour = 30;
    power = 5;
    character = 1;
    originalPower=power;
}

Pilgrim::~Pilgrim()
{

}


void Pilgrim::attack(Entity* entity)
{
    switch(currentAction)
    {
        case 1:
            getSprite()->updateAnimation(8,4);

            if ( entity->getHealth() - getPower() > 0 )
            {
                entity->updateHealth(entity->getHealth() - getPower()); 
            }
            else
            {
                entity->updateHealth(0);
            }
            break;
        case 2:
            getSprite()->updateAnimation(7,3);
            entity->updatePower(entity->getPower()-entity->getPower()*(getArmour()/100));
            break;
        case 3:
            getSprite()->updateAnimation(8,4);
            updatePower(10);
            originalPower=power;
            if ( entity->getHealth() - getPower() > 0 )
            {
                entity->updateHealth(entity->getHealth() - getPower()); 
            }
            else
            {
                entity->updateHealth(0);
            }
            break;
        case 4:
            getSprite()->updateAnimation(7,3);
            entity->updatePower(entity->getPower()-entity->getPower()*(getArmour()/100));
            break;
        case 5:
            getSprite()->updateAnimation(8,4);
            updatePower(20);
            originalPower=power;
            if ( entity->getHealth() - getPower() > 0 )
            {
                entity->updateHealth(entity->getHealth() - getPower()); 
            }
            else
            {
                entity->updateHealth(0);
            }
            break;
        case 6:
            getSprite()->updateAnimation(7,3);
            entity->updatePower(entity->getPower()-entity->getPower()*(getArmour()/100));
            break;
        case 7:
            getSprite()->updateAnimation(8,4);
            if ( entity->getHealth() - getPower() > 0 )
            {
                entity->updateHealth(entity->getHealth() - getPower()); 
            }
            else
            {
                entity->updateHealth(0);
            }
            break;
        case 8:
            getSprite()->updateAnimation(7,3);
            entity->updatePower(entity->getPower()-entity->getPower()*(getArmour()/100));
            break;
        case 9:
            getSprite()->updateAnimation(8,4);
            if ( entity->getHealth() - getPower() > 0 )
            {
                entity->updateHealth(entity->getHealth() - getPower()); 
            }
            else
            {
                entity->updateHealth(0);
            }
            break;
        case 10:
            getSprite()->updateAnimation(7,3);
            entity->updatePower(entity->getPower()-entity->getPower()*(getArmour()/100));
            break;
        default:
            getSprite()->updateAnimation(8,4);
            if ( entity->getHealth() - getPower() > 0 )
            {
                entity->updateHealth(entity->getHealth() - getPower()); 
            }
            else
            {
                entity->updateHealth(0);
            }
            break;
    }
}
