#include "Game.h"
#include <iostream>
#include <time.h>
#include <algorithm>


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

     //create enemies and assign to array
    golem  = new Golem(this);
    viking = new Viking(this);
    pilgrim = new Pilgrim(this);
    brute = new Brute(this);

    enemyArr[0] = pilgrim;
    enemyArr[1] = viking;
    enemyArr[2] = brute;
    enemyArr[3] = golem;

    // fisher yates shuffle to randomise enemy placement
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

    golem->getGUI()->flip();
    viking->getGUI()->flip();
    pilgrim->getGUI()->flip();
    brute->getGUI()->flip();

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

void Game::incrementCurrentEnemy()
{
    currentEnemy++;
}

void Game::updateCurrentEnemy(int n)
{
    currentEnemy=n;
}

void Game::resetEnemy()
{
    currentEnemy=0;
    pilgrim->setHealth(60);
    viking->setHealth(60);
    brute->setHealth(60);
    golem->setHealth(80);
}

int Game::getCurrentEnemy()
{
    return currentEnemy;
}


 