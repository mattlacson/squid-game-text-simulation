#include <fstream>  // Include fstream for file handling
#include "save.h"

bool saveGame(int &health, long long &money, int &level) {
    std::ofstream file("savegame.txt");  // Use std::ofstream
    if (!file) return false;

    file << health << " " << money << " " << level;
    file.close();
    return true;
}

bool loadGame(int &health, long long &money, int &level) {
    std::ifstream file("savegame.txt");  // Use std::ifstream
    if (!file) return false;

    file >> health >> money >> level;
    file.close();
    return true;
}
