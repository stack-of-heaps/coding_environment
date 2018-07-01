#include "menu.hpp"
#include "yomu.hpp"

#include <iostream>

//The base function here simply asks if we want to play or not
int menu(){

    int inputChecker = -1;

        std::cout << "1. Play Game" << std::endl;
        std::cout << "2. Quit" << std::endl;
        inputChecker = intYomu(1, 2, "strict");

        if (inputChecker == 2) 
            exit(EXIT_SUCCESS);

}

//This menu function prompts the user to choose which kind of die to play with
int menuChooseDieType(int playerNumber) {

    std::cout << "Player " << playerNumber << ": What kind of die will you use?" << std::endl;
    std::cout << "1. Standard" << std::endl;
    std::cout << "2. Loaded" << std::endl;

    int inputChecker = -1;
inputChecker = intYomu(1, 2, "strict");

return inputChecker;
}

//This menu function asks how many rounds the game will consist of
int menuHowManyRounds() {
    std::cout << "How many rounds in this match?" << std::endl;

    int userChoice = intYomu(1);

    return userChoice;
}
