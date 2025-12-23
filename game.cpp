#include "game.h"

// Define global variables
int health = 3;
long long money = 0;  // Changed from int to long long for large amounts in Won
int level = 1;
bool rivalAlive = true;
int reputation = 0;
string playerName = "";
int playerNumber = 0;

void intro() {
    typeText("\n====================================");
    typeText("      WELCOME TO SQUID GAME       ");
    typeText("====================================");
    typeText("You must survive all games to win the grand prize!");
}

void gameOver() {
    typeText("\nGame Over. You have been eliminated.");
}

void determineEnding() {
    typeText("\nGame Over! You survived Squid Game!");
}

// Rival Interaction
void rivalInteraction() {
    cout << "\nYou notice Player #101 struggling. Do you help them? (1: Yes, 2: No): ";
    int choice;
    while (true) {
        cin >> choice;
        if (cin.fail() || (choice != 1 && choice != 2)) {
            cout << "Invalid choice. Enter 1 for Yes or 2 for No.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else {
            break;
        }
    }

    if (choice == 1) {
        typeText("You help Player #101. They thank you and promise to help you later.");
        reputation += 5;
        rivalAlive = true;
    } else {
        typeText("You ignore Player #101. They look at you with distrust.");
        reputation -= 5;
        rivalAlive = false;
    }
}

// Random Events
void randomEvent() {
    if (rand() % 10 < 8) {  // 80% chance of running a random event
        int event = rand() % 3;

        switch (event) {
            case 0:
                typeText("\nA guard searches the area but finds nothing suspicious.");
                break;
            case 1:
                typeText("\nYou find an extra 30,000,000 Won hidden under a table!");
                money += 30000000; // Earn 30,000,000 Won
                break;
            case 2:
                typeText("\nAnother player tries to steal your money but fails.");
                break;
        }
    } else {
        typeText("\nNothing unusual happens this time."); // 20% chance of no event
    }
}

void meetSpecialCharacter() {
    int character = rand() % 10;  // Increased variety of character encounters

    switch (character) {
        case 0:
            typeText("\nPlayer 001 (Oh Il-nam) shuffles toward you.");
            typeText("'Sometimes, not moving is the best move,' he whispers.");
            reputation += 3;
            break;

        case 1:
            typeText("\nPlayer 067 (Kang Sae-byeok) approaches with a cold stare.");
            typeText("'Trust no one. Especially here.'");
            typeText("Do you trust her?");
            cout << "Enter 1 for yes or 2 for no: ";
            int choice;
            cin >> choice;
            if (choice == 1) {
                typeText("\nShe sighs. 'Let's see if you survive.'");
                reputation += 5;
            } else {
                typeText("\nShe rolls her eyes and walks away.");
                reputation -= 3;
            }
            break;

        case 2:
            typeText("\nPlayer 101 (Jang Deok-su) slams his fist into his palm.");
            typeText("'You think you're tough? I run this place!'");
            typeText("Do you challenge him?");
            cout << "Enter 1 to challenge or 2 to walk away: ";
            cin >> choice;
            if (choice == 1) {
                typeText("\nHe glares at you, then smirks. 'You got guts, kid.'");
                reputation += 3;
            } else {
                typeText("\nHe laughs as you step aside. 'That's what I thought.'");
                reputation -= 2;
            }
            break;

        case 3:
            typeText("\nPlayer 218 (Cho Sang-woo) sits alone, lost in thought.");
            typeText("'Sometimes, the smartest move is the one nobody expects.'");
            typeText("Do you listen?");
            cout << "Enter 1 to listen or 2 to ignore: ";
            cin >> choice;
            if (choice == 1) {
                typeText("\nHis advice makes you think. You gain insight.");
                money += 1000000;  // Receive a tip worth 1,000,000 Won
            } else {
                typeText("\nYou ignore him and move on.");
            }
            break;

        case 4:
            typeText("\nA mysterious man in a suit approaches.");
            typeText("The Recruiter (Gong Yoo). He flips a paper in his hand.");
            typeText("'Want to play a real game?' he asks with a smirk.");
            typeText("Do you take his card?");
            cout << "Enter 1 to take it or 2 to refuse: ";
            cin >> choice;
            if (choice == 1) {
                typeText("\nYou take the card. He smiles and vanishes.");
                reputation += 10;
            } else {
                typeText("\nYou refuse. He shrugs and walks away.");
            }
            break;

        case 5:
            typeText("\nPlayer 199 (Ali Abdul) smiles warmly at you.");
            typeText("'I will always be loyal to my friends.'");
            typeText("Do you trust him?");
            cout << "Enter 1 to trust or 2 to be cautious: ";
            cin >> choice;
            if (choice == 1) {
                typeText("\nAli nods. 'Thank you, my friend.'");
                reputation += 5;
            } else {
                typeText("\nAli looks disappointed but says nothing.");
                reputation -= 2;
            }
            break;

        case 6:
            typeText("\nPlayer 212 (Han Mi-nyeo) walks up to you.");
            typeText("'I'm not just smart, I'm a survivor!'");
            typeText("She offers you an alliance. Do you accept?");
            cout << "Enter 1 for yes or 2 for no: ";
            cin >> choice;
            if (choice == 1) {
                typeText("\nShe grins. 'You wont regret this!'");
                reputation += 4;
            } else {
                typeText("\nShe scoffs. 'Your loss, loser.'");
                reputation -= 3;
            }
            break;

        case 7:
            typeText("\nPlayer 120 (Cho Hyun-ju) nudges you.");
            typeText("'If you panic, you die first. Remember that.'");
            reputation += 2;
            break;

        case 8:
            typeText("\nPlayer 007 (Park Yong-sik) adjusts his glasses.");
            typeText("'Every game has a pattern. Watch closely, and you win.'");
            typeText("Do you analyze the games more carefully?");
            cout << "Enter 1 for yes or 2 for no: ";
            cin >> choice;
            if (choice == 1) {
                typeText("\nYou start noticing small details you missed before.");
                reputation += 3;
            } else {
                typeText("\nYou ignore him. He shrugs and walks away.");
            }
            break;

        case 9:
            typeText("\nPlayer 230 (Choi Su-bong) suddenly yells.");
            typeText("\"I'M A LEGEND! THANOS!!!\"");
            typeText("Everyone turns to stare at him.");
            typeText("IM SORRY BOY! Let's team up cause I! LIKE! U!");
            cout << "Enter 1 to yell with him or 2 to stay quiet: ";
            cin >> choice;
            if (choice == 1) {
                typeText("\nYou yell, 'LETS GO!!!!'");
                typeText("The other players laugh, and you gain some respect.");
                reputation += 5;
            } else {
                typeText("\nYou ignore him. He glares at you.");
                reputation -= 3;
            }
            break;
    }
}


