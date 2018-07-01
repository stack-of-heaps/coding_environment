#ifndef BOARD_HPP
#define BOARD_HPP

#include "critter.hpp"
#include "Ant.hpp"
#include "doodle.hpp"

#include <random>
#include <iostream>

/************************************************************************     
* RANDOM STARTING POINT FUNCTION I'm pretty partial to using this 
* kind of setup lately.  
* This will rely on numberOfColumns and numberOfRows ints in Board class.
*************************************************************************/ 
    
//setting up the Mersenne Twister
static std::random_device randyEngine;
static std::mt19937 theTwister(randyEngine());
   

//Update 5-9: (kak)
//1. Split prior initBoard() into two functions: one to prompt user for input, (initBoard), and another to actually "create" the board (createBoard()).
//2. Integrated Matthew's random starting point function + tweaks
//3. Added int numberOfAnts, numberOfDoodles, antCounter, and doodleCounter to Board data member
class Board {

    private:
        bool customBoard = false;
        Critter*** gameBoardPtr;
        int numberOfRows;
        int numberOfColumns;
        int numberOfAnts;
        int numberOfDoodlebugs;
        int antCount;
        int doodleCount;

    public:
        bool isCustom();
        void initBoard(); // Walks user through creation of board: custom or standard

        void createBoard(); // Actually initializes the board
        void printBoard();
		void breedCritters();
        void everythingMove();
        void randomStartingSpawns(int ant, int doodle); // Places all critters at the beginning of the simulation
        void placeAnt(int x, int y); //Places an individual ant; x and y are randomly generated coordinates
        void placeDoodlebug(int x, int y); // Places an individual doodlebug; x and y are randomly generated coordinates

        int getXLimit();
        int getYLimit();

        int getNumberOfAnts();
        int getNumberOfDoodles();

        int setNumberOfAnts();
        int setNumberOfDoodles();

	void makeMove();

        //I made two because I wasn't confident that returning an array would work so well.
        //One function handles the X dimension of the board, another handles the Y
        //The functions know if the board is custom and will adapt to that situation.
        //If the board is "standard," (20x20), it will behave appropriately.
        int randomSpawnPointX();
        int randomSpawnPointY();

        ~Board();

};

#endif
