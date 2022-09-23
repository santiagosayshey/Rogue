#include "Wizard.h"

Wizard::Wizard(std::string texture, int x, int y):
Human(texture)
{ 
    sprite->setScale(10,10);
    sprite->setPosition(x,y);
    row = 0;

    melee    = new Button("assets/entity/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "MELEE", 100, 300, 2);
    range    = new Button("assets/entity/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "RANGE", 100, 400, 2);
    die      = new Button("assets/entity/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "DIE", 100, 500, 2);
    idle     = new Button("assets/entity/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "IDLE", 100, 600, 2);
    walk     = new Button("assets/entity/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "WALK", 100, 700, 2);
    
    buffer.loadFromFile("assets/button/click.wav");
    click.setBuffer(buffer);
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

    melee   ->update(window, game);
    range   ->update(window, game);
    die     ->update(window, game);
    idle    ->update(window, game);
    walk    ->update(window, game);



    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (checkCollision(window))
        {
            click.play();
            currentFrame = 0;
            numFrames = 8;
            row = 1;
        }

        else if(melee->checkCollision(window))
        {
            click.play();
            currentFrame = 0;
            numFrames = 8;
            row = 3;
        }
        else if(range->checkCollision(window))
        {
            click.play();
            currentFrame = 0;
            numFrames = 8;
            row = 4;
        }
        else if(die->checkCollision(window))
        {
            click.play();
            currentFrame = 0;
            numFrames = 8;
            row = 8;
        }
        else if(idle->checkCollision(window))
        {
            click.play();
            currentFrame = 0;
            numFrames = 7;
            row = 0;
        }
        else if(walk->checkCollision(window))
        {
            click.play();
            currentFrame = 0;
            numFrames = 6;
            row = 2;
        }
    }
    animation(numFrames,row);
    

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();
    }


}

void Wizard::setPos(int x, int y)
{
    sprite->setPosition(x,y);
}

void Wizard::animation(int numFrames, int row)
{
    sprite->setTextureRect(sf::IntRect(64*currentFrame, 64*row, 64, 64));
    if (currentFrame != numFrames)
    {
        currentFrame++;
    }
    // remove else statement to play animation once
/*     else {
        currentFrame = 0;
    }  */
}

void Wizard::draw(sf::RenderWindow* window)
{
    Human::draw(window);
    melee->draw(window);
    range->draw(window);
    die->draw(window);
    idle->draw(window);
    walk->draw(window);
}