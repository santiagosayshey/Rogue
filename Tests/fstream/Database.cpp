#include "Database.h"
#include <iostream>
#include <cstdio>
#include <fstream> // File editing
using namespace std;

void Database::createStats() {
    ofstream stats;
    stats.open("Stats.txt", std::ofstream::out | std::ofstream::trunc);
    // (Health, Armour, Power) x 3
    stats << "50\n0\n30\n100\n50\n15\n75\n25\n20"; 
    stats.close();
}

// Returns array of all player stats
int** Database::returnStats() {
    int** player_stats = new int* [3];
    for(int i = 0; i < 3; i++) {
        player_stats[i] = new int[3];
        for(int j = 0; j < 3; j++) {
            player_stats[i][j] = 0;
        }
    }

    // Open the file
    string op; // Output
    fstream stats;
    stats.open("Stats.txt");

    int counter = -1;
    for(int k = 0; k < 9; k++) {
        if((k%3) == 0) {
            counter++;
        }
        getline(stats,op);
        player_stats[counter][k] = stoi(op);
        cout << player_stats[counter][k] << "\n";
    }
    stats.close();

    /*
    for(int m = 0; m < 3; m++) {
        for(int n = 0; n < 3; n++) {
            cout << player_stats[m][n] << "\n";
        }
    }
    */

    //Open the file
    // string op;
    // fstream stats;
    // stats.open("Stats.txt");

    // Split stats into the three row
    // stats.close();
    // Return multidimensional array
    return player_stats;
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
            stats << j << "\n";
        }
    }
    stats.close();
}