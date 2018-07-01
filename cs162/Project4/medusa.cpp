#include "medusa.hpp"


Medusa::Medusa(std::string n) : Character(n, 2, 6, 1, 6, 3, 8, "Medusa", 8) {
};

void Medusa::attack(int* attackArray) {
     std::uniform_int_distribution<int> standardAttack(1, attackDieSides);
    
    int totalAttack = 0;
    int roll = 0;
    int rollCounter = 1;

    std::cout << charType << "'s Attack" << std::endl;
    //Roll attack die; output roll result; add to total attack value
    for (int i = 0; i < attackDieRolls; i++) {
        roll = standardAttack(Twister);
        std::cout << "Roll #" << rollCounter << ": " << roll << std::endl;
        rollCounter++;
        totalAttack += roll;
    }

    //Medusa's special attack "glare." 
    if (totalAttack == 12) 
        totalAttack = 1000;
}

