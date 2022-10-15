#include "Golem.h"

Golem::Golem(Game* g)
{
    sprite = new DynamicSprite(g->p->s_golem,1800,65,64,64,12);
    health = 999;
    armour = 99;
    power = 1;
    character = 4;
    originalPower=power;

    firstMove = "AttacK - 1 DMG";
}

Golem::~Golem()
{

}


std::string Golem::attack(Entity* entity)
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
