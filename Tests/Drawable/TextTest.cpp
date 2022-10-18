#include <SFML/Graphics.hpp>


#include "../../Include/Drawable/Text.h"
#include "../../Include/Instance/Path.h"

#include <iostream>


int main()

{

    // create a render window
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1920,1080),"TEXT_TEST");

    // create a path instance
    Path* path = new Path();

    // TEST 1 - DRAWING CONSTRUCTED REGULAR TEXT //
    Text* test = new Text(path->f_main,100,sf::Color::Black,sf::Text::Regular,"TEST",0,0);

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
                        // TEST 2 - UPDATING TEXT STRING //
                        case sf::Keyboard::Space:
                        { 
                            std::cout << "MOVED" << std::endl;
                            test->setPosition(test->getX()+100,test->getY()+100);
                            break;
                        }

                        // TEST 3 - UPDATING POSITION CHECKING FOR NEW POSITION //
                        case sf::Keyboard::A:
                        {
                            std::cout << "UPDATED" << std::endl;
                            test->setText("SUCESSFULLY UPDATED TEXT");
                            break;
                        }
                    }
                    break;
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