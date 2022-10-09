#include "Game.h"
#include <iostream>


Game::Game(int width, int height)
{
    player = new Player;
    this->window = new sf::RenderWindow(sf::VideoMode(width,height),"Test",sf::Style::Close);
    this->currentState = new MenuState(this, player);
    hover.loadFromFile(p->e_hover);
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

 