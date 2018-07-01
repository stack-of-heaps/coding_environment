#include "barbarian.hpp"

Barbarian::Barbarian(std::string n) : Character(n, 2, 6, 2, 6, 0, 12, "Barbarian", 12) {};

/*
int Barbarian::attack() {
    std::uniform_int_distribution<int> standardAttack(1, attackDieSides);

    int totalAttack = 0;

    for (int i = 0; i < attackDieRolls; i++)
        totalAttack += standardAttack(Twister);

    std::cout << "Barbarian attacks for ";
    return totalAttack;
}

int Barbarian::defend() {
    std::uniform_int_distribution<int> standardDefense(1, defenseDieSides);

    int totalDefense = 0;

    for (int i = 0; i < attackDieRolls; i++)
        totalDefense += standardDefense(Twister);

    std::cout << "Barbarian defends for ";
    return totalDefense;
}

*/
