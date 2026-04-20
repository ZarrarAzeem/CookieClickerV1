#include <iostream>
#include <conio.h>
#include <random>
#include <fstream>

void mainMenu();
void clickMenu();
void upgradeMenu();

int cashPerClick(int cashMultiplier, int cookiesPerClick);

void saveGame(int cash,
    int cashMultiplier,
    int cashMultiplierUpgradeLevel,
    int cashMultiplierUpgradeCost,
    int cookiesPerClick,
    int cookiesPerClickUpgradeLevel,
    int cookiesPerClickUpgradeCost,
    int critChance,
    int critChanceUpgradeLevel,
    int critChanceUpgradeCost);

int main()
{
    std::cout << "*** Cookie Clicker Version 1.0 ***\n";
    std::cout << "   (This is my first ever game)    \n\n\n";
    std::cout << "How to play:      - Collect cookies to earn cash\n                  - Buy upgrades to make money faster\n                  - Get diabetes from all the cookies =)\n\n\n";

    int cash = 0;

    int cashMultiplier = 1;
    int cashMultiplierUpgradeLevel = 1;
    int cashMultiplierUpgradeCost = 25;

    int cookiesPerClick = 1;
    int cookiesPerClickUpgradeLevel = 1;
    int cookiesPerClickUpgradeCost = 40;

    float critChance = 0.01;
    int critChanceUpgradeLevel = 1;
    int critChanceUpgradeCost = 50;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distribution(0.00, 1.00);

    // Start Menu (choose new game or save game)
    while (true) {
        int startMenuChoice = 0;
        std::cout << "1 - Start New Game\n" << "2 - Continue Saved Game\n\n";
        std::cin >> startMenuChoice;

        if (startMenuChoice == 1) {
            std::ofstream saveFile("saveGame.txt");
            saveFile.close();

            break;
        }
        else if (startMenuChoice == 2) {
            std::ifstream saveFile("saveGame.txt");

            if (!saveFile.is_open()) {
                std::cout << "Save File Could Not be Opened.\n\n";
                continue;
            }
            else {
                std::cout << "Save Game Loaded.\n\n";

                std::string name = "\0";
                float value = 0;

                while (saveFile >> name >> value) {
                    if (name == "cash")
                        cash = value;
                    else if (name == "cashMultiplier")
                        cashMultiplier = value;
                    else if (name == "cashMultiplierUpgradeLevel")
                        cashMultiplierUpgradeLevel = value;
                    else if (name == "cashMultiplierUpgradeCost")
                        cashMultiplierUpgradeCost = value;
                    else if (name == "cookiesPerClick")
                        cookiesPerClick = value;
                    else if (name == "cookiesPerClickUpgradeLevel")
                        cookiesPerClickUpgradeLevel = value;
                    else if (name == "cookiesPerClickUpgradeCost")
                        cookiesPerClickUpgradeCost = value;
                    else if (name == "critChance")
                        critChance = value;
                    else if (name == "critChanceUpgradeLevel")
                        critChanceUpgradeLevel = value;
                    else if (name == "critChanceUpgradeCost")
                        critChanceUpgradeCost = value;
                }

                std::cout << "Cash: $" << cash << '\n';
                std::cout << "Cash Multiplier Level: " << cashMultiplierUpgradeLevel << '\n';
                std::cout << "Cookies Per Click Level: " << cookiesPerClickUpgradeLevel << '\n';
                std::cout << "Baker's Special Level: " << critChanceUpgradeLevel << '\n' << '\n';

                break;
            }
        }
        else {
            std::cout << "Invalid Choice. Please Select 1 or 2.\n\n";
        }
    }

    // Main Game Loop
    while (true) {
        mainMenu();

        int mainMenuChoice;
        std::cin >> mainMenuChoice;

        // Clicking Interface
        if (mainMenuChoice == 1) {
            clickMenu();

            bool clickLoop = true;
            while (clickLoop) {
                double critRoll = distribution(gen);

                int key = _getch();
                if (key == 32) {
                    if (critRoll <= critChance) {
                        std::cout << "Baker's Special!!! You got $" << 3 * cashPerClick(cashMultiplier, cookiesPerClick) << '\n';
                        cash = cash + 3 * cashPerClick(cashMultiplier, cookiesPerClick);
                    }
                    else {
                        std::cout << "You got $" << cashPerClick(cashMultiplier, cookiesPerClick) << '\n';
                        cash = cash + cashPerClick(cashMultiplier, cookiesPerClick);
                    }
                    
                }
                else
                    clickLoop = false;
            }

            std::cout << "\nCash: $" << cash << '\n';
        }
        // Upgrade Menu
        else if (mainMenuChoice == 2) { 
            char upgradeMenuChoice = 0;

            upgradeMenu();
            std::cin >> upgradeMenuChoice;

            // Cash Multiplier
            if (upgradeMenuChoice == '1') {
                std::cout << "Upgrade Cash Multiplier to level " << cashMultiplierUpgradeLevel + 1 << "?\n";
                std::cout << "$" << cashMultiplierUpgradeCost << " Y|N\n\n";
                std::cout << "Cash: $" << cash << '\n';

                char option = '\0';
                std::cin >> option;

                if (option == 'Y' || option == 'y') {
                    if (cash < cashMultiplierUpgradeCost) {
                        std::cout << "Sorry, you don't have enough money. Click more cookies\n";
                    }
                    else {
                        cash -= cashMultiplierUpgradeCost;
                        cashMultiplier *= 4;
                        cashMultiplierUpgradeCost *= 23;
                        cashMultiplierUpgradeLevel++;

                        std::cout << "Cash Multiplier Upgraded to level " << cashMultiplierUpgradeLevel << '\n';
                        std::cout << "Cash: $" << cash << '\n';
                    }
                }
            }
            // Cookies per Click
            else if (upgradeMenuChoice == '2') {
                std::cout << "Upgrade Cookies per Click to level " << cookiesPerClickUpgradeLevel + 1 << "?\n";
                std::cout << "$" << cookiesPerClickUpgradeCost << " Y|N\n\n";
                std::cout << "Cash: $" << cash << '\n';

                char option = '\0';
                std::cin >> option;

                if (option == 'Y' || option == 'y') {
                    if (cash < cookiesPerClickUpgradeCost) {
                        std::cout << "Sorry, you don't have enough money. Click more cookies\n";
                    }
                    else {
                        cash -= cookiesPerClickUpgradeCost;
                        cookiesPerClick *= 2;
                        cookiesPerClickUpgradeCost *= 37;
                        cookiesPerClickUpgradeLevel++;

                        std::cout << "Cookies per Click Upgraded to level " << cookiesPerClickUpgradeLevel << '\n';
                        std::cout << "Cash: $" << cash << '\n';
                    }
                }
            }
            // Baker's Special
            else if (upgradeMenuChoice == '3') {
                std::cout << "Upgrade Baker's Special to level " << critChanceUpgradeLevel + 1 << "?\n";
                std::cout << "$" << critChanceUpgradeCost << " Y|N\n\n";
                std::cout << "Cash: $" << cash << '\n';

                char option = '\0';
                std::cin >> option;

                if (option == 'Y' || option == 'y') {
                    if (cash < critChanceUpgradeCost) {
                        std::cout << "Sorry, you don't have enough money. Click more cookies\n";
                    }
                    else {
                        cash -= critChanceUpgradeCost;
                        critChance += 0.015;
                        critChanceUpgradeCost *= 49;
                        critChanceUpgradeLevel++;

                        std::cout << "Baker's Special Upgraded to level " << critChanceUpgradeLevel << '\n';
                        std::cout << "Cash: $" << cash << '\n';
                    }
                }
            }
        }
        // if incorrect input, prompt again
        else if (mainMenuChoice == 8) {
            std::cout << "Saving Game...\n";
            saveGame(cash,
                cashMultiplier,
                cashMultiplierUpgradeLevel,
                cashMultiplierUpgradeCost,
                cookiesPerClick,
                cookiesPerClickUpgradeLevel,
                cookiesPerClickUpgradeCost,
                critChance,
                critChanceUpgradeLevel,
                critChanceUpgradeCost);
            break;
        }
        else if (mainMenuChoice == 9) {
            std::cout << "See you later!";
            break;
        }
        else
            continue;
    }

    return 0;
}

