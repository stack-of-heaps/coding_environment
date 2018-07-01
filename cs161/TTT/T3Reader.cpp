/*****************************************************************
 * Name: Kyle Karthauser
 * Description: T3Reader.cpp relies on the T3Reader class defined in
 * Board.hpp as well as functions in Board.cpp.
 * -----T3Reader(); is the default constructor. Initializes a Board
 *      object and assigns playerTurn a default value 'x'.
 * -----T3Reader(char); is a constructor that does the same thing
 *      as above but lets the user control starting piece.
 * -----switchPlayerTurn(); allows the program to easily switch
 *      playerTurn value from 'x' to 'o' or vice versa.
 * -----T3ReadGameFile(string); lets the user enter a string as a
 *      filename for the program to read. The function reads values
 *      from the file, calls Board.cpp's makeMove() function, and
 *      if the move is valid, the data from the file is recorded 
 *      to the Board. If it is not, the data is not recorded to the
 *      Board object.
 * ****************************************************************/

#include "Board.hpp"
#include "T3Reader.hpp"
#include <fstream>
#include <iostream>

T3Reader::T3Reader(){

    playerTurn = 'x';        //playerTurn = 'x' or 'o'

    //initialize tic tac toe board
    Board thisGame; // Board instance that will be written from file
}
    
T3Reader::T3Reader(char playerSymbol){  
    playerTurn = playerSymbol;   //playerSymbol = playerTurn -> 'x' or 'o'

    Board thisGame;
}

void T3Reader::switchPlayerTurn(){
    switch (playerTurn){
        case 'x': playerTurn = 'o';
                  break;
        case 'o': playerTurn = 'x';
                  break;
    }
}

bool T3Reader::readGameFile(std::string fileName){ //reads in game log file

    std::ifstream gameLog;
    gameLog.open(fileName);

    bool makeAnotherMove = true;
    int coordOne, coordTwo; // to hold inputs from file
    int counter = 0;
    
    //do loop: initiates and regulates the process of reading data
    //from input file. runs as long as file has data to read &&
    //bool variable "makeAnotherMove" returns true when making a move
    do {
        gameLog >> coordOne;
        gameLog >> coordTwo;
        makeAnotherMove = reRunGame.makeMove(coordOne, coordTwo, playerTurn);
        std::cout<<"Make another move?: " << makeAnotherMove << "(" << coordOne << ", " << coordTwo << ")"<<std::endl;
        switchPlayerTurn();
        counter++;
        std::cout << "counter: "<< counter << std::endl;
       } while (gameLog && makeAnotherMove);

       GameResult finished;
       finished = reRunGame.gameState();
       std::cout << "finished = " << finished << std::endl;
       if (finished == UNFINISHED){
       return false;
       gameLog.close();
    }
    
    else {
        return true;
        gameLog.close();
    } 
}
/*
int main(){

    T3Reader a = T3Reader('x');

bool tester;

 tester = a.readGameFile("exfile.txt");

std::cout << tester << std::endl;

 return 0;
}
*/
