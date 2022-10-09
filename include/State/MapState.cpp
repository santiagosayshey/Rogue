#include "MapState.h"
#include "../Instance/Game.h"
#include "PlayState.h"

MapState::MapState(Game* game, Player* player):
State(game, player)
{

}

MapState::~MapState()
{

}

void MapState::update(sf::RenderWindow* window)
{
    while (window->pollEvent(event))
    {
        // "close requested" event: we close the window
        switch (event.type) {
            case sf::Event::Closed: {
                window->close();
                break;
            }
            case sf::Event::KeyReleased: {
                if (sf::Keyboard::Space)
                    game->setState(new PlayState(game, player));
            }
            default:
                break;
        }
    }
}

void MapState::render(sf::RenderWindow* window)
{
    window->clear(sf::Color::White);
 
    window->draw(bgSpr);

    window->display();
}