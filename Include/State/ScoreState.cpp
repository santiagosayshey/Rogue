#include "ScoreState.h"
#include "MenuState.h"
#include "../Instance/Game.h"
#include "PickState.h"
#include <iostream>

typedef sf::Color c;
typedef sf::Text t;

ScoreState::ScoreState(Game* game, Player* player):
State(game, player)
{
    // splash screen
    splash      = new Sprite (game->getPath()->s_scoreSplash,0,0,1920,1080,1);

    // back button
    s_back      = new Sprite (game->getPath()->s_button,1500,500,30,14,7);
    b_back      = new Text   (game->getPath()->f_main, 50, c::Black, t::Bold, "BACK", 1535, 530);
    w_back      = new Text   (game->getPath()->f_main, 50, c::White, t::Bold, "BACK", 1540, 525);

    // scores

    fastRun    = new Text(game->getPath()->f_score, 100, c::Black, t::Bold, "FASTEST RUN:    "     +std::to_string(int(game->getFastestRunTime()))+"S" , 250, 200);
    totalRun   = new Text(game->getPath()->f_score, 100, c::Black, t::Bold, "PLAY TIME:       "    +std::to_string(int(game->getTotalPlayTime())/60)+"M" , 250, 400);
    wins       = new Text(game->getPath()->f_score, 100, c::Black, t::Bold, "TOTAL WINS:       "   +std::to_string(game->getTotalWins()) , 250, 600);
    losses     = new Text(game->getPath()->f_score, 100, c::Black, t::Bold, "TOTAL LOSSES:    "    +std::to_string(game->getTotalLosses()) , 250, 800);}

ScoreState::~ScoreState()
{
    delete splash;

    delete s_back;
    delete b_back;
    delete w_back;

    delete fastRun;
    delete totalRun;
    delete wins;
    delete losses;
}

void ScoreState::update(sf::RenderWindow* window)
{
    // check for button collisions with mouse
    // if true, move them to indicate the player can click them 
    if (!s_back->checkCollision(window))
    {
        s_back   ->setPosition(s_back->getX(), s_back->getY());
        b_back   ->setPosition(b_back->getX(), b_back->getY());
        w_back   ->setPosition(w_back->getX(), w_back->getY());
    }
    else
    {
        s_back   ->setPosition(s_back->getX()+20, s_back->getY());
        b_back   ->setPosition(b_back->getX()+20, b_back->getY());
        w_back   ->setPosition(w_back->getX()+20, w_back->getY());

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

                // if play button is clicked, change the game state to menu select
                if (s_back->checkCollision(window))
                {
                    game->setState(new MenuState(game, player));
                    break;
                }
            }
            default:
                break;
        }
        
    }
}

void ScoreState::render(sf::RenderWindow* window)
{
    // clear the window
    window     ->clear(c::Black);

    // render the drawables inside the render window

        // splash screen
        splash         ->draw(window);

        // buttons
        s_back         ->draw(window);
        b_back         ->draw(window);
        w_back         ->draw(window);

        // scores
        fastRun        ->draw(window);
        totalRun       ->draw(window);
        wins           ->draw(window);
        losses         ->draw(window);
        
    // display the drawables inside the render window
    window     ->display();

}

