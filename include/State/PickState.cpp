#include "PickState.h"
#include "../Instance/Game.h"
#include "../Entity/Player.h"
#include "MapState.h"

typedef sf::Color c;
typedef sf::Text t;

PickState::PickState(Game* g, Player* player):
State(g, player)
{


    splash = new Sprite(g->p->s_charSplash,0,0,1920,1080,1);

    s_wiz      = new Sprite(g->p->s_buttonBig,150,350,46,14,7);
    b_wiz      = new Text(g->p->f_main, 50, c::Black, t::Bold, "MAGE", 240, 380);
    t_wiz      = new Text(g->p->f_main, 50, c::White, t::Bold, "MAGE", 245, 375);

    s_pal      = new Sprite(g->p->s_buttonBig,150,500,46,14,7);
    b_pal      = new Text(g->p->f_main, 50, c::Black, t::Bold, "PALADIN", 185, 530);
    t_pal      = new Text(g->p->f_main, 50, c::White, t::Bold, "PALADIN", 190, 525);

    s_nin      = new Sprite(g->p->s_buttonBig,150,650,46,14,7);
    b_nin      = new Text(g->p->f_main, 50, c::Black, t::Bold, "NINJA", 220, 680);
    t_nin      = new Text(g->p->f_main, 50, c::White, t::Bold, "NINJA", 225, 675);

    s_emb      = new Sprite(g->p->s_buttonBig,1500,650,46,14,7);
    b_emb      = new Text(g->p->f_main, 50, c::Black, t::Bold, "EMBARK", 1550, 680);
    t_emb      = new Text(g->p->f_main, 50, c::White, t::Bold, "EMBARK", 1555, 675);

    UI. setBuffer(g->hover);

    spr_wiz     = new DynamicSprite(g->p->s_mage,620,65,64,64,12);
    spr_pal     = new DynamicSprite(g->p->s_paladin,620,65,64,64,12);
    spr_nin     = new DynamicSprite(g->p->s_ninja,670,65,64,64,12);

    spr_wiz_stats = new Sprite(g->p->s_mag_stat,1500,320,1063,1063,0.3);
    spr_pal_stats = new Sprite(g->p->s_pal_stat,1500,320,1063,1063,0.3);
    spr_nin_stats = new Sprite(g->p->s_nin_stat,1500,320,1063,1063,0.3);

    b_prompt = new Text(g->p->f_main, 100, c::Black, t::Bold, "Choose Your Character...", 350, 900);
    prompt   = new Text(g->p->f_main, 100, c::White, t::Bold, "Choose Your Character...", 360, 890);

    choice=1;
    player->setCharacter(spr_wiz,1);
    player->updateHealth(65);
    player->updateArmour(10);
    player->updatePower(30);
    player->setOGPower(30);
    player->setGUI(game->p->s_wiz_gui);
}  

PickState::~PickState() 
{

}

