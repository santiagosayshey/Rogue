#include "MenuState.h"
#include "../Instance/Game.h"
#include "PickState.h"

MenuState::MenuState(Game* game, Player* player):
State(game, player)
{

    s_play = new Sprite("assets/button/button.png",100,500,30,14,7);
    s_quit = new Sprite("assets/button/button.png",100,650,30,14,7);

    b_play    = new Button("assets/button/m.ttf", 50, sf::Color::Black, sf::Text::Bold, "PLAY", 135, 530);
    b_quit    = new Button("assets/button/m.ttf", 50, sf::Color::Black, sf::Text::Bold, "QUIT", 120, 680);

    play    = new Button("assets/button/m.ttf", 50, sf::Color::White, sf::Text::Bold, "PLAY", 140, 525);
    quit    = new Button("assets/button/m.ttf", 50, sf::Color::White, sf::Text::Bold, "QUIT", 125, 675);

}

MenuState::~MenuState()
{ }

void MenuState::update(sf::RenderWindow* window)

{
    s_play->update(window);
    s_quit->update(window);

    b_play->update(window);
    b_quit->update(window);

    play->update(window);
    quit->update(window);



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
    //splash->draw(window);
    s_play->draw(window);
    s_quit->draw(window);

    b_play->draw(window);
    b_quit->draw(window);

    play   ->draw(window);
    quit   ->draw(window);

    window->display();
}

