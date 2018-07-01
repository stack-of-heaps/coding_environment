#include "animal.hpp"

#include <iostream>

/*
***EXTRA CREDIT:
CREATE MY OWN ANIMAL AND ADD IT TO THE ZOO.
NEEDS ITS OWN .HPP AND .CPP FILES
*/

Animal::Animal(int a, double c, int b, double aMultiplier, double qMultiplier, double poMultiplier) {
    age = a;
    cost = c;
    babies = b;
    animalMultiplier = aMultiplier;
    qualityMultiplier = qMultiplier;
    payoffMultiplier = poMultiplier;
    food = BASE_FOOD_COST * animalMultiplier * qualityMultiplier;
    payoff = cost * payoffMultiplier;
}

double Animal::feed(){

    age++;
    
    return food; 
}

double Animal::getPayoff() {
    return payoff;
}

double Animal::setFoodQualityMultiplier(double qMultiplier) {
    qualityMultiplier = qMultiplier;
}

double Animal::getFoodQuality() {
    return qualityMultiplier;
}

bool Animal::isAdult() {

    if (age >=3)
        return true;
    else
        return false;
}

int Animal::getBabies() {
    return babies;
}

void Animal::setAge(int a) {
    age = a;
}

double Animal::getCost() {
    return cost;
}

void Animal::info() {
    std::cout << "***ANIMAL***" << std::endl;
    std::cout << "age: " << age << std::endl;
    std::cout << "cost: " << cost << std::endl;
    std::cout << "babies: " << babies << std::endl;
    std::cout << "animal multiplier: " << animalMultiplier << std::endl;
    std::cout << "quality multiplier: " << qualityMultiplier << std::endl;
    std::cout << "payoff: " << payoffMultiplier << std::endl;
    std::cout << std::endl;
}