void mainMenu() {
    std::cout << "\nPlease pick an option from the menu:  \t1 - Click Cookies\n      \t\t\t\t\t2 - Upgrade\n\n      \t\t\t\t\t8 - Save and Quit\n      \t\t\t\t\t9 - Quit Without Saving\n\n";
}

void clickMenu() {
    std::cout << "\nPress * Spacebar * to click\n";
    std::cout << "\nPress any other key to exit to main menu\n";
}

void upgradeMenu() {
    std::cout << "\n*Please Select an Upgrade*\n";
    std::cout << "1 - Cash Multiplier: Earn more $ per cookie\n";
    std::cout << "2 - Cookies per Click: Earn more cookies per click\n";
    std::cout << "3 - Baker's Special: Chance for a cookie to be worth 3x\n\n";
    std::cout << "Any key - Return to Main Menu\n\n";
}

int cashPerClick(int cashMultiplier, int cookiesPerClick) {
    int baseIncome = 1;

    baseIncome = baseIncome * cashMultiplier;
    baseIncome = baseIncome * cookiesPerClick;

    return baseIncome;
}

void saveGame(int cash,
    int cashMultiplier,
    int cashMultiplierUpgradeLevel,
    int cashMultiplierUpgradeCost,
    int cookiesPerClick,
    int cookiesPerClickUpgradeLevel,
    int cookiesPerClickUpgradeCost,
    int critChance,
    int critChanceUpgradeLevel,
    int critChanceUpgradeCost) {

    std::ofstream saveFile("saveGame.txt");

    if (!saveFile.is_open()) {
        std::cout << "Save File could not be opened.\n\n";
        return;
    }

    saveFile << "cash " << cash << '\n';
    saveFile << "cashMultiplierUpgradeLevel " << cashMultiplierUpgradeLevel << '\n';
    saveFile << "cashMultiplierUpgradeCost " << cashMultiplierUpgradeCost << '\n';
    saveFile << "cookiesPerClick " << cookiesPerClick << '\n';
    saveFile << "cookiesPerClickUpgradeLevel " << cookiesPerClickUpgradeLevel << '\n';
    saveFile << "cookiesPerClickUpgradeCost " << cookiesPerClickUpgradeCost << '\n';
    saveFile << "critChance " << critChance << '\n';
    saveFile << "critChanceUpgradeLevel " << critChanceUpgradeLevel << '\n';
    saveFile << "critChanceUpgradeCost " << critChanceUpgradeCost << '\n';

    saveFile.close();

    std::cout << "Game Saved. See you later!";
}

// add save game/quit without saving to main menu logic
// add _getch() for all key presses so game is more streamlined