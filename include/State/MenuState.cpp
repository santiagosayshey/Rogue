#include "MenuState.h"
#include "../Instance/Game.h"
#include "PickState.h"

MenuState::MenuState(Game* game, Player* player):
State(game, player)
{
    t_splash.loadFromFile("assets/background/splash.png");
    s_splash.setTexture(t_splash);

    play    = new Button("assets/entity/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "PLAY", 100, 300);
    options = new Button("assets/entity/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "OPTIONS", 100, 400);
    quit    = new Button("assets/entity/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "QUIT", 100, 500);
}

MenuState::~MenuState()
{ }

void MenuState::update(sf::RenderWindow* window)

{
    // include some sort of event manager that iterates through an array of objects?
    play   ->update(window, game);
    options->update(window, game);
    quit   ->update(window, game);

    if (play->isClicked(window)) {
        game->setState(new PickState(game, player));
    }

    // events  
    while (window->pollEvent(event))
    {
        // "close requested" event: we close the window
        switch (event.type) {
            case sf::Event::Closed:
                window->close();
                break;
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

