#include "Brute.h"

Brute::Brute(Game* g)
{
    sprite = new DynamicSprite(g->p->s_brute,1500,350,288,288,2);
    sprite->setPos(1700,255);
    sprite->updateAnimation(8,0);
    health = 100;
    armour = 0;
    power = 15;
    character = 3;
    originalPower=power;
    setGUI(g->p->s_brute_gui);

    firstMove = "15 DMG";
}

Brute::~Brute()
{

}


std::string Brute::attack(Entity* entity)
{
    switch(currentAction)
    {
        case 1:
            getSprite()->updateAnimation(19,2);

            if ( entity->getHealth() - getPower() > 0 )
            {
                entity->updateHealth(entity->getHealth() - getPower()); 
            }
            else
            {
                entity->updateHealth(0);
            }
            return a_brute2;
            break;
        case 2:
            getSprite()->updateAnimation(19,2);
            if ( entity->getHealth() - getPower() > 0 )
            {
                entity->updateHealth(entity->getHealth() - getPower()); 
            }
            else
            {
                entity->updateHealth(0);
            }
            return a_brute3;
            break;
        case 3:
            getSprite()->updateAnimation(19,2);
            if ( entity->getHealth() - getPower() > 0 )
            {
                entity->updateHealth(entity->getHealth() - getPower()); 
            }
            else
            {
                entity->updateHealth(0);
            }
            return a_brute4;
            break;
        case 4:
            getSprite()->updateAnimation(19,2);
            if ( entity->getHealth() - getPower() > 0 )
            {
                entity->updateHealth(entity->getHealth() - getPower()); 
            }
            else
            {
                entity->updateHealth(0);
            }
            return a_bruteDef;
            break;
        default:
            getSprite()->updateAnimation(4,6);
            entity->updatePower(entity->getPower()-entity->getPower()*(getArmour()/100));
            return a_bruteDef;
            break;
    }
}