// Game Functions with Money Rewards
bool redLightGreenLight() {
    typeText("\nRed Light, Green Light");
    typeText("Move only when the light is green. Stop when it's red.");

    int choice;
    auto start = std::chrono::steady_clock::now();

    cout << "Press 1 to run or 2 to stop (You have 5 seconds): ";
    while (true) {
        auto now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - start).count();

        if (elapsed >= 5) {
            typeText("\nTime is up! You were caught moving too late.");
            return false;
        }

        if (cin >> choice && (choice == 1 || choice == 2)) {
            break;
        }

        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter 1 or 2: ";
    }

    int guard = rand() % 3;
    if (choice == 1 && guard == 0) {
        typeText("You were caught moving. Shot down.");
        return false;
    }

    typeText("You crossed safely.");
    money += 250000000; //Earn 2500000 won
    return true;
}

bool dalgonaCandy() {
    typeText("\nDalgona Candy Game");
    typeText("You must carefully carve out your candy shape.");

    int choice;
    while (true) {
        cout << "Choose 1 to be slow (safer) or 2 to be fast (higher risk): ";
        cin >> choice;

        if (cin.fail() || (choice != 1 && choice != 2)) {
            cout << "Invalid choice. Enter 1 for slow or 2 for fast.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else {
            break;
        }
    }

    int breakChance = (choice == 2) ? 50 : 20;
    int success = rand() % 100;

    if (success < breakChance) {
        typeText("Your candy broke. You are eliminated.");
        return false;
    }

    typeText("You successfully carved your shape.");
    money += 7000000;//Earn 7000000 won
    return true;
}

bool tugOfWar() {
    typeText("\nTug of War");
    typeText("Your team must pull harder than the opponents.");

    int strength;
    while (true) {
        cout << "Enter a number (1-10) for your pull strength: ";
        cin >> strength;

        if (cin.fail() || strength < 1 || strength > 10) {
            cout << "Invalid choice. Enter a number between 1 and 10.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else {
            break;
        }
    }

    int opponentStrength = rand() % 10 + 1;

    if (strength >= opponentStrength) {
        typeText("Your team pulled harder and won the round!");
        money += 9000000000; // Earn 9000000000 won
        reputation += 5;
        return true;
    } else {
        typeText("Your team lost the tug of war battle. You have been eliminated.");
        return false;
    }
}

bool marbles() {
    typeText("\nMarbles Game");
    typeText("You must guess if the number is even or odd to survive.");

    int choice;
    while (true) {
        cout << "Enter 0 for even, 1 for odd: ";
        cin >> choice;

        if (cin.fail() || (choice != 0 && choice != 1)) {
            cout << "Invalid choice. Enter 0 for even or 1 for odd.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else {
            break;
        }
    }

    int marble = rand() % 2;
    if (choice != marble) {
        typeText("Wrong guess. You lost all your marbles and were eliminated.");
        return false;
    }

    typeText("Correct guess! You survived the marbles game.");
    money += 1500000000;//Earn 15000000 won
    reputation += 3;
    return true;
}

bool glassBridge() {
    typeText("\nGlass Bridge");
    typeText("You must cross 6 steps. Choose left (0) or right (1).");

    int correctPattern[6] = {1, 1, 0, 1, 0, 1};

    for (int i = 0; i < 6; i++) {
        int choice;
        while (true) {
            cout << "Step " << (i + 1) << ": Choose left (0) or right (1): ";
            cin >> choice;

            if (cin.fail() || (choice != 0 && choice != 1)) {
                cout << "Invalid choice. Enter 0 for left or 1 for right.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            } else {
                break;
            }
        }

        if (choice != correctPattern[i]) {
            typeText("Wrong choice! The glass shattered beneath you, and you fell.");
            return false;
        }

        typeText("Safe! You chose correctly.");
    }

    typeText("You successfully crossed the Glass Bridge!");
    money += 3000000000;//Earn 3,000,000 Won
    reputation += 10;
    return true;
}

bool squidGame() {
    typeText("\nSquid Game Final Round");

    int choice;
    while (true) {
        cout << "Choose 1 for attack, 2 for defense: ";
        cin >> choice;

        if (cin.fail() || (choice != 1 && choice != 2)) {
            cout << "Invalid choice. Enter 1 for attack or 2 for defense.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else {
            break;
        }
    }

    int opponent = rand() % 2 + 1;

    if (choice == opponent) {
        typeText("You lost the final fight.");
        return false;
    } else {
        typeText("You won the final fight!");
        money += 50000000;// Earn 5,000,000 Won for winning Squid Game
        return true;
    }
}
