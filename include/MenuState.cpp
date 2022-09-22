#include "MenuState.h"
#include "Game.h"

MenuState::MenuState(Game* game):
State(game)
{
    t_splash.loadFromFile("assets/background/splash.png");
    s_splash.setTexture(t_splash);

    play    = new Button("assets/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "PLAY", 100, 300, 1);
    options = new Button("assets/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "OPTIONS", 100, 400, 2);
    quit    = new Button("assets/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "QUIT", 100, 500, 3);
}

MenuState::~MenuState()
{}

void MenuState::update(sf::RenderWindow* window)

{
    // include some sort of event manager that iterates through an array of objects?
    play   ->update(window, game);
    options->update(window, game);
    quit   ->update(window, game);

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
    play   ->draw(window);
    options->draw(window);
    quit   ->draw(window);

    window->display();
}

