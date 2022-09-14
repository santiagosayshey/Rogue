#include "Game.h"

Game::Game(int w, int h, std::string t):
winWidth(w), winHeight(h), title(t)
{
    window = new sf::RenderWindow(sf::VideoMode(w,h), t);   
}


void Game::run()
{

    // run the program as long as the window is open
    while (window->isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear();
        window->display();

    }
}


Game::~Game()
{
    delete window;

}