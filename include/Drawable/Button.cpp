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

void Button::draw(sf::RenderWindow* window)
{
    background->draw(window);
    black->draw(window);
    white->draw(window);
}

bool Button::checkCollision(sf::RenderWindow *window)
{
    return background->checkCollision(window);
}