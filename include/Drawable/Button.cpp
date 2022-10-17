#include "Button.h"



Button::Button(int ID, std::string string, int fSize, Game* game)
{
    this->ID = ID;

    switch (ID)
    {
        case 1:
        { background = new Sprite(game->getPath()->s_button,0,0,30,14,7);}

        case 2:
        { background = new Sprite(game->getPath()->s_buttonBig,0,0,46,14,7);}

        case 3: 
        { background = new Sprite(game->getPath()->s_buttonSmall,0,0,14,13,7);}
    }

    black = new Text(game->getPath()->f_main,fSize,c::Black,t::Bold,string,0,0);
    white = new Text(game->getPath()->f_main,fSize,c::White,t::Bold,string,0,0);
}

Button::~Button()
{

}

void Button::setPosition(int x, int y)
{
    background->setPosition(x,y);
}

void Button::setTextPosition(int x, int y)
{
    white->setPosition(x,y);
    black->setPosition(x-5,y+5);
}

bool Button::checkCollision(sf::RenderWindow *window)
{
    // find the bounds of the mouse
    sf::Vector2f mouse = window->mapPixelToCoords(sf::Mouse::getPosition(*window));

    // find the bounds of the current sprite
    sf::FloatRect bounds = background->getSFSprite()->getGlobalBounds();

    // return a boolean that defines whether the bounds of the sprite contains the bounds of the mouse
    return bounds.contains(mouse);
}