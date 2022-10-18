#include "../../Include/Entity/Entity.h"
#include "../../Include/Instance/Path.h"
#include "../../Include/Drawable/Sprite.h"
#include <iostream>


using namespace std;
void testPass()
{
    cout << "TEST PASSED" << endl;
}

using namespace std;
void testFail()
{
    cout << "TEST FAILED" << endl;
}

using namespace std;
int main()
{
    // path database
    Path* path = new Path();

    // test entity
    Entity* entity = new Entity;
    
    // test sprite
    Sprite* sprite = new Sprite(path->s_brute,5,5,5,5,5);

    float statTemp;

    // testing set values

        // health
        cout << "Enter health value" << endl;
        cin >> statTemp;

        entity->setHealth(statTemp);

        cout << "Expected health value: " << statTemp << endl;
        cout << "Actual health value: " << entity->getHealth() << endl;

        if (statTemp == entity->getHealth())
        {
            testPass();
        }
        else{
            testFail();
        }
        cout << endl;

        

        // armour
        cout << "Enter armour value" << endl;
        cin >> statTemp;

        entity->setArmour(statTemp);

        cout << "Expected armour value: " << statTemp << endl;
        cout << "Actual armour value: " << entity->getArmour() << endl;

        if (statTemp == entity->getArmour())
        {
            testPass();
        }
        else{
            testFail();
        }
        cout << endl;

        // power
        cout << "Enter power value" << endl;
        cin >> statTemp;

        entity->setPower(statTemp);

        cout << "Expected power value: " << statTemp << endl;
        cout << "Actual power value: " << entity->getPower() << endl;

        if (statTemp == entity->getPower())
        {
            testPass();
        }
        else{
            testFail();
        }
        cout << endl;

        // original power
        entity->setPowerBuffer(entity->getPower());

        cout << "Expected original power value: " << entity->getPower() << endl;
        cout << "Actual original power value: " << entity->getPowerBuffer() << endl;

        if (entity->getPower() == entity->getPowerBuffer())
        {
            testPass();
        }
        else{
            testFail();
        }
        cout << endl;

    return 0;
}