#ifndef PLAYER_H
#define PLAYER_H

#pragma once

#include "../Entity/Human.h"
#include <iostream>

class Player
{
public:
    Player();
    Player(Human* sprite, int health, int armour, int attack, int exp, int lvl, int accuracy, int evasion);
    ~Player();

    void chooseRole(int role);

    void updateHealth(int health);
    void updateArmour(int armour);
    void updateAttack(int attack);
    void updateExp(int exp);
    void updateLvl();
    void updateAccuracy(int accuracy);
    void updateEvasion(int evasion);

    int getHealth();
    int getArmour();
    int getAttack();
    int getExp();
    int getLvl();
    int getAccuracy();
    int getEvasion();


private:
    Human* sprite;

    int health;
    int armour;
    int attack;
    int exp=0;
    int lvl=1;
    int accuracy;
    int evasion;

};

#endif