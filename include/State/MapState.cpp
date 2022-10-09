#include "MapState.h"
#include "../Instance/Game.h"
#include "PlayState.h"

MapState::MapState(Game* g, Player* player):
State(g, player)
{
    mapTemplate = new Sprite(g->p->s_mapSplash,0,0,1920,1080,1);

    lvl = new Sprite(g->p->s_lvlTemp,450,450,14,14,15);
    lvlHover = new Sprite(g->p->s_lvlHover,450,450,14,14,15);

    enemy = new Sprite(g->p->s_enemy,490,490,64,64,2);
    enemyHover = new Sprite(g->p->s_enemyHover,490,490,64,64,2);

    UI. setBuffer(g->hover);
}

MapState::~MapState()
{

}

void MapState::update(sf::RenderWindow* window)
{
    if (!lvl->checkCollision(window))
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

    while (window->pollEvent(event))
    {
        // "close requested" event: we close the window
        switch (event.type) {
            case sf::Event::Closed: {
                window->close();
                break;
            }
            case sf::Event::MouseButtonReleased: {
                if (lvl->checkCollision(window))
                {
                    game->setState(new PlayState(game, player));
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

    window->display();
}