#include "PlayState.h"
#include "../Instance/Game.h"
#include "MenuState.h"
#include "PickState.h"


PlayState::PlayState(Game* game, Player* player):
State(game,player)
{
    
    attack = new Text("assets/entity/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "Attack", 100, 300);
    attackP = new Text("assets/entity/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "Attack\nPlayer", 100, 500);

    wiz = new Sprite("assets/UI/necromancer.png",100,100,26,36,5);
    wizhealth = new Sprite("assets/UI/heart.png",500,500,268,268,0.2);

    health = new Text("assets/entity/font/menu.ttf", 25, sf::Color(255, 172, 28), sf::Text::Bold, "75/75", 170, 50);
    healthShadow = new Text("assets/entity/font/menu.ttf", 25, sf::Color::Black, sf::Text::Bold, "75/75", 173, 53);

    enemy = new Enemy;

    sEnemy = new Sprite("assets/entity/Character/GOLEM.png",1400,400,64,64,10);
    sEnemy->flip();

    enemy->setChararacter(sEnemy);
    enemy->updateRole(4);
    enemy->updateDamage(5);
    enemy->updateHealth(100);
}

PlayState::~PlayState()
{

}

void PlayState::update(sf::RenderWindow* window)
{

    wiz->update(window);
    wizhealth->update(window);

    while (window->pollEvent(event))
    {
        // "close requested" event: we close the window
        switch (event.type) {
            case sf::Event::Closed: {
                window->close();
                break;
            }
            case sf::Event::MouseButtonReleased: {
                if (attack->checkCollision(window)) {
                    player->attack(enemy);
                    break;
                }
                if (attackP->checkCollision(window)) {
                    enemy->attack(player);
                    break;
                }
            }
            case sf::Event::KeyReleased: { 
                if (sf::Keyboard::Space)
                    //game->setState(new PickState(game, player));
                    break;
            }
            default:
                break;
        }
    }

    
    attack->update(window);
    attackP->update(window);

    // always update the frames and animate but only play death animations if previous attack animation is finished
    if (player->update(window) && enemy->getHealth() < 1 && enemyDead == false) {
        switch (enemy->getRole()) {
            case 4:
                enemy->getSprite()->updateAnimation(13,4);
                break;
        }
        enemyDead = true;
    }
    if (enemy->update(window) && player->getHealth() < 1 && playerDead == false) {
        switch (player->getRole()) {
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

    healthShadow->updateText(std::to_string(player->getHealth()));
    healthShadow->update(window);

    health->updateText(std::to_string(player->getHealth()));
    health->update(window);
}

void PlayState::render(sf::RenderWindow* window)
{
    window   ->clear(sf::Color::White);

    wiz->draw(window);


    attack->draw(window);
    attackP->draw(window);

    enemy->draw(window);
    player->draw(window);
    wizhealth->draw(window);
    healthShadow->draw(window);
    health->draw(window);

    
    window   ->display();
}
