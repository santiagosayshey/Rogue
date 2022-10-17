#ifndef PATH_H
#define PATH_H

#include <string>

typedef std::string path;
typedef std::string action;

#pragma once

struct Path
{
    Path() {}
    ~Path() {}

    // fonts
    path f_main               = "assets/fonts/main.ttf";

    // sprites

        // splash screens
        path s_splash             = "assets/sprites/splash.jpg";
        path s_knightSp           = "assets/sprites/knightChar.png";
        path s_charSplash         = "assets/sprites/charSplash.png";
        path s_mapSplash          = "assets/sprites/mapSplash.png";
        path s_battleSplash       = "assets/sprites/battleSplash.png";
        path s_battleSplashAlt    = "assets/sprites/green.png";

        // button backgrounds
        path s_button             = "assets/sprites/button.png";
        path s_buttonBig          = "assets/sprites/buttonBig.png";
        path s_buttonSmall        = "assets/sprites/buttonSmall.png";

        // character sprites
        path s_mage               = "assets/entity/MAGE.png";
        path s_paladin            = "assets/entity/PALADIN.png";
        path s_ninja              = "assets/entity/NECROMANCER.png";
        path s_golem              = "assets/entity/GOLEM.png";
        path s_viking             = "assets/entity/VIKING.png";
        path s_pilgrim            = "assets/entity/PILGRIM.png";
        path s_brute              = "assets/entity/BRUTE.png";

        // character stats
        path s_mag_stat           = "assets/sprites/wizStats.png";
        path s_pal_stat           = "assets/sprites/palStats.png";
        path s_nin_stat           = "assets/sprites/ninStats.png";

        // character GUI

            // player
            path s_pal_gui       = "assets/sprites/palGUI.png";
            path s_wiz_gui       = "assets/sprites/wizGUI.png";
            path s_nin_gui       = "assets/sprites/ninGUI.png";

            // enemy
            path s_pilgrim_gui    = "assets/sprites/pilgrimGUI.png";
            path s_viking_gui     = "assets/sprites/vikingGUI.png";
            path s_brute_gui      = "assets/sprites/bruteGUI.png";
            path s_golem_gui      = "assets/sprites/golemGUI.png";

        // levels
        path s_lvlTemp            = "assets/level/mapLvl.png";
        path s_lvlHover           = "assets/level/mapLvlHover.png";
        path s_enemy              = "assets/level/enemy.png";
        path s_enemyHover         = "assets/level/enemyHover.png";
        path s_boss               = "assets/level/boss.png";
        path s_bossHover          = "assets/level/bossHover.png";
        path s_treasure           = "assets/level/unknown.png";
        path s_treasureHover      = "assets/level/unknownHover.png";

    // sound effects
    path e_hover              = "assets/sounds/hover.wav";
    path e_bMusic             = "assets/sounds/medieval.wav";

private:

};

#endif