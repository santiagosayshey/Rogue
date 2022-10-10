#include "Game.h"
#include <iostream>


Game::Game(int width, int height)
{
    // initialise player
    player = new Player; 

    // declare a create a new render window
    this->window = new sf::RenderWindow(sf::VideoMode(width,height),"Test",sf::Style::Close);

    // set currentState to MenuState; load menu page
    this->currentState = new MenuState(this, player);

    // access audio file 'e_hover'
    hover.loadFromFile(p->e_hover);
}

Game::~Game(){}

void Game::run()
{
    // the run function used to determine whether if game is running
    while (window->isOpen())
    {
        // while window is still open, continue to update and render window
        this->currentState->update(window);
        this->currentState->render(window);
    }

}

void Game::setState(State* newState)
{
    currentState = newState; // Change game state 
}

 