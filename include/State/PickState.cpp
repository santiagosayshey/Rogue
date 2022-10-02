#include "PickState.h"
#include "../Instance/Game.h"
#include "../Entity/Player.h"
#include "PlayState.h"


PickState::PickState(Game* game, Player* player):
State(game, player)
{
    wizardButton     = new Button("assets/entity/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "The \nWizard", 100, 300);
    paladinButton    = new Button("assets/entity/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "The \nPaladin", 100, 500);
    samuraiButton    = new Button("assets/entity/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "The \nSamurai", 100, 700);
    embark           = new Button("assets/entity/font/menu.ttf", 50, sf::Color::Black, sf::Text::Bold, "Embark!", 1600, 500);

    wizard = new Sprite("assets/entity/Character/MAGE.png",850,400,64,10);
    paladin  = new Sprite("assets/entity/Character/PALADIN.png",850,400,64,10);
    samurai = new Sprite("assets/entity/Character/SAMURAI.png",950,500,48,10);

    font.loadFromFile("assets/entity/font/menu.ttf");
    paladinStats.setFont(font);
    paladinStats.setCharacterSize(30);
    paladinStats.setFillColor(sf::Color::Black);
    paladinStats.setString("Statistics:\nHealth:                75\nArmour:               40%\nAttack:                20\nAccuracy:            60%\nEvasion:              5%\nStrength:             Blunt\nWeakness:            Magic\nNeutral:              Bleed\n");
    paladinStats.setPosition(1050,400);

    wizardStats.setFont(font);
    wizardStats.setCharacterSize(30);
    wizardStats.setFillColor(sf::Color::Black);
    wizardStats.setString("Statistics:\nHealth:                50\nArmour:               0%\nAttack:                30\nAccuracy:            90%\nEvasion:              50%\nStrength:             Magic\nWeakness:            Bleed\nNeutral:              Blunt\n");
    wizardStats.setPosition(1050,400);

    samuraiStats.setFont(font);
    samuraiStats.setCharacterSize(30);
    samuraiStats.setFillColor(sf::Color::Black);
    samuraiStats.setString("Statistics:\nHealth:                75\nArmour:               20%\nAttack:                5\nAccuracy:            80%\nEvasion:              30%\nStrength:             Bleed\nWeakness:            Blunt\nNeutral:              Magic\n");
    samuraiStats.setPosition(1050,400);

    currentSel = 1;
    player->chooseRole(currentSel);
    player->setChararacter(wizard);

}  

PickState::~PickState()
{

}

void PickState::update(sf::RenderWindow* window)
{
    while (window->pollEvent(event))
    {
        // "close requested" event: we close the window
        switch (event.type) {
            case sf::Event::Closed: {
                window->close();
                break;
            }
            case sf::Event::MouseButtonReleased: {
                if (wizardButton->checkCollision(window))
                {
                    currentSel = 1;
                    player->chooseRole(currentSel);
                    player->setChararacter(wizard);
                    std::cout << "Click" << std::endl;
                    break;
                }
                if (paladinButton->checkCollision(window))
                {
                    currentSel = 2;
                    player->chooseRole(currentSel);
                    player->setChararacter(paladin);
                    
                    std::cout << "Click" << std::endl;
                    break;
                }
                if (samuraiButton->checkCollision(window))
                {
                    currentSel = 3;
                    player->chooseRole(currentSel);
                    player->setChararacter(samurai);
                    std::cout << "Click" << std::endl;
                    break;
                }
                if (embark->checkCollision(window))
                {
                    game->setState(new PlayState(game, player));
                    std::cout << "Click" << std::endl;
                    break;
                }
            }
        }
    }

    wizardButton   ->update(window);
    paladinButton  ->update(window);
    samuraiButton  ->update(window);
    embark         ->update(window);

    wizard->animation(true);
    paladin->animation(true);
    samurai->animation(true);
}

void PickState::render(sf::RenderWindow* window)
{
    window   ->clear(sf::Color::White);

    wizardButton  ->draw(window);
    paladinButton ->draw(window);
    samuraiButton ->draw(window);
    embark        ->draw(window);

    switch (currentSel) {
        case 1:
            wizard->draw(window);
            window->draw(wizardStats);
            break;
        case 2:
            paladin->draw(window);
            window->draw(paladinStats);
            break;
        case 3:
            samurai->draw(window);
            window->draw(samuraiStats);
            break;
    }
    
    window   ->display();
}

