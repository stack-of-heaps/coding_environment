#ifndef T3READER_HPP
#define T3READER_HPP

#include <string>

class T3Reader
{
    private:
    Board reRunGame;         //array to read in the game log from a file
    char playerTurn;        //playerTurn = 'x' or 'o'; indicates whose turn it is

    public:
    T3Reader();
    T3Reader(char playerSymbol);    //playerSymbol = playerTurn -> 'x' or 'o'
    void switchPlayerTurn();
    bool readGameFile(std::string fileName); //reads in game log file
};

#endif