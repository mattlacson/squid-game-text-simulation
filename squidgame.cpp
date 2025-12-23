#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "game.h"
#include "save.h"
#include "leaderboard.h"
#include <cstdlib>  // Required for system() command

using namespace std;

// Global variables defined in game.cpp (Declared in game.h)
extern int health;
bool hasSave = loadGame(health, money, level);  // money is now long long
extern int level;
extern bool rivalAlive;
extern int reputation;
extern string playerName;
extern int playerNumber;
int timesDisagreed = 0; 

void checkSecretEnding() {
    if (timesDisagreed == 5) {
        typeText("\nThe Front Man appears...");
        typeText("He is impressed by your refusal to participate.");
        typeText("Instead of eliminating you, he offers you a position among the VIPs.");
        typeText("You have escaped Squid Game as a VIP.");
        exit(0);
    }
}

void postGameStats() {
    cout << "\n========================================\n";
    cout << "           GAME SUMMARY\n";
    cout << "========================================\n";
    cout << "Total Money Earned: " << (money)<<" WON" << endl;
    cout << "Games Survived: " << level - 1 << endl;
    cout << "Reputation Score: " << reputation << endl;
    cout << "Final Player Number: #" << playerNumber << endl;
    cout << "========================================\n";
}


int main() {
    srand(time(0));

    bool hasSave = loadGame(health, money, level);

    if (hasSave) {
        int choice;
        while (true) {
            cout << "\nA saved game was found.\n";
            cout << "Do you want to continue from where you left off? (1: Yes, 2: No): ";
            cin >> choice;

            if (cin.fail() || (choice != 1 && choice != 2)) {
                cout << "Invalid choice. Enter 1 to continue or 2 to start a new game.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            } else {
                break;
            }
        }

        if (choice == 1) {
            cout << "\nLoaded previous game!\n";
        } else {
            health = 3;
            money = 0;
            level = 1;
            saveGame(health, money, level);
            cout << "\nStarting a new game...\n";
            
            cout << "Enter your name: ";
            cin >> playerName;
            playerNumber = rand() % 401 + 100;
            cout << "\nWelcome, " << playerName << ". You have been assigned Player #" << playerNumber << ".\n";

            typeText("\n========================================");
            typeText("         SQUID GAME TERMS OF SERVICE");
            typeText("========================================");
            typeText("By agreeing to participate in Squid Game, you acknowledge and accept");
            typeText("the following terms:");
            typeText("- All players will compete in a series of children's games.");
            typeText("- Failure to complete a game will result in immediate elimination.");
            typeText("- Once the games begin, withdrawal is not permitted.");
            typeText("- The final player remaining will receive a grand cash prize.");
            typeText("\nDo you wish to proceed?");

            string agreement;
            while (true) {
                cout << "Type 'agree' to participate or 'disagree' to decline: ";
                cin >> agreement;

                if (agreement == "agree") {
                    typeText("\nYou have agreed to participate. Let the games begin!");

                    // Play the Squid Game theme song in the background
    #ifdef _WIN32
        system("start /min squidgametheme.mp3");  // Windows command
    #elif __APPLE__
        system("afplay squidgametheme.mp3 &");   // macOS command
    #elif __linux__
        system("mpg123 -q squidgametheme.mp3 &"); // Linux command
    #endif
                    break;
                } else if (agreement == "disagree") {
                    typeText("\nYou have refused to participate. The game will now end.");
                    timesDisagreed++;
                    checkSecretEnding();
                    return 0;
                } else {
                    cout << "Invalid input. Please type 'agree' or 'disagree'.\n";
                }
            }
        }
    }

    intro();

    if (level == 1) {
        if (!redLightGreenLight()) { gameOver(); postGameStats(); return 0; }
        level++;
        meetSpecialCharacter();
        saveGame(health, money, level);
    }
    if (level == 2) {
        if (!dalgonaCandy()) { gameOver(); postGameStats(); return 0; }
        level++;
        meetSpecialCharacter();
        saveGame(health, money, level);
    }
    if (level == 3) {
        if (!tugOfWar()) { gameOver(); postGameStats(); return 0; }
        level++;
        meetSpecialCharacter();
        saveGame(health, money, level);
    }
    if (level == 4) {
        if (!marbles()) { gameOver(); postGameStats(); return 0; }
        level++;
        meetSpecialCharacter();
        saveGame(health, money, level);
    }
    if (level == 5) {
        if (!glassBridge()) { gameOver(); postGameStats(); return 0; }
        level++;
        meetSpecialCharacter();
        saveGame(health, money, level);
    }
    if (level == 6) {
        if (!squidGame()) { gameOver(); postGameStats(); return 0; }
    }

    determineEnding();
    saveHighScore(playerName, money);
    postGameStats();
    return 0;
}
