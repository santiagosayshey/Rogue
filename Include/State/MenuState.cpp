#include "MenuState.h"
#include "../Instance/Game.h"
#include "PickState.h"
#include <iostream>
#include "ScoreState.h"

typedef sf::Color c;
typedef sf::Text t;



MenuState::MenuState(Game* game, Player* player):
State(game, player)
{
    // splash screen
        splash      = new Sprite (game->getPath()->s_splash,0,0,1280,720,1.5);

    // buttons
        
        // play
        s_play      = new Sprite (game->getPath()->s_button,150,400,30,14,7);
        b_play      = new Text   (game->getPath()->f_main, 50, c::Black, t::Bold, "PLAY", 185, 430);
        w_play      = new Text   (game->getPath()->f_main, 50, c::White, t::Bold, "PLAY", 190, 425);

        // statistics
        s_stats     = new Sprite (game->getPath()->s_button,150,550,30,14,7);
        b_stats     = new Text   (game->getPath()->f_main, 40, c::Black, t::Bold, "SCORES", 165, 585);
        w_stats     = new Text   (game->getPath()->f_main, 40, c::White, t::Bold, "SCORES", 170, 580);

        // quit
        s_quit      = new Sprite (game->getPath()->s_button,150,700,30,14,7);
        b_quit      = new Text   (game->getPath()->f_main, 50, c::Black, t::Bold, "QUIT", 170, 730);
        w_quit      = new Text   (game->getPath()->f_main, 50, c::White, t::Bold, "QUIT", 175, 725);

    // text
    b_title     = new Text (game->getPath()->f_main, 200, c::Black, t::Bold, "ROGUE", 1000, 425);
    w_title     = new Text (game->getPath()->f_main, 200, c::White, t::Bold, "ROGUE", 1010, 415);

    // sounds
    buffer.loadFromFile(game->getPath()->e_hover);
    UI.setBuffer(buffer);
}

MenuState::~MenuState()
{   
    delete splash;

    delete s_play;
    delete s_quit;
    delete s_stats;

    delete b_play;
    delete b_quit;
    delete b_stats;

    delete w_play;
    delete w_quit;
    delete w_stats;

    delete b_title;
    delete w_title;
}

void MenuState::update(sf::RenderWindow* window)

{
    // check for button collisions with mouse
    // if true, move them to indicate the player can click them
    if (!s_play->checkCollision(window))
    {
        sound1=true;
        s_play   ->setPosition(s_play->getX(), s_play->getY());
        b_play   ->setPosition(b_play->getX(), b_play->getY());
        w_play   ->setPosition(w_play->getX(), w_play->getY());
    }
    else
    {
        while (sound1==true)
        {
            UI.play();
            sound1=false;
        }
        
        s_play   ->setPosition(s_play->getX()+20, s_play->getY());
        b_play   ->setPosition(b_play->getX()+20, b_play->getY());
        w_play   ->setPosition(w_play->getX()+20, w_play->getY());

    }

    if (!s_quit->checkCollision(window))
    {
        sound2 = true;
        s_quit   ->setPosition(s_quit->getX(), s_quit->getY());
        b_quit   ->setPosition(b_quit->getX(), b_quit->getY());
        w_quit   ->setPosition(w_quit->getX(), w_quit->getY());
    }
    else
    {
        while (sound2==true)
        {
            UI.play();
            sound2=false;
        }
        s_quit   ->setPosition(s_quit->getX()+20, s_quit->getY());
        b_quit   ->setPosition(b_quit->getX()+20, b_quit->getY());
        w_quit   ->setPosition(w_quit->getX()+20, w_quit->getY());
        
    }

    if (!s_stats->checkCollision(window))
    {
        sound3 = true;
        s_stats   ->setPosition(s_stats->getX(), s_stats->getY());
        b_stats   ->setPosition(b_stats->getX(), b_stats->getY());
        w_stats   ->setPosition(w_stats->getX(), w_stats->getY());
    }
    else
    {
        while (sound3==true)
        {
            UI.play();
            sound3=false;
        }
        s_stats   ->setPosition(s_stats->getX()+20, s_stats->getY());
        b_stats   ->setPosition(b_stats->getX()+20, b_stats->getY());
        w_stats   ->setPosition(w_stats->getX()+20, w_stats->getY());
        
    }

    // event manager
    while (window->pollEvent(event))
    {
        switch (event.type)
        {
            // close the window if the player clicks close
            case sf::Event::Closed:
                window->close();
                break;

            case sf::Event::MouseButtonReleased: {

                // if play button is clicked, change the game state to character select
                if (s_play->checkCollision(window))
                {
                    game->setState(new PickState(game, player));
                    break;
                }

                if (s_stats->checkCollision(window))
                {
                    game->setState(new ScoreState(game, player));
                    break;
                }

                // if quit button is clicked, close the window and end the game loop
                if (s_quit->checkCollision(window))
                {
                    window->close();
                    break;
                }
            }
            
            default:
                break;
        }
        
    }
}


void MenuState::render(sf::RenderWindow* window)
{
    // clear the window
    window     ->clear(c::White);

    // render the drawables inside the render window

        // splash screen
        splash         ->draw(window);

        // buttons
        s_play         ->draw(window);
        s_quit         ->draw(window);
        s_stats        ->draw(window);
        
        // text
        b_play         ->draw(window);
        w_play         ->draw(window);
        
        b_quit         ->draw(window);
        w_quit         ->draw(window);

        b_stats         ->draw(window);
        w_stats         ->draw(window);

        b_title        ->draw(window);
        w_title        ->draw(window);

    // display the drawables inside the render window
    window     ->display();

}

