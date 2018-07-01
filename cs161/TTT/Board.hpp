#ifndef BOARD_HPP
#define BOARD_HPP

enum GameResult { X_WON, O_WON, DRAW, UNFINISHED };

class Board{
    private:
            char gameBoard[3][3];
    public:
            Board();
            bool makeMove(int, int, char);
            GameResult gameState();
            void print();
};
#endif