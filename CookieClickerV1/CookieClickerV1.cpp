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
    // int upgradeTier = 0;
    int cookiesPerClick = 1;

    while (game) {
        mainMenu();

        int choice;
        std::cin >> choice;
        if (choice == 99)
            game = false;
        else if (choice == 1) {
            // clicking logic
        }
        else if (choice == 2) {
            // upgrade menu logic
        }
        else
            mainMenu();
    }

    return 0;
}

void mainMenu() {
    std::cout << "Please pick an option from the menu:          1 - Click Cookies\n                                              2 - Upgrade\n                                              99 - Quit Game\n\n\n";
}

void clickMenu() {

}

void upgradeMenu() {

}