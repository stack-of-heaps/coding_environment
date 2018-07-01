#include "harrypotter.hpp"

HarryPotter::HarryPotter(std::string n) : Character(n, 2, 6, 2, 6, 0, 10, "Harry Potter", 10) {
    lifeCount = 1;
};

int HarryPotter::defend(int atk) {
    std::uniform_int_distribution<int> standardDefense(1, defenseDieSides);

    int totalDefense = 0;
 
    int roll = 0;
    int rollCounter = 1;
    for (int i = 0; i < defenseDieRolls; i++) {
        roll = standardDefense(Twister);
        std::cout <<"Roll #" << rollCounter << " for defense: " << roll << std::endl;
        rollCounter++;
        totalDefense += roll;
    }

    // if attack is greater than defense rolls and armor, deduct it from strength
    int damageTaken = 0;
    if (totalDefense + armor < atk) { 
        damageTaken = abs((totalDefense + armor - atk));
        strength -= damageTaken; 
    }

    if ((strength <= 0) && (lifeCount > 0)) {
        std::cout << "Harry Potter... rise from the ashes... to fight again!" << std::endl;
            lifeCount--;
            strength = 20;
    }

    else if ((strength <= 0) && (lifeCount <= 0)) 
        std::cout << "Harry potter dead" << std::endl;

    else {
        std::cout << "Total Defense: " << totalDefense << std::endl;
        std::cout << "Damage Taken: " << damageTaken << std::endl;
        std::cout << name << "'s end-of-round strength is: " << strength << std::endl;
    }
}
