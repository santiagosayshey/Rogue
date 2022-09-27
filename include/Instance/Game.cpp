#include "Game.h"
#include <iostream>


Game::Game(int width, int height)
{
    this->window = new sf::RenderWindow(sf::VideoMode(width,height),"Test");
    this->currentState = new MenuState(this);
    this->window->setFramerateLimit(20);

    player = new Player;
}

Game::~Game()
{

}

void Game::run()
{

    while (window->isOpen())
    {
        this->currentState->update(window);
        this->currentState->render(window);
    }

}

void Game::setState(State* newState)
{
    currentState = newState;
}

 