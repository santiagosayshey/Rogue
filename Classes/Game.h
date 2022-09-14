#ifndef Game_H
#define Game_H

#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Game
{
public:
    // structors
    Game(int w, int h, std::string t);
    ~Game();

    // functions
    void run();

private:

    // data members
    int winWidth;
    int winHeight;
    std::string title;

    // data classes
    sf::RenderWindow* window;
    sf::Clock clock;
    float dt;

};

#endif