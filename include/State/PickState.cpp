#include "PickState.h"
#include "../Instance/Game.h"
#include "PlayState.h"

PickState::PickState(Game* game):
State(game)
{
    wizardButton    = new Button("assets/entity/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "The \nWizard", 100, 300, 7);
    paladinButton    = new Button("assets/entity/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "The \nPaladin", 100, 500, 8);
    samuraiButton    = new Button("assets/entity/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "The \nSamurai", 100, 700, 9);


    wizard = new Human("assets/entity/human/MAGE.png",850,400,64);
    paladin  = new Human("assets/entity/human/PALADIN.png",850,400,64);
    samurai = new Human("assets/entity/human/SAMURAI.png",950,500,48);

    font.loadFromFile("assets/entity/font/menu.ttf");
    palDes.setFont(font);
    palDes.setCharacterSize(15);
    palDes.setFillColor(sf::Color::Black);
    palDes.setString("The Paladin was once a noble servant of the realm. He served the king and his allies \nvaliantly, of course until they betrayed his loyalty and exiled him to depths of this \ntreacherous world. Armed with a big ass axe and armour that weighs twice as much as \nhimself, The Paladin now walks a new road, making coin wear he can and kicking ass. \n");
    palDes.setPosition(1000,500);

    palStat.setFont(font);
    palStat.setCharacterSize(15);
    palStat.setFillColor(sf::Color::Black);
    palStat.setString("Statistics:\nHealth: 75\nArmour: 40%\nAttack Power: 20\nAccuracy: 60%\nEvasion: 5%\nStrength: Blunt\nWeakness: Magic\nNeutral: Bleed\n");
    palStat.setPosition(1000,800);

}

PickState::~PickState()
{

}

void PickState::update(sf::RenderWindow* window)
{
    while (window->pollEvent(event))
    {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            window->close();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            game->setState(new PlayState(game));
        }
    }

    if (wizardButton->isClicked(window))
    {
        currentSel = 1;
    }
    if (paladinButton->isClicked(window))
    {
        currentSel = 2;
    }
    if (samuraiButton->isClicked(window))
    {
        currentSel = 3;
    }

    wizardButton   ->update(window, game);
    paladinButton   ->update(window, game);
    samuraiButton     ->update(window, game);

    if (wizard->isClicked(window))
    {
        wizard->updateAnimation(4,6);
    }

        if (wizard->isClicked(window))
    {
        wizard->updateAnimation(4,6);
    }

        if (wizard->isClicked(window))
    {
        wizard->updateAnimation(4,6);
    }

    wizard->animation(true);
    paladin->animation(true);
    samurai->animation(true);
}

void PickState::render(sf::RenderWindow* window)
{
    window   ->clear(sf::Color::White);

    wizardButton    ->draw(window);
    paladinButton ->draw(window);
    samuraiButton ->draw(window);

    switch (currentSel) {
        case 1:
            wizard->draw(window);
            break;
        case 2:
            paladin->draw(window);
            window->draw(palDes);
            window->draw(palStat);
            break;
        case 3:
            samurai->draw(window);
            break;
    }
    
    window   ->display();
}

