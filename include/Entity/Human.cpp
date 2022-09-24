#include "Human.h"

Human::Human(std::string texture, int x, int y)
{
    this->texture = new sf::Texture;
    this->texture->loadFromFile(texture);
    this->texture->setRepeated(true);

    sprite = new sf::Sprite;
    sprite->setTexture(*(this->texture));
    sprite->setTextureRect(sf::IntRect(0,0,64,64));
    sprite->setPosition(x,y);
    sprite->setScale(10,10);


    currentFrame = 0;
    numFrames = 7;
    row = 0;
}

Human::~Human()
{
    delete texture;
    delete sprite;
}

void Human::update(sf::RenderWindow* window, Game* game)
{
    
}

void Human::updateSprite(int numFrames, int row)
{ 
    currentFrame = 0;
    this->numFrames = numFrames;
    this->row = row;
}

bool Human::checkCollision(sf::RenderWindow* window)
{
    sf::Vector2f mouse = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
    sf::FloatRect bounds = sprite->getGlobalBounds();

    return bounds.contains(mouse);
}

void Human::animation(bool repeat)
{
    if (clock.getElapsedTime().asSeconds() > 0.1f)
    {
        sprite->setTextureRect(sf::IntRect(64*currentFrame, 64*row, 64, 64));
        if (currentFrame != numFrames)
        {
            currentFrame++;
        }
        else
        {
            if (repeat == true)
                // set current frame to 0 IF the animation needs to be repeated
                currentFrame = 0;
            else
                // if not repeated, set to current animation first frame
                sprite->setTextureRect(sf::IntRect(0, 64*row, 64, 64));
        }
        clock.restart();
    }
}

void Human::draw(sf::RenderWindow* window)
{
    window->draw(*sprite);
}

void Human::setPos(int x, int y)
{
    sprite->setPosition(x,y);
}

