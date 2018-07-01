//Edit 5-9: (kak)
//1. Added Matt's random spoint point functions + tweaks
//2. Added createBoard() function (see header file notes)

#include "board.hpp"
#include "yomu.hpp"

#include <random>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void Board::initBoard(){

    int cols;
    int rows;

    std::cout << "Would you like to choose the size of the board?" << std::endl;
    std::cout << "1. Yes" << std::endl;
    std::cout << "2. No" << std::endl;

    int userChoice = intYomu(1, 2, "strict");

    //custom board
    switch (userChoice) {
        case 1: {
            std::cout << "How big is the board? (Format: X by Y tiles, where X and Y are equal)" << std::endl;    
            std::cout << "X and Y values?" << std::endl;
            numberOfColumns = intYomu(2);  //My input validator reads this as: "input must be 2 or greater to be valid"
            numberOfRows = numberOfColumns;
            customBoard = true;

            createBoard();

            std::cout << "How many ants and doodlebugs on the board?" << std::endl;
            std::cout << "The maximum number is: " << numberOfRows * numberOfColumns << "." << std::endl;
            std::cout << "Ants: " << std::endl;
            numberOfAnts = intYomu(0, (numberOfRows * numberOfColumns));

            //user enters number of ants = to number of spaces on the board
            if (numberOfAnts == numberOfRows * numberOfColumns) {
                std::cout << "Okay, the entire board is composed of ants." << std::endl;
                randomStartingSpawns(numberOfAnts, numberOfDoodlebugs);
            }
            else
            {
                std::cout << "There are " << numberOfRows * numberOfColumns - numberOfAnts << " spaces left on the board." << std::endl;
                std::cout << "Doodlebugs: " << std::endl;
                numberOfDoodlebugs = intYomu(0, (numberOfRows * numberOfColumns) - numberOfAnts);
            
                randomStartingSpawns(numberOfAnts, numberOfDoodlebugs);
                }
            
            break;

            }
        
    //default board, "else userInput == 2" from line 24)
        case 2:  {
            std::cout << "Okay, the board will be 20x20." << std::endl;
            std::cout << "The board will start with 5 ants and 100 doodlebugs." << std::endl;
            numberOfColumns = 20;
            numberOfRows = 20;
            numberOfAnts = 5;
            numberOfDoodlebugs = 100;
            customBoard = false;

            createBoard();

            randomStartingSpawns(numberOfAnts, numberOfDoodlebugs);
            
            break;

            }
    }
}

void Board::createBoard() {
    // Each element in array is going to point to its own array of Critter*
    // + 2 is to accomodate a boarder around the game board
    // USEABLE GAMESPACE IS FROM ROW 1 THROUGH NUMBER OF ROWS
    // USEABLE GAMESPACE IS FROM COL 1 THROUGH NUMBER OF COLS
    gameBoardPtr = new Critter**[numberOfRows + 2];	// rows

    for (int row = 0; row < numberOfRows + 2; row++)
    {
        gameBoardPtr[row] = new Critter*[numberOfColumns + 2];	// columns
    }

    /******************************************
    ** Setup border critters and start with empty grid
    ******************************************/
    for (int row = 0; row < numberOfRows + 2; row++)
    {
        for (int col = 0; col < numberOfColumns + 2; col++)
        {
            if (row == 0 || row == numberOfRows + 1)
            {
                gameBoardPtr[row][col] = new Critter('-', row, col);	// These critters are only used to display border
            }

            else if ((col == 0 && (row > 0 && row < numberOfRows + 1)) ||
                (col == numberOfColumns + 1 && (row > 0 && row < numberOfRows + 1)))
            {
                gameBoardPtr[row][col] = new Critter('|', row, col);
            }

            else
            {
                gameBoardPtr[row][col] = new Critter(' ', row, col);
            }
        }
    }
}

void Board::randomStartingSpawns(int ant, int doodle) {
    numberOfAnts = ant;
    numberOfDoodlebugs = doodle;
    antCount = 0;
    doodleCount = 0;
    int randomRow;
    int randomCol;
   
    //making ants
    do{      
        randomRow = randomSpawnPointX();      
        randomCol = randomSpawnPointY();       

        if (gameBoardPtr[randomRow][randomCol] -> getBugLetter() == ' ')
            placeAnt(randomRow, randomCol);
    
    } while (antCount < numberOfAnts);    
   
    //making doodlebugs
    do {      
        randomRow = randomSpawnPointX();      
        randomCol = randomSpawnPointY();       
        if(gameBoardPtr[randomRow][randomCol]->getBugLetter() == ' ')
            placeDoodlebug(randomRow, randomCol);
        
    } while (doodleCount < numberOfDoodlebugs);  
}

void Board::placeAnt(int x, int y) {

    gameBoardPtr[x][y] = new Ant('O', x, y);
   
    antCount++;
}

void Board::placeDoodlebug(int x, int y) {

    gameBoardPtr[x][y] = new Doodle('X', x, y);

    doodleCount++;

}

