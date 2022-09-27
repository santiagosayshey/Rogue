#include "PlayState.h"
#include "../Instance/Game.h"
#include "MenuState.h"

PlayState::PlayState(Game* game):
State(game)
{
    wizard   = new Human("assets/entity/human/MAGE.png",150,50,64);
    paladin  = new Human("assets/entity/human/PALADIN.png",650,50,64);
    necrom   = new Human("assets/entity/human/NECROMANCER.png",1150,50,64);
    golem    = new Human("assets/entity/human/GOLEM.png",700,10,64);

    melee    = new Button("assets/entity/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "MELEE", 320, 800, 2);
    range    = new Button("assets/entity/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "RANGE", 640, 800, 2);
    die      = new Button("assets/entity/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "DIE", 960, 800, 2);
    idle     = new Button("assets/entity/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "IDLE", 1280, 800, 2);
    walk     = new Button("assets/entity/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "WALK", 1500, 800, 2);
}

PlayState::~PlayState()
{

}

void PlayState::update(sf::RenderWindow* window)
{

    // events
    while (window->pollEvent(event))
    {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            window->close();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            game->setState(new MenuState(game));
        }
    }

    melee   ->update(window, game);
    range   ->update(window, game);
    die     ->update(window, game);
    idle    ->update(window, game);
    walk    ->update(window, game);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (wizard->checkCollision(window))
        { wizard->updateAnimation(8,1);
          paladin->updateAnimation(8,1);
          necrom->updateAnimation(8,1); }

        if (melee->checkCollision(window))
        { wizard->updateAnimation(8,3);
          paladin->updateAnimation(7,3);
          necrom->updateAnimation(6,3); }

        if (range->checkCollision(window))
        { wizard->updateAnimation(8,4);
          paladin->updateAnimation(7,4);
          necrom->updateAnimation(5,4); }

        if (die->checkCollision(window))
        { wizard->updateAnimation(8,8);
          paladin->updateAnimation(8,6);
          necrom->updateAnimation(8,6); }

        if (idle->checkCollision(window))
        { wizard->updateAnimation(10,4);
          paladin->updateAnimation(9,6);
          necrom->updateAnimation(9,6); }

        if (walk->checkCollision(window))
        { wizard->updateAnimation(6,2);
          paladin->updateAnimation(6,2);
          necrom->updateAnimation(6,2); }
    }
    wizard->animation(true);
    paladin->animation(true);
    necrom->animation(true);
    golem->animation(true);
} 

void PlayState::render(sf::RenderWindow* window)
{
    window   ->clear(sf::Color::White);

/*     wizard   ->draw(window);
    paladin  ->draw(window);
    necrom   ->draw(window); */
    golem    ->draw(window);

    melee    ->draw(window);
    range    ->draw(window);
    die      ->draw(window);
    idle     ->draw(window);
    walk     ->draw(window);

    window   ->display();
}
