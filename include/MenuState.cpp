#include "MenuState.h"
#include "Game.h"

MenuState::MenuState(Game* game):
State(game)
{
    t_splash.loadFromFile("assets/background/splash.png");
    s_splash.setTexture(t_splash);

    play = new TextBox(50, sf::Color::Black, "Play", 124, 377);
}

MenuState::~MenuState()
{}

void MenuState::update(sf::RenderWindow* window)

{
    play->update(window, game, play);
    // events  
    while (window->pollEvent(event))
    {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed) {
            window->close();
        }
        
    }
            
}


void MenuState::render(sf::RenderWindow* window)
{
    window->clear(sf::Color::White);
    //window->draw(s_splash);
    play->draw(window);
    window->display();
}

