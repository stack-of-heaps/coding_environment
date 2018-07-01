#include "menu.hpp"
#include "yomu.hpp"
#include <iostream>

void setupMatchPromptPlayer1() {

    int charChoice = 0;
    std::string charName;

    std::cout << "Player 1: Welcome to the MONSTER BASH !" << std::endl;
    std::cout << "Please choose from among these possible fighters: " << std::endl;
    std::cout << "1. Barbarian" << std::endl;
    std::cout << "2. Vampire" << std::endl;
    std::cout << "3. Medusa" << std::endl;
    std::cout << "4. Blue Men" << std::endl;
    std::cout << "5. Harry Potter" << std::endl;

    charChoice = intYomu(1, 5);

    switch (charChoice) {
        case 1: {
                    std::cout << "What's your Barbarian's name?" << std::endl;
                    getline(std::cin, charName);
                    p1 = new Barbarian(charName);
                    break; 
                }
        case 2: {
                    std::cout << "What's your Vampire's name?" << std::endl;
                    getline(std::cin, charName);
                    p1 = new Vampire(charName);
                    break; 
                }
        case 3: {
                    std::cout << "What's your Medusa's name?" << std::endl;
                    getline(std::cin, charName);
                    p1 = new Medusa(charName);
                    break; 
                }
        case 4: {
                    std::cout << "What's your BlueMen's name?" << std::endl;
                    getline(std::cin, charName);
                    p1 = new BlueMen(charName);
                    break; 
                }
        case 5: {
                    std::cout << "What's your Harry Potter's name?" << std::endl;
                    getline(std::cin, charName);
                    p1 = new HarryPotter(charName);
                    break; 
                }
    }
}

void setupMatchPromptPlayer2() {

    int charChoice = 0;
    std::string charName;

    std::cout << "Player 2: Welcome to the MONSTER BASH !" << std::endl;
    std::cout << "Please choose from among these possible fighters: " << std::endl;
    std::cout << "1. Barbarian" << std::endl;
    std::cout << "2. Vampire" << std::endl;
    std::cout << "3. Medusa" << std::endl;
    std::cout << "4. Blue Men" << std::endl;
    std::cout << "5. Harry Potter" << std::endl;

    charChoice = intYomu(1, 5);

    switch (charChoice) {
        case 1: {
                    std::cout << "What's your Barbarian's name?" << std::endl;
                    getline(std::cin, charName);
                    p2 = new Barbarian(charName);
                    break; 
                }
        case 2: {
                    std::cout << "What's your Vampire's name?" << std::endl;
                    getline(std::cin, charName);
                    p2 = new Vampire(charName);
                    break; 
                }
        case 3: {
                    std::cout << "What's your Medusa's name?" << std::endl;
                    getline(std::cin, charName);
                    p2 = new Medusa(charName);
                    break; 
                }
        case 4: {
                    std::cout << "What's your BlueMen's name?" << std::endl;
                    getline(std::cin, charName);
                    p2 = new BlueMen(charName);
                    break; 
                }
        case 5: {
                    std::cout << "What's your Harry Potter's name?" << std::endl;
                    getline(std::cin, charName);
                    p2 = new HarryPotter(charName);
                    break; 
                }
    }
}

void setupMatch() {

    setupMatchPromptPlayer1();
    setupMatchPromptPlayer2();

    match = new Match(p1, p2);

    andFight();

}

void playAgainPrompt() {

    int userChoice = 0;

    std::cout << "Would you like to play again?" << std::endl;
    std::cout << "1. Yes." << std::endl;
    std::cout << "2. No." << std::endl;

    userChoice = intYomu(1, 2, "strict");

    switch (userChoice) {
        case 1: {
                    match -> ~Match();
                    setupMatch();
                    break;
                }
        case 2: {
                    match -> ~Match();
                    delete match;
                    match = nullptr;
                    exit (EXIT_SUCCESS);
                    break;
                }
    }
}

void andFight(){

    bool keepFighting = true;

    while (keepFighting)  
        keepFighting = match -> oneRound();
        
    playAgainPrompt();
}
