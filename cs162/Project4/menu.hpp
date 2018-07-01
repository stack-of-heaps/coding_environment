#ifndef MENU_HPP
#define MENU_HPP

#include "match.hpp"
#include "lineup.hpp"

#include "character.hpp"
#include "barbarian.hpp"
#include "vampire.hpp"
#include "medusa.hpp"
#include "harrypotter.hpp"
#include "bluemen.hpp"

    static Match* match;

    static int numRounds;

    void setupLineup(Lineup* roster);
    int playAgainPrompt(); 
    void setupMatch();
    void andFight();
    bool doWePlay();

#endif
