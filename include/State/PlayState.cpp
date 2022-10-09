#include "PlayState.h"
#include "../Instance/Game.h"
#include "MenuState.h"
#include "PickState.h"
#include <string>

typedef sf::Color c;
typedef sf::Text t;

PlayState::PlayState(Game* g, Player* player):
State(g,player)
{
    UI. setBuffer(g->hover);

    player->getSprite()->setPos(100,100);

    //player_s_health = new Sprite();
    player_b_health = new Text(g->p->f_main,50,c::Black, t::Bold, "Health: "+std::to_string(player->getHealth()), 200,200);
    player_t_health = new Text(g->p->f_main,50,c::White, t::Bold, "Health: "+std::to_string(player->getHealth()), 205,195);
    

    s_attack = new Sprite(g->p->s_button,150,500,30,14,7);
    b_attack = new Text(g->p->f_main, 50, c::Black, t::Bold, "AttacK", 170, 530);
    t_attack = new Text(g->p->f_main, 50, c::White, t::Bold, "AttacK", 175, 525);

    s_defend = new Sprite(g->p->s_button,150,700,30,14,7);
    b_defend = new Text(g->p->f_main, 50, c::Black, t::Bold, "Defend", 170, 730);
    t_defend = new Text(g->p->f_main, 50, c::White, t::Bold, "Defend", 175, 725);

    s_endTurn = new Sprite(g->p->s_buttonBig,150,700,46,14,7);
    b_endTurn = new Text(g->p->f_main, 50, c::Black, t::Bold, "End Turn", 170, 730);
    t_endTurn = new Text(g->p->f_main, 50, c::White, t::Bold, "Defend", 175, 725);

    b_prompt_player = new Text(g->p->f_main, 100, c::Black, t::Bold, "Player Turn!", 350, 900);
    t_prompt_player = new Text(g->p->f_main, 100, c::White, t::Bold, "Player Turn!", 360, 890);

    b_prompt_enemy = new Text(g->p->f_main, 100, c::Black, t::Bold, "Enemy Turn!", 350, 900);
    t_prompt_enemy = new Text(g->p->f_main, 100, c::White, t::Bold, "Enemy Turn!", 360, 890);
}

PlayState::~PlayState()
{

}

void PlayState::update(sf::RenderWindow* window)
{
    switch (currentTurn)
    {
        case true: {

            if (!s_attack->checkCollision(window))
            {
                s_attack ->setPos(s_attack->getX(), s_attack->getY());
                b_attack ->setPos(b_attack->getX(), b_attack->getY());
                t_attack   ->setPos(t_attack->getX(), t_attack->getY());
                sound1=true;
            }
            else
            {
                while (sound1)
                {
                    UI.play();
                    sound1=false;
                }
                s_attack ->setPos(s_attack->getX()+20, s_attack->getY());
                b_attack ->setPos(b_attack->getX()+20, b_attack->getY());
                t_attack   ->setPos(t_attack->getX()+20, t_attack->getY());

            }

            if (!s_defend->checkCollision(window))
            {
                s_defend ->setPos(s_defend->getX(), s_defend->getY());
                b_defend ->setPos(b_defend->getX(), b_defend->getY());
                t_defend   ->setPos(t_defend->getX(), t_defend->getY());
                sound1=true;
            }
            else
            {
                while (sound2)
                {
                    UI.play();
                    sound1=false;
                }
                s_defend ->setPos(s_defend->getX()+20, s_defend->getY());
                b_defend ->setPos(b_defend->getX()+20, b_defend->getY());
                t_defend   ->setPos(t_defend->getX()+20, t_defend->getY());

            }



            while (window->pollEvent(event))
            {
                // "close requested" event: we close the window
                switch (event.type) {
                    case sf::Event::Closed: {
                        window->close();
                        break;
                    }
                    case sf::Event::MouseButtonReleased: {
                        break;
                    }
                    case sf::Event::KeyReleased: {
                        if (s_attack->checkCollision(window)) 
                        {
                            choice = 0;
                        }
                    }
                    default: {
                        break;
                    }
                }
            }

            if (clock.getElapsedTime().asSeconds() > 1)
            {
                currentTurn = false;
                clock.restart();
            }
            break;
            
        }



        
        case false:
        
            while (window->pollEvent(event))
            {
                // "close requested" event: we close the window
                switch (event.type) {
                    case sf::Event::Closed: {
                        window->close();
                        break;
                    }
                    case sf::Event::MouseButtonReleased: {
                        break;
                    }
                    case sf::Event::KeyReleased: {
                    }
                    default: {
                        break;
                    }
                }
            }

            
            if (clock.getElapsedTime().asSeconds() > 1)
            {
                currentTurn = true;
                clock.restart();
            }
            break;
        default:
            break;
    }







    player->getSprite()->animation(true);
}

void PlayState::render(sf::RenderWindow* window)
{
    window   ->clear(sf::Color::Green);

    player->getSprite()->draw(window);

    player_b_health->draw(window);
    player_t_health->draw(window);

    s_attack->draw(window);
    b_attack->draw(window);
    t_attack->draw(window);

    s_defend->draw(window);
    b_defend->draw(window);
    t_defend->draw(window);

    switch (currentTurn)
    {
        case true:
            b_prompt_player->draw(window);
            t_prompt_player->draw(window);
            break;
        case false:
            b_prompt_enemy->draw(window);
            t_prompt_enemy->draw(window);
            break;
    }

    window   ->display();
}
