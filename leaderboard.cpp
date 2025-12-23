#include <iostream>
#include <fstream>
#include <string>  // Add this line!
#include "leaderboard.h"

using namespace std;

void saveHighScore(string name, int money) {
    ofstream file("leaderboard.txt", ios::app);
    file << name << " " << money << endl;
    file.close();
    cout << "\nHigh Score Saved!\n";
}
