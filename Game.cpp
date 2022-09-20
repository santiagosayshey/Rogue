#include "Game.h"

Game::Game() {}

Game::Game(int width, int height)
{
    this->window = new sf::RenderWindow(sf::VideoMode(width,height),"Title");
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

void Game::setState(GameState* newState)
{
    currentState = newState;
}

