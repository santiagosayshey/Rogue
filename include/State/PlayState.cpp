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
    splash = new Sprite(game->getPath()->s_charSplash,0,0,1920,1080,1);
    enemy = game->returnEnemy();


    // buttons
    s_attack = new Sprite(game->getPath()->s_button,150,550,30,14,7);
    b_attack = new Text(game->getPath()->f_main, 50, c::Black, t::Bold, "AttacK", 170, 580);
    t_attack = new Text(game->getPath()->f_main, 50, c::White, t::Bold, "AttacK", 175, 575);

    s_fortify = new Sprite(game->getPath()->s_button,150,700,30,14,7);
    b_fortify = new Text(game->getPath()->f_main, 45, c::Black, t::Bold, "Fortify", 170, 730);
    t_fortify = new Text(game->getPath()->f_main, 45, c::White, t::Bold, "Fortify", 175, 725);

    s_endTurn = new Sprite(game->getPath()->s_button,1630,600,30,14,7);
    b_endTurn = new Text(game->getPath()->f_main, 33, c::Black, t::Bold, "End Turn", 1650, 635);
    t_endTurn = new Text(game->getPath()->f_main, 33, c::White, t::Bold, "End Turn", 1655, 630);

    // player
    player->getSprite()->setPosition(200,65);
    player->getGUI()->setPosition(150,100);
    enemy->getGUI()->setPosition(1800,100);
        
    player_b_health = new Text(game->getPath()->f_main,40,c::Black, t::Bold, "Health: "+std::to_string(int(player->getHealth())), 360,125);
    player_t_health = new Text(game->getPath()->f_main,40,c::White, t::Bold, "Health: "+std::to_string(int(player->getHealth())), 365,120);

    player_b_armour = new Text(game->getPath()->f_main,40,c::Black, t::Bold, "Armour: "+std::to_string(int(player->getArmour())), 360,215);
    player_t_armour = new Text(game->getPath()->f_main,40,c::White, t::Bold, "Armour: "+std::to_string(int(player->getArmour())), 365,210);

    // enemy
    enemy_b_health = new Text(game->getPath()->f_main,40,c::Black, t::Bold, "Health: "+std::to_string(int(enemy->getHealth())), 1370,125);
    enemy_t_health = new Text(game->getPath()->f_main,40,c::White, t::Bold, "Health: "+std::to_string(int(enemy->getHealth())), 1375,120);

    enemy_b_armour = new Text(game->getPath()->f_main,40,c::Black, t::Bold, "Armour: "+std::to_string(int(enemy->getArmour())), 1370,215);
    enemy_t_armour = new Text(game->getPath()->f_main,40,c::White, t::Bold, "Armour: "+std::to_string(int(enemy->getArmour())), 1375,210);

    // prompts  
    b_prompt = new Text(game->getPath()->f_main, 80, c::Black, t::Bold, "Player Turn!", 700, 900);
    t_prompt = new Text(game->getPath()->f_main, 80, c::White, t::Bold, "Player Turn!", 705, 890);

    b_enemy_nextMove = new Text(game->getPath()->f_main, 50, c::Black, t::Bold, enemy->getFirstMove(), 1300, 850);
    t_enemy_nextMove = new Text(game->getPath()->f_main, 50, c::White, t::Bold, enemy->getFirstMove(), 1305, 845);

    b_player_choice = new Text(game->getPath()->f_main, 50, c::Black, t::Bold, std::to_string(int(player->getPower()))+ " DMG", 480, 850);
    t_player_choice = new Text(game->getPath()->f_main, 50, c::White, t::Bold, std::to_string(int(player->getPower()))+ " DMG", 485,845);

    // battle over
    b_gameOver = new Text(game->getPath()->f_main, 100, c::Black, t::Bold, "GAME OVER!", 580, 500);
    t_gameOver = new Text(game->getPath()->f_main, 100, c::Red, t::Bold, "GAME OVER!", 590, 490);

    b_gameWon = new Text(game->getPath()->f_main, 100, c::Black, t::Bold, "YOU WON!", 620, 500);
    t_gameWon = new Text(game->getPath()->f_main, 100, c::Green, t::Bold, "YOU WON!", 630, 490);

    b_endPrompt = new Text(game->getPath()->f_main, 50, c::Black, t::Bold, "Press Space to Continue", 600, 700);
    t_endPrompt = new Text(game->getPath()->f_main, 50, c::White, t::Bold, "Press Space to Continue", 610, 690);
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
            b_prompt->setText("Player Turn!");
            t_prompt->setText("Player Turn!");
            // button feedback
            if (!s_attack->checkCollision(window))
            {
                s_attack ->setPosition(s_attack->getX(), s_attack->getY());
                b_attack ->setPosition(b_attack->getX(), b_attack->getY());
                t_attack   ->setPosition(t_attack->getX(), t_attack->getY());
                sound1=true;
            }
            else
            {
                while (sound1)
                {
                    UI.play();
                    sound1=false;
                }
                s_attack ->setPosition(s_attack->getX()+20, s_attack->getY());
                b_attack ->setPosition(b_attack->getX()+20, b_attack->getY());
                t_attack   ->setPosition(t_attack->getX()+20, t_attack->getY());

            }
            if (!s_fortify->checkCollision(window))
            {
                s_fortify ->setPosition(s_fortify->getX(), s_fortify->getY());
                b_fortify ->setPosition(b_fortify->getX(), b_fortify->getY());
                t_fortify   ->setPosition(t_fortify->getX(), t_fortify->getY());
                sound2=true;
            }
            else
            {
                while (sound2)
                {
                    UI.play();
                    sound2=false;
                }
                s_fortify ->setPosition(s_fortify->getX()+20, s_fortify->getY());
                b_fortify ->setPosition(b_fortify->getX()+20, b_fortify->getY());
                t_fortify   ->setPosition(t_fortify->getX()+20, t_fortify->getY());

            }
            if (!s_endTurn->checkCollision(window))
            {
                s_endTurn ->setPosition(s_endTurn->getX(), s_endTurn->getY());
                b_endTurn ->setPosition(b_endTurn->getX(), b_endTurn->getY());
                t_endTurn   ->setPosition(t_endTurn->getX(), t_endTurn->getY());
                sound3=true;
            }
            else
            {
                while (sound3)
                {
                    UI.play();
                    sound3=false;
                }
                s_endTurn ->setPosition(s_endTurn->getX()+20, s_endTurn->getY());
                b_endTurn ->setPosition(b_endTurn->getX()+20, b_endTurn->getY());
                t_endTurn   ->setPosition(t_endTurn->getX()+20, t_endTurn->getY());

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
                            b_player_choice->setText(std::to_string(int(player->getPower()))+" DMG");
                            t_player_choice->setText(std::to_string(int(player->getPower()))+" DMG");

                            break;
                        }
                        if (s_fortify->checkCollision(window)) 
                        {
                            currentChoice = "Fortify";
                            b_player_choice->setText("Fortify");
                            t_player_choice->setText("Fortify");
                            break;
                        }
                        if (s_endTurn->checkCollision(window)) 
                        {
                            if (currentChoice == "AttacK")
                            {
                                switch (player->getID())
                                {
                                    case 1:
                                        player->getSprite()->setAnimation(7,3);
                                        break;
                                    case 2:
                                        player->getSprite()->setAnimation(7,4);
                                        break;
                                    case 3:
                                        player->getSprite()->setAnimation(6,3);
                                        break;
                                    default:
                                        break;
                                }
                                player->attack(enemy);
                                player->setPower(player->getPowerBuffer());

                                enemy_b_health->setText("Health: " + std::to_string(int(enemy->getHealth())));
                                enemy_t_health->setText("Health: " + std::to_string(int(enemy->getHealth())));
                                state = 1;
                            }
                            else if (currentChoice == "Fortify")
                            {
                                enemy->setPower(enemy->getPower()-enemy->getPower()*(player->getArmour()/100));
                                player->setPower(player->getPowerBuffer());

                                switch (player->getID())
                                {
                                    case 1:
                                        player->getSprite()->setAnimation(4,6);
                                        break;
                                    case 2:
                                        player->getSprite()->setAnimation(7,2);
                                        break;
                                    case 3:
                                        player->getSprite()->setAnimation(8,2);
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
            break;
        }
            
        case 1:
        {
            if (!enemyDead)
            {
                b_prompt->setText("Enemy Turn!");
                t_prompt->setText("Enemy Turn!");

                enemyCount++;

                if (enemyCount > 300)
                {
                    enemyNextMove = enemy->attack(player);

                    b_enemy_nextMove->setText(enemyNextMove);
                    t_enemy_nextMove->setText(enemyNextMove);

                    enemy->setPower(enemy->getPowerBuffer());



                    enemy->incrementAction();
                    
                    player_b_health->setText("Health: " + std::to_string(int(player->getHealth())));
                    player_t_health->setText("Health: " + std::to_string(int(player->getHealth())));

                    if (currentChoice == "AttacK")
                    {
                        b_player_choice->setText(std::to_string(int(player->getPower()))+" DMG");
                        t_player_choice->setText(std::to_string(int(player->getPower()))+" DMG");
                    }


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
                            
                            if (game->getCurrentEnemy() == 4)
                            {
                                game->setEnemy(0);
                                game->setState(new MenuState(game, player));
                                break;
                            }
                            else
                            {
                                game->setState(game->getMap());
                                break;
                            }

                        }
                    }
                }
            }
            break;
        }
    }

    if (player->getHealth() == 0 && playerDead == false)
    {
        switch (player->getID())
        {
            case 1:
                player->getSprite()->setAnimation(7,8);
                break;
            case 2:           
                player->getSprite()->setAnimation(9,6);
                break;
            case 3:
                player->getSprite()->setAnimation(8,6);
                break;
            
        }
    playerDead = true;
    }

    if (enemy->getHealth() < 1 && enemyDead == false)
    {
        switch(enemy->getID())
        {
            case 1:
                enemy->getSprite()->setAnimation(7,6);
                break;
            case 2:
                enemy->getSprite()->setAnimation(8,5);
                break;
            case 3:
                enemy->getSprite()->setAnimation(5,5);
                break;
            case 4:
                enemy->getSprite()->setAnimation(16,4);
                break;

        }
    enemyDead = true;
    }

    if (playerDead)
    {
        game->getMap()->setLVL(1);
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
        splash->draw(window);
        player->getSprite()->draw(window);
        enemy->getSprite()->draw(window);

        b_player_choice->draw(window);
        t_player_choice->draw(window);

        player->getGUI()->draw(window);
        enemy->getGUI()->draw(window);

        player_b_health->draw(window);
        player_t_health->draw(window);

        player_b_armour->draw(window);
        player_t_armour->draw(window);

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
