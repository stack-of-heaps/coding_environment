#include "board.hpp"
#ifndef ANT_HPP
#define ANT_HPP

#include <string>

class Ant {
    private:
        Board virtualCoil;  //Where Langton will strut his hour 'pon the stage
        int turnLimit;      //Max # of turns for current simulation
        int turnCounter;    //# of turns in current simulation
        enum Orientation { NORTH, EAST, SOUTH, WEST };
        Orientation isFacing;
        int position[2];    // Holds position as x=position[0] and y=position[1]

    public:
        Ant();
        bool evaluate();    // Before moving: turnCounter = simLimit? Does move() take me beyond an edge?
        void move(Orientation dir);        //If okay, ant moves orientation + 1
        void flip();        //For edge cases: Flip ant 180*
        void rotate(std::string dir); //rotates Langton; "left" or "right" as params
        void orient();      //Initialize Langton's orientation and position
        Orientation reOrient(int direction); //Changes/sets Langton's orientation. Use enum values or 0-3 above for cardinal directions or 4 for random
        void getStatus();   //For testing purposes
        int getTurn();      //Returns turn of the simulation
        int getTurnLimit(); //Returns user-specified # of iterations for sim
};

#endif
