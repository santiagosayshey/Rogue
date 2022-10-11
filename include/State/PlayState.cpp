#include "PlayState.h"
#include "../Instance/Game.h"
#include "MenuState.h"
#include "PickState.h"
#include <string>
#include <iostream>

typedef sf::Color c;
typedef sf::Text t;

PlayState::PlayState(Game* g, Player* player):
State(g,player)
{
    UI. setBuffer(g->hover);

    // player
        player->getSprite()->setPos(200,50);

        player_b_health = new Text(g->p->f_main,50,c::Black, t::Bold, "Health: "+std::to_string(player->getHealth()), 200,100);
        player_t_health = new Text(g->p->f_main,50,c::White, t::Bold, "Health: "+std::to_string(player->getHealth()), 205,95);

        player_b_armour = new Text(g->p->f_main,50,c::Black, t::Bold, "Armour: "+std::to_string(player->getArmour()), 200,200);
        player_t_armour = new Text(g->p->f_main,50,c::White, t::Bold, "Armour: "+std::to_string(player->getArmour()), 205,195);

        player_b_power = new Text(g->p->f_main,50,c::Black, t::Bold, "Power: "+std::to_string(player->getPower()), 200,300);
        player_t_power = new Text(g->p->f_main,50,c::White, t::Bold, "Power: "+std::to_string(player->getPower()), 205,295);

            // buttons
            s_attack = new Sprite(g->p->s_button,150,500,30,14,7);
            b_attack = new Text(g->p->f_main, 50, c::Black, t::Bold, "AttacK", 170, 530);
            t_attack = new Text(g->p->f_main, 50, c::White, t::Bold, "AttacK", 175, 525);

            s_dodge = new Sprite(g->p->s_button,150,700,30,14,7);
            b_dodge = new Text(g->p->f_main, 50, c::Black, t::Bold, "Dodge", 170, 730);
            t_dodge = new Text(g->p->f_main, 50, c::White, t::Bold, "Dodge", 175, 725);

            s_endTurn = new Sprite(g->p->s_buttonBig,1300,900,46,14,7);
            b_endTurn = new Text(g->p->f_main, 50, c::Black, t::Bold, "End Turn", 1320, 930);
            t_endTurn = new Text(g->p->f_main, 50, c::White, t::Bold, "End Turn", 1325, 925);

        b_prompt = new Text(g->p->f_main, 100, c::Black, t::Bold, "Choice: " + currentChoice, 350, 900);
        t_prompt = new Text(g->p->f_main, 100, c::White, t::Bold, "Choice: " + currentChoice, 360, 890);

    // enemy
        enemy = new Golem(g);
        enemy->getSprite()->flip();

        enemy_b_health = new Text(g->p->f_main,50,c::Black, t::Bold, "Health: "+std::to_string(enemy->getHealth()), 1300,100);
        enemy_t_health = new Text(g->p->f_main,50,c::White, t::Bold, "Health: "+std::to_string(enemy->getHealth()), 1305,95);

        enemy_b_armour = new Text(g->p->f_main,50,c::Black, t::Bold, "Armour: "+std::to_string(enemy->getArmour()), 1300,200);
        enemy_t_armour = new Text(g->p->f_main,50,c::White, t::Bold, "Armour: "+std::to_string(enemy->getArmour()), 1305,195);

        enemy_b_power = new Text(g->p->f_main,50,c::Black, t::Bold, "Power: "+std::to_string(enemy->getPower()), 1300,300);
        enemy_t_power = new Text(g->p->f_main,50,c::White, t::Bold, "Power: "+std::to_string(enemy->getPower()), 1305,295);
}

PlayState::~PlayState()
{

}

