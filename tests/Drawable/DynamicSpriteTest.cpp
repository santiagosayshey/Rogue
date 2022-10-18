#include <SFML/Graphics.hpp>

#include "../../include/Drawable/Sprite.h"
#include "../../include/Drawable/DynamicSprite.h"
#include "../../include/Instance/Path.h"

#include <iostream>


int main()

{

    // create a render window
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1920,1080),"DYNAMIC_SPRITE_TEST");

    // create a path instance
    Path* path = new Path();

    // TEST 1 - DRAWING CONSTRUCTED REGULAR DYNAMIC SPRITE //
    DynamicSprite* test = new DynamicSprite(path->s_mage,300,-500,64,64,20);

    // event
    sf::Event e;

    while (window->isOpen())
    {
        
        while (window->pollEvent(e))
        {
            
            switch (e.type)
            {
                case sf::Event::Closed:
                { window->close(); break; }

                case sf::Event::KeyReleased:
                {
                    switch (e.key.code)
                    {
                        // TEST 3 - ATTACK ANIMATION //
                        case sf::Keyboard::Q:
                        { 
                            test->setAnimation(7,3);
                            break;
                        }

                        // TEST 4 - FORTIFY ANIMATION // 
                        case sf::Keyboard::W:
                        {
                            test->setAnimation(4,6); 
                            break;
                        }

                        // TEST 5 - DIE ANIMATION // 
                        case sf::Keyboard::E:
                        {
                            test->setAnimation(7,8);
                            break;
                        }

                        // TEST 6 - ATTACK 2 ANIMATION // 
                        case sf::Keyboard::R:
                        {
                            test->setAnimation(7,4);
                            break;
                        }
                    }
                    break;
                }
            }


        }
        
        // TEST 2 - CONTINUALLY UPDATING ANIMATION EACH FRAME //
        test->animation(true,false);

        window->clear(sf::Color::White);

            
        test->draw(window);
        window->display();

    }

    delete window;
    delete path;
    delete test;

    return 0;
}