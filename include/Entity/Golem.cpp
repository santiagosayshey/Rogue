#include "Golem.h"

Golem::Golem(Game* g)
{
    // set character sprite and ID
    sprite = new DynamicSprite(g->p->s_golem,1800,65,64,64,12);

    // set GUI
    setGUI(g->p->s_golem_gui);

    // set initial stats
    firstMove   = "ZZZ";
    health      = 999;
    armour      = 99;
    power       = 0;
    ID          = 4;
    powerBuffer = power;
}

Golem::~Golem() { }


std::string Golem::attack(Entity* entity)
{
    // iterate through the possible behaviours
    // default behvaiour is to sleep, if the player attacks, set power to 999 and attack player
    switch(currentAction)
    {
        default:
        {
            // check if the player has attacked the golem
            if (health < 999)
            {
                // set power to 999 to instakill player
                power         =999;
                powerBuffer   =power;

                // update too attack animation
                getSprite()   ->setAnimation(8,2);

                // attack the player
                if ( entity->getHealth() - getPower() > 0 )

                { entity->setHealth(entity->getHealth() - getPower()); }

                else

                { entity->setHealth(0); }
            }
             
             // check if the player has not attacked the golem
            if (health == 999)

            // return sleep behaviour
            { return a_golemDef; }

            else

            // return attack behaviour
            { return a_golemDef2; }
        }

        // if the player has not attacked the golem for 3 straight turns ->
        case 3:

            // check if the golem has been attacked
            if (health < 999)
            {
                // if it has, set its power to 99
                power        = 999;
                powerBuffer  = power;

                // set the attack animation
                getSprite()->setAnimation(8,2);

                // attack the player
                if ( entity->getHealth() - getPower() > 0 )

                { entity->setHealth(entity->getHealth() - getPower()); }

                else

                { entity->setHealth(0); }

                // return attack behaviour
                return a_golemDef2;
            }

            // if the player has NOT attacked the golem ->
            else 
            {
                // set its health to 0 and kill it
                health=0;

                // set death animation
                getSprite()->setAnimation(8,4);

                // return death behaviour
                return a_golemDeath;
            }
    }
    
}


