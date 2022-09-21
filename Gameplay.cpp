#include "Gameplay.h"
#include "Game.h"
#include "MenuState.h"

Gameplay::Gameplay(Game* game):
GameState(game)
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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                game->setState(new MenuState(game));
            }
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
