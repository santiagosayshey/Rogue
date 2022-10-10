#include "State.h"

State::State(Game* game, Player* player)
{
    this->game = game; // Initialise game and player
    this->player = player;
}