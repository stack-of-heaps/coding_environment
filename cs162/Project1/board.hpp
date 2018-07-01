#ifndef BOARD_HPP
#define BOARD_HPP
#include <iostream>
#include <cstdlib>

class Board {
    private:
        int xDimension; //x and y dimensions of initialized board
        int yDimension;
        char** boardGoesHere; //uninitialized board placeholder
    public:
        void initBoard();
        ~Board();
        void dispBoard(int* antPosition); //Takes Langton's position and displays board
        void updateBoard(int* pos); //Takes Langton's position and updates square color
        char tileColor(int* antPosition);
        int getXLimit();
        int getYLimit();
};

#endif
