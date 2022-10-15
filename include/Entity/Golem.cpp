#include "Golem.h"

Golem::Golem(Game* g)
{
    sprite = new DynamicSprite(g->p->s_golem,1800,65,64,64,12);
    health = 999;
    armour = 99;
    power = 0;
    character = 4;
    originalPower=power;

    firstMove = "ZZZ";
}

Golem::~Golem()
{

}


std::string Golem::attack(Entity* entity)
{
    switch(currentAction)
    {
        default:
            if (health < 999)
            {
                power=999;
                originalPower=power;
                getSprite()->updateAnimation(8,2);

                if ( entity->getHealth() - getPower() > 0 )
                {
                    entity->updateHealth(entity->getHealth() - getPower()); 
                }
                else
                {
                    entity->updateHealth(0);
                }
            }

            if (health == 999)
            {
                return a_golemDef;
            }
            else
            {
                return a_golemDef2;
            }
            break;
        case 4:
            if (health < 999)
            {
                power=999;
                originalPower=power;
                getSprite()->updateAnimation(8,2);

                if ( entity->getHealth() - getPower() > 0 )
                {
                    entity->updateHealth(entity->getHealth() - getPower()); 
                }
                else
                {
                    entity->updateHealth(0);
                }
                return a_golemDef2;
            }
            else 
            {
                health=0;
                getSprite()->updateAnimation(8,4);
                return a_golemDeath;
            }

            break;
    }
}
