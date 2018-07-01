#ifndef DOODLE_HPP
#define DOODLE_HPP

#include "critter.hpp"

class Doodle : public Critter{

public:

    Doodle(char bugLetter, int xPos, int yPos);

    void move(int rows, int columns, Critter*** gameBoardPtr, int numberOfRows, int numberOfColumns);


};

#endif // 
