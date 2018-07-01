#include "character.hpp"

Character::Character(std::string n, int atkRolls, int atkSides, int defRolls, int defSides, int arm, int str, std::string type, int maxStr) {
    name = n;
    attackDieRolls = atkRolls;
    attackDieSides = atkSides;
    defenseDieRolls = defRolls;
    defenseDieSides = defSides;
    armor = arm;
    strength = str;
    charType = type;
    maxStrength = maxStr;
}

int Character::attack() {
     std::uniform_int_distribution<int> standardAttack(1, attackDieSides);
    
     //reset attackArray values
    int damageOut = 0;
    int roll = 0;
    int rollCounter = 1;

    //Roll attack die; output roll result; add to total attack value
    for (int i = 0; i < attackDieRolls; i++) {
        roll = standardAttack(Twister);
        std::cout << "Roll #" << rollCounter << ": " << roll << std::endl;
        rollCounter++;
        damageOut += roll;
    }
    return damageOut;
}

int Character::defend(int atk) {
    std::uniform_int_distribution<int> standardDefense(1, defenseDieSides);

    int totalDefense = 0;
 
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

void Character::restoreHealth() {
    if (strength * 1.5 > maxStrength)
        strength = maxStrength;
    else
        strength = strength * 1.5;
}
