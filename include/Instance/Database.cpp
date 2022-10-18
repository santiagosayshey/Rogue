#include "Database.h"
#include <iostream>
#include <fstream> // File editing
using namespace std;

// NOTE! THE RETURN OF THE MULTIDIMENSIONAL ARRAY IS NOT WORKING. MAYBE I NEED DOUBLE POINTERS.
// I WILL BE SWITCHING TO VECTORS. 

void Database::createStats() {
    ofstream stats;
    stats.open("Stats.txt", std::ofstream::out | std::ofstream::trunc);
    // (Health, Armour, Power) x 3
    stats << "50\n0\n30\n100\n50\n15\n75\n25\n20"; 
    stats.close();
}

// Returns array of all player stats
int* Database::returnStats() {
    const int rows = 3;
    const int cols = 3;
    // Allocate multidimensional array, using the constants. 
    int (*player_stats)[rows] = new int[rows][cols];
    int counter = 0;

    //Open the file
    string op;
    fstream stats;
    stats.open("Stats.txt");
    // Split stats into the three rows
    for(int i = 0; i < 9; i++) {
        getline(stats,op);
        if(i % 3 == 0) {
            counter++;
        }
        player_stats[counter-1][i] = stoi(op);
    }
    stats.close();
    // Return multidimensional array
    return *player_stats;
}

void Database::updateStats(int* updated_array[3][3]) {
    string op;
    fstream stats;
    // Truncation option deletes file content.
    stats.open("Stats.txt", std::ofstream::out | std::ofstream::trunc);
    //Iterates through rows, and writes them to text file. 
    for(int j = 0; j < 3; j++) {
        for(int k = 0; k < 3; k++) {
            stats << updated_array[j][k] << "\n";
        }
    }
    stats.close();
}