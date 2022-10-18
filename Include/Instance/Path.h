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
    path f_main               = "Assets/fonts/main.ttf";

    // sprites

        // splash screens
        path s_splash             = "Assets/sprites/splash.jpg";
        path s_knightSp           = "Assets/sprites/knightChar.png";
        path s_charSplash         = "Assets/sprites/charSplash.png";
        path s_mapSplash          = "Assets/sprites/mapSplash.png";
        path s_battleSplash       = "Assets/sprites/battleSplash.png";
        path s_battleSplashAlt    = "Assets/sprites/green.png";

        // button backgrounds
        path s_button             = "Assets/sprites/button.png";
        path s_buttonBig          = "Assets/sprites/buttonBig.png";
        path s_buttonSmall        = "Assets/sprites/buttonSmall.png";

        // character sprites
        path s_mage               = "Assets/entity/MAGE.png";
        path s_paladin            = "Assets/entity/PALADIN.png";
        path s_ninja              = "Assets/entity/NECROMANCER.png";
        path s_golem              = "Assets/entity/GOLEM.png";
        path s_viking             = "Assets/entity/VIKING.png";
        path s_pilgrim            = "Assets/entity/PILGRIM.png";
        path s_brute              = "Assets/entity/BRUTE.png";

        // character stats
        path s_mag_stat           = "Assets/sprites/wizStats.png";
        path s_pal_stat           = "Assets/sprites/palStats.png";
        path s_nin_stat           = "Assets/sprites/ninStats.png";

        // character GUI

            // player
            path s_pal_gui       = "Assets/sprites/palGUI.png";
            path s_wiz_gui       = "Assets/sprites/wizGUI.png";
            path s_nin_gui       = "Assets/sprites/ninGUI.png";

            // enemy
            path s_pilgrim_gui    = "Assets/sprites/pilgrimGUI.png";
            path s_viking_gui     = "Assets/sprites/vikingGUI.png";
            path s_brute_gui      = "Assets/sprites/bruteGUI.png";
            path s_golem_gui      = "Assets/sprites/golemGUI.png";

        // levels
        path s_lvlTemp            = "Assets/level/mapLvl.png";
        path s_lvlHover           = "Assets/level/mapLvlHover.png";
        path s_enemy              = "Assets/level/enemy.png";
        path s_enemyHover         = "Assets/level/enemyHover.png";
        path s_boss               = "Assets/level/boss.png";
        path s_bossHover          = "Assets/level/bossHover.png";
        path s_treasure           = "Assets/level/unknown.png";
        path s_treasureHover      = "Assets/level/unknownHover.png";

    // sound effects
    path e_hover              = "Assets/sounds/hover.wav";
    path e_bMusic             = "Assets/sounds/medieval.wav";

private:

};

#endif