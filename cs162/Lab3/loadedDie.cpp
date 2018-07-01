#include "loadedDie.hpp"
#include "die.hpp"

LoadedDie::LoadedDie(){}

//this is the constructor we actually use in the program
LoadedDie::LoadedDie(int sides, double userWeight) {
    n = sides;
    weight = userWeight;
}


/********************************
 * int roll()
 * *****************************
//Handles rolling of the loaded die
// When roll is evaluated, an element of the array is randomly chosen and
//   converted to an int. 
//   Because the roll value can't be higher than the number of sides,
//   the program will convert any roll values higher than # sides to the # of sides.
*/

//See die.cpp for source, but this is taken from a StackOverflow post
int LoadedDie::roll(){
    std::mt19937 mt(rd());

    //Set type of randomization, output, and distribution range
    std::uniform_int_distribution<int> dist(1, n);

    int rollResult = dist(mt) * weight;

    if (rollResult > n)
        return n;
    else
        return rollResult;
}

/******************************
 * Getter functions
 * ***************************/
double LoadedDie::getWeight() {
    return weight;
}

int LoadedDie::getSides() {
   return n;
}
