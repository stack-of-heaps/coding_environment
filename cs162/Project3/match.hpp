#ifndef MATCH_HPP
#define MATCH_HPP

#include "character.hpp"

#include <vector>

class Match {

    private:
        std::vector<Character*> fighter; //Holds the two fighters for each match
        std::vector<int> referee {0}; //Holds attack results for each attack
        int fighterOneAttack[2];
        int fighterTwoAttack[2];
        int rounds;
        int roundCounter;
        int *matchRecord; // Pointer for dynamic initialization of a 2d array to record bouts. [x][y] -> x is round number; y is victor (1 = player 1; 2 = player 2);
        
    public:
        Match(Character* char1, Character* char2);
        void chooseFighters();
        void resetRoundCounter();
        void setRounds(int numRounds);
        int getRound();
        int getRoundLimit();
        int fighterOne(int special = 0);
        int fighterTwo(int special = 0);
        bool oneRound();
        ~Match();

};

#endif
