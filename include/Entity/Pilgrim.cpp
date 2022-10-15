#include "Pilgrim.h"
#include <iostream>

Pilgrim::Pilgrim(Game* g)
{
    sprite = new DynamicSprite(g->p->s_pilgrim,1500,350,32,32,16);
    health = 50;
    armour = 50;
    power = 5;
    character = 1;
    originalPower=power;

    firstMove = "AttacK - 5 DMG";
}

Pilgrim::~Pilgrim()
{

}


std::string Pilgrim::attack(Entity* entity)
{
    switch(currentAction)
    {
        case 1:
            getSprite()->updateAnimation(5,2);

            if ( entity->getHealth() - getPower() > 0 )
            {
                entity->updateHealth(entity->getHealth() - getPower()); 
            }
            else
            {
                entity->updateHealth(0);
            }
            return a_pilgrim2;
            break;
        case 2:
            getSprite()->updateAnimation(7,3);
            entity->updatePower(entity->getPower()-entity->getPower()*(getArmour()/100));
            updatePower(10);
            originalPower=power;
            return a_pilgrim3;
            break;
        case 3:
            getSprite()->updateAnimation(8,4);
            if ( entity->getHealth() - getPower() > 0 )
            {
                entity->updateHealth(entity->getHealth() - getPower()); 
            }
            else
            {
                entity->updateHealth(0);
            }
            return a_pilgrim4;
            break;
        case 4:
            getSprite()->updateAnimation(7,3);
            entity->updatePower(entity->getPower()-entity->getPower()*(getArmour()/100));
            getSprite()->updateAnimation(8,4);
            updatePower(20);
            originalPower=power;
            return a_pilgrim5;
            break;
        case 5:
            if ( entity->getHealth() - getPower() > 0 )
            {
                entity->updateHealth(entity->getHealth() - getPower()); 
            }
            else
            {
                entity->updateHealth(0);
            }
            return a_pilgrim6;
            break;
        case 6:
            getSprite()->updateAnimation(7,3);
            entity->updatePower(entity->getPower()-entity->getPower()*(getArmour()/100));
            return a_pilgrim7;
            break;
        case 7:
            getSprite()->updateAnimation(5,2);
            if ( entity->getHealth() - getPower() > 0 )
            {
                entity->updateHealth(entity->getHealth() - getPower()); 
            }
            else
            {
                entity->updateHealth(0);
            }
            return a_pilgrim8;
            break;
        case 8:
            getSprite()->updateAnimation(7,3);
            entity->updatePower(entity->getPower()-entity->getPower()*(getArmour()/100));
            return a_pilgrim9;
            break;
        case 9:
            getSprite()->updateAnimation(5,2);
            if ( entity->getHealth() - getPower() > 0 )
            {
                entity->updateHealth(entity->getHealth() - getPower()); 
            }
            else
            {
                entity->updateHealth(0);
            }
            return a_pilgrim10;
            break;
        case 10:
            getSprite()->updateAnimation(7,3);
            entity->updatePower(entity->getPower()-entity->getPower()*(getArmour()/100));
            return a_pilgrimDef;
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
            return a_pilgrimDef;
            break;
    }
}
