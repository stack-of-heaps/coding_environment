#include "menu.hpp"
#include "yomu.hpp"
#include <iostream>

bool doWePlay() {
    std::cout << "1. Play game" << std::endl;
    std::cout << "2. Exit" << std::endl;
    int userChoice = intYomu(1, 2, "strict");

    if (userChoice == 1)
        return true;
    else
        return false;
}

void setupLineup(Lineup* roster) {

    int charChoice = 0;
    std::string charName;

    std::cout << "Welcome to the MONSTER BASH !" << std::endl;
    std::cout << "How many fighters are we going to add to " << roster -> getLineupName() << std::endl;
    int fighterNumber = intYomu(1);

    int counter = 0;

    while (counter < fighterNumber) {
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
                        roster -> addBack(new Barbarian(charName));
                        counter++;
                        break; 
                    }
            case 2: {
                        std::cout << "What's your Vampire's name?" << std::endl;
                        getline(std::cin, charName);
                        roster -> addBack(new Vampire(charName));
                        counter++;
                        break; 
                    }
            case 3: {
                        std::cout << "What's your Medusa's name?" << std::endl;
                        getline(std::cin, charName);
                        roster -> addBack (new Medusa(charName));
                        counter++;
                        break; 
                    }
            case 4: {
                        std::cout << "What's your BlueMen's name?" << std::endl;
                        getline(std::cin, charName);
                        roster -> addBack(new BlueMen(charName));
                        counter++;
                        break; 
                    }
            case 5: {
                        std::cout << "What's your Harry Potter's name?" << std::endl;
                        getline(std::cin, charName);
                        roster -> addBack(new HarryPotter(charName));
                        counter++;
                        break; 
                    }
        }
    }
}

void setupMatch() {
    Lineup* team1 = new Lineup("Red Team");
    Lineup* team2 = new Lineup("Blue Team");
    Lineup* losers = new Lineup("Losers");
    Match* theMatch;
        
    setupLineup(team1);
    setupLineup(team2);

    team1 -> printLineup();
    team2 -> printLineup();

    theMatch = new Match(team1, team2, losers);

    theMatch -> andFight();


    playAgainPrompt();

}

int playAgainPrompt() {

    int userChoice = 0;

    std::cout << "1. Play again" << std::endl;
    std::cout << "2. Quit" << std::endl;

    userChoice = intYomu(1, 2, "strict");

    switch (userChoice) {
        case 1: {
                    setupMatch();
                    break;
                }
        case 2: {
                    exit (EXIT_SUCCESS);
                    break;
                }
    }
}

void andFight(Lineup* roster1, Lineup* roster2){

    bool keepFighting = true;

    while (keepFighting)  
        match -> oneRound();
        
    playAgainPrompt();
}
