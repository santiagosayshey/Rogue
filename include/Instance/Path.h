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
    path s_button = "assets/sprites/button.png";

    // sound effects
    path e_hover = "assets/sounds/hover.wav";
    path e_bMusic = "assets/sounds/medieval.wav";




};

#endif