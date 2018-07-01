#include "lineup.hpp"
#include "menu.hpp"

int main(){

    //Include pointers to Lineup* team1, Lineup* team2; Lineup* losers;
    //Include pointer to Match object
    
    //**TEAM SETUP PHASE**
    //1) Ask user how many fighters on lineup 1
    //2) Loop that many times, asking to create a new fighter each time
    //3) How many fighters on team 2?
    //4) Loop that many times, asking to create a new fighter each time
   
    //(**FIGHT PHASE**
    //1) andFight(Lineup1 -> getHead(), Lineup2 -> getHead());
    //2) This function needs to be checking for death
    //3) When a fighter dies, round states are collected and added to the node's match record
    //4) The fighter('s node) is removed from the lineup and copied to the loser lineup

    bool start = doWePlay();

    if (!start)
        return 0;
    else 
        setupMatch();
        
    return 0;
}

