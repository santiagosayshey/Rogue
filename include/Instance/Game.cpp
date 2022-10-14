#include "Game.h"
#include <iostream>


Game::Game(int width, int height)
{
    // initialise player
    player = new Player; 

    // create a new render window
    this->window = new sf::RenderWindow(sf::VideoMode(width,height),"Test",sf::Style::Close);

    // set currentState to MenuState
    this->currentState = new MenuState(this, player);

    // load audio file into sound buffer
    hover.loadFromFile(p->e_hover);

    // init enemies
    initEnemies();

    // set current enemy to 0
    currentEnemy=0;
}

Game::~Game(){}

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

void Game::initEnemies()
{
    golem  = new Golem(this);
    viking = new Viking(this);
    pilgrim = new Pilgrim(this);
    brute = new Brute(this);
    
    golem->getSprite()->flip();
    viking->getSprite()->flip();
    pilgrim->getSprite()->flip();
    brute->getSprite()->flip();

    enemyArr[0] = pilgrim;
    enemyArr[1] = viking;
    enemyArr[2] = brute;
    enemyArr[3] = golem;
}

void Game::setState(State* newState)
{
    // change game state 
    currentState = newState; 
}

Entity* Game::returnEnemy()
{
    return enemyArr[currentEnemy];
}

void Game::updateCurrentEnemy()
{
    currentEnemy++;
}

void Game::resetEnemy()
{
    currentEnemy=0;
    pilgrim->updateHealth(60);
    viking->updateHealth(60);
    brute->updateHealth(60);
    golem->updateHealth(80);
}


 