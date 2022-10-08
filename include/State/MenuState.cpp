#include "MenuState.h"
#include "../Instance/Game.h"
#include "PickState.h"
#include <iostream>

typedef sf::Color c;
typedef sf::Text t;



MenuState::MenuState(Game* g, Player* player):
State(g, player)
{

    splash    = new Sprite(g->p->s_splash,0,0,1280,720,1.5);

    s_play    = new Sprite(g->p->s_button,150,400,30,14,7);
    b_play    = new Text(g->p->f_main, 50, c::Black, t::Bold, "PLAY", 185, 430);
    play      = new Text(g->p->f_main, 50, c::White, t::Bold, "PLAY", 190, 425);

    s_quit    = new Sprite(g->p->s_button,150,550,30,14,7);
    b_quit    = new Text(g->p->f_main, 50, c::Black, t::Bold, "QUIT", 170, 580);
    quit      = new Text(g->p->f_main, 50, c::White, t::Bold, "QUIT", 175, 575);

    b_title   = new Text(g->p->f_main, 200, c::Black, t::Bold, "ROGUE", 1000, 425);
    title     = new Text(g->p->f_main, 200, c::White, t::Bold, "ROGUE", 1010, 415);

    sb. loadFromFile(g->p->e_hover);
    sb2.loadFromFile(g->p->e_bMusic);

    UI. setBuffer(sb);
    mus.setBuffer(sb2);

    //mus.play();

    std::cout << "succesfully created drawables" << std::endl;

}

MenuState::~MenuState()
{   
    delete splash;
    delete s_play;
    delete s_quit;
    delete b_play;
    delete b_quit;
    delete play;
    delete quit;
    delete b_title;
    delete title;

    std::cout << "succesfully deleted drawables" << std::endl;

}

void MenuState::update(sf::RenderWindow* window)

{
    splash   ->update(window);
    s_play   ->update(window);
    b_play   ->update(window);
    play     ->update(window);
    s_quit   ->update(window);
    b_quit   ->update(window);
    quit     ->update(window);
    b_title  ->update(window);
    title    ->update(window);

    //std::cout << "succesfully updated drawables" << std::endl;

    if (!s_play->checkCollision(window))
    {
        //std::cout << "no collision success" << std::endl;

        s_play ->setPos(s_play->getX(), s_play->getY());
        b_play ->setPos(b_play->getX(), b_play->getY());
        play   ->setPos(play->getX(), play->getY());
        sound1=true;
    }
    else
    {
        std::cout << "collision success" << std::endl;
        while (sound1)
        {
            std::cout << "sound success" << std::endl;
            UI.play();
            sound1=false;
        }
        std::cout << "Text move success" << std::endl;
        s_play ->setPos(s_play->getX()+20, s_play->getY());
        b_play ->setPos(b_play->getX()+20, b_play->getY());
        play   ->setPos(play->getX()+20, play->getY());

    }

    if (!s_quit->checkCollision(window))
    {
        //std::cout << "no collision success" << std::endl;
        s_quit ->setPos(s_quit->getX(), s_quit->getY());
        b_quit ->setPos(b_quit->getX(), b_quit->getY());
        quit   ->setPos(quit->getX(), quit->getY());
        sound2=true;
    }
    else
    {
        while (sound2)
        {
            std::cout << "sound success" << std::endl;
            UI.play();
            sound2=false;
        }
        std::cout << "Text move success" << std::endl;
        s_quit ->setPos(s_quit->getX()+20, s_quit->getY());
        b_quit ->setPos(b_quit->getX()+20, b_quit->getY());
        quit   ->setPos(quit->getX()+20, quit->getY());
        
    }


    while (window->pollEvent(event))
    {
        switch (event.type) {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::MouseButtonReleased: {
                if (play->checkCollision(window)) {
                    UI.play();
                    mus.stop();
                    std::cout << "click successful" << std::endl;
                    game->setState(new PickState(game, player));
                    break;
                }
                if (quit->checkCollision(window)) {
                    UI.play();
                    std::cout << "click successful" << std::endl;
                    window->close();
                    break;
                }
            }
        }
        
    }
}


void MenuState::render(sf::RenderWindow* window)
{
    window     ->clear(c::White);

    splash     ->draw(window);
    s_play     ->draw(window);
    b_play     ->draw(window);
    play       ->draw(window);
    s_quit     ->draw(window);
    b_quit     ->draw(window);
    quit       ->draw(window);
    b_title    ->draw(window);
    title      ->draw(window);

    window     ->display();

    //std::cout << "draw successful" << std::endl;
}

