#include "Main.h"

Main::Main():
winWidth(800), winHeight(600), difficulty(0), title("Default")
{
    window = new sf::RenderWindow(sf::VideoMode(800,600), "Default");  
}

Main::Main(int w, int h, int d, std::string t):
winWidth(w), winHeight(h), difficulty(d), title(t)
{
    window = new sf::RenderWindow(sf::VideoMode(w,h), t);   
}


void Main::run()
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


Main::~Main()
{
    delete window;
        // delete player
        // delete enemy
}