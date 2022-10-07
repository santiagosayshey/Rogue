#include "MenuState.h"
#include "../Instance/Game.h"
#include "PickState.h"
#include "../Instance/Path.cpp"

typedef sf::Color c;
typedef sf::Text t;

MenuState::MenuState(Game* game, Player* player):
State(game, player)
{

    splash  = new Sprite(p.s_splash,0,0,1280,720,1.5);

    s_play = new Sprite(p.s_button,150,400,30,14,7);
    s_quit = new Sprite(p.s_button,150,550,30,14,7);

    b_play    = new Button(p.f_main, 50, c::Black, t::Bold, "PLAY", 185, 430);
    b_quit    = new Button(p.f_main, 50, c::Black, t::Bold, "QUIT", 170, 580);

    play    = new Button(p.f_main, 50, c::White, t::Bold, "PLAY", 190, 425);
    quit    = new Button(p.f_main, 50, c::White, t::Bold, "QUIT", 175, 575);

    b_title    = new Button(p.f_main, 200, c::Black, t::Bold, "ROGUE", 1000, 425);
    title    = new Button(p.f_main, 200, c::White, t::Bold, "ROGUE", 1010, 415);

    sb.loadFromFile(p.e_hover);
    UI.setBuffer(sb);

    sb2.loadFromFile(p.e_bMusic);
    mus.setBuffer(sb2);
    mus.play();

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
}

void MenuState::update(sf::RenderWindow* window)

{
    
    s_play->update(window);
    s_quit->update(window);

    b_play->update(window);
    b_quit->update(window);

    play->update(window);
    quit->update(window);

    b_title->update(window);
    title->update(window);

    if (!s_play->checkCollision(window))
    {

        s_play ->setPos(s_play->getX(), s_play->getY());
        b_play ->setPos(b_play->getX(), b_play->getY());
        play   ->setPos(play->getX(), play->getY());
        sound1=true;
    }
    else
    {
        while (sound1)
        {
            UI.play();
            sound1=false;
        }
        s_play ->setPos(s_play->getX()+20, s_play->getY());
        b_play ->setPos(b_play->getX()+20, b_play->getY());
        play   ->setPos(play->getX()+20, play->getY());

    }

    if (!s_quit->checkCollision(window))
    {

        s_quit ->setPos(s_quit->getX(), s_quit->getY());
        b_quit ->setPos(b_quit->getX(), b_quit->getY());
        quit   ->setPos(quit->getX(), quit->getY());
        sound2=true;
    }
    else
    {
        while (sound2)
        {
            UI.play();
            sound2=false;
        }
        s_quit ->setPos(s_quit->getX()+20, s_quit->getY());
        b_quit ->setPos(b_quit->getX()+20, b_quit->getY());
        quit   ->setPos(quit->getX()+20, quit->getY());
        
    }


    // events  
    while (window->pollEvent(event))
    {
        // "close requested" event: we close the window
        switch (event.type) {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::MouseButtonReleased: {
                if (play->checkCollision(window)) {
                    UI.play();
                    std::cout << "Click" << std::endl;
                    game->setState(new PickState(game, player));
                    break;
                }
                if (quit->checkCollision(window)) {
                    UI.play();
                    std::cout << "Click" << std::endl;
                    window->close();
                    break;
                }
            }
        }
        
    }
}


void MenuState::render(sf::RenderWindow* window)
{
    window->clear(c::Green);

    splash->draw(window);

    s_play->draw(window);
    s_quit->draw(window);

    b_play->draw(window);
    b_quit->draw(window);

    play   ->draw(window);
    quit   ->draw(window);

    b_title->draw(window);
    title->draw(window);

    window->display();
}

