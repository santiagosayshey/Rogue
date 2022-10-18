#include "Sound.h"

Sound::Sound(std::string type)
{
    buffer.loadFromFile(type);
    sound.setBuffer(buffer);
}

Sound::~Sound()
{

}

sf::Sound Sound::getSound()
{
    return sound;
}