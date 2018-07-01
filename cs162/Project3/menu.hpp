#ifndef MENU_HPP
#define MENU_HPP

#include "match.hpp"

#include "character.hpp"
#include "barbarian.hpp"
#include "vampire.hpp"
#include "medusa.hpp"
#include "harrypotter.hpp"
#include "bluemen.hpp"

    static Character* p1;
    static Character* p2;
    static Match* match;

    static int numRounds;

    void setupMatchPromptPlayer1();
    void setupMatchPromptPlayer2();
    void playAgainPrompt(); 
    void setupMatch();
    void andFight();

#endif
