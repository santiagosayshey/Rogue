#include "PlayState.h"
#include "../Instance/Game.h"
#include "MenuState.h"

PlayState::PlayState(Game* game):
State(game)
{
}

PlayState::~PlayState()
{

}

void PlayState::update(sf::RenderWindow* window)
{

    // events
    while (window->pollEvent(event))
    {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            window->close();
    }
} 

void PlayState::render(sf::RenderWindow* window)
{
    window   ->clear(sf::Color::White);

    window   ->display();
}
