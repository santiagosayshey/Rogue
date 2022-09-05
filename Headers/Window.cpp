#include "Window.h"

Window::Window() 
{
    window = new sf::RenderWindow(sf::VideoMode(800,600), "Default");  
}

Window::Window(int width, int height, std::string title)
{
    window = new sf::RenderWindow(sf::VideoMode(width,height), title);   
}


void Window::gameLoop()
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
    }
}


Window::~Window()
{
    delete window;
}