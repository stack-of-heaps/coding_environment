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

    std::cout << "*****************Round #" << roundCounter + 1 << "*******************" << std::endl;
    attackResult = 0;
    defendResult = 0;

    if (fighter[0] -> canAttack()) {
            attackResult = fighter[0] -> attack();

            switch (attackResult) {
               
                case -99: {
                    std::cout << fighter[0] -> getName() << " has perished. " << fighter[1] -> getName() << " is the victor!" << std::endl;
                    exit (EXIT_SUCCESS);
                    fighter[0] -> death();
                    break;
                    }
                
                case -5: {
                    std::cout << "Medusa glares! Her opponent is turned to stone! Insta-death!" << std::endl;

                    fighter[1] -> death();
                    break;
                        }
               
                case -10: {
                    std::cout << "Vampire has charmed its opponent! They will not attack this round." << std::endl;
                    fighter[0] -> skipNextAttack();
                    break;
                    }

                default:
                    defendResult = fighter[1] -> defend(attackResult);
            };
        }

    if (fighter[1] -> getStrength() <= 0) {
        std::cout << fighter[0] -> getName() << " has perished. " << fighter[1] -> getName() << " wins!" << std::endl;
        exit (EXIT_SUCCESS);
    }

    else {
        attackResult = 0;
        defendResult = 0;

        if (fighter[1] -> canAttack()) {
            attackResult = fighter[1] -> attack();

            switch (attackResult) {
               
                case -99: {
                    std::cout << fighter[0] -> getName() << " has perished. " << fighter[1] -> getName() << " is the victor!" << std::endl;
                    exit (EXIT_SUCCESS);
                    fighter[0] -> death();
                    break;
                    }
                
                case -5: {
                    std::cout << "Medusa glares! Her opponent is turned to stone! Insta-death!" << std::endl;
                    fighter[0] -> death();
                    break;
                        }
               
                case -10: {
                    std::cout << "Vampire has charmed its opponent! They will not attack this round." << std::endl;

                    fighter[0] -> skipNextAttack();
                    break;
                    }
                default: defendResult = fighter[0] -> defend(attackResult);
                        break;
            };
            
            if (fighter[0] -> getStrength() <= 0) {
                std::cout << fighter[0] -> getName() << " has perished. " << fighter[1] -> getName() << " wins!" << std::endl;
                exit (EXIT_SUCCESS);
            }
        }
    roundCounter++;
    }
}

void Match::resetRoundCounter() {
    roundCounter = 0;
}
