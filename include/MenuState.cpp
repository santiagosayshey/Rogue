#include "MenuState.h"
#include "Game.h"
#include "PlayState.h"

MenuState::MenuState(Game* game):
State(game)
{
    t_splash.loadFromFile("assets/background/splash.png");
    s_splash.setTexture(t_splash);

    font.loadFromFile("assets/font/upheavtt.ttf");
    text.setFont(font);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setString("PLAY");
    text.setPosition(124,377);
}

MenuState::~MenuState()
{}

void MenuState::update(sf::RenderWindow* window)

{
        // entities
        sf::Vector2f mouse = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
        sf::FloatRect bounds = text.getGlobalBounds();
        if (!bounds.contains(mouse))
        {
            text.setFillColor(sf::Color::Black);
        }
        else 
        {
            text.setFillColor(sf::Color::Blue);
        }

        // keyboard
        
        // mouse

        // events  
        while (window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2f mouse = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
                sf::FloatRect bounds = text.getGlobalBounds();
                if (bounds.contains(mouse))
                {
                    game->setState(new PlayState(game));
                }
            }
            
        }


}

void MenuState::render(sf::RenderWindow* window)
{
    window->clear(sf::Color::White);
    //window->draw(s_splash);
    window->draw(text);
    window->display();
}

