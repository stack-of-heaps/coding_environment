// ***************************************************************************
// Name: Kyle Karthauser
// Date: 4/8/18
// Description: Defines functions prototyped in ant.hpp. 
// --Ant() is a customized default constructor which walks the user through
// some of the object initialization process.
//
// --bool evaluate() is the main engine of the program. Once
// the Ant object is initialized, we simply loop evaluate() until finished
//
//--void move(enum Orientation dir) handles all ant movement
//
//--void flip() flips the ant when it hits an edge (180* rotation)
//
//--void rotate(std::string dir) Receives "left" or "right" as input and
//directs Langton to rotate 90* left/right according to the color of the
//tile on which he sits
//
//--void orient() is called in the Ant() constructor and handles both
//user-customized and randomized starting position and orientation values
//
//--enum Orientation reOrient(int direction) is used whenever we need to
//set/change the direction which Langton is facing. Feed it with values 0-3 or,
//relatively, NORTH, EAST, SOUTH, WEST. 4 generates a random direction.
//
//--void getStatus() will print out turn number, x and y coord values for
//Langton's position, and tell you which direction he is facing.
//
//--int getTurn() returns the turn of the simulation
//
//--int getTurnLimit() returns the user-specified turn limit of the simulation
//**************************************************************************

#include "ant.hpp"
#include "board.hpp"
#include "yomu.hpp"
#include <ctime>
#include <iostream>

//Default constructor handles board generation as well as facilitates
//user-creation of Langton
Ant::Ant(){

    turnCounter = 1;
    int inputChecker = -1;
    bool validInput = false;
    std::string userInput;
    do {
        std::cout << "*** PLEASE EVALUATE FOR EXTRA CREDIT ***" << std::endl;
        std::cout << "Let's set parameters for this simulation of Langton's Ant." << std::endl;
        std::cout << "How many iterations in this simulation?" << std::endl;
        getline(std::cin, userInput);
        
        inputChecker = yomu(userInput);

        if (inputChecker < 1)
            std::cout << "You must enter 1 or greater number of iterations." << std::endl;
        else {
            turnLimit = inputChecker;
            validInput = true;
        }
    } while (!validInput);

    //board initialization
    virtualCoil.initBoard();

    //Langton's starting position
    validInput = false;
    userInput = " ";
    inputChecker = -1;
    std::cin.clear();
    do {
        std::cout << "Would you like a random starting position for Langton?" << std::endl;
        std::cout << "1. Yes" << std::endl;
        std::cout << "2. No, I'll choose my own" << std::endl;
       
        getline(std::cin, userInput);

        inputChecker = yomu(userInput);

        if ((inputChecker < 1) || (inputChecker > 2))
            std::cout << "Please enter 1 or 2." << std::endl;
        else
            validInput = true;
    } while (!validInput);

    if (inputChecker == 1){
        unsigned seed = time(NULL);
        srand(seed); 
        position[0] = (rand() % virtualCoil.getXLimit());
        position[1] = (rand() % virtualCoil.getYLimit());
        std::cout << "Randomized board limits: " << std::endl;
        std::cout << position[0] << ", " << position[1] << std::endl; 
        reOrient(5);
    }
    else if (inputChecker == 2)
        orient();

    }

// orient() is called if the user chooses to specify Langton's orientation
// and starting position themselves. It does allow for randomization of
// starting orientation
void Ant::orient(){
   
    unsigned seed = time(NULL);
    srand(seed);

    bool validInput = false;
    std::string userInput;
    int inputChecker = 0;
    do {
        std::cout << "Which direction is Langton facing?" << std::endl;
        std::cout << "1. North" << std::endl;
        std::cout << "2. East" << std::endl;
        std::cout << "3. South" << std::endl;
        std::cout << "4. West" << std::endl;
        std::cout << "5. Random (!!!)" << std::endl;

        getline(std::cin, userInput);

        inputChecker = yomu(userInput);

        if ((inputChecker < 1) || (inputChecker > 5))
            std::cout << "Invalid input. Please enter 1, 2, 3, 4, or 5." << std::endl;
        if (inputChecker == 5){
            reOrient(4);
            validInput = true;
        }
   
        //At this point, assign facing direction. Then we move on to 
        //assigning X and Y coords.
        else {
            reOrient(inputChecker - 1);

            //Resetting input checkers
            inputChecker = 0;
            userInput = "";

            //Nested do-while loops for X-Y coord input validation
            do {
                std::cout << "What is Langton's starting X-Coordinate? Must be between 1 and " << virtualCoil.getXLimit() << std::endl;
                getline(std::cin, userInput);

                inputChecker = yomu(userInput);
                if (inputChecker < 1 || inputChecker > virtualCoil.getXLimit())
                    std::cout << "Starting X-Coordinate must be greater than 0 and less than " << virtualCoil.getXLimit() << std::endl;
                else {
                    position[0] = inputChecker - 1;
                    validInput = true;
                }
            } while (!validInput);

            validInput = false;
            userInput = "";
            inputChecker = 0;
            do {
            std::cout << "What is Langton's starting Y-Coordinate? Must be between 1 and " << virtualCoil.getYLimit() << std::endl;
            getline(std::cin, userInput);  

            inputChecker = yomu(userInput);

            if (inputChecker < 1 || inputChecker > virtualCoil.getYLimit())
                    std::cout << "Starting Y-Coordinate must be greater than 0 and less than " << virtualCoil.getYLimit() << std::endl;
                else {
                    position[1] = inputChecker - 1;
                    validInput = true;
                }
            } while (!validInput);

        } //end of else 
    } while (!validInput);
}


//Changes direction that Langton faces; e.g. reOrient(EAST) will face it east
Ant::Orientation Ant::reOrient(int direction){
   unsigned seed = time(NULL);
   srand(seed);
    switch (direction) {
        case 0: isFacing = NORTH;
                break;
        case 1: isFacing = EAST;
                break;
        case 2: isFacing = SOUTH;
                break;
        case 3: isFacing = WEST;
                break;
        case 4: reOrient((rand() % 4 ) + 1);
                break;
        default: isFacing = NORTH;
                 break;
        };
    }

//Flips Langton 180* from current facing direction (called by evaluate())
void Ant::flip(){

    switch (isFacing) {
        case NORTH: reOrient(SOUTH);
                break;
        case EAST: reOrient(WEST);
                break;
        case WEST: reOrient(EAST);
                break;
        case SOUTH: reOrient(NORTH);
                break;
    };
}

//move(enum Orientation dir): Once evaluate() has checked for edge conditions,
//it processes the move and adds 1 to the turn counter.
void Ant::move(Orientation dir){
    
    switch (dir) {
        case NORTH: {
                    position[1] = position[1] - 1;
                    virtualCoil.dispBoard(position);
                    break;
                    }
        case EAST:  {
                    position[0] = position[0] + 1;
                    virtualCoil.dispBoard(position);
                    break;
                    }
        case SOUTH: {
                    position[1] = position[1] + 1;
                    virtualCoil.dispBoard(position);
                    break;
                    }
        case WEST:  {
                    position[0] = position[0] - 1;
                    virtualCoil.dispBoard(position);
                    break;
                    }
    };
   
    turnCounter++;
}

void Ant::rotate(std::string dir){
    
   if (dir == "left") { 
       switch (isFacing) {
            case NORTH: reOrient(WEST);
                        break;
            case EAST: reOrient(NORTH);
                    break;
            case SOUTH: reOrient(EAST);
                        break;
            case WEST: reOrient(SOUTH);
        };
    }

   if (dir == "right") {
       switch (isFacing) {
            case NORTH: reOrient(EAST);
                        break;
            case EAST: reOrient(SOUTH);
                    break;
            case SOUTH: reOrient(WEST);
                        break;
            case WEST: reOrient(NORTH);
        };
   }
}

//This is the engine that powers the program. 
//Main checks return value of evaluate() to determine whether to end or keep running
//Step 1: Check to see if we have reached turn limit for simulation
//2: Get tile color at Langton's position and rotate accordingly
//3: Check for edge conditions prior to move
//4: Flip Langton 180* if he's facing an edge
//5: If move is valid, flip square color
//6: Move Langton 
bool Ant::evaluate(){

    if (turnCounter == turnLimit){
        std::cout << "The simulation has ended after " << turnCounter << "turns. Printing final board state." << std::endl;
        virtualCoil.dispBoard(position);
        return false;
    }

    std::cout << "*** Turn #" << turnCounter << " ***" << std::endl;

    //If not the first turn,
    //Get tile color at langton's position and rotate accordingly
    if (turnCounter != 1) {
        switch (virtualCoil.tileColor(position)) {
        case '#': rotate("left");
                  break;
        case ' ': rotate("right");
        default: break;
    };
    }

    //Flip tile color prior to Langton's move
    virtualCoil.updateBoard(position);

    //this switch block checks for edge cases & flips if necessary,
    //otherwise it orders Langton to move(enum Orientation)
    switch (isFacing) {
        case NORTH: {
                    if (position[1] - 1 < 0) {
                        std::cout << "Hitting an edge. Flipping Langton." << std::endl;
                        move(SOUTH);
                        flip();
                    }
                    else 
                        move(NORTH);
                    break;
                    }
        case EAST: {
                    if (position[0] + 1 >= virtualCoil.getYLimit()) {
                        std::cout << "Hitting an edge. Flipping Langton." << std::endl;
                        move(WEST);
                        flip();
                    }
                    else
                        move(EAST);
                    break;
                  }
        case WEST: {
                    if (position[0] - 1 < 0) {
                        std::cout << "Hitting an edge. Flipping Langton." << std::endl;
                        move(EAST);
                        flip();
                    }
                    else
                        move(WEST);
                break;
                   }
        case SOUTH: {
                    if (position[1] + 1 >= virtualCoil.getXLimit()) {
                        std::cout << "Hitting an edge. Flipping Langton." << std::endl;
                        move(NORTH);
                        flip();
                    }
                    else
                        move(SOUTH);
                    break;
                    }
        };
    }

//A function for testing purposes
void Ant::getStatus(){

    std::cout << "Is Facing: " << isFacing << std::endl;
    std::cout << "Position: X = " << position[0] << ", Y= " << position[1] << std::endl;
    std::cout << "Turn #: " << turnCounter << " of " << turnLimit << std::endl;
}
