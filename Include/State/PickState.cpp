#include "PickState.h"
#include "../Instance/Game.h"
#include "../Entity/Player.h"
#include "MapState.h"

typedef sf::Color c;
typedef sf::Text t;

PickState::PickState(Game* game, Player* player):
State(game, player)
{
    // splash screen
    splash = new Sprite(game->getPath()->s_charSplash,0,0,1920,1080,1);

    // buttons 

    // wizard
    s_wiz      = new Sprite (game->getPath()->s_buttonBig,150,350,46,14,7);
    b_wiz      = new Text   (game->getPath()->f_main, 50, c::Black, t::Bold, "MAGE", 240, 380);
    w_wiz      = new Text   (game->getPath()->f_main, 50, c::White, t::Bold, "MAGE", 245, 375);

    // paladin
    s_pal      = new Sprite (game->getPath()->s_buttonBig,150,500,46,14,7);
    b_pal      = new Text   (game->getPath()->f_main, 50, c::Black, t::Bold, "PALADIN", 185, 530);
    w_pal      = new Text   (game->getPath()->f_main, 50, c::White, t::Bold, "PALADIN", 190, 525);

    // ninja
    s_nin      = new Sprite (game->getPath()->s_buttonBig,150,650,46,14,7);
    b_nin      = new Text   (game->getPath()->f_main, 50, c::Black, t::Bold, "NINJA", 220, 680);
    w_nin      = new Text   (game->getPath()->f_main, 50, c::White, t::Bold, "NINJA", 225, 675);

    // embark
    s_emb      = new Sprite (game->getPath()->s_buttonBig,1500,650,46,14,7);
    b_emb      = new Text   (game->getPath()->f_main, 50, c::Black, t::Bold, "EMBARK", 1550, 680);
    w_emb      = new Text   (game->getPath()->f_main, 50, c::White, t::Bold, "EMBARK", 1555, 675);
    
    // dynamic sprites
    spr_wiz    = new DynamicSprite (game->getPath()->s_mage,620,65,64,64,12);
    spr_pal    = new DynamicSprite (game->getPath()->s_paladin,620,65,64,64,12);
    spr_nin    = new DynamicSprite (game->getPath()->s_ninja,670,65,64,64,12);

    // regular sprites
    spr_wiz_stats  = new Sprite (game->getPath()->s_mag_stat,1500,320,1063,1063,0.3);
    spr_pal_stats  = new Sprite (game->getPath()->s_pal_stat,1500,320,1063,1063,0.3);
    spr_nin_stats  = new Sprite (game->getPath()->s_nin_stat,1500,320,1063,1063,0.3);

    // text
    b_prompt   = new Text (game->getPath()->f_main, 100, c::Black, t::Bold, "Choose Your Character...", 350, 900);
    w_prompt   = new Text (game->getPath()->f_main, 100, c::White, t::Bold, "Choose Your Character...", 360, 890);

    // initialise wizard as first choice, needed to not seg fault if player clicks embark without selecting a character
    choice = 1;

    // update player variables with stats of chosen character

    // sprites, ID, GUI
    player  ->setCharacter(spr_wiz,1);
    player  ->setGUI(game->getPath()->s_wiz_gui);

    // stats
    player  ->setHealth(65);
    player  ->setArmour(10);
    player  ->setPower(30);
    player  ->setPowerBuffer(30);
    
}  

PickState::~PickState() 
{
    delete splash;

    delete s_wiz;
    delete s_pal;
    delete s_nin;
    delete s_emb;

    delete spr_wiz_stats;
    delete spr_pal_stats;
    delete spr_nin_stats;

    delete b_wiz;
    delete w_wiz;
    delete b_pal;
    delete w_pal;
    delete b_nin;
    delete w_nin;
    delete b_emb;
    delete w_emb;

    delete w_prompt;
    delete b_prompt;
}

