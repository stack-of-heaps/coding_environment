#include "doodle.hpp"
#include "critter.hpp"
#include "board.hpp"
#include <iostream>
using std::cout;
using std::endl;

Doodle::Doodle(char bugLetter, int xPos, int yPos) : Critter(bugLetter, xPos, yPos) {};

void Doodle::move(int row, int col, Critter*** gameBoardPtr, int numberOfRows, int numberOfColumns)
{
	if(gameBoardPtr[row - 1][col]->getBugLetter() == 'O'
            && row != 1 && gameBoardPtr[row][col]->getAlreadyMoved() == false)
        {
            delete gameBoardPtr[row - 1][col];	// Delete the blank generic Critter there
            gameBoardPtr[row][col]->setAlreadyMoved(true);
            gameBoardPtr[row - 1][col] = gameBoardPtr[row][col];	// Our Ant moves up one row
            gameBoardPtr[row][col] = new Critter(' ');
            cout << "Doodle moved Up!" << endl;

        }

    else if(gameBoardPtr[row + 1][col]->getBugLetter() == 'O'
            && row != numberOfRows && gameBoardPtr[row][col]->getAlreadyMoved() == false)
        {
            delete gameBoardPtr[row + 1][col];
            gameBoardPtr[row][col]->setAlreadyMoved(true);
            gameBoardPtr[row + 1][col] = gameBoardPtr[row][col];
            gameBoardPtr[row][col] = new Critter(' ');
            cout << "Doodle moved Down!" << endl;

        }

    else if(gameBoardPtr[row][col - 1]->getBugLetter() == 'O'
            && col != 1 && gameBoardPtr[row][col]->getAlreadyMoved() == false)
        {

            delete gameBoardPtr[row][col - 1];
            gameBoardPtr[row][col]->setAlreadyMoved(true);
            gameBoardPtr[row][col - 1] = gameBoardPtr[row][col];
            gameBoardPtr[row][col] = new Critter(' ');
            cout << "Doodle moved Left!" << endl;

        }

    else if(gameBoardPtr[row][col + 1]->getBugLetter() == 'O'
            && col != numberOfColumns && gameBoardPtr[row][col]->getAlreadyMoved() == false)
        {

            delete gameBoardPtr[row][col + 1];
            gameBoardPtr[row][col]->setAlreadyMoved(true);
            gameBoardPtr[row][col + 1] = gameBoardPtr[row][col];
            gameBoardPtr[row][col] = new Critter(' ');
            cout << "Doodle moved Right!" << endl;

        }


	else{
        CritterDirection newDirection;


        newDirection = nextDirection(); // This returns a random enum

        if (newDirection == Up && gameBoardPtr[row - 1][col]->getBugLetter() == ' '
            && row != 1 && gameBoardPtr[row][col]->getAlreadyMoved() == false)
        {
            delete gameBoardPtr[row - 1][col];	// Delete the blank generic Critter there
            gameBoardPtr[row][col]->setAlreadyMoved(true);
            gameBoardPtr[row - 1][col] = gameBoardPtr[row][col];	// Our Ant moves up one row
            gameBoardPtr[row][col] = new Critter(' ');
            cout << "Doodle moved Up!" << endl;
        }

        else if (newDirection == Down && gameBoardPtr[row + 1][col]->getBugLetter() == ' '
            && row != numberOfRows && gameBoardPtr[row][col]->getAlreadyMoved() == false)
        {
            delete gameBoardPtr[row + 1][col];
            gameBoardPtr[row][col]->setAlreadyMoved(true);
            gameBoardPtr[row + 1][col] = gameBoardPtr[row][col];
            gameBoardPtr[row][col] = new Critter(' ');
            cout << "Doodle moved Down!" << endl;
        }

        else if (newDirection == Left && gameBoardPtr[row][col - 1]->getBugLetter() == ' '
            && col != 1 && gameBoardPtr[row][col]->getAlreadyMoved() == false)
        {
            delete gameBoardPtr[row][col - 1];
            gameBoardPtr[row][col]->setAlreadyMoved(true);
            gameBoardPtr[row][col - 1] = gameBoardPtr[row][col];
            gameBoardPtr[row][col] = new Critter(' ');
            cout << "Doodle moved Left!" << endl;
        }

        else if (newDirection == Right && gameBoardPtr[row][col + 1]->getBugLetter() == ' '
            && col != numberOfColumns && gameBoardPtr[row][col]->getAlreadyMoved() == false)
        {
            delete gameBoardPtr[row][col + 1];
            gameBoardPtr[row][col]->setAlreadyMoved(true);
            gameBoardPtr[row][col + 1] = gameBoardPtr[row][col];
            gameBoardPtr[row][col] = new Critter(' ');
            cout << "Doodle moved Right!" << endl;
        }

        else
        {
            cout << "Ant stayed put!" << endl;
        }


	}

		// If none of these conditions met, the Ant will not move

	// Reset all Critter's alreadyMoved to false for the next round
	for (int row = 1; row <= numberOfRows; row++)
	{
		for (int col = 1; col <= numberOfColumns;col++)
		{
			gameBoardPtr[row][col]->setAlreadyMoved(false);
		}
	}

}
