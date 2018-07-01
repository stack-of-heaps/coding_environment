#include "die.hpp"

Die::Die(){}

//This is the constructor we actually use for the program.
Die::Die(int sides) {
    n = sides;
}

int Die::getSides(){
    return n;
}

//Random number device generation code from:
//https://stackoverflow.com/questions/7617587/is-there-an-alternative-to-using-time-to-seed-a-random-number-generation
int Die::roll() {
    
    //Create "Mersenne Twister" (mt) which also uses "rd," random_device created in die.hpp
    std::mt19937 mt(rd());

    //Set type of randomization, output, and distribution range
    std::uniform_int_distribution<int> dist(1, n);

    int rollResult = dist(mt);

    return rollResult;
} 
