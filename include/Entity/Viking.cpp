#include "Viking.h"

Viking::Viking(Game* g)
{
    sprite = new DynamicSprite(g->p->s_viking,1500,350,32,32,16);
    sprite->setPos(1700,320);
    sprite->updateAnimation(6,0);
    health = 20;
    armour = 80;
    power = 20;
    character = 2;
    originalPower=power;
    setGUI(g->p->s_viking_gui);
    firstMove = "20 DMG";
}

Viking::~Viking()
{

}


std::string Viking::attack(Entity* entity)
{
    switch(currentAction)
    {
        case 1:
            getSprite()->updateAnimation(8,3);

            if ( entity->getHealth() - getPower() > 0 )
            {
                entity->updateHealth(entity->getHealth() - getPower()); 
            }
            else
            {
                entity->updateHealth(0);
            }
            return a_viking2;
            break;
        case 2:
            getSprite()->updateAnimation(4,2);
            entity->updatePower(entity->getPower()-entity->getPower()*(getArmour()/100));
             updatePower(10);
            originalPower=power;
            return a_viking3;
            break;
        case 3:
            getSprite()->updateAnimation(8,3);
            if ( entity->getHealth() - getPower() > 0 )
            {
                entity->updateHealth(entity->getHealth() - getPower()); 
            }
            else
            {
                entity->updateHealth(0);
            }
            return a_viking4;
            break;
        case 4:
            getSprite()->updateAnimation(4,2);
            entity->updatePower(entity->getPower()-entity->getPower()*(getArmour()/100));
             updatePower(5);
            originalPower=power;
            return a_viking5;
            break;
        case 5:
            getSprite()->updateAnimation(8,3);
            if ( entity->getHealth() - getPower() > 0 )
            {
                entity->updateHealth(entity->getHealth() - getPower()); 
            }
            else
            {
                entity->updateHealth(0);
            }
            return a_viking6;
            break;
        case 6:
            getSprite()->updateAnimation(4,2);
            entity->updatePower(entity->getPower()-entity->getPower()*(getArmour()/100));
            return a_viking7;
            break;
        case 7:
            getSprite()->updateAnimation(8,3);
            if ( entity->getHealth() - getPower() > 0 )
            {
                entity->updateHealth(entity->getHealth() - getPower()); 
            }
            else
            {
                entity->updateHealth(0);
            }
            return a_viking8;
            break;
        case 8:
            getSprite()->updateAnimation(4,2);
            entity->updatePower(entity->getPower()-entity->getPower()*(getArmour()/100));
            return a_viking9;
            break;
        case 9:
            getSprite()->updateAnimation(8,3);
            if ( entity->getHealth() - getPower() > 0 )
            {
                entity->updateHealth(entity->getHealth() - getPower()); 
            }
            else
            {
                entity->updateHealth(0);
            }
            return a_viking10;
            break;
        case 10:
            getSprite()->updateAnimation(4,2);
            entity->updatePower(entity->getPower()-entity->getPower()*(getArmour()/100));
            return a_vikingDef;
            break;
        default:
            getSprite()->updateAnimation(8,3);
            if ( entity->getHealth() - getPower() > 0 )
            {
                entity->updateHealth(entity->getHealth() - getPower()); 
            }
            else
            {
                entity->updateHealth(0);
            }
            return a_vikingDef;
            break;
    }
}
