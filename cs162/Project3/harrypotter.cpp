#include "harrypotter.hpp"

HarryPotter::HarryPotter(std::string n) : Character(n, 2, 6, 2, 6, 0, 10, "Harry Potter") {
    lifeCount = 1;
};

/*
int HarryPotter::attack() {
    std::uniform_int_distribution<int> standardAttack(1, attackDieSides);

    int totalAttack = 0;

    for (int i = 0; i < attackDieRolls; i++)
        totalAttack += standardAttack(Twister);

    std::cout << "HarryPotter attacks for ";
    return totalAttack;
}

*/

void HarryPotter::defend(int* attackArray) {
    std::uniform_int_distribution<int> standardDefense(1, defenseDieSides);

    int totalDefense = 0;
 
    if (attackArray[1] == -10) 
        std::cout << name << " cannot resist the Vampire's charm. Skipping attack." << std::endl;
        
//check for glare
    if (attackArray[1] == -5) {
        if (lifeCount == 0) {
            std::cout << "Harry Potter has run out of lives. He dead." << std::endl;
            death();
            }
        else {
            std::cout << "Harry Potter... rise from the ashes... to fight again!" << std::endl;
            lifeCount--;
            attackArray[0] = 0;
            attackArray[1] = 0;
        }
    }

    else {
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
        if (totalDefense + armor < attackArray[0]) { 
            damageTaken = abs((totalDefense + armor - attackArray[0]));
            strength -= damageTaken; 
        }

        if ((strength <= 0) && (lifeCount > 0)) {
            std::cout << "Harry Potter... rise from the ashes... to fight again!" << std::endl;
                lifeCount--;
                strength = 10;
        }

    std::cout << "Total Defense: " << totalDefense << std::endl;
    std::cout << "Damage Taken: " << damageTaken << std::endl;
    std::cout << name << "'s end-of-round strength is: " << strength << std::endl;
    }
}
