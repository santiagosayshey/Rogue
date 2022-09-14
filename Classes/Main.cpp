#include "Main.h"

Main::Main(int w, int h, std::string t):
winWidth(w), winHeight(h), title(t)
{
    window = new sf::RenderWindow(sf::VideoMode(w,h), t);   
}


void Main::run()
{
    window->setFramerateLimit(60);

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

        dt = clock.restart().asSeconds();

        window->clear();
        window->display();

        std::cout << "dt: " << dt << std::endl; 
    }
}


Main::~Main()
{
    delete window;
        // delete player
        // delete enemy
}