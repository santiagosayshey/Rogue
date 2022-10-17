#include "Viking.h"

Viking::Viking(Game* g)
{
    sprite = new DynamicSprite(g->p->s_viking,1500,350,32,32,16);
    sprite->setPosition(1700,320);
    sprite->setAnimation(6,0);
    health = 30;
    armour = 80;
    power = 20;
    ID = 2;
    powerBuffer=power;
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
            getSprite()->setAnimation(8,3);

            if ( entity->getHealth() - getPower() > 0 )
            {
                entity->setHealth(entity->getHealth() - getPower()); 
            }
            else
            {
                entity->setHealth(0);
            }
            return a_viking2;
            break;
        case 2:
            getSprite()->setAnimation(4,2);
            entity->setPower(entity->getPower()-entity->getPower()*(getArmour()/100));
             setPower(10);
            powerBuffer=power;
            return a_viking3;
            break;
        case 3:
            getSprite()->setAnimation(8,3);
            if ( entity->getHealth() - getPower() > 0 )
            {
                entity->setHealth(entity->getHealth() - getPower()); 
            }
            else
            {
                entity->setHealth(0);
            }
            return a_viking4;
            break;
        case 4:
            getSprite()->setAnimation(4,2);
            entity->setPower(entity->getPower()-entity->getPower()*(getArmour()/100));
             setPower(5);
            powerBuffer=power;
            return a_viking5;
            break;
        case 5:
            getSprite()->setAnimation(8,3);
            if ( entity->getHealth() - getPower() > 0 )
            {
                entity->setHealth(entity->getHealth() - getPower()); 
            }
            else
            {
                entity->setHealth(0);
            }
            return a_viking6;
            break;
        case 6:
            getSprite()->setAnimation(4,2);
            entity->setPower(entity->getPower()-entity->getPower()*(getArmour()/100));
            return a_viking7;
            break;
        case 7:
            getSprite()->setAnimation(8,3);
            if ( entity->getHealth() - getPower() > 0 )
            {
                entity->setHealth(entity->getHealth() - getPower()); 
            }
            else
            {
                entity->setHealth(0);
            }
            return a_viking8;
            break;
        case 8:
            getSprite()->setAnimation(4,2);
            entity->setPower(entity->getPower()-entity->getPower()*(getArmour()/100));
            return a_viking9;
            break;
        case 9:
            getSprite()->setAnimation(8,3);
            if ( entity->getHealth() - getPower() > 0 )
            {
                entity->setHealth(entity->getHealth() - getPower()); 
            }
            else
            {
                entity->setHealth(0);
            }
            return a_viking10;
            break;
        case 10:
            getSprite()->setAnimation(4,2);
            entity->setPower(entity->getPower()-entity->getPower()*(getArmour()/100));
            return a_vikingDef;
            break;
        default:
            getSprite()->setAnimation(8,3);
            if ( entity->getHealth() - getPower() > 0 )
            {
                entity->setHealth(entity->getHealth() - getPower()); 
            }
            else
            {
                entity->setHealth(0);
            }
            return a_vikingDef;
            break;
    }
}
