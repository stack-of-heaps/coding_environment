#include "vampire.hpp"

Vampire::Vampire(std::string n) : Character(n, 1, 12, 1, 6, 1, 18, "Vampire") {};

void Vampire::attack(int* attackArray) {
    std::uniform_int_distribution<int> standardAttack(1, attackDieSides);
    std::uniform_int_distribution<int> charmAttack(1, 2);

    //reset attackArray values
    attackArray[0] = 0;
    attackArray[1] = 0;
    int charmChance = charmAttack(Twister);

    //set charm effect
    if (charmChance == 2) 
        attackArray[1] = -10;

    int totalAttack = 0;
    int roll = 0;

    //Roll attack die; output roll result; add to total attack value
    for (int i = 0; i < attackDieRolls; i++) {
        roll = standardAttack(Twister);
        std::cout << "First roll: " << roll << std::endl;
        attackArray[0] += roll;
    }
}

void Vampire::defend(int* attackArray) {
    std::uniform_int_distribution<int> standardDefense(1, defenseDieSides);

    int totalDefense = 0;
 
    if (attackArray[1] == -10) 
        std::cout << name << " cannot resist the Vampire's charm. Skipping attack." << std::endl;
        

    else if (attackArray[1] == -5)
            std::cout << name << " will be turned to stone--unless it can cast charm for its attack!" << std::endl;

    else {
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
        if (totalDefense + armor < attackArray[0]) { 
            damageTaken = abs((totalDefense + armor - attackArray[0]));
           strength -= damageTaken; 
        }

        std::cout << "Total Defense: " << totalDefense << std::endl;
        std::cout << "Damage Taken: " << damageTaken << std::endl;
        std::cout << name << "'s end-of-round strength is: " << strength << std::endl;
    }
}