void PickState::update(sf::RenderWindow* window)
{
    // check for button collisions with mouse
    // if true, move them to indicate the player can click them
    if (!s_wiz ->checkCollision(window))
    {
        s_wiz   ->setPosition(s_wiz->getX(), s_wiz->getY());
        b_wiz   ->setPosition(b_wiz->getX(), b_wiz->getY());
        w_wiz   ->setPosition(w_wiz->getX(), w_wiz->getY());
    }
    else
    {
        s_wiz   ->setPosition(s_wiz->getX()+20, s_wiz->getY());
        b_wiz   ->setPosition(b_wiz->getX()+20, b_wiz->getY());
        w_wiz   ->setPosition(w_wiz->getX()+20, w_wiz->getY());
    }

    if (!s_pal ->checkCollision(window))
    {
        s_pal   ->setPosition(s_pal->getX(), s_pal->getY());
        b_pal   ->setPosition(b_pal->getX(), b_pal->getY());
        w_pal   ->setPosition(w_pal->getX(), w_pal->getY());
    }
    else
    {
        s_pal   ->setPosition(s_pal->getX()+20, s_pal->getY());
        b_pal   ->setPosition(b_pal->getX()+20, b_pal->getY());
        w_pal   ->setPosition(w_pal->getX()+20, w_pal->getY());
    }

    if (!s_nin ->checkCollision(window))
    {
        s_nin   ->setPosition(s_nin->getX(), s_nin->getY());
        b_nin   ->setPosition(b_nin->getX(), b_nin->getY());
        w_nin   ->setPosition(w_nin->getX(), w_nin->getY());
    }
    else
    {
        s_nin   ->setPosition(s_nin->getX()+20, s_nin->getY());
        b_nin   ->setPosition(b_nin->getX()+20, b_nin->getY());
        w_nin   ->setPosition(w_nin->getX()+20, w_nin->getY());
    }

    if (!s_emb ->checkCollision(window))
    {
        s_emb   ->setPosition(s_emb->getX(), s_emb->getY());
        b_emb   ->setPosition(b_emb->getX(), b_emb->getY());
        w_emb   ->setPosition(w_emb->getX(), w_emb->getY());
    }
    else
    {
        s_emb   ->setPosition(s_emb->getX()+20, s_emb->getY());
        b_emb   ->setPosition(b_emb->getX()+20, b_emb->getY());
        w_emb   ->setPosition(w_emb->getX()+20, w_emb->getY());
    }

    // event manager
    while (window->pollEvent(event))
    {
        
        switch (event.type)
        {
            // close the window if the player clicks close
            case sf::Event::Closed:
            {
                window->close();
                break;
            }

            case sf::Event::MouseButtonReleased: {
                
                // if wizard is clicked, update the players stats to wiz's
                if (s_wiz->checkCollision(window))
                {
                    // for rendering
                    choice = 1;

                    // sprites, GUI, ID
                    player ->setCharacter(spr_wiz,1);
                    player ->setGUI(game->getPath()->s_wiz_gui);

                    // stats
                    player ->setHealth(65);
                    player ->setArmour(10);
                    player ->setPower(30);
                    player ->setPowerBuffer(30);
                    
                    break;
                }

                // for paladin
                if (s_pal->checkCollision(window))
                {
                    // for rendering
                    choice = 2;

                    // sprites, GUI , ID
                    player->setCharacter(spr_pal,2);
                    player->setGUI(game->getPath()->s_pal_gui);

                    // stats
                    player->setHealth(100);
                    player->setArmour(50);
                    player->setPower(15);
                    player->setPowerBuffer(15);
                    
                    break;
                }

                // for ninja
                if (s_nin->checkCollision(window))
                {
                    // for rendering
                    choice = 3;

                    // sprites, GUI, ID
                    player->setCharacter(spr_nin,3);
                    player->setGUI(game->getPath()->s_nin_gui);

                    // stats
                    player->setHealth(75);
                    player->setArmour(25);
                    player->setPower(20);
                    player->setPowerBuffer(20);
                    
                    break;
                }

                // if player clicks, embark button, save the stats to the player
                if (s_emb->checkCollision(window))
                {
                    // update the game state to swtich to the map
                    game->setState(new MapState(game, player));
                    break;
                }
                break;
            }

            default:
                break; 
            
        }
    }

    // update the texture rectangles for each dynamic sprite
    // they only idle so repeat the animation
    // set death to false as they can only idle
    spr_wiz->animation(true,false);
    spr_pal->animation(true,false);
    spr_nin->animation(true,false);
}

void PickState::render(sf::RenderWindow* window)
{
    // clear the window
    window   ->clear(sf::Color::White);

    // splash screen
    splash->draw(window);

    // render the drawables inside the render window

        // depending on choice, draw the corresponding dynamic sprite and character stats
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

        // button sprites and text
        s_wiz->draw(window);
        b_wiz->draw(window);
        w_wiz->draw(window);

        s_pal->draw(window);
        b_pal->draw(window);
        w_pal->draw(window);

        s_nin->draw(window);
        b_nin->draw(window);
        w_nin->draw(window);

        s_emb->draw(window);
        b_emb->draw(window);
        w_emb->draw(window);

        // prompt
        b_prompt->draw(window);
        w_prompt->draw(window);    
    
    // display the drawables inside the render window
    window   ->display();
}
