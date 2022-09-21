#include "Gameplay.h"
#include "Game.h"
#include "MenuState.h"

Gameplay::Gameplay()
{
}

Gameplay::~Gameplay()
{

}

void Gameplay::update(sf::RenderWindow* window)
{
        // framerate
        dt = clock.restart().asSeconds();
        
        // events
        while (window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window->close();
        }

        // keyboard
        
        // mouse
}

void Gameplay::render(sf::RenderWindow* window)
{
    window->clear();
    // draw
    window->display();
}
