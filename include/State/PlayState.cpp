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
    // SPLASH SCREEN //
    splash = new Sprite(game->getPath()->s_charSplash,0,0,1920,1080,1);

    // BUTTONS //
    s_attack  = new Sprite(game->getPath()->s_button,150,550,30,14,7);
    b_attack  = new Text(game->getPath()->f_main, 50, c::Black, t::Bold, "AttacK", 170, 580);
    t_attack  = new Text(game->getPath()->f_main, 50, c::White, t::Bold, "AttacK", 175, 575);

    s_fortify = new Sprite(game->getPath()->s_button,150,700,30,14,7);
    b_fortify = new Text(game->getPath()->f_main, 45, c::Black, t::Bold, "Fortify", 170, 730);
    t_fortify = new Text(game->getPath()->f_main, 45, c::White, t::Bold, "Fortify", 175, 725);

    s_endTurn = new Sprite(game->getPath()->s_button,1630,600,30,14,7);
    b_endTurn = new Text(game->getPath()->f_main, 33, c::Black, t::Bold, "End Turn", 1650, 635);
    t_endTurn = new Text(game->getPath()->f_main, 33, c::White, t::Bold, "End Turn", 1655, 630);

    // PROMPTS //   
    b_prompt  = new Text(game->getPath()->f_main, 80, c::Black, t::Bold, "Player Turn!", 700, 900);
    t_prompt  = new Text(game->getPath()->f_main, 80, c::White, t::Bold, "Player Turn!", 705, 890);

    b_enemy_nextMove = new Text(game->getPath()->f_main, 50, c::Black, t::Bold, enemy->getFirstMove(), 1300, 850);
    t_enemy_nextMove = new Text(game->getPath()->f_main, 50, c::White, t::Bold, enemy->getFirstMove(), 1305, 845);

    b_player_choice  = new Text(game->getPath()->f_main, 50, c::Black, t::Bold, std::to_string(int(player->getPower()))+ " DMG", 480, 850);
    t_player_choice  = new Text(game->getPath()->f_main, 50, c::White, t::Bold, std::to_string(int(player->getPower()))+ " DMG", 485,845);

    // OVER SCREENS SPRITES + TEXT // 
    b_gameOver  = new Text(game->getPath()->f_main, 100, c::Black, t::Bold, "GAME OVER!", 580, 500);
    t_gameOver  = new Text(game->getPath()->f_main, 100, c::Red, t::Bold, "GAME OVER!", 590, 490);

    b_gameWon   = new Text(game->getPath()->f_main, 100, c::Black, t::Bold, "YOU WON!", 620, 500);
    t_gameWon   = new Text(game->getPath()->f_main, 100, c::Green, t::Bold, "YOU WON!", 630, 490);

    b_endPrompt = new Text(game->getPath()->f_main, 50, c::Black, t::Bold, "Press Space to Continue", 600, 700);
    t_endPrompt = new Text(game->getPath()->f_main, 50, c::White, t::Bold, "Press Space to Continue", 610, 690);

    // PLAYER // 

        // SPRITES //
        player->getSprite()->setPosition(200,65);

        // GUI //
        player->getGUI()->setPosition(150,100);

        player_b_health = new Text(game->getPath()->f_main,40,c::Black, t::Bold, "Health: "+std::to_string(int(player->getHealth())), 360,125);
        player_t_health = new Text(game->getPath()->f_main,40,c::White, t::Bold, "Health: "+std::to_string(int(player->getHealth())), 365,120);

        player_b_armour = new Text(game->getPath()->f_main,40,c::Black, t::Bold, "Armour: "+std::to_string(int(player->getArmour())), 360,215);
        player_t_armour = new Text(game->getPath()->f_main,40,c::White, t::Bold, "Armour: "+std::to_string(int(player->getArmour())), 365,210);

    // ENEMY //

        // return the current enemy from the random enemy array
        enemy = game->returnEnemy();

        // GUI //
        enemy->getGUI()->setPosition(1800,100);

        enemy_b_health = new Text(game->getPath()->f_main,40,c::Black, t::Bold, "Health: "+std::to_string(int(enemy->getHealth())), 1370,125);
        enemy_t_health = new Text(game->getPath()->f_main,40,c::White, t::Bold, "Health: "+std::to_string(int(enemy->getHealth())), 1375,120);

        enemy_b_armour = new Text(game->getPath()->f_main,40,c::Black, t::Bold, "Armour: "+std::to_string(int(enemy->getArmour())), 1370,215);
        enemy_t_armour = new Text(game->getPath()->f_main,40,c::White, t::Bold, "Armour: "+std::to_string(int(enemy->getArmour())), 1375,210);
}

