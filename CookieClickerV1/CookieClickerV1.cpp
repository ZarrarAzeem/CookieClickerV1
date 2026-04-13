#include <iostream>

void mainMenu();
void clickMenu();
void upgradeMenu();

int main()
{
    std::cout << "*** Cookie Clicker Version 1.0 ***\n";
    std::cout << "   (This is my first ever game)    \n\n\n";
    std::cout << "How to play:      - Collect cookies to earn cash\n                  - Buy upgrades to make money faster\n                  - Get diabetes from all the cookies =)\n\n\n";

    bool game = true;
    unsigned int cash = 0;

    int cashMultiplier = 1;
    int cashMultiplierUpgradeCost = 10;
    int cashMultiplierUpgradeLevel = 1;

    int cookiesPerClick = 1;
    int cookiesPerClickUpgradeCost = 25;
    int cookiesPerClickUpgradeLevel = 1;

    double critChance = 0.05;
    int critChanceUpgradeCost = 20;
    int critChanceUpgradeLevel = 1;

    while (game) {
        mainMenu();

        int mainMenuChoice;
        std::cin >> mainMenuChoice;

        if (mainMenuChoice == 99) {
            game = false;
        }
        else if (mainMenuChoice == 1) {
            // clicking logic
        }
        else if (mainMenuChoice == 2) {
            char upgradeMenuChoice = 0;

            upgradeMenu();
            std::cin >> upgradeMenuChoice;

            if (upgradeMenuChoice == '1') {
                std::cout << "Upgrade Cash Multiplier to level " << cashMultiplierUpgradeLevel + 1 << "?\n";
                std::cout << "$" << cashMultiplierUpgradeCost << " Y|N\n\n";
                std::cout << "Cash: $" << cash << std::endl;

                char option = '\0';
                std::cin >> option;

                if (option == 'Y' || option == 'y') {
                    if (cash < cashMultiplierUpgradeCost) {
                        std::cout << "Sorry, you don't have enough money. Click more cookies\n";
                    }
                    else {
                        cash -= cashMultiplierUpgradeCost;
                        cashMultiplier *= 2;
                        cashMultiplierUpgradeCost *= 2.9;
                        cashMultiplierUpgradeLevel++;
                    }
                }
            }
            else if (upgradeMenuChoice == '2') {

            }
            else if (upgradeMenuChoice == '3') {

            }
            else {

            }
        }
        // if incorrect input, prompt again
        else
            mainMenu();
    }

    return 0;
}

void mainMenu() {
    std::cout << "\nPlease pick an option from the menu:          1 - Click Cookies\n                                              2 - Upgrade\n                                              99 - Quit Game\n\n";
}

void clickMenu() {

}

void upgradeMenu() {
    std::cout << "\n*Please Select an Upgrade*\n";
    std::cout << "1 - Cash Multiplier: Earn more $ per cookie\n";
    std::cout << "2 - Cookies per Click: Earn more cookies per click\n";
    std::cout << "3 - Baker's Special: Chance for a cookie to be worth 3x\n\n";
    std::cout << "Any key - Return to Main Menu\n\n";
}