#include "PlayState.h"
#include "../Instance/Game.h"
#include "MenuState.h"
#include "PickState.h"


PlayState::PlayState(Game* game, Player* player):
State(game,player)
{
    
    attack = new Button("assets/entity/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "Attack", 100, 300);
    attackP = new Button("assets/entity/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "Attack\nPlayer", 100, 500);

    enemy = new Enemy;

    sEnemy = new Character("assets/entity/Character/GOLEM.png",1400,400,64);
    sEnemy->flip();

    enemy->setChararacter(sEnemy);
    enemy->updateRole(4);
    enemy->updateDamage(30);
    enemy->updateHealth(100);
}

PlayState::~PlayState()
{

}

void PlayState::update(sf::RenderWindow* window)
{


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
                    game->setState(new PickState(game, player));
                    break;
            }
        }
    }

    
    attack->update(window);
    attackP->update(window);

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
}

void PlayState::render(sf::RenderWindow* window)
{
    window   ->clear(sf::Color::White);

    attack->draw(window);
    attackP->draw(window);

    enemy->draw(window);
    player->draw(window);

    window   ->display();
}
