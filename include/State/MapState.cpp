#include "MapState.h"
#include "../Instance/Game.h"
#include "PlayState.h"
#include "MenuState.h"

typedef sf::Color c;
typedef sf::Text t;

MapState::MapState(Game* game, Player* player):
State(game, player)
{
    // splash screen
    mapTemplate = new Sprite(game->getPath()->s_mapSplash,0,0,1920,1080,1);

    // levels - non collision
    lvl  = new Sprite(game->getPath()->s_lvlTemp,355,440,14,14,15);
    lvl2 = new Sprite(game->getPath()->s_lvlTemp,688,440,14,14,15);
    lvl3 = new Sprite(game->getPath()->s_lvlTemp,1021,440,14,14,15);
    lvl4 = new Sprite(game->getPath()->s_lvlTemp,1355,440,14,14,15);

    // levels - collision
    lvlHover  = new Sprite(game->getPath()->s_lvlHover,355,440,14,14,15);
    lvl2Hover = new Sprite(game->getPath()->s_lvlHover,688,440,14,14,15);
    lvl3Hover = new Sprite(game->getPath()->s_lvlHover,1021,440,14,14,15);
    lvl4Hover = new Sprite(game->getPath()->s_lvlHover,1355,440,14,14,15);

    // enemy sprites - no collision
    enemy  = new Sprite(game->getPath()->s_enemy,395,480,64,64,2);
    enemy2 = new Sprite(game->getPath()->s_enemy,728,480,64,64,2);
    enemy3 = new Sprite(game->getPath()->s_enemy,1061,480,64,64,2);
    boss   = new Sprite(game->getPath()->s_boss,1395,480,64,64,2);

    // enemy sprites - collision
    enemyHover  = new Sprite(game->getPath()->s_enemyHover,395,480,64,64,2);
    enemyHover2 = new Sprite(game->getPath()->s_enemyHover,728,480,64,64,2);
    enemyHover3 = new Sprite(game->getPath()->s_enemyHover,1061,480,64,64,2);
    bossHover   = new Sprite(game->getPath()->s_bossHover,1395,480,64,64,2);

    // prompt
    b_prompt = new Text(game->getPath()->f_main, 100, c::Black, t::Bold, "Choose a Level...", 550, 800);

    // build and randomise enemy array
    game->initEnemies();

    // store the current map inside the game instance so that it doesnt disappear when moving into the next state
    game->setMap(this);
}

MapState::~MapState(){}

void MapState::update(sf::RenderWindow* window)
{
    /* check for collisions between mouse and level sprites, if true, tell the render function
    by updating the hover booleans */
    if (!lvl->checkCollision(window) && currentLVL==1) { hover1 = false; }

    else { hover1 = true; }

    if (!lvl2->checkCollision(window) && currentLVL==2) { hover2 = false; }

    else { hover2 = true; }

    if (!lvl3->checkCollision(window) && currentLVL==3) { hover3 = false; }

    else { hover3 = true; }

    if (!lvl4->checkCollision(window) && currentLVL==4) { hover4 = false; }

    else { hover4 = true; }


    // event manager
    while (window->pollEvent(event))
    {
        // "close requested" event: we close the window
        switch (event.type) {
            case sf::Event::Closed: {
                window->close();
                break;
            }
            case sf::Event::MouseButtonReleased: {
                if (lvl->checkCollision(window) && currentLVL==1)
                {
                    game->setState(new PlayState(game, player));
                    game->incrementEnemy();
                    currentLVL=2;
                    break;
                }
                if (lvl2->checkCollision(window) && currentLVL==2)
                {
                    game->setState(new PlayState(game, player));
                    game->incrementEnemy();
                    currentLVL=3;
                    break;
                }
                if (lvl3->checkCollision(window) && currentLVL==3)
                {
                    game->setState(new PlayState(game, player));
                    game->incrementEnemy();
                    currentLVL=4;
                    break;
                }
                if (lvl4->checkCollision(window) && currentLVL==4)
                {
                    game->setState(new PlayState(game, player));
                    game->incrementEnemy();
                    break;
                }
                break;
            }

            case sf::Event::KeyReleased: {
            }
            default: {
                break;
            }
        }
    }

}

void MapState::render(sf::RenderWindow* window)
{
    window->clear(sf::Color::Black);
 
    mapTemplate->draw(window);

    b_prompt->draw(window);  
    
    switch (hover1)
    {
        case true:
            lvlHover->draw(window);
            enemyHover->draw(window);
            break;
        case false:
            lvl->draw(window);
            enemy->draw(window);
            break;
    }

    switch (hover2)
    {
        case true:
            lvl2Hover->draw(window);
            enemyHover2->draw(window);
            break;
        case false:
            lvl2->draw(window);
            enemy2->draw(window);
            break;
    }

    switch (hover3)
    {
        case true:
            lvl3Hover->draw(window);
            enemyHover3->draw(window);
            break;
        case false:
            lvl3->draw(window);
            enemy3->draw(window);
            break;
    }

    switch (hover4)
    {
        case true:
            lvl4Hover->draw(window);
            bossHover->draw(window);
            break;
        case false:
            lvl4->draw(window);
            boss->draw(window);
            break;
    }

    window->display();
}

void MapState::incrementLVL()
{
    currentLVL++;
}

void MapState::setLVL(int lvl)
{
    currentLVL = lvl;
}