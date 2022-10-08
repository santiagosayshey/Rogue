#ifndef PATH_H
#define PATH_H

#include <string>

typedef std::string path;

#pragma once

class Path
{
public:
    Path();
    ~Path();

    // fonts
    path f_main = "assets/fonts/main.ttf";

    // sprites
    path s_splash = "assets/sprites/splash.jpg";
    path s_knightSp = "assets/sprites/knightChar.png";
    path s_charSplash = "assets/sprites/charSplash.png";

    path s_floor = "assets/sprites/floor.png";
    path s_button = "assets/sprites/button.png";
    path s_buttonBig = "assets/sprites/buttonBig.png";
    path s_mage = "assets/entity/MAGE.png";
    path s_paladin = "assets/entity/PALADIN.png";
    path s_ninja = "assets/entity/NECROMANCER.png";

    // sound effects
    path e_hover = "assets/sounds/hover.wav";
    path e_bMusic = "assets/sounds/medieval.wav";




};

#endif