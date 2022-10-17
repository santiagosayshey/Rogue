#include "Golem.h"

Golem::Golem(Game* g)
{
    sprite = new DynamicSprite(g->p->s_golem,1800,65,64,64,12);
    health = 999;
    armour = 99;
    power = 0;
    ID = 4;
    powerBuffer=power;
    setGUI(g->p->s_golem_gui);

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
                powerBuffer=power;
                getSprite()->setAnimation(8,2);

                if ( entity->getHealth() - getPower() > 0 )
                {
                    entity->setHealth(entity->getHealth() - getPower()); 
                }
                else
                {
                    entity->setHealth(0);
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
        case 3:
            if (health < 999)
            {
                power=999;
                powerBuffer=power;
                getSprite()->setAnimation(8,2);

                if ( entity->getHealth() - getPower() > 0 )
                {
                    entity->setHealth(entity->getHealth() - getPower()); 
                }
                else
                {
                    entity->setHealth(0);
                }
                return a_golemDef2;
            }
            else 
            {
                health=0;
                getSprite()->setAnimation(8,4);
                return a_golemDeath;
            }

            break;
    }
    
}


