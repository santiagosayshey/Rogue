#include "Wizard.h"

Wizard::Wizard(std::string texture, int x, int y):
Human(texture)
{ 
    sprite->setScale(10,10);
    sprite->setPosition(x,y);
    row = 0;
}

Wizard::~Wizard()
{

}

bool Wizard::checkCollision(sf::RenderWindow* window)
{
    sf::Vector2f mouse = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
    sf::FloatRect bounds = sprite->getGlobalBounds();

    return bounds.contains(mouse);
}

void Wizard::update(sf::RenderWindow* window, Game* game)
{
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();

        switch(event.key.code)
        {
            case (sf::Keyboard::Q):
                row = 0;
                break;
            case (sf::Keyboard::W):
                row = 64;
                break;
            case (sf::Keyboard::E):
                row = 128;
                break;
            case (sf::Keyboard::R):
                row = 192;
                break;
            case (sf::Keyboard::T):
                row = 256;
                break;
            case (sf::Keyboard::Y):
                row = 320;
                break;
            case (sf::Keyboard::U):
                row = 384;
                break;
            case (sf::Keyboard::I):
                row = 448;
                break;
            case (sf::Keyboard::P):
                row = 512;
                break;
            case (sf::Keyboard::Escape):
                window->close();
                break;
        }
    }
    animation(row);
}

void Wizard::setPos(int x, int y)
{
    sprite->setPosition(x,y);
}

void Wizard::animation(int row)
{
    sprite->setTextureRect(sf::IntRect(64*currentFrame,row,64,64));
    currentFrame++;
}