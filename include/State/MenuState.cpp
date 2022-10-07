#include "MenuState.h"
#include "../Instance/Game.h"
#include "PickState.h"

MenuState::MenuState(Game* game, Player* player):
State(game, player)
{
    splash  = new Sprite("assets/background/splashscreen2.png",0,0,940,512,2);
    play    = new Button("assets/entity/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "PLAY", 100, 300);
    quit    = new Button("assets/entity/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "QUIT", 100, 400);

    //splash->flip();
    splash->updateAnimation(24,0);
}

MenuState::~MenuState()
{ }

void MenuState::update(sf::RenderWindow* window)

{

    if (play->checkCollision(window))
    {
        play->updateText("Fuck");
    }
    else
    {
        play->updateText("Play");
    }
    // include some sort of event manager that iterates through an array of objects?
    play   ->update(window);
    quit   ->update(window);
    splash->update(window);



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

    splash->animation(true);
            
}


void MenuState::render(sf::RenderWindow* window)
{
    window->clear(sf::Color::White);
    //window->draw(s_splash);
    splash->draw(window);
    play   ->draw(window);
    quit   ->draw(window);

    window->display();
}

