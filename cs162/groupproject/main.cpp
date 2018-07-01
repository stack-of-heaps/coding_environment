#include "critter.hpp"
#include "board.hpp"
#include <ctime>

#include <iostream>
using std::cin;
using std::cout;
using std::endl;


int main()
{
	unsigned seed;         // srand expects an unsigned integer
	seed = time(0);        // seed set to changing value of time
	srand(seed);           // initiating seed in srand

    Board gameBoard;

    gameBoard.initBoard();
    gameBoard.printBoard();
   
    gameBoard.makeMove();
    gameBoard.printBoard();

	return 0;
}
