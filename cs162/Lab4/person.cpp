#include "person.hpp"

//As GPA, rating, and age are all randomized for each Person and Instructor object,
//we only need to ask for the name as input
Person::Person(std::string n) {
    name = n;
    
}

//returns a randomized rating for an instructor
double Person::randomizedRating() {
    return ratingDist(theTwister);
}

//returns a randomized gpa for a student
double Person::randomizedGPA() {
    return gpaDist(theTwister);
}

//returns random hours for a student or instructor to "do work"
int Person::randomizedAvailability() {
    return hoursAvailableDist(theTwister);
}
