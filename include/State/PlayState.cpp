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
    enemy = game->returnEnemy();
    UI. setBuffer(g->hover);

    // player
        player->getSprite()->setPos(200,50);

        player_b_health = new Text(g->p->f_main,50,c::Black, t::Bold, "Health: "+std::to_string(int(player->getHealth())), 200,100);
        player_t_health = new Text(g->p->f_main,50,c::White, t::Bold, "Health: "+std::to_string(int(player->getHealth())), 205,95);

        player_b_armour = new Text(g->p->f_main,50,c::Black, t::Bold, "Armour: "+std::to_string(int(player->getArmour())), 200,200);
        player_t_armour = new Text(g->p->f_main,50,c::White, t::Bold, "Armour: "+std::to_string(int(player->getArmour())), 205,195);

        player_b_power = new Text(g->p->f_main,50,c::Black, t::Bold, "Power: "+std::to_string(int(player->getPower())), 200,300);
        player_t_power = new Text(g->p->f_main,50,c::White, t::Bold, "Power: "+std::to_string(int(player->getPower())), 205,295);

        b_player_choice = new Text(g->p->f_main, 50, c::Black, t::Bold, "Player Choice: " + currentChoice, 600, 100);
        t_player_choice = new Text(g->p->f_main, 50, c::White, t::Bold, "Player Choice: " + currentChoice, 605, 95);

            // buttons
            s_attack = new Sprite(g->p->s_button,150,500,30,14,7);
            b_attack = new Text(g->p->f_main, 50, c::Black, t::Bold, "AttacK", 170, 530);
            t_attack = new Text(g->p->f_main, 50, c::White, t::Bold, "AttacK", 175, 525);

            s_fortify = new Sprite(g->p->s_button,150,700,30,14,7);
            b_fortify = new Text(g->p->f_main, 50, c::Black, t::Bold, "Fortify", 170, 730);
            t_fortify = new Text(g->p->f_main, 50, c::White, t::Bold, "Fortify", 175, 725);

            s_endTurn = new Sprite(g->p->s_buttonBig,1300,900,46,14,7);
            b_endTurn = new Text(g->p->f_main, 50, c::Black, t::Bold, "End Turn", 1320, 930);
            t_endTurn = new Text(g->p->f_main, 50, c::White, t::Bold, "End Turn", 1325, 925);

        b_prompt = new Text(g->p->f_main, 100, c::Black, t::Bold, "Player Turn!", 350, 900);
        t_prompt = new Text(g->p->f_main, 100, c::White, t::Bold, "Player Turn!", 360, 890);

        b_gameOver = new Text(g->p->f_main, 100, c::Black, t::Bold, "GAME OVER!", 580, 500);
        t_gameOver = new Text(g->p->f_main, 100, c::Red, t::Bold, "GAME OVER!", 590, 490);

        b_gameWon = new Text(g->p->f_main, 100, c::Black, t::Bold, "YOU WON!", 620, 500);
        t_gameWon = new Text(g->p->f_main, 100, c::Green, t::Bold, "YOU WON!", 630, 490);

        b_endPrompt = new Text(g->p->f_main, 50, c::Black, t::Bold, "Press Space to Continue", 600, 700);
        t_endPrompt = new Text(g->p->f_main, 50, c::White, t::Bold, "Press Space to Continue", 610, 690);

    // enemy
        enemy_b_health = new Text(g->p->f_main,50,c::Black, t::Bold, "Health: "+std::to_string(int(enemy->getHealth())), 1300,100);
        enemy_t_health = new Text(g->p->f_main,50,c::White, t::Bold, "Health: "+std::to_string(int(enemy->getHealth())), 1305,95);

        enemy_b_armour = new Text(g->p->f_main,50,c::Black, t::Bold, "Armour: "+std::to_string(int(enemy->getArmour())), 1300,200);
        enemy_t_armour = new Text(g->p->f_main,50,c::White, t::Bold, "Armour: "+std::to_string(int(enemy->getArmour())), 1305,195);

        b_enemy_nextMove = new Text(g->p->f_main, 50, c::Black, t::Bold, enemy->getFirstMove(), 800, 100);
        t_enemy_nextMove = new Text(g->p->f_main, 50, c::White, t::Bold, enemy->getFirstMove(), 805, 95);
    

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
            b_prompt->updateText("Player Turn!");
            t_prompt->updateText("Player Turn!");
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
            if (!s_fortify->checkCollision(window))
            {
                s_fortify ->setPos(s_fortify->getX(), s_fortify->getY());
                b_fortify ->setPos(b_fortify->getX(), b_fortify->getY());
                t_fortify   ->setPos(t_fortify->getX(), t_fortify->getY());
                sound2=true;
            }
            else
            {
                while (sound2)
                {
                    UI.play();
                    sound2=false;
                }
                s_fortify ->setPos(s_fortify->getX()+20, s_fortify->getY());
                b_fortify ->setPos(b_fortify->getX()+20, b_fortify->getY());
                t_fortify   ->setPos(t_fortify->getX()+20, t_fortify->getY());

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
                        if (s_fortify->checkCollision(window)) 
                        {
                            currentChoice = "fortify";
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
                                player->updatePower(player->getOGPower());

                                player_b_power->updateText("Power: " + std::to_string(int(player->getPower())));
                                player_t_power->updateText("Power: " + std::to_string(int(player->getPower())));

                                enemy_b_health->updateText("Health: " + std::to_string(int(enemy->getHealth())));
                                enemy_t_health->updateText("Health: " + std::to_string(int(enemy->getHealth())));
                                state = 1;
                            }
                            else if (currentChoice == "fortify")
                            {
                                enemy->updatePower(enemy->getPower()-enemy->getPower()*(player->getArmour()/100));
                                player->updatePower(player->getOGPower());

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
            b_player_choice->updateText("Choice: " + currentChoice);
            t_player_choice->updateText("Choice: " + currentChoice);
            break;
        }
            
        case 1:
        {
            if (!enemyDead)
            {
                b_prompt->updateText("Enemy Turn!");
                t_prompt->updateText("Enemy Turn!");

                enemyCount++;

                if (enemyCount > 300)
                {
                    enemyNextMove = enemy->attack(player);

                    b_enemy_nextMove->updateText(enemyNextMove);
                    t_enemy_nextMove->updateText(enemyNextMove);

                    enemy->updatePower(enemy->getOGPower());



                    enemy->incrementAction();
                    
                    player_b_health->updateText("Health: " + std::to_string(int(player->getHealth())));
                    player_t_health->updateText("Health: " + std::to_string(int(player->getHealth())));

                    player_b_power->updateText("Power: " + std::to_string(int(player->getPower())));
                    player_t_power->updateText("Power: " + std::to_string(int(player->getPower())));

                    enemyCount=0;
                    state = 0;
                }            
            }
            else {state = 0;}
            break;
        }

        case 2:
        {
            while (window->pollEvent(event))
            {
                switch (event.type) 
                {
                    case sf::Event::KeyReleased:
                    {
                        if (sf::Keyboard::Space)
                        {
                            game->setState(new MenuState(game, player));
                            break;
                        }
                    }
                }
            }
            break;
        }

        case 3:
        {
            while (window->pollEvent(event))
            {
                switch (event.type) 
                {
                    case sf::Event::KeyReleased:
                    {
                        if (sf::Keyboard::Space)
                        {
                            game->setState(game->map);
                            break;
                        }
                    }
                }
            }
            break;
        }
    }

    if (player->getHealth() == 0 && playerDead == false)
    {
        switch (player->returnChar())
        {
            case 1:
                player->getSprite()->updateAnimation(7,8);
                break;
            case 2:           
                player->getSprite()->updateAnimation(9,6);
                break;
            case 3:
                player->getSprite()->updateAnimation(8,6);
                break;
            
        }
    playerDead = true;
    }

    if (enemy->getHealth() < 1 && enemyDead == false)
    {
        switch(enemy->returnChar())
        {
            case 1:
                enemy->getSprite()->updateAnimation(7,6);
                break;
            case 2:
                enemy->getSprite()->updateAnimation(8,5);
                break;
            case 3:
                enemy->getSprite()->updateAnimation(5,5);
                break;
            case 4:
                enemy->getSprite()->updateAnimation(16,4);
                break;

        }
    enemyDead = true;
    }

    if (playerDead)
    {
        game->map->setLVL(1);
        game->resetEnemy();
        playerDeadCount++;
        player ->getSprite()->animation(false,true);
        if (playerDeadCount > 300)
        {
            
            state =2;
            playerDeadCount=0;
        }
    }
    else
    {
        player ->getSprite()->animation(false,false);
    }

    if (enemyDead)
    {
        enemyDeadCount++;
        enemy ->getSprite()->animation(false,true);
        if (enemyDeadCount > 300)
        {
            state =3;
            enemyDeadCount=0;
        }
    }
    else
    {
        enemy ->getSprite()->animation(false,false);
    }
}

void PlayState::render(sf::RenderWindow* window)
{
    window   ->clear(sf::Color::Black);

    if (state < 2)
    {
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

        s_fortify->draw(window);
        b_fortify->draw(window);
        t_fortify->draw(window);

        s_endTurn->draw(window);
        b_endTurn->draw(window);
        t_endTurn->draw(window);

        b_prompt->draw(window);
        t_prompt->draw(window);

        enemy_b_health->draw(window);
        enemy_t_health->draw(window);

        enemy_b_armour->draw(window);
        enemy_t_armour->draw(window);

        b_enemy_nextMove->draw(window);
        t_enemy_nextMove->draw(window);
    }



    switch (state)
    {
        case 0:
            //b_player_choice->draw(window);
            //t_player_choice->draw(window);
            break;
        case 1:
            break;
        case 2:
            b_gameOver->draw(window);
            t_gameOver->draw(window);
            b_endPrompt->draw(window);
            t_endPrompt->draw(window);
            break;
        case 3:
            b_gameWon->draw(window);
            t_gameWon->draw(window);
            b_endPrompt->draw(window);
            t_endPrompt->draw(window);
    }

    window   ->display();
}
