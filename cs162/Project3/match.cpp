#include "match.hpp"

Match::Match(Character* char1, Character* char2) { 

    fighter.reserve(2);
    fighter[0] = char1;
    fighter[1] = char2;

}

Match::~Match() {

    delete fighter[0];
    delete fighter[1];
    fighter.clear();

}

void Match::setRounds(int numRounds) {
    rounds = numRounds;
}

int Match::getRound(){
    return roundCounter;
}

int Match::getRoundLimit() {
    return rounds;
}

bool Match::oneRound() {

    std::cout << "[***********]Round #" << roundCounter + 1 << "[***********]" << std::endl;

    /***************************************************************
     * PLAYER 1 ATTACK
     * ************************************************************/

    std::cout << "Player 1 Name: " << fighter[0] -> getName() << std::endl;
    std::cout << "Player 1 Strength: " << fighter[0] -> getStrength() << std::endl;
    std::cout << "Player 1 Armor: " << fighter[0] -> getArmor() << std::endl;

    std::cout << "Player 1 Attack: " << std::endl;
    fighter[0] -> attack(fighterOneAttack);
    std::cout << "Player 1 Total Attack: " << fighterOneAttack[0];


    if (fighterOneAttack[1] == -5 || fighterOneAttack[1] == -10)
        std::cout << ", plus a special ability!!!";

    std::cout << std::endl;

    /***************************************************************
     * PLAYER 2 ATTACK
     * ************************************************************/
    std::cout << "Player 2 Class: " << fighter[1] -> getType() << std::endl;
    std::cout << "Player 2 Name: " << fighter[1] -> getName()  << std::endl;
    std::cout << "Player 2 Strength: " << fighter[1] -> getStrength() << std::endl;
    std::cout << "Player 2 Armor: " << fighter[1] -> getArmor() << std::endl;

    std::cout << "Player 2 Attack: " << std::endl;
    fighter[1] -> attack(fighterTwoAttack);
    std::cout << "Player 2 Total Attack: " << fighterTwoAttack[0];

    if (fighterTwoAttack[1] == -5 || fighterTwoAttack[1] == -10)
        std::cout << ", plus a special ability!!!";

    std::cout << std::endl;

    /***************************************************************
     * CHECKING FOR SPECIAL CASES:
     * Vampire vs Medusa
     * Medusa's special ability
     * Vampire's special ability
     * ************************************************************/
    if (fighterOneAttack[1] == -10 && fighterTwoAttack[1] == -5) {
        std::cout << "Vampire's charm cancels out Medusa's glare!" << std::endl;
        std::cout << "No one takes damage this round." << std::endl;
        fighterOneAttack[0] = 0;
        fighterTwoAttack[0] = 0;
    }

    if (fighterOneAttack[1] == -5 && fighterTwoAttack[1] == -10) {
        std::cout << "Vampire's charm cancels out Medusa's glare!" << std::endl;
        std::cout << "No one takes damage this round." << std::endl;
        fighterOneAttack[0] = 0;
        fighterTwoAttack[0] = 0;
    }

    if (fighterOneAttack[1] == -5) {
        std::cout << fighter[1] -> getName() << " has been turned to stone by Medusa."  << std::endl;
    }

    if (fighterTwoAttack[1] == -5) {
        std::cout << fighter[0] -> getName() << " has been turned to stone by Medusa." << std::endl;
        }

    if (fighterOneAttack[1] == -10) {
        fighterTwoAttack[0] = 0;
    }

    if (fighterTwoAttack[1] == -10) {
        fighterOneAttack[0] = 0;
    }

    /***************************************************************
     * PLAYER 2 DEFENSE
     * ************************************************************/
    std::cout << "Player 2 Defense" << std::endl;
        fighter[1] -> defend(fighterOneAttack);
   
        //death check
        if (fighter[1] -> getStrength() <= 0) {
            std::cout << fighter[1] -> getName() << " has perished. " << fighter[0] -> getName() << " wins!" << std::endl;
            return false;
        }

    /***************************************************************
     * PLAYER 1 DEFENSE
     * ************************************************************/
        std::cout << "Player 1 Defense" << std::endl;
        fighter[0] -> defend(fighterTwoAttack);
       
        //death check
        if (fighter[0] -> getStrength() <= 0) {
            std::cout << fighter[0] -> getName() << " has perished. " << fighter[1] -> getName() << " wins!" << std::endl;
            return false;
            }

        //increment the round counter
    roundCounter++;

}

void Match::resetRoundCounter() {
    roundCounter = 0;
}
