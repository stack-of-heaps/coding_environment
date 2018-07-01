#include "critter.hpp"

void Critter::setBugLetter(char enteredLetter)
{
	bugLetter = enteredLetter;
}

char Critter::getBugLetter()
{
	return bugLetter;
}

int Critter::getAge()
{
	return age;
}

void Critter::setYPosition(int y) {
    this->row = y;
}

void Critter::setXPosition(int x) {
    this->column = x;
}

void Critter::setAge(int age) {
	this->age = age;
}

int Critter::getYPosition() {
	return this->row;
}

int Critter::getXPosition() {
	return this->column;
}

Critter::Critter(char enteredLetter, int row, int column) {
	setBugLetter(enteredLetter);
	age = 0;	// Age always starts at 0
	alreadyMoved = false;
	this->row = row;
	this->column = column;
}

void Critter::setAlreadyMoved(bool moveStatus)
{
	alreadyMoved = moveStatus;
}


bool Critter::getAlreadyMoved()
{
	return alreadyMoved;
}

void Critter::breed(Critter*** gameBoardPtr, int &returnRow, int &returnCol, bool &spaceFound) {
	int rowMove;
	int colMove;
	//set vector for possible adjacent locations
	std::vector<int> adjacentOptions = {1, 2, 3, 4};

	//until open board location found, loop through all four adjacent locations
	spaceFound = false;
	for (int count = 0;  count < 4; count++) {
		if (spaceFound){break;}

		//call random number function based on size of adjacentOptions vector
		int adjacentIndex;
		adjacentIndex = (randDirection(adjacentOptions.size())) - 1;

		//convert random vector index to the board direction to check for empty cell
		CritterDirection checkDirection = CritterDirection(adjacentOptions[adjacentIndex]);

		//call returnCell method by passing checkDirection which returns the row
		//and column of board location that is to be checked for occupancy.
		checkPosition(rowMove, colMove, checkDirection);

		//check board for open space
		if (gameBoardPtr[rowMove][colMove]->getBugLetter() == ' '){
			returnRow = rowMove;
			returnCol = colMove;
			spaceFound = true;
			return;
		}
		//if space occupied, remove index value from vector and try different random location
		else {
			adjacentOptions.erase(adjacentOptions.begin() + adjacentIndex);
		}
	}
}

/************************************************************************************
* I'm unfamiliar with this method of random integer generation, but I think this
* will return a random vector index location based on the size of the direction
* vector passed to the function
*************************************************************************************/
int Critter::randDirection(int numDirections) {
	int randomNumber = (rand() % (numDirections)) + 1;
	return randomNumber;
}

/************************************************************************************
* checkPosition method sets the rowMove and colMove board index values based on the 
* Direction passed to the method. These values are returned by reference and will
* be used to checked if board location is occupied
*************************************************************************************/
void Critter::checkPosition(int &rowMove, int &colMove, CritterDirection checkDirection) {
	
	int critterRow = this->getYPosition();
	int critterColumn = this->getXPosition();
		
	switch (checkDirection) {
		case Up: {
			rowMove = critterRow - 1;
			colMove = critterColumn;
			break;
		}
		case Down: {
			rowMove = critterRow + 1;
			colMove = critterColumn;
			break;
		}
		case Left: {
			rowMove = critterRow;
			colMove = critterColumn - 1;
			break;
		}
		case Right: {
			rowMove = critterRow;
			colMove = critterColumn + 1;
			break;
		}
	}
	return;
}
		
CritterDirection Critter::nextDirection()	// Return random enum for next move
{
	int randomNumber;  // the value in range of 1 to 4
	const int MIN_VALUE = 1;
	const int MAX_VALUE = 4;

	randomNumber = randDirection(MAX_VALUE);

	if (randomNumber == 1)
	{
		return Up;
	}

	else if (randomNumber == 2)
	{
		return Down;
	}

	else if (randomNumber == 3)
	{
		return Left;
	}

	else if (randomNumber == 4)
	{
		return Right;
	}

}

