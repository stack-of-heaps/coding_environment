#include "game.hpp"
#include "menu.hpp"

/***********************************************
 * Handles playing of the game
 * Parameters:
 *      -- int numberOfRounds 
 *      -- vector of Die pointers (passed by reference)
 *      -- vector of LoadedDie pointers (passed by reference)
 *
 * 1) Create dynamic array to hold score results
 * 2) Dynamic array is 2 cells "wide" and number of games deep
 * 3) Check vectors to see if they contain objects
 * 4) Roll dice until game is finished, store the results
 * 5) Judge the winner
 * 6) Display the results
 * 7) Delete dynamic array
 ****************************************************/
void game(int numberOfRounds, std::vector<Die*>&dice, std::vector<LoadedDie*>&loadedDice) {

    int counter = 1;    //Start at game #1
    int** scoreCounter; // raw material for dynamic 2d array for holding scores

    // in lines 11-15 the array produced will have dimensions of roundsx[2]
    // i.e., in a 3 round game: [3][2]
    // 0-0
    // 0-0
    // 0-0
    // Where [x][y] x = player 1, y = player 2
    scoreCounter = new int*[numberOfRounds]; 
    
    for (int i = 0; i < numberOfRounds; i++) {
        scoreCounter[i] = new int[2];
    }

    for (int x = 0; x < numberOfRounds; x++) {
        for (int y = 0; y < 2; y++) 
            scoreCounter[x][y] = 0;
    }

    int rollValue = 0; //this will hold the roll value for each roll
    int playerOneScore = 0;
    int playerTwoScore = 0;

    do {
        std::cout << "***************************" << std::endl;

        int playerCounter = 0; //used to keep track of player 1 or player 2 turns
        playerOneScore = 0;
        playerTwoScore = 0;
        //Don't examine the vector if it doesn't contain anything!
        if (dice.size() > 0) {
            
            for (int i = 0; i < dice.size(); i++){
                rollValue = dice[i] -> roll(); 
                std::cout << "Player " << playerCounter + 1 << " rolls " << rollValue << " (Standard Die with " << dice[i] -> getSides() << " sides)" << std::endl;
                scoreCounter[counter - 1][playerCounter] = rollValue;
                playerCounter++;
            }
        }

        //Don't examine the vector if it doesn't contain anything!
        if (loadedDice.size() > 0) {

            //Roll die, save results, increment whose turn it is
            for (int i = 0; i < loadedDice.size(); i++){
                rollValue = loadedDice[i] -> roll();
                 std::cout << "Player " << playerCounter + 1 << " rolls " << rollValue << " (Loaded Die with " << loadedDice[i] -> getSides() << " sides)" << std::endl;
                scoreCounter[counter - 1][playerCounter] = rollValue;
                playerCounter++;
            }       
        }

        //judge winner of the round    

        // Player one wins round if...
        if (scoreCounter[counter - 1][0] > scoreCounter[counter - 1][1])
            playerOneScore++;
        //Player two wins round if..
        if (scoreCounter[counter - 1][0] < scoreCounter[counter - 1][1])
            playerTwoScore++;

        std::cout << "Round " << counter << " result: ";
        //judge logic
        if (playerOneScore > playerTwoScore)
            std::cout << "Player one wins!" << std::endl;
        if (playerTwoScore > playerOneScore)
            std::cout << "Player two wins!" << std::endl;
        if (playerOneScore == playerTwoScore) 
            std::cout << "Tie!" << std::endl;

        std::cout << "***************************" << std::endl;
        std::cout << std::endl;
        
        counter++;

    } while (counter - 1 < numberOfRounds);

//prints final score array; increment score counters to judge a winner
    playerOneScore = 0;
    playerTwoScore = 0;
    std::cout << "Game Summary" << std::endl;
    for (int x = 0; x < numberOfRounds; x++) {
        if (x != 0)
            std::cout << std::endl;
        if (scoreCounter[x][0] > scoreCounter[x][1])
            playerOneScore++;
        if (scoreCounter[x][0] < scoreCounter[x][1])
            playerTwoScore++;
        for (int y = 0; y < 2; y++) 
            std::cout << scoreCounter[x][y] << " - ";
    }

 //judge a winner
    for (int x = 0; x < numberOfRounds; x++) {
        }
    std::cout << std::endl;

    if (playerOneScore > playerTwoScore)
        std::cout << "Player one wins!" << std::endl;
    if (playerTwoScore > playerOneScore)
        std::cout << "Player two wins!" << std::endl;
    if (playerOneScore == playerTwoScore) 
        std::cout << "Tie!" << std::endl;
   
delete [] scoreCounter;
}
