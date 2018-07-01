#include "character.hpp"

Character::Character(std::string n, int atkRolls, int atkSides, int defRolls, int defSides, int arm, int str, std::string type) {
    name = n;
    attackDieRolls = atkRolls;
    attackDieSides = atkSides;
    defenseDieRolls = defRolls;
    defenseDieSides = defSides;
    armor = arm;
    strength = str;
    charType = type;
}

void Character::attack(int* attackArray) {
     std::uniform_int_distribution<int> standardAttack(1, attackDieSides);
    
     //reset attackArray values
    attackArray[0] = 0;
    attackArray[1] = 0;
    int roll = 0;
    int rollCounter = 1;

    std::cout << charType << "'s Attack" << std::endl;
    //Roll attack die; output roll result; add to total attack value
    for (int i = 0; i < attackDieRolls; i++) {
        roll = standardAttack(Twister);
        std::cout << "Roll #" << rollCounter << ": " << roll << std::endl;
        rollCounter++;
        attackArray[0] += roll;
    }
}

void Character::defend(int* attackArray) {
    std::uniform_int_distribution<int> standardDefense(1, defenseDieSides);

    int totalDefense = 0;
 
    if (attackArray[1] == -10) 
        std::cout << name << " cannot resist the Vampire's charm. Skipping attack." << std::endl;
        
    if (attackArray[1] == -5)
            std::cout << name << " will be turned to stone--unless it can cast charm for its attack!" << std::endl;

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

std::string Character::getName() {
    return name;
}

int Character::getStrength() {
    return strength;
}

int Character::getArmor() {
    return armor;
}

std::string Character::getType() {
    return charType;
}

void Character::death() {
    strength = 0;
}

void Character::skipNextAttack() {
    getsAttack = false;
}

bool Character::canAttack() {
    return getsAttack;
}
