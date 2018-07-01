#ifndef MATCH_HPP
#define MATCH_HPP

#include "character.hpp"
#include "lineup.hpp"

class Match {

    private:
        Lineup* team1;
        Lineup* team2;
        Lineup* losers;
        int rounds;
        int roundCounter;
        
    public:
        Match(Lineup* t1, Lineup* t2, Lineup* losers);
        ~Match();
        void resetRoundCounter();
        void setRounds(int numRounds);
        int getRound();
        bool oneRound();
        bool andFight();

};

#endif
