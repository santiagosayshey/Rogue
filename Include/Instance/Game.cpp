#include "Game.h"
#include <iostream>
#include <time.h>
#include <algorithm>
#include <fstream>


Game::Game(int width, int height)
{
    // create a new render window
    window = new sf::RenderWindow(sf::VideoMode(width,height),"ROGUE",sf::Style::Close);

    // set first state to MenuState
    /* pass 'this' as in, the current game instance to the 
    current state so that it may exist within the entire scope */
    currentState = new MenuState(this, player);

    // start the game clock
    currentPlayTime.restart();
    currentRunTime.restart();

    // read previous stats to game instance
    std::ifstream readTotalPlayTime  ("Statistics/total.txt");
    std::ifstream readFastestRunTime ("Statistics/speed.txt");

    std::ifstream readTotalWins   ("Statistics/wins.txt");
    std::ifstream readTotalLosses ("Statistics/losses.txt");

    while (readTotalPlayTime >> temp)
    {
        setTotalPlayTime(stof(temp));
    }

    while (readFastestRunTime >> temp)
    {
        setFastestRunTime(stof(temp));
    }

    while (readTotalWins >> temp)
    {
        setTotalWins(stoi(temp));
    }

    while (readTotalLosses >> temp)
    {
        setTotalLosses(stoi(temp));
    }

}

Game::~Game()
{ 
    delete window;
    delete player;
    delete path;
    delete map;
    delete[] *enemyArr;

    delete golem;
    delete viking;
    delete pilgrim;
    delete brute;
}

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
    golem    ->getSprite()->flip();
    viking   ->getSprite()->flip();
    pilgrim  ->getSprite()->flip();
    brute    ->getSprite()->flip();

    // flip enemy GUIs
    golem    ->getGUI()   ->flip();
    viking   ->getGUI()   ->flip();
    pilgrim  ->getGUI()   ->flip();
    brute    ->getGUI()   ->flip();

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

void Game::setTotalPlayTime(float n)
{
    totalPlayTime = n;
}

void Game::setFastestRunTime(float n)
{
    fastestRunTime = n;
}

float Game::getTotalPlayTime()
{
    return totalPlayTime;
}

float Game::getFastestRunTime()
{
    return fastestRunTime;
}

sf::Clock Game::getCurrentRunTime()
{
    return currentRunTime;
}

sf::Clock Game::getCurrentPlayTime()
{
    return currentPlayTime;
}

int Game::getTotalWins()
{
    return totalWins;
}

int Game::getTotalLosses()
{
    return totalLosses;
}

void Game::incrementWins()
{
    totalWins++;
}

void Game::incrementLosses()
{
    totalLosses++;
}

void Game::setTotalWins(int n)
{
    totalWins = n;
}

void Game::setTotalLosses(int n)
{
    totalLosses = n;
}


 