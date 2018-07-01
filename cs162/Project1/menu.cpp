//************************************************************************
//Name: Kyle Karthauser
//Date: 4/9/18
//Description: A very basic menu routine or two to get Langton's Ant
//simulation going.
//
//int menu() asks the user if they would like to begin or quit the program.
//Quits are handled by returning 0 to main().
//
//If we want to run the program, an Ant is created, which calls the
//Ant constructor implicitly.
//
//After the simulation runs, the menu asks if we would like to run again. 
//This is handled simply and efficiently but calling menu() to start
//the whole process over, if the user elects to run the program again.
//*************************************************************************
#include "menu.hpp"
#include "board.hpp"
#include "ant.hpp"
#include "yomu.hpp"

int menu() {

    bool validInput = false;
    int inputChecker;
    std::string inputString;
    std::cout << "Start the simulation?" << std::endl;
    std::cout << "1. Yes " << std::endl;
    std::cout << "2. No " << std::endl;
    std::cin.clear();
     
     do {
       getline(std::cin, inputString);

       inputChecker = yomu(inputString);

       switch (inputChecker) {
            case -1: std::cout << "Invalid input. Please enter 1 or 2." << std::endl;
                     break;
            case 2: {
                        validInput = true;
                        return 0;
                        break;
                    }
            case 1: validInput = true;
                    break;
            default: std::cout << "Invalid input. Please try again." << std::endl;
        }
     } while (!validInput);

    //We're only here if the user inputs 1 to run simulation. Create ant. Run.
    Ant langton;
    
    bool runSimulation = true;
    do {
        runSimulation = langton.evaluate();
    } while (runSimulation);

    validInput = false;
    inputChecker = 0;
    inputString = "";
    std::cout << "Run again?" << std::endl;
    std::cout << "1. Yes " << std::endl;
    std::cout << "2. No " << std::endl;

     do {
       getline(std::cin, inputString);

        inputChecker = yomu(inputString);

        switch (inputChecker) {
            case -1: std::cout << "Invalid input. Please enter 1 or 2." << std::endl;
                     break;
            case 2: {
                        validInput = true;
                        return 0;
                        break;
                    }
            case 1: validInput = true;
                    break;
            default: std::cout << "Invalid input. Please try again." << std::endl;
        }
     } while (!validInput);

        menu();
}
