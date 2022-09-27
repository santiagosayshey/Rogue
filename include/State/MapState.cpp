#include "MapState.h"

MapState::MapState(Game* game, Player* player):
State(game, player)
{
    bgTex.loadFromFile("assets/level/map.png");
    bgSpr.setTexture(bgTex);
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
        }
    }
}

void MapState::render(sf::RenderWindow* window)
{
    window->clear(sf::Color::White);
 
    window->draw(bgSpr);

    window->display();
}