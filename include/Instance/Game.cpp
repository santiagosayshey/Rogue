#include "Game.h"
#include <iostream>


Game::Game(int width, int height)
{
    player = new Player; // initialise player
    this->window = new sf::RenderWindow(sf::VideoMode(width,height),"Test",sf::Style::Close); // declare and create a new render window
    this->currentState = new MenuState(this, player); // set currentState to Menu
    hover.loadFromFile(p->e_hover); // play start-up sound effects
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
    currentState = newState; // Change game state 
}

 