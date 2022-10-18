#ifndef SOUND_H
#define SOUND_H

#include <SFML/Audio.hpp>

#pragma once

class Sound
{
public:
    Sound(std::string type);
    ~Sound();

    sf::Sound getSound();

private:
    // sfml sound objects
    sf::SoundBuffer buffer;
    sf::Sound sound;

};

#endif