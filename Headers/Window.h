#ifndef WINDOW_H
#define WINDOW_H

#pragma once
#include <SFML/Graphics.hpp>
#include <string>

// this class handles the main window and skeleton of game loop
class Window
{
public:
    // default constructor
    Window();

    // custom constructor
    Window(int width, int height, std::string title);

    // game loop
    void gameLoop();

    // default deconstructor
    ~Window();

private:
    sf::RenderWindow* window;
};

#endif