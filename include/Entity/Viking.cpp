#include "Viking.h"

Viking::Viking(Game* game)
{
    // set character sprite and ID
    sprite = new DynamicSprite(game->getPath()->s_viking,1500,350,32,32,16);
    
    // set the position of the sprite
    sprite->setPosition(1700,320);

    // set animation parameters for idling
    sprite->setAnimation(6,0);

    // set gui
    setGUI(game->getPath()->s_viking_gui);

    // set initial stats
    firstMove = "20 DMG";
    health = 30;
    armour = 80;
    power = 20;
    ID = 2;
    powerBuffer=power;
}

Viking::~Viking()
{

}


std::string Viking::attack(Entity* entity)
{

    // iterate through the possible behaviours
    // keep switching between attack and fortify, decreasing attack until power = 5
    // after turn 10, default is attack 20 DMG
    switch(currentAction)
    {
        case 1:
        {
            // set attack animation
            getSprite()->setAnimation(8,3);

            // attack the player
            if ( entity->getHealth() - getPower() > 0 )

            { entity->setHealth(entity->getHealth() - getPower()); }

            else

            { entity->setHealth(0); }

            // return next move
            return a_viking2;
        }

        case 2:
        {
            // set fortify animation
            getSprite()->setAnimation(4,2);

            // update player power according to viking armour stat
            entity->setPower(entity->getPower()-entity->getPower()*(getArmour()/100));

            // update the power of the viking back incase it was changed
            setPower(10);
            powerBuffer = power;

            // return the next move
            return a_viking3;
        }

        // ad nauseum... 
        case 3:
        {
            getSprite()->setAnimation(8,3);

            if ( entity->getHealth() - getPower() > 0 )
            { entity->setHealth(entity->getHealth() - getPower()); }

            else

            { entity->setHealth(0); }

            return a_viking4;
        }

        case 4:
        {
            getSprite()->setAnimation(4,2);

            entity->setPower(entity->getPower()-entity->getPower()*(getArmour()/100));

            getSprite()->setAnimation(8,4);

            setPower(5);
            powerBuffer = power;

            return a_viking5;
        }


        case 5:
        {
            getSprite()->setAnimation(8,3);

            if ( entity->getHealth() - getPower() > 0 )

            { entity->setHealth(entity->getHealth() - getPower()); }
            
            else

            { entity->setHealth(0); }

            return a_viking6;
        }


        case 6:
        {

            getSprite()->setAnimation(4,2);

            entity->setPower(entity->getPower()-entity->getPower()*(getArmour()/100));

            return a_viking7;
        }


        case 7:
        {
            getSprite()->setAnimation(8,3);

            if ( entity->getHealth() - getPower() > 0 )

            { entity->setHealth(entity->getHealth() - getPower()); }

            else

            { entity->setHealth(0); }

            return a_viking8;
        }


        case 8:
        {
            getSprite()->setAnimation(4,2);

            entity->setPower(entity->getPower()-entity->getPower()*(getArmour()/100));

            return a_viking9;
        }



        case 9:
        {
            getSprite()->setAnimation(8,3);

            if ( entity->getHealth() - getPower() > 0 )

            { entity->setHealth(entity->getHealth() - getPower()); }

            else

            { entity->setHealth(0); }
            
            return a_viking10;
        }


        case 10:
        {
            getSprite()->setAnimation(4,2);

            entity->setPower(entity->getPower()-entity->getPower()*(getArmour()/100));

            return a_vikingDef;

        }


        // default attack for the last listed damege - 5 
        default:
        {
            getSprite()->setAnimation(8,3);

            if ( entity->getHealth() - getPower() > 0 )

            { entity->setHealth(entity->getHealth() - getPower()); }

            else

            { entity->setHealth(0); }

            return a_vikingDef;
        }
    }
}