void PlayState::update(sf::RenderWindow* window)
{
    switch (state)
    {
        case 0:
        {
            // button feedback
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
            if (!s_dodge->checkCollision(window))
            {
                s_dodge ->setPos(s_dodge->getX(), s_dodge->getY());
                b_dodge ->setPos(b_dodge->getX(), b_dodge->getY());
                t_dodge   ->setPos(t_dodge->getX(), t_dodge->getY());
                sound2=true;
            }
            else
            {
                while (sound2)
                {
                    UI.play();
                    sound2=false;
                }
                s_dodge ->setPos(s_dodge->getX()+20, s_dodge->getY());
                b_dodge ->setPos(b_dodge->getX()+20, b_dodge->getY());
                t_dodge   ->setPos(t_dodge->getX()+20, t_dodge->getY());

            }
            if (!s_endTurn->checkCollision(window))
            {
                s_endTurn ->setPos(s_endTurn->getX(), s_endTurn->getY());
                b_endTurn ->setPos(b_endTurn->getX(), b_endTurn->getY());
                t_endTurn   ->setPos(t_endTurn->getX(), t_endTurn->getY());
                sound3=true;
            }
            else
            {
                while (sound3)
                {
                    UI.play();
                    sound3=false;
                }
                s_endTurn ->setPos(s_endTurn->getX()+20, s_endTurn->getY());
                b_endTurn ->setPos(b_endTurn->getX()+20, b_endTurn->getY());
                t_endTurn   ->setPos(t_endTurn->getX()+20, t_endTurn->getY());

            }

            while (window->pollEvent(event))
            {
                // "close requested" event: we close the window
                switch (event.type)
                {
                    case sf::Event::Closed: { window->close(); break; }
                    case sf::Event::MouseButtonReleased:
                    {
                        if (s_attack->checkCollision(window)) 
                        {
                            currentChoice = "AttacK";

                            break;
                        }
                        if (s_dodge->checkCollision(window)) 
                        {
                            currentChoice = "Dodge";
                            break;
                        }
                        if (s_endTurn->checkCollision(window)) 
                        {
                            if (currentChoice == "AttacK")
                            {
                                switch (player->returnChar())
                                {
                                    case 1:
                                        player->getSprite()->updateAnimation(7,3);
                                        break;
                                    case 2:
                                        player->getSprite()->updateAnimation(7,4);
                                        break;
                                    case 3:
                                        player->getSprite()->updateAnimation(6,3);
                                        break;
                                    default:
                                        break;
                                }
                                player->attack(enemy);
                                enemy_b_health->updateText("Health: " + std::to_string(enemy->getHealth()));
                                enemy_t_health->updateText("Health: " + std::to_string(enemy->getHealth()));
                                state = 1;
                            }
                            else if (currentChoice == "Dodge")
                            {
                                switch (player->returnChar())
                                {
                                    case 1:
                                        player->getSprite()->updateAnimation(4,6);
                                        break;
                                    case 2:
                                        player->getSprite()->updateAnimation(7,2);
                                        break;
                                    case 3:
                                        player->getSprite()->updateAnimation(8,2);
                                        break;
                                    default:
                                        break;
                                }
                                state = 1;
                            }

                        }
                        break;
                    }
                    default: 
                    {
                        break;
                    }
                }
            }
            b_prompt->updateText("Choice: " + currentChoice);
            t_prompt->updateText("Choice: " + currentChoice);
            break;
        }
            
        case 1:
        {
            b_prompt->updateText("Enemy Turn!");
            t_prompt->updateText("Enemy Turn!");

            enemyCount++;

            if (enemyCount > 150)
            {
                enemy->getSprite()->updateAnimation(8,3);
                enemy->attack(player);
                
                player_b_health->updateText("Health: " + std::to_string(player->getHealth()));
                player_t_health->updateText("Health: " + std::to_string(player->getHealth()));

                enemyCount=0;
                state = 0;
            }            
            break;
        }
    }

    if (player->getHealth() == 0 && playerDead == false)
    {
        switch (enemy->returnChar())
        {
            case 1:
                player->getSprite()->updateAnimation(7,8);
                break;
            case 2:           
                player->getSprite()->updateAnimation(9,6);
                break;
            case 3:
                player->getSprite()->updateAnimation(5,8);
                break;
            
        }
    playerDead = true;
    }

    if (enemy->getHealth() < 1 && enemyDead == false)
    {
        switch (enemy->returnChar()) {
            case 1:
                enemy->getSprite()->updateAnimation(16,4);
                break;
        }
    enemyDead = true;
    }

    if (playerDead)
    {
        player ->getSprite()->animation(false,true);
    }
    else
    {
        player ->getSprite()->animation(false,false);
    }

    if (enemyDead)
    {
        enemy ->getSprite()->animation(false,true);
    }
    else
    {
        enemy ->getSprite()->animation(false,false);
    }
}

void PlayState::render(sf::RenderWindow* window)
{
    window   ->clear(sf::Color::Green);

    player->getSprite()->draw(window);
    enemy->getSprite()->draw(window);

    player_b_health->draw(window);
    player_t_health->draw(window);

    player_b_armour->draw(window);
    player_t_armour->draw(window);

    player_b_power->draw(window);
    player_t_power->draw(window);

    s_attack->draw(window);
    b_attack->draw(window);
    t_attack->draw(window);

    s_dodge->draw(window);
    b_dodge->draw(window);
    t_dodge->draw(window);

    s_endTurn->draw(window);
    b_endTurn->draw(window);
    t_endTurn->draw(window);

    b_prompt->draw(window);
    t_prompt->draw(window);

    enemy_b_health->draw(window);
    enemy_t_health->draw(window);

    enemy_b_armour->draw(window);
    enemy_t_armour->draw(window);

    enemy_b_power->draw(window);
    enemy_t_power->draw(window);

/*     switch (currentTurn)
    {
        case true:
            b_prompt_player->draw(window);
            t_prompt_player->draw(window);
            break;
        case false:
            b_prompt_enemy->draw(window);
            t_prompt_enemy->draw(window);
            break;
    } */

    window   ->display();
}
