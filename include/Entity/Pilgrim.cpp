#include "Pilgrim.h"
#include <iostream>

Pilgrim::Pilgrim(Game* g)
{
    // set character sprite and ID
    sprite = new DynamicSprite(g->p->s_pilgrim,1500,350,32,32,16);

    sprite ->setPosition(1700,320);
    
    // set GUI
    setGUI(g->p->s_pilgrim_gui);

    // set intial stats
    firstMove = "5 DMG";
    health = 50;
    armour = 50;
    power = 5;
    ID = 1;
    powerBuffer=power;
}

Pilgrim::~Pilgrim() { }


std::string Pilgrim::attack(Entity* entity)
{

    // iterate through the possible behaviours
    // keep switching between attack and fortify, increasing attack until power = 20
    // after turn 10, default is attack 20 DMG
    switch(currentAction)
    {
        case 1:
        {
            // set attack animation
            getSprite()->setAnimation(5,2);

            // attack the player
            if ( entity->getHealth() - getPower() > 0 )

            { entity->setHealth(entity->getHealth() - getPower()); }

            else

            { entity->setHealth(0); }

            // return next move
            return a_pilgrim2;
        }

        case 2:
        {
            // set fortify animation
            getSprite()->setAnimation(7,3);

            // update player power according to pilgrim armour stat
            entity->setPower(entity->getPower()-entity->getPower()*(getArmour()/100));

            // update the power of the pilgrim back incase it was changed
            setPower(10);
            powerBuffer = power;

            // return the next move
            return a_pilgrim3;
        }

        // ad nauseum... 
        case 3:
        {
            getSprite()->setAnimation(8,4);

            if ( entity->getHealth() - getPower() > 0 )
            { entity->setHealth(entity->getHealth() - getPower()); }

            else

            { entity->setHealth(0); }

            return a_pilgrim4;
        }

        case 4:
        {
            getSprite()->setAnimation(7,3);

            entity->setPower(entity->getPower()-entity->getPower()*(getArmour()/100));

            getSprite()->setAnimation(8,4);

            setPower(20);
            powerBuffer = power;

            return a_pilgrim5;
        }


        case 5:
        {
            if ( entity->getHealth() - getPower() > 0 )

            { entity->setHealth(entity->getHealth() - getPower()); }
            
            else

            { entity->setHealth(0); }

            return a_pilgrim6;
        }


        case 6:
        {
            getSprite()->setAnimation(7,3);

            entity->setPower(entity->getPower()-entity->getPower()*(getArmour()/100));

            return a_pilgrim7;
        }


        case 7:
        {
            getSprite()->setAnimation(5,2);

            if ( entity->getHealth() - getPower() > 0 )

            { entity->setHealth(entity->getHealth() - getPower()); }

            else

            { entity->setHealth(0); }

            return a_pilgrim8;
        }


        case 8:
        {
            getSprite()->setAnimation(7,3);

            entity->setPower(entity->getPower()-entity->getPower()*(getArmour()/100));

            return a_pilgrim9;
        }



        case 9:
        {
            getSprite()->setAnimation(5,2);

            if ( entity->getHealth() - getPower() > 0 )

            { entity->setHealth(entity->getHealth() - getPower()); }

            else

            { entity->setHealth(0); }
            
            return a_pilgrim10;
        }


        case 10:
        {
            getSprite()->setAnimation(7,3);

            entity->setPower(entity->getPower()-entity->getPower()*(getArmour()/100));

            return a_pilgrimDef;
        }


        // default attack for the last listed damege - 20 
        default:
        {
            getSprite()->setAnimation(8,4);

            if ( entity->getHealth() - getPower() > 0 )

            { entity->setHealth(entity->getHealth() - getPower()); }

            else

            { entity->setHealth(0); }

            return a_pilgrimDef;
        }
    }
}
