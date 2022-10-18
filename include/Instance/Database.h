#ifndef DATABASE_H
#define DATABASE_H

#include <fstream>

#pragma once

#include <iostream>

class Database {
    private:
        //pass
    public:
        // Create/Restore original player stats in text file. 
        void createStats();

        // Return multidimensional array of stats
        int* returnStats(); 

        // Update text file and return player stats.
        // "player_pick" is either 1 (Mage), 2 (Paladin), 3 (Ninja). 
        void updateStats(int* updated_array[3][3]);
};

#endif