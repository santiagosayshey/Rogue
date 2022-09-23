#include "Human.h"

Human::Human(std::string texture)
{
    this->texture = new sf::Texture;
    this->texture->loadFromFile(texture);
    this->texture->setRepeated(true);
    sprite = new sf::Sprite;
    sprite->setTexture(*(this->texture));
    sprite->setTextureRect(sf::IntRect(0,0,64,64));
}

Human::~Human()
{
    delete texture;
    delete sprite;
}


void Human::draw(sf::RenderWindow* window)
{
    window->draw(*sprite);
}

