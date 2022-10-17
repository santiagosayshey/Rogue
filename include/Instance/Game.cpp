#include "Game.h"
#include <iostream>
#include <time.h>
#include <algorithm>


Game::Game(int width, int height)
{
    // create a new render window
    window = new sf::RenderWindow(sf::VideoMode(width,height),"Test",sf::Style::Close);

    // set first state to MenuState
    /* pass 'this' as in, the current game instance to the 
    current state so that it may exist within the entire scope */
    currentState = new MenuState(this, player);
}

Game::~Game() {  }

void Game::run()
{
    // check whether the window is open or not
    while (window->isOpen())
    {
        // if open, let the current state update and render the current window
        this->currentState->update(window);
        this->currentState->render(window);
    }

}

void Game::setState(State* newState)
{
    // update the current game state
    currentState = newState; 
}

void Game::initEnemies()
{

    // create enemies and assign to array
    golem  = new Golem(this);
    viking = new Viking(this);
    pilgrim = new Pilgrim(this);
    brute = new Brute(this);

    // fill the enemy array
    enemyArr[0] = pilgrim;
    enemyArr[1] = viking;
    enemyArr[2] = brute;
    enemyArr[3] = golem;

    // randomise the enemy array
    srand (time(NULL));
    for (int i = 3 - 1; i > 0; i--)
    {
        // Pick a random index from 0 to i
        int j = rand() % (i + 1);
 
        // Swap arr[i] with the element
        // at random index
        std::swap(enemyArr[i], enemyArr[j]);
    }

    // flip enemy sprites
    golem->getSprite()->flip();
    viking->getSprite()->flip();
    pilgrim->getSprite()->flip();
    brute->getSprite()->flip();

    // flip enemy GUIs
    golem->getGUI()->flip();
    viking->getGUI()->flip();
    pilgrim->getGUI()->flip();
    brute->getGUI()->flip();

}

Entity* Game::returnEnemy()
{
    return enemyArr[currentEnemy];
}

void Game::setEnemy(int n)
{
    currentEnemy=n;
}

void Game::incrementEnemy()
{
    currentEnemy++;
}

void Game::resetEnemy()
{
    // in case player replays game without quitting, reset current iterator
    currentEnemy = 0;

    // reset enemy healths
    pilgrim    ->setHealth(60);
    viking     ->setHealth(60);
    brute      ->setHealth(60);
    golem      ->setHealth(80);
}

int Game::getCurrentEnemy()
{
    return currentEnemy;
}

void Game::setMap(MapState* map)
{
    this->map = map;
}

MapState* Game::getMap()
{
    return map;
}

Path* Game::getPath()
{
    return path;
}


 