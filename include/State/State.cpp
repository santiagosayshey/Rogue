#include "State.h"

State::State(Game* game, Player* player)
{
    // initialise game and player
    this->game = game; 
    this->player = player;
}