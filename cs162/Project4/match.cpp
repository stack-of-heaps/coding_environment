#include "match.hpp"

Match::Match(Lineup* t1, Lineup* t2, Lineup* l) { 
    team1 = t1;
    team2 = t2;
    losers = l;
}

Match::~Match() {

    delete team1;
    delete team2;
    delete losers;
}

void Match::setRounds(int numRounds) {
    rounds = numRounds;
}

int Match::getRound(){
    return roundCounter;
}

bool Match::oneRound() {

    std::cout << std::endl;
    std::cout << "*****************************************" << std::endl;
    std::cout << "*               Round #" << roundCounter + 1 << "                 *" << std::endl;
    std::cout << "*****************************************" << std::endl;
    std::cout << std::endl;

    /***************************************************************
     * PLAYER 1 ATTACK
     * ************************************************************/

    int totalAttack = 0;
    
    std::cout << "--FIGHTER 1 ATTACK PHASE" << std::endl;
    std::cout << "Name : " << team1 -> getFront() -> getName() << std::endl;
    std::cout << "Type : " << team1 -> getFront() -> getType() << std::endl;
    
    totalAttack = team1 -> getFront() -> attack();
    std::cout << "Total attack: " << totalAttack << std::endl;
    std::cout << std::endl;

    /***************************************************************
     * PLAYER 2 DEFENSE
     * ************************************************************/
    std::cout << "--FIGHTER 2 DEFENSE PHASE" << std::endl;
    
    std::cout << "Strength: " << team2 -> getFront() -> getStrength() << std::endl;
    std::cout << "Armor: " << team2 -> getFront() -> getArmor() << std::endl;

    team2 -> getFront() -> defend(totalAttack);
   
        //death check
        if (team2 -> getFront() -> getStrength() <= 0) {
            std::cout << "*****************************************" << std::endl;
            std::cout << "*       " << team2 -> getFront() -> getName() << " the " << team2 -> getFront() -> getType() << " has perished. " << team1 -> getFront() -> getName() << " wins!                *" << std::endl;
            std::cout << "*****************************************" << std::endl;
            std::cout << std::endl;

            //If a fighter has died, move them to the loser Lineup
            losers -> addBack(team2 -> getFront());
            team2 -> removeFront();
            //Check to see if team2's roster has been wiped out
            if (team2 -> isEmpty())
                return false;

            //Restore 50% health to the victor and move it to the back of their lineup
            team1 -> getFront() -> restoreHealth();
            team1 -> moveToBack();
        }

        std::cout << std::endl;

    /***************************************************************
     * PLAYER 2 ATTACK
     * ************************************************************/
    int totalAtack = 0;
    std::cout << "--FIGHTER 2 ATTACK PHASE" << std::endl;
    std::cout << "Name : " << team2 -> getFront() -> getName() << std::endl;
    std::cout << "Type : " << team2 -> getFront() -> getType() << std::endl;
    
    totalAttack = team2 -> getFront() -> attack();
    std::cout << "Total attack: " << totalAttack << std::endl;
    std::cout << std::endl;

    /***************************************************************
     * PLAYER 1 DEFENSE
     * ************************************************************/
    std::cout << "--FIGHTER 1 DEFENSE PHASE" << std::endl;
    std::cout << "Strength: " << team1 -> getFront() -> getStrength() << std::endl;
    std::cout << "Armor: " << team1 -> getFront() -> getArmor() << std::endl;

    team1 -> getFront() -> defend(totalAttack);
    std::cout << std::endl;
   
        //death check

        if (team1 -> getFront() -> getStrength() <= 0) {
            
            std::cout << "*****************************************" << std::endl;
            std::cout << team1 -> getFront() -> getName() << " the " << team1 -> getFront() -> getType() << " has perished. " << team2 -> getFront() -> getName() << " wins!" << std::endl;

            std::cout << "*****************************************" << std::endl;
            std::cout << std::endl;
            //If a fighter has died, move them to the loser Lineup
            losers -> addBack(team1 -> getFront());
            team1 -> removeFront();
            //Check to see if team2's roster has been wiped out
            if (team1 -> isEmpty())
                return false;
            
        team2 -> getFront() -> restoreHealth();
        team2 -> moveToBack();
        }
        //increment the round counter
    roundCounter++;

}

void Match::resetRoundCounter() {
    roundCounter = 0;
}

bool Match::andFight() {
    bool keepFighting = true;
    while (keepFighting)
        keepFighting = oneRound();

    losers -> printLineup();

}


