#ifndef MAIN_H
#define MAIN_H

#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Main
{
public:

    // default constructor, initialises window size, highscores
    // ?difficulty?
    Main();

    // custom constructor, passes parameters for all data members
    Main(int w, int h, int d, std::string t);

    // deconstructor
    ~Main();

    // run the game
    void run();

private:

    // data members
    int winWidth;
    int winHeight;
    int difficulty;
    std::string title;

    // data classes
    sf::RenderWindow* window;
        // Character* player;
        // Character* enemy;

};

#endif