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

void Game::setState(State* newState)
{
    // change game state 
    currentState = newState; 
}

 