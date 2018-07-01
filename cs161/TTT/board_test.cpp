/*****************************************************************
 * Name: Kyle Karthauser
 * Description: Board.cpp relies on the Board class defined in
 * Board.hpp. 
 * -----bool makeMove(int, int, char) takes ints to define
 *      x, y coords on the tic-tac-toe board and a character to
 *      define whose turn it is. Returns true if a valid move
 *      is being made and false if not.
 * -----Board() is a default constructor. Initializes an empty
 *              3x3 char gameBoard[][] array.
 * -----GameResult gameState(); Checks for win, draw, or an
 *      unfinished game. Returns an enum which is indexed to 
 *      X_WON, O_WON, DRAW, UNFINISHED.
 * -----print(); Prints game boards belonging to the Board class.
 * ****************************************************************/

#include "Board.hpp"
#include <iostream>

Board::Board(){
    for (int counterCol = 0; counterCol < 3; counterCol++){
        for (int counterRow = 0; counterRow < 3; counterRow++){
            gameBoard[counterRow][counterCol] = '\0';
        }
    }
}

//Board(1, 2, 'x');
//receives play data and player turn and returns true if move is new and legal
//returns false if space has already been claimed
bool Board::makeMove(int xCoord, int yCoord, char thisPlayer){

        // return false if the space is occupied
    if (gameBoard[xCoord][yCoord] != '\0')
        return false;
     
    // return false if we've reached a pre-defined gamestate
    GameResult preMoveCheck;
    preMoveCheck = gameState();

    switch (preMoveCheck){
      case X_WON:       return false;
                        break;
      case O_WON:       return false;
                        break;
      case DRAW:        return false;
                        break;
      default:          break;
      }
      
    //otherwise record the move and return true; accept next move
    gameBoard[xCoord][yCoord] = thisPlayer; 

    return true;
}

 /*****************************************
 *         DIAGRAM OF WIN STATES          *
        - - x       x - -       x x x
        - - x       - x -       - - -
        - - x       - - x       - - -
        {0, 2}      {0, 0}      {0, 0}
        {1, 2}      {1, 1}      {0, 1}
        {2, 2}      {2, 2}      {0, 2}
          A           B           C
        The values will be read sequentially. So when we process them, we can use the first vlaues read as reference for win states?
        Case A, B, C below are all WIN STATES
        A: three of the same xCoords
        B: xCoord1+1 = xCoord0+1 = xCoord0 (or yCoord)
        C: three of the same yCoords
        Return values: {X_WON, O_WON, DRAW, or UNFINISHED}


//Stupid way to do this--
//I'm enumerating each win condition.
//Win is assessed by combined value of characters found in array positions.
//'x' ASCII = 180, therefore a win = 360. 'o' ASCII = 111; win = 333.

    //Horizontal win states
    if (gameBoard[0][0] + gameBoard[0][1] + gameBoard[0][2] == 360)
    return X_WON;
    
    if (gameBoard[1][0] + gameBoard[1][1] + gameBoard[1][2] == 360)
    return X_WON;

    if (gameBoard[2][0] + gameBoard[2][1] + gameBoard[2][2] == 360)
    return X_WON;

    if (gameBoard[0][0] + gameBoard[0][1] + gameBoard[0][2] == 333)
    return O_WON;
    
    if (gameBoard[1][0] + gameBoard[1][1] + gameBoard[1][2] == 333)
    return O_WON;

    if (gameBoard[2][0] + gameBoard[2][1] + gameBoard[2][2] == 333)
    return O_WON;

    //Vertical win states
    if (gameBoard[0][0] + gameBoard[1][0] + gameBoard[2][0] == 360)
    return X_WON;
    
    if (gameBoard[0][1] + gameBoard[1][1] + gameBoard[2][1] == 360)
    return X_WON;

    if (gameBoard[0][2] + gameBoard[1][2] + gameBoard[2][2] == 360)
    return X_WON;

    if (gameBoard[0][0] + gameBoard[1][0] + gameBoard[2][0] == 333)
    return O_WON;
    
    if (gameBoard[0][1] + gameBoard[1][1] + gameBoard[2][1] == 333)
    return O_WON;

    if (gameBoard[0][2] + gameBoard[1][2] + gameBoard[2][2] == 333)
    return O_WON;
  
    //Diagonal win states
    if (gameBoard[0][0] + gameBoard[1][1] + gameBoard[2][2] == 360)
    return X_WON;
    
    if (gameBoard[2][0] + gameBoard[1][1] + gameBoard[0][2] == 360)
    return X_WON;
  
    if (gameBoard[0][0] + gameBoard[1][1] + gameBoard[2][2] == 333)
    return O_WON;
    
    if (gameBoard[2][0] + gameBoard[1][1] + gameBoard[0][2] == 333)
    return O_WON;
  */
  GameResult Board::gameState(){
    //Diagonal win states
    if (gameBoard[0][0] + gameBoard[1][1] + gameBoard[2][2] == 360)
    return X_WON;
    
    if (gameBoard[2][0] + gameBoard[1][1] + gameBoard[0][2] == 360)
    return X_WON;
  
    if (gameBoard[0][0] + gameBoard[1][1] + gameBoard[2][2] == 333)
    return O_WON;
    
    if (gameBoard[2][0] + gameBoard[1][1] + gameBoard[0][2] == 333)
    return O_WON;
    
    //horizontal
    int pointTally = 0;
        for (int counterCol = 0; counterCol < 3; counterCol++){
            if (pointTally == 360)
                return X_WON;
            if (pointTally == 333)
                return O_WON;
                
         pointTally = 0; //reset tally
            
        for (int counterRow = 0; counterRow < 3; counterRow++){
            pointTally += gameBoard[counterRow][counterCol];
            }
        }
    
    //vertical
    pointTally = 0;
        for (int counterRow = 0; counterRow < 3; counterRow++){
            if (pointTally == 360)
                return X_WON;
            if (pointTally == 333)
                return O_WON;
                
            pointTally = 0; // reset tally
            
            for (int counterCol = 0; counterCol < 3; counterCol++){
                pointTally += gameBoard[counterRow][counterCol];
            }
        }
        
    //Is the game finished? 
    for (int counterCol = 0; counterCol < 3; counterCol++){
        for (int counterRow = 0; counterRow < 3; counterRow++){
            if (gameBoard[counterCol][counterRow] == '\0')
                return UNFINISHED;
             }
        }
  
    //If checks above fail
    return DRAW;
}

void Board::print(){
    for (int counterRow = 0; counterRow < 3; counterRow++){
        
        if (counterRow != 0)
            std::cout << std::endl;

        for (int counterCol = 0; counterCol < 3; counterCol++){
        std::cout << gameBoard[counterRow][counterCol];
        }
    }
}

int main(){

    Board a;
   
a.makeMove(0,0,'x');
a.makeMove(0,2,'x');
a.makeMove(0,1,'o');
a.makeMove(1,0,'o');
a.makeMove(1,2,'x');
  a.makeMove(1,1,'o');
   a.makeMove(2,0,'x');
   a.makeMove(2,2,'o');
    a.makeMove(2,1,'x');

    GameResult finalRuling;

    a.print();

    std::cout << std::endl;

    finalRuling = a.gameState();

    std::cout << finalRuling;

    return 0;
}