void PickState::update(sf::RenderWindow* window)
{
    if (!s_wiz->checkCollision(window))
    {
        s_wiz ->setPos(s_wiz->getX(), s_wiz->getY());
        b_wiz ->setPos(b_wiz->getX(), b_wiz->getY());
        t_wiz   ->setPos(t_wiz->getX(), t_wiz->getY());
        sound1=true;
    }
    else
    {
        while (sound1)
        {
            UI.play();
            sound1=false;
        }
        s_wiz ->setPos(s_wiz->getX()+20, s_wiz->getY());
        b_wiz ->setPos(b_wiz->getX()+20, b_wiz->getY());
        t_wiz   ->setPos(t_wiz->getX()+20, t_wiz->getY());

    }

    if (!s_pal->checkCollision(window))
    {
        s_pal ->setPos(s_pal->getX(), s_pal->getY());
        b_pal ->setPos(b_pal->getX(), b_pal->getY());
        t_pal   ->setPos(t_pal->getX(), t_pal->getY());
        sound2=true;
    }
    else
    {
        while (sound2)
        {
            UI.play();
            sound2=false;
        }
        s_pal ->setPos(s_pal->getX()+20, s_pal->getY());
        b_pal ->setPos(b_pal->getX()+20, b_pal->getY());
        t_pal   ->setPos(t_pal->getX()+20, t_pal->getY());

    }

    if (!s_nin->checkCollision(window))
    {
        s_nin ->setPos(s_nin->getX(), s_nin->getY());
        b_nin ->setPos(b_nin->getX(), b_nin->getY());
        t_nin   ->setPos(t_nin->getX(), t_nin->getY());
        sound3=true;
    }
    else
    {
        while (sound3)
        {
            UI.play();
            sound3=false;
        }
        s_nin ->setPos(s_nin->getX()+20, s_nin->getY());
        b_nin ->setPos(b_nin->getX()+20, b_nin->getY());
        t_nin   ->setPos(t_nin->getX()+20, t_nin->getY());

    }

    if (!s_emb->checkCollision(window))
    {
        s_emb ->setPos(s_emb->getX(), s_emb->getY());
        b_emb ->setPos(b_emb->getX(), b_emb->getY());
        t_emb   ->setPos(t_emb->getX(), t_emb->getY());
        sound4=true;
    }
    else
    {
        while (sound4)
        {
            UI.play();
            sound4=false;
        }
        s_emb ->setPos(s_emb->getX()+20, s_emb->getY());
        b_emb ->setPos(b_emb->getX()+20, b_emb->getY());
        t_emb   ->setPos(t_emb->getX()+20, t_emb->getY());

    }


    while (window->pollEvent(event))
    {
        // "close requested" event: we close the window
        switch (event.type) {
            case sf::Event::Closed: {
                window->close();
                break;
            }
            case sf::Event::MouseButtonReleased: {
                if (s_wiz->checkCollision(window))
                {
                    choice = 1;
                    player->setCharacter(spr_wiz,1);
                    player->updateHealth(65);
                    player->updateArmour(10);
                    player->updatePower(30);
                    player->setOGPower(30);
                    player->setGUI(game->p->s_wiz_gui);
                    break;
                }
                if (s_pal->checkCollision(window))
                {
                    choice = 2;
                    player->setCharacter(spr_pal,2);
                    player->updateHealth(100);
                    player->updateArmour(50);
                    player->updatePower(15);
                    player->setOGPower(15);
                    player->setGUI(game->p->s_pal_gui);
                    break;
                }
                if (s_nin->checkCollision(window))
                {
                    choice = 3;
                    player->setCharacter(spr_nin,3);
                    player->updateHealth(75);
                    player->updateArmour(25);
                    player->updatePower(20);
                    player->setOGPower(20);
                    player->setGUI(game->p->s_nin_gui);
                    break;
                }
                if (s_emb->checkCollision(window))
                {
                    game->setState(new MapState(game, player));
                    break;
                }
                break;
            }
            case sf::Event::KeyReleased: {
                if (sf::Keyboard::Space) {
                    game->setState(new MenuState(game, player));
                    break;
                }
            }
            default:
                break; 
            
        }
    }
    spr_wiz->animation(true,false);
    spr_pal->animation(true,false);
    spr_nin->animation(true,false);
}

void PickState::render(sf::RenderWindow* window)
{
    window   ->clear(sf::Color::White);

    splash->draw(window);

    switch (choice) {
        case 1:
            spr_wiz_stats->draw(window);
            spr_wiz->draw(window);
            break;
        case 2:
            spr_pal_stats->draw(window);
            spr_pal->draw(window);
            break;
        case 3:
            spr_nin_stats->draw(window);
            spr_nin->draw(window);
            break;
        default:
            break;
    } 

    s_wiz->draw(window);
    b_wiz->draw(window);
    t_wiz->draw(window);

    s_pal->draw(window);
    b_pal->draw(window);
    t_pal->draw(window);

    s_nin->draw(window);
    b_nin->draw(window);
    t_nin->draw(window);

    s_emb->draw(window);
    b_emb->draw(window);
    t_emb->draw(window);

    b_prompt->draw(window);
    prompt->draw(window);    
    
    window   ->display();
}
