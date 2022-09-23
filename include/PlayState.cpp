#include "PlayState.h"
#include "Game.h"
#include "MenuState.h"

PlayState::PlayState(Game* game):
State(game)
{
    wizard   = new Wizard("assets/entity/human/MAGE.png",200,50);
}

PlayState::~PlayState()
{

}

void PlayState::update(sf::RenderWindow* window)
{
        // framerate
        dt = clock.restart().asSeconds();

        wizard  ->update(window, game);

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

void PlayState::render(sf::RenderWindow* window)
{
    window->clear(sf::Color::White);
    wizard->draw(window);
    window->display();
}
