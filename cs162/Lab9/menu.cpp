#include "menu.hpp"
#include "yomu.hpp"
#include "buffer.hpp"
#include "stack.hpp"
#include <iostream>
#include <stack>


bool init() {
    std::cout << "1. Buffer" << std::endl;
    std::cout << "2. Stack" << std::endl;
    std::cout << "3. Quit" << std::endl;

    int userInput = intYomu(1, 3);

    if (userInput == 1)
        runBuffer();
    else if (userInput == 2)
        runStack();
    else if (userInput == 3)
        return false;
}

void runBuffer() {

    std::cout << "Buffer simulation" << std::endl;

    std::cout << "How many steps in the simulation?" << std::endl;

    int simSteps = intYomu(1);
   
    std::cout << "What is the chance that a random number is added to the buffer?" << std::endl;
   
    int addThreshold = intYomu(0, 100);
   
    std::cout << "What is the chance that a number is removed from the end of the buffer?" << std::endl;
    
    int removeThreshold = intYomu(0, 100);

    bufferSim(simSteps, addThreshold, removeThreshold);

    std::cout << std::endl;

    init();
}


void runStack() {

    std::cout << "Please enter a string." << std::endl;
    //Capture user string input
    std::string userString;
    getline(std::cin, userString);
    
    palindromer(userString);

    std::cout << std::endl;

    init();
}
