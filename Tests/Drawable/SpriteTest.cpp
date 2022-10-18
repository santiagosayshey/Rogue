#include <SFML/Graphics.hpp>

#include "../../include/Drawable/Sprite.h"
#include "../../include/Instance/Path.h"

#include <iostream>


int main()

{

    // create a render window
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1920,1080),"SPRITE_TEST");

    // create a path instance
    Path* path = new Path();

    // TEST 1 - DRAWING CONSTRUCTED REGULAR SPRITE //
    Sprite* test = new Sprite(path->s_mage,500,500,64,64,5);

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
                        // TEST 2 - FLIPPING THE SPRITE //
                        case sf::Keyboard::Space:
                        { 
                            test->getSFSprite()->scale(-1.f,1.f);
                            break;
                        }

                        // TEST 2 - UPDATING THE TEXTURE RECT // 
                        case sf::Keyboard::A:
                        { 
                            test->getSFSprite()->setTextureRect(sf::IntRect(64, 64, 64, 64));
                            break;
                        }
                    }
                    break;
                }

                case sf::Event::MouseButtonReleased:
                {
                    // TEST 3 - CHECKING FOR MOUSE CLICKS WITH COLLISION //
                    // TEST 4 - UPDATING POSTION ON CLICK //
                    if (test->checkCollision(window))
                    {
                        test->setPosition(100,100);
                        break;
                    }
                }
            }


        }

        window->clear(sf::Color::White);

        
        test->draw(window);
        window->display();
    }

    delete window;
    delete path;
    delete test;

    return 0;
}