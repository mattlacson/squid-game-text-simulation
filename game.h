#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <unistd.h>
#include <string>
#include <sstream>  

using namespace std;

// Declare global variables
extern int health;
extern long long money;  // Ensure money is long long everywhere
extern int level;
extern bool rivalAlive;
extern int reputation;
extern string playerName;
extern int playerNumber;

// Function Prototypes
void intro();
void gameOver();
void determineEnding();
void meetSpecialCharacter();  // Declare meetSpecialCharacter for use in squidgame.cpp
bool redLightGreenLight();
bool dalgonaCandy();
bool tugOfWar();
bool marbles();
bool glassBridge();
bool squidGame();
void rivalInteraction();
void randomEvent();
string formatMoney(long long amount);

// Inline function for cinematic typing effect
inline void typeText(string text) {
    for (char c : text) {
        cout << c << flush;
        usleep(15000);
    }
    cout << endl;
}

// Function to format money with commas (₩1,000,000 instead of ₩1000000)
inline string formatMoney(long long amount) {
    string num = to_string(amount);
    int insertPosition = num.length() - 3;

    // Insert commas every 3 digits
    while (insertPosition > 0) {
        num.insert(insertPosition, ",");
        insertPosition -= 3;
    }

    return num + " Won";  // Append " Won" after formatting
}


#endif
