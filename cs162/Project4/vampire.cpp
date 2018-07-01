#include "vampire.hpp"

Vampire::Vampire(std::string n) : Character(n, 1, 12, 1, 6, 1, 18, "Vampire", 18) {};

int Vampire::defend(int atk) {
    std::uniform_int_distribution<int> standardDefense(1, defenseDieSides);
    std::uniform_int_distribution<int> charm(1, 2);
    int totalDefense = 0;

    //Implementing charm special ability
    int charmChance = charm(Twister);

    //50% chance of invoking special ability
    if (charmChance == 2) {
        std::cout << "Vampire has charmed its opponent! Vampire takes no damage" << std::endl;
        atk = 0;
    }

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
        if (totalDefense + armor < atk) { 
            damageTaken = abs((totalDefense + armor - atk));
           strength -= damageTaken; 
        }

        std::cout << "Total Defense: " << totalDefense << std::endl;
        std::cout << "Damage Taken: " << damageTaken << std::endl;
        std::cout << name << "'s end-of-round strength is: " << strength << std::endl;
}