PlayState::~PlayState()
{
    delete splash;
    
    delete s_attack;
    delete b_attack;
    delete t_attack;

    delete s_fortify;
    delete b_fortify;
    delete t_fortify;

    delete s_endTurn;
    delete b_endTurn;
    delete t_endTurn;

    delete b_prompt;
    delete t_prompt;

    delete b_endPrompt;
    delete t_endPrompt;

    delete b_gameOver;
    delete t_gameOver;

    delete b_gameWon;
    delete t_gameWon;

    delete b_player_choice;
    delete t_player_choice;
    
    delete b_enemy_nextMove;
    delete t_enemy_nextMove;

    delete player_b_health;
    delete player_t_health;

    delete player_b_armour;
    delete player_t_armour;

    delete enemy;

    delete enemy_s_health;
    delete enemy_b_health;
    delete enemy_t_health;

    delete enemy_s_armour;
    delete enemy_b_armour;
    delete enemy_t_armour;
}

void PlayState::update(sf::RenderWindow* window)
{

    // iterate through the different states
    switch (state)
    {

        // player turn
        case 0:
        {
            // set the intial play prompt to player turn
            b_prompt->setText("Player Turn!");
            t_prompt->setText("Player Turn!");
            
            // check for button hovers
            if (!s_attack  ->checkCollision(window))
            {
                s_attack   ->setPosition(s_attack->getX(), s_attack->getY());
                b_attack   ->setPosition(b_attack->getX(), b_attack->getY());
                t_attack   ->setPosition(t_attack->getX(), t_attack->getY());
            }
            else
            {
                s_attack   ->setPosition(s_attack->getX()+20, s_attack->getY());
                b_attack   ->setPosition(b_attack->getX()+20, b_attack->getY());
                t_attack   ->setPosition(t_attack->getX()+20, t_attack->getY());

            }
            if (!s_fortify  ->checkCollision(window))
            {
                s_fortify   ->setPosition(s_fortify->getX(), s_fortify->getY());
                b_fortify   ->setPosition(b_fortify->getX(), b_fortify->getY());
                t_fortify   ->setPosition(t_fortify->getX(), t_fortify->getY());
            }
            else
            {
                s_fortify   ->setPosition(s_fortify->getX()+20, s_fortify->getY());
                b_fortify   ->setPosition(b_fortify->getX()+20, b_fortify->getY());
                t_fortify   ->setPosition(t_fortify->getX()+20, t_fortify->getY());

            }
            if (!s_endTurn  ->checkCollision(window))
            {
                s_endTurn   ->setPosition(s_endTurn->getX(), s_endTurn->getY());
                b_endTurn   ->setPosition(b_endTurn->getX(), b_endTurn->getY());
                t_endTurn   ->setPosition(t_endTurn->getX(), t_endTurn->getY());
            }
            else
            {
                s_endTurn   ->setPosition(s_endTurn->getX()+20, s_endTurn->getY());
                b_endTurn   ->setPosition(b_endTurn->getX()+20, b_endTurn->getY());
                t_endTurn   ->setPosition(t_endTurn->getX()+20, t_endTurn->getY());

            }

            // event manager
            while (window->pollEvent(event))
            {
                
                switch (event.type)
                {
                    // close the window if the player clicks close
                    case sf::Event::Closed:
                    { 
                        window->close();
                        break; 
                    }

                    case sf::Event::MouseButtonReleased:
                    {
                        // check if attack is clicked
                        if (s_attack->checkCollision(window)) 
                        {
                            // set the current choice to attack and update the player intent prompt
                            currentChoice = "AttacK";
                            b_player_choice->setText(std::to_string(int(player->getPower()))+" DMG");
                            t_player_choice->setText(std::to_string(int(player->getPower()))+" DMG");

                            break;
                        }

                        // check if fortify is clicked
                        if (s_fortify->checkCollision(window)) 
                        {
                            // set the current choice to fortify and update the player intent prompt
                            currentChoice = "Fortify";
                            b_player_choice->setText("Fortify");
                            t_player_choice->setText("Fortify");
                            break;
                        }

                        // check if end turn is clicked
                        if (s_endTurn->checkCollision(window)) 
                        {
                            // check if attack was chosen
                            if (currentChoice == "AttacK")
                            {
                                // find the correct attack animation depending on player ID
                                switch (player->getID())
                                {
                                    // update the animation variables...
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

                                // pass the enemy to player so that it can attack it
                                player->attack(enemy);

                                // update the player's power back to the buffer to remove fotify debuffs
                                player->setPower(player->getPowerBuffer());

                                // update the enemy's health GUI after the player damages them
                                enemy_b_health->setText("Health: " + std::to_string(int(enemy->getHealth())));
                                enemy_t_health->setText("Health: " + std::to_string(int(enemy->getHealth())));

                                // switch the state to enemy turn
                                state = 1;
                            }

                            // check if foritfy was chosen
                            else if (currentChoice == "Fortify")
                            {
                                // apply a foritfy debuff to the enemy's power
                                enemy->setPower(enemy->getPower()-enemy->getPower()*(player->getArmour()/100));

                                 // update the player's power back to the buffer to remove fotify debuffs
                                player->setPower(player->getPowerBuffer());

                                // find the correct fortify animation depending on player ID
                                switch (player->getID())
                                {
                                    // update the animation variables...
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

                                // switch the state to enemy turn
                                state = 1;
                            }
                        }
                    }

                    default: 
                        break;
                }
            }
        }

        // enemy turn    
        case 1:
        {
            // only continue if the enemy is alive. This stops the enemy animating if its already dead
            if (!enemyDead)
            {
                // update the turn prompt to reflect state change
                b_prompt->setText("Enemy Turn!");
                t_prompt->setText("Enemy Turn!");

                // increment the enemy count to delay animation update
                enemyCount++;

                if (enemyCount > 300)
                {
                    // pass the player to the enemy so that it may complete an action
                    // return the next enemy action
                    enemyNextMove = enemy->attack(player);

                    // update the enemy intents
                    b_enemy_nextMove->setText(enemyNextMove);
                    t_enemy_nextMove->setText(enemyNextMove);

                    // remove any power debuffs from the enemy
                    enemy->setPower(enemy->getPowerBuffer());

                    // increment the enemy's action array
                    enemy->incrementAction();
                    
                    // update the player's GUI health stats
                    player_b_health->setText("Health: " + std::to_string(int(player->getHealth())));
                    player_t_health->setText("Health: " + std::to_string(int(player->getHealth())));

                    // if the player's last turn was an attack, update the player's intent to reflect any fortify debuffs
                    if (currentChoice == "AttacK")
                    {
                        b_player_choice->setText(std::to_string(int(player->getPower()))+" DMG");
                        t_player_choice->setText(std::to_string(int(player->getPower()))+" DMG");
                    }

                    // reset the enemy counter so that it may be delayed next turn
                    enemyCount=0;

                    // switch back to the player state
                    state = 0;
                }            
            }
            // if the enemy is dead, switch the state back to the player
            else {state = 0;}
            break;
        }

        // player is dead
        case 2:
        {
            // event manager
            while (window->pollEvent(event))
            {
                switch (event.type) 
                {
                    case sf::Event::KeyReleased:
                    {
                        // if the player is dead, check for space press to kick them back to the main menu
                        if (sf::Keyboard::Space)
                        {
                            // if true, set the game state back to the main menu and remove the past game from the stack. 
                            game->setState(new MenuState(game, player));
                            break;
                        }
                    }
                }
            }
            break;
        }

        // enemy is dead
        case 3:
        {
            // event manager
            while (window->pollEvent(event))
            {
                switch (event.type) 
                {
                    case sf::Event::KeyReleased:
                    {
                        // check if space bar is pressed
                        if (sf::Keyboard::Space)
                        {
                            // if the game is in the last enemy (golem) ->
                            if (game->getCurrentEnemy() == 4)
                            {
                                // reset the enemy array (needed to start a new game without seg faults)
                                game->setEnemy(0);

                                // switch the game state back to the main menu
                                game->setState(new MenuState(game, player));
                                break;
                            }
                            else
                            {
                                /* if an enemy is deafeated and its not the golem, kick the 
                                player back to the main menu to select the next level */
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

    // IF STATEMENT ANIMATIONS ALWAYS EXECUTE REGARDLESS OF TURN //
    // ALLOWS DECOUPLED DOUBLE ANIMATIONS //

    // check if the player is dead and this conditional has not been executed
    if (player->getHealth() == 0 && playerDead == false)
    {
        // find the corresponding player death animation
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
        // update the conditional conditional.. 
        playerDead = true;
    }

    // check if the enemy is dead and this conditional has not been executed
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
         // update the conditional conditional.. 
        enemyDead = true;
    }

    // IF ONLY the player is dead ->
    if (playerDead)
    {
        // reset the current level
        game->getMap()->setLVL(1);

        // reset the current enemy
        game->resetEnemy();

        // increment the timer to delay game over screen
        playerDeadCount++;

        // play death animation with death=true to stop at last frame
        player ->getSprite()->animation(false,true);

        // if the timer reaches an amount ->
        if (playerDeadCount > 300)
        {
            // switch the state to game over
            state = 2;

            // reset the timer
            playerDeadCount=0;
        }
    }
    else
    {
        // if they're not dead, play the updated animation - depends on whose turn it is
        player ->getSprite()->animation(false,false);
    }

    // IF ONLY the enemy is dead ->
    if (enemyDead)
    {
        // increment the timer to delay the game won screen
        enemyDeadCount++;

        // play death animation with death=true to stop at last frame
        enemy ->getSprite()->animation(false,true);

        // if the timer reaches an amount ->
        if (enemyDeadCount > 300)
        {
            // switch the state to game won
            state = 3;

            // reset the timer
            enemyDeadCount=0;
        }
    }
    else
    {
        // if they're not dead, play the updated animation - depends on whose turn it is
        enemy ->getSprite()->animation(false,false);
    }
}

void PlayState::render(sf::RenderWindow* window)
{
    // clear the previous frame
    window   ->clear(sf::Color::Black);
    
    // check if not a game over / won state
    if (state < 2)
    {
        // render the drawables
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
    
    // conditional rendering for over states
    switch (state)
    {
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
        default:
            break;
    }

    // display the renders on the render window
    window   ->display();
}
