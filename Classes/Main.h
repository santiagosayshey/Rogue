#ifndef MAIN_H
#define MAIN_H

#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Main
{
public:

    // custom constructor, passes parameters for all data members
    Main(int w, int h, std::string t);

    // deconstructor
    ~Main();

    // run the game
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