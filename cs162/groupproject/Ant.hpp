#ifndef ANT_HPP
#define ANT_HPP

#include "critter.hpp"

class Ant : public Critter
{
private:


public:

    Ant(char bugLetter, int xPos, int yPos);

    void move(int rows, int columns, Critter*** gameBoardPtr, int numberOfRows, int numberOfColumns);

};


#endif
