#include "Game.h"
#include <sqlite3.h>
#include <iostream>

static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s: ", (const char*)data);
   
   for(i = 0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   
   printf("\n");
   return 0;
}

Game::Game(int width, int height)
{
    this->window = new sf::RenderWindow(sf::VideoMode(width,height),"Test");
    this->currentState = new MenuState(this);
    this->window->setFramerateLimit(20);

    p_idle.x
}

Game::~Game()
{

}

void Game::run()
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    const char *sql;
    const char* data = "Callback function called";

    rc = sqlite3_open("animations.db", &db);

    /* Create SQL statement */
     sql = "SELECT Frames FROM Animations WHERE Animation = 'Attack 2'";


    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

    std::cout << rc << std::endl;
   
    sqlite3_close(db);

/*     while (window->isOpen())
    {
        this->currentState->update(window);
        this->currentState->render(window);
    } */

}

void Game::setState(State* newState)
{
    currentState = newState;
}

 