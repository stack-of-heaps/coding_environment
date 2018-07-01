//*********************************************************************
//Name: Kyle Karthauser
//Date: 4/9/18
//Description: board.cpp defines function prototypes found in board.hpp
//
// --void initBoard() takes the pointer to a pointer char** boardGoesHere
// memory placeholder and turns it into a 2D dynamic array. Comes with its
// own custom ~Board(); destructor which handles memory leaks
//
// -- void dispBoard(int* antPosition) takes a pointer to an array as input
// and prints the board. The array has the form "array[2]," where
// "array[0]" is the x value and "array[1]" is the y value.
// The board displays ' ' and '#' spaces to represent
// white and black tiles respectively. A '*' tile indicates the position of
// Langton.
//
// --void updateBoard(int* pos) takes Langton's current position (prior to 
// a move) and swaps the color of the tile upon which he sits. White becomes
// black, black becomes white. The input is a pointer to an array containing
// Langton's position.
//
// --char tileColor(int* antPosition) returns the color of the tile under
// Langton. accepts a pointer to an array outlined above. Used in ant.cpp
// to determine which direction to rotate.
//
// --int getXLimit() returns the size of the 2D array in the X dimension
// --int getYLimit() returns the size of the array in the Y dimension
// *************************************************************************
#include "board.hpp"
#include "ant.hpp"
#include "yomu.hpp"

void Board::initBoard(){

    std::cout << "How big is Langton's world? (Format: X by Y tiles)" << std::endl;
    //Get size of X Dimension 
    bool validInput = false;
    int inputChecker = -1;
    std::string inputString = "";
    do {
        std::cout << "X: " << std::endl;
        getline(std::cin, inputString);
        inputChecker = yomu(inputString);
        if (inputChecker < 2) {
            std::cout << "X dimension must be at least 2." << std::endl;
            std::cout << "Please enter X dimension: " << std::endl;
        }
        else {
            xDimension = inputChecker;
            validInput = true;
        }
    } while (!validInput);

    validInput = false;
    inputChecker = -1;
    inputString = " ";
    do {
        std::cout << "Y: " << std:: endl;
        getline(std::cin, inputString);
        inputChecker = yomu(inputString);
        if ((inputChecker < 2) || (inputChecker < xDimension)) {
            std::cout << "Y dimension must be at least 2 and greater than " << xDimension << std::endl;
            std::cout << "Please enter Y dimension: " << std::endl;
        }
        else {
            yDimension = inputChecker;
            validInput = true;
        }
    } while (!validInput);

    //create the board (dynamic 2D array)
    boardGoesHere = new char*[xDimension];
    for (int i = 0; i < yDimension; i++)
        boardGoesHere[i] = new char[yDimension];

    //populate board with "white" spaces
    for (int xItr = 0; xItr < xDimension; xItr++){
        for (int yItr = 0; yItr < yDimension; yItr++)
            boardGoesHere[xItr][yItr] = ' ';
    }
}

Board::~Board() {
    
    int y = getYLimit();
    for (int i = 0; i < y; i++)
        delete [] boardGoesHere[i];

    delete [] boardGoesHere;
}

void Board::dispBoard(int* antPosition){

    int x = getXLimit();
    int y = getYLimit();
    int antX = antPosition[0];
    int antY = antPosition[1];

    for (int yItr = 0; yItr < y; yItr++){
        std::cout << std::endl;
        for (int xItr = 0; xItr < x; xItr++){
            if ((xItr == antX) && (yItr == antY))
                std::cout << "[*]";
            else
            std::cout << "[" << boardGoesHere[xItr][yItr] << "]";
        }
    }
    std::cout << std::endl;
}

//Refreshes array with most current tile color
void Board::updateBoard(int* antPosition){

    int x, y;
    x = antPosition[0];
    y = antPosition[1];

    if (boardGoesHere[x][y] == '#')
        boardGoesHere[x][y] = ' ';
    else
        boardGoesHere[x][y] = '#';
}

int Board::getXLimit(){
    return xDimension;
}

int Board::getYLimit(){
    return yDimension;
}

//Returns tile color of langton's position
char Board::tileColor(int* position) {

    int x = position[0];
    int y = position[1];

    return boardGoesHere[x][y];
}
