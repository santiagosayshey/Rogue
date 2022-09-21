#include "Game.h"

Game::Game() {}

Game::Game(int width, int height)
{
    this->window = new sf::RenderWindow(sf::VideoMode(width,height),"The Last of Us");
    this->currentState = new MenuState(this);
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

