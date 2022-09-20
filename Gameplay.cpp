#include "Gameplay.h"

Gameplay::Gameplay(Game game)
{
    this->game = game;
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
