#include "bluemen.hpp"

BlueMen::BlueMen(std::string n) : Character(n, 2, 10, 3, 6, 3, 12, "Blue Men", 12) {};

int BlueMen::defend(int attack) {
    std::uniform_int_distribution<int> standardDefense(1, defenseDieSides);

    int totalDefense = 0;
    mobStrength();
 
    //Roll for each defense die; record and print result; add to defense total

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
    if (totalDefense + armor < attack) { 
        damageTaken = abs((totalDefense + armor - attack));
        strength -= damageTaken; 
    }

    std::cout << "Total Defense: " << totalDefense << std::endl;
    std::cout << "Damage Taken: " << damageTaken << std::endl;
    std::cout << name << "'s end-of-round strength is: " << strength << std::endl;
}

void BlueMen::mobStrength() {
    if (strength <= 8)
        defenseDieRolls = 2;
    else if (strength <= 4)
        defenseDieRolls = 1;
}
