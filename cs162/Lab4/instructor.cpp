#include "instructor.hpp"

//Instructor only needs a name as input parameter.
//Rating and age are both randomzied
Instructor::Instructor(std::string n) : Person(n) {
    rating = randomizedRating();
    age = randomizedAge();
}

//prints how long the instructor graded papers for
void Instructor::do_work() {

    std::cout << name << " graded papers for " << randomizedAvailability() << " hours." << std::endl;

}

//returns a randomized age
int Instructor::randomizedAge() {
    return instructorAgeDist(theTwister);
}

//prints name, age, rating
void Instructor::printInfo() {

    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Rating: " << rating << std::endl;
    
}
//returns the instructor's name
std::string Instructor::getName() {
    return name;
}
