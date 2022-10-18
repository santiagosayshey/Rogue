#include "Sound.h"

Sound::Sound()
{

}

Sound::~Sound()
{

}

void Sound::setBuffer(std::string type)
{
    buffer.loadFromFile(type);
    sound.setBuffer(buffer);
}

sf::Sound Sound::getSound()
{
    return sound;
}