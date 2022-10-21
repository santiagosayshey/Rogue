#ifndef DATABASE_H
#define DATABASE_H

#include <fstream>

#pragma once

#include <iostream>

//Explanation: 
// Player stats are stored 3x3 multidimensional array. Player choice, 0, 1, or 2, corresponds to the rows of the matrix.
// Each row contains Health, Armour, and Power stats.
// This file can be reset, fetched for its multidimensional array, and updated/overwritten by passing in an edited array.

// CRTICIAL ISSUE: Passing in and returning these arrays isnt working. It's an issue with pointers. 


class Database {
    private:
        //pass
    public:
        // Create/Restore original player stats in text file. 
        void createStats();

        // Return multidimensional array of stats
        int** returnStats(); 

        // Update text file and return player stats.
        // "player_pick" is either 1 (Mage), 2 (Paladin), 3 (Ninja). 
        void updateStats(int** updated_array[3][3]);
};

#endif