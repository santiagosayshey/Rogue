#include "MapState.h"
#include "../Instance/Game.h"
#include "PlayState.h"

MapState::MapState(Game* g, Player* player):
State(g, player)
{
    // set map template to mapSplash.png, with size scaled to 1920 x 1080
    mapTemplate = new Sprite(g->p->s_mapSplash,0,0,1920,1080,1);

    // set levels on the map 
    lvl  = new Sprite(g->p->s_lvlTemp,450,450,14,14,15);
    lvl2 = new Sprite(g->p->s_lvlTemp,750,450,14,14,15);
    lvl3 = new Sprite(g->p->s_lvlTemp,1050,450,14,14,15);

    // create a change in colour in the levels when collision occurs with mouse
    lvlHover  = new Sprite(g->p->s_lvlHover,450,450,14,14,15);
    lvl2Hover = new Sprite(g->p->s_lvlHover,750,450,14,14,15);
    lvl3Hover = new Sprite(g->p->s_lvlHover,1050,450,14,14,15);

    // create enemies
    enemy  = new Sprite(g->p->s_enemy,490,490,64,64,2);
    enemy2 = new Sprite(g->p->s_enemy,790,490,64,64,2);
    enemy3 = new Sprite(g->p->s_enemy,1090,490,64,64,2);

    enemyHover  = new Sprite(g->p->s_enemyHover,490,490,64,64,2);
    enemyHover2 = new Sprite(g->p->s_enemyHover,790,490,64,64,2);
    enemyHover3 = new Sprite(g->p->s_enemyHover,1090,490,64,64,2);

    UI.setBuffer(g->hover);

    g->map = this;
}

MapState::~MapState(){}

void MapState::update(sf::RenderWindow* window)
{
    if (!lvl->checkCollision(window) && currentLVL==1)
    {
        hover1 = false;
        sound1=true;
    }
    else
    {
        hover1 = true;
        while (sound1)
        {
            UI.play();
            sound1=false;
        }
    }

    if (!lvl2->checkCollision(window) && currentLVL==2)
    {
        hover2 = false;
        sound2=true;
    }
    else
    {
        hover2 = true;
        while (sound2)
        {
            UI.play();
            sound2=false;
        }
    }

    if (!lvl3->checkCollision(window) && currentLVL==3)
    {
        hover3 = false;
        sound3=true;
    }
    else
    {
        hover3 = true;
        while (sound3)
        {
            UI.play();
            sound3=false;
        }
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
                if (lvl->checkCollision(window) && currentLVL==1)
                {
                    game->setState(new PlayState(game, player));
                    break;
                }
                if (lvl2->checkCollision(window) && currentLVL==2)
                {
                    game->setState(new PlayState(game, player));
                    break;
                }
                if (lvl3->checkCollision(window) && currentLVL==3)
                {
                    game->setState(new PlayState(game, player));
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

    window->display();
}

void MapState::updateLVL()
{
    currentLVL++;
}