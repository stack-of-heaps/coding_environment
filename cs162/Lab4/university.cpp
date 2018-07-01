#include "university.hpp"
#include "yomu.hpp"

//Use this to add a building via main.cpp
void University::addBuilding(std::string n, std::string addy, double area) {
    buildings.emplace_back(new Building(n, addy, area));
}

//Use this to add a student via main.cpp
void University::addStudent(std::string n) {
    people.emplace_back(new Student(n));
}

//Use this to add an instructor via main.cpp
void University::addInstructor(std::string n) {
    people.emplace_back(new Instructor(n));
}

//This prints all of the building info contained within the buildings vector
void University::printBuildingInfo() {

    int counter = 1;

    for (int i = 0; i < buildings.size(); i++) {
        std::cout << "Building #" << counter << std::endl;
        buildings[i] -> printInfo();
        counter++;
    }
}

//This prints all of the info contained within the people vector
void University::printPeopleInfo() {

    int counter = 1;
    for (int i = 0; i < people.size(); i++) {
        std::cout << "Person #" << counter << std::endl;
        people[i] -> printInfo();
        counter++;
    }
}

//Returns the university's name
std::string University::printUName() {
    return name;
}

//Used for menu option 3: Display all people at the university and
//prompt the user to choose one to "do work" (do_work()). Program exits thereafter
void University::chooseWork() {
    for (int i = 0; i < people.size(); i++) {
        std::cout << i + 1 << ": " << people[i] -> getName() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Whom would you like to do some work?" << std::endl;
    std::cout << "Please enter a number between 1 and " << people.size() << std::endl;
    int userChoice = intYomu(1, people.size());

    people[userChoice - 1] -> do_work();
} 
