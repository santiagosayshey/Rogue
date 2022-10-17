#include "Brute.h"

Brute::Brute(Game* g)
{
    // set character sprite and ID
    sprite = new DynamicSprite(g->p->s_brute,1500,350,288,288,2);

    // set the position of the sprite
    sprite ->setPosition(1700,255);

    // set animation parameters for idling
    sprite ->setAnimation(8,0);

    // set gui
    setGUI(g->p->s_brute_gui);

    // set initial stats
    firstMove    = "15 DMG";
    health       = 100;
    power        = 15;
    armour       = 0;
    ID           = 3;
    powerBuffer  = power;
}

Brute::~Brute() { }

std::string Brute::attack(Entity* entity)
{
    // iterate through the possible behaviours
    // default behvaiour is to fortify, otherwise attack turns 1-4
    switch(currentAction)
    {
        case 1:
        {
            // set the attack animation
            getSprite()->setAnimation(19,2);

            // regular attack behaviour
            if ( entity->getHealth() - getPower() > 0 )
            { entity->setHealth(entity->getHealth() - getPower()); }

            else
            { entity->setHealth(0); }
            
            // return the next move
            return a_brute2;
        }

        case 2:
        {
            getSprite()->setAnimation(19,2);

            if ( entity->getHealth() - getPower() > 0 ) 
            
            { entity->setHealth(entity->getHealth() - getPower()); }

            else 
            
            { entity->setHealth(0); }

            return a_brute3;
        }


        case 3:
        {
            getSprite()->setAnimation(19,2);

            if ( entity->getHealth() - getPower() > 0 )

            { entity->setHealth(entity->getHealth() - getPower()); }

            else

            { entity->setHealth(0); }

            return a_brute4;
        }


        case 4:
        {
            getSprite()->setAnimation(19,2);

            if ( entity->getHealth() - getPower() > 0 )

            { entity->setHealth(entity->getHealth() - getPower()); }

            else

            { entity->setHealth(0); }

            return a_bruteDef;
        }

            
        default:
        {
            // set fortify animation
            getSprite()->setAnimation(4,6);

            // update the player power according to current entity armour stats
            entity->setPower(entity->getPower()-entity->getPower()*(getArmour()/100));

            // return default move
            return a_bruteDef;
        }


    }
}
