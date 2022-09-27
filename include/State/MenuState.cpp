#include "MenuState.h"
#include "../Instance/Game.h"
#include "PickState.h"

MenuState::MenuState(Game* game, Player* player):
State(game, player)
{
    play    = new Button("assets/entity/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "PLAY", 100, 300);
    quit    = new Button("assets/entity/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "QUIT", 100, 400);
}

MenuState::~MenuState()
{ }

void MenuState::update(sf::RenderWindow* window)

{
    // include some sort of event manager that iterates through an array of objects?
    play   ->update(window, game);
    quit   ->update(window, game);



    // events  
    while (window->pollEvent(event))
    {
        // "close requested" event: we close the window
        switch (event.type) {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::MouseButtonReleased: {
                if (play->checkCollision(window)) {
                    std::cout << "Click" << std::endl;
                    game->setState(new PickState(game, player));
                    break;
                }
                if (quit->checkCollision(window)) {
                    std::cout << "Click" << std::endl;
                    window->close();
                    break;
                }
            }
        }
        
    }
            
}


void MenuState::render(sf::RenderWindow* window)
{
    window->clear(sf::Color::White);
    //window->draw(s_splash);
    play   ->draw(window);
    quit   ->draw(window);

    window->display();
}