int Board::randomSpawnPointX() 
    {   
    if (customBoard)
        {
        std::uniform_int_distribution<int> customBoardDistX(1, numberOfRows);
        return customBoardDistX(theTwister);
        }    
    else    
        {    
        std::uniform_int_distribution<int> standardBoardDist(1, 20);
        return standardBoardDist(theTwister);
        }  
    }

int Board::randomSpawnPointY() 
    {   
    if (customBoard)
        {
        std::uniform_int_distribution<int> customBoardDistY(1, numberOfColumns);
        return customBoardDistY(theTwister);
        
        }    
    else    
        {    
        std::uniform_int_distribution<int> standardBoardDist(1, 20);
        return standardBoardDist(theTwister);
        }  
    }
/****************************************************************************
** Description: The printBoard function is used to print the board upon
completion of each step in the simulation. The 2D array is printed in
"square" format.
****************************************************************************/
void Board::printBoard()
{
	if (gameBoardPtr != NULL)
	{
		for (int row = 0; row < numberOfRows + 2; row++)
		{
			for (int col = 0; col < numberOfColumns + 2; col++)
			{
				cout << gameBoardPtr[row][col]->getBugLetter() << " ";
			}

			cout << endl;
		}

		cout << endl;
	}
}

std::ostream& operator<<(std::ostream& outStream, Critter bugToPrint)
{
	outStream << bugToPrint.getBugLetter();

	return outStream;
}

bool Board::isCustom() 
{
    return customBoard;
}

int Board::getXLimit() 
{
    return numberOfRows;
}

int Board::getYLimit()
{
    return numberOfColumns;
}

void Board::breedCritters() {
	//loop through all board locations to and determine if critter is old enough to breed
	for (int row = 0; row < numberOfRows + 2; row++) {
		for (int col = 0; col < numberOfColumns + 2; col++) {
			char getType = gameBoardPtr[row][col]->getBugLetter();
			switch (getType) {
				//if grid cell location contains an Ant
			case 'O': {
				//check if Ant age is equal to 3
				if (gameBoardPtr[row][col]->getAge() == 3) {
					bool spaceFound;
					int returnRow, returnCol;
					//call Critter breed function
					gameBoardPtr[row][col]->breed(gameBoardPtr, returnRow, returnCol, spaceFound);
					//if open space found, delete critter object in that position and replace with new Ant
					if (spaceFound) {
						delete gameBoardPtr[row][col];
						//Critter object will need to be replaced by Ant object once class is created
						gameBoardPtr[row][col] = new Critter('O', row, col);
					}
					//reset age to 0. This can probably be contained in breed() method as well
					gameBoardPtr[row][col]->setAge(0);
				}
				break;
			}
			//if grid cell location contains a Doodlebug
			case 'X': {
				//check if Doodlebug age is equal to 8
				if (gameBoardPtr[row][col]->getAge() == 0) {
					bool spaceFound;
					int returnRow, returnCol;
					//call Critter breed function
					gameBoardPtr[row][col]->breed(gameBoardPtr, returnRow, returnCol, spaceFound);
					//if open space found, delete critter object in that position and replace with new Doodlebug 
					if (spaceFound) {
						delete gameBoardPtr[row][col];
						//Critter object will need to be replaced by Doodlebug object once class is created
						gameBoardPtr[row][col] = new Critter('X', row, col);
					}
					//reset age to 0. This can probably be contained in breed() method as well
					gameBoardPtr[row][col]->setAge(0);
				}
			}
			//if neither cell contains Ant or Doodlebug, do nothing
			default: {
				break;
			}
			}
		}
	}
}

void Board::makeMove()
{
	// First the doodlebugs will move
	for (int row = 1; row <= numberOfRows; row++)
	{
		for (int col = 1; col <= numberOfColumns; col++)
		{
			if (gameBoardPtr[row][col]->getBugLetter() == 'X')
			{
				gameBoardPtr[row][col]->move(row, col, gameBoardPtr, numberOfRows, numberOfColumns);

			}

		}
	}
	
	// Then the ants will move
	for (int row = 1; row <= numberOfRows; row++)
	{
		for (int col = 1; col <= numberOfColumns; col++)
		{
			if (gameBoardPtr[row][col]->getBugLetter() == 'O')
			{
				gameBoardPtr[row][col]->move(row, col, gameBoardPtr, numberOfRows, numberOfColumns);

			}

		}
	}
	
	// Reset all Critter's alreadyMoved to false for the next round
	for (int row = 1; row <= numberOfRows; row++)
	{
		for (int col = 1; col <= numberOfColumns;col++)
		{
			gameBoardPtr[row][col]->setAlreadyMoved(false);
		}
	}

}

/****************************
** Delete Board when finished
****************************/
Board::~Board() {
	for (int row = 0; row < numberOfRows + 2; row++)
	{
		for (int col = 0; col < numberOfColumns + 2; col++)
		{
			delete gameBoardPtr[row][col]; // Delete all Critter Type Objects
		}
	}
	delete[] gameBoardPtr; // Free array of Critter pointer pointers
}
