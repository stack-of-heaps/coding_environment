#ifndef PERSON_INCLUDED
#define PERSON_INCLUDED

#include <iostream>
#include <string>
#include <random>

//setting up our Mersenne Twister
static std::random_device randyEngine;
static std::mt19937 theTwister(randyEngine());

//to call a random professor rating -> ratingDist(theTwister);
//aliased below as randomizedRating();
static std::uniform_real_distribution<double> ratingDist(0.0, 5.0);

//to call a random gpa -> gpaDist(theTwister);
//aliased below as randomizedGPA();
static std::uniform_real_distribution<double> gpaDist(0.0, 4.0);

//to call a random hours available for work -> hoursAvailableDist(theTwister);
//we will alias this as randomizedAvailability();
static std::uniform_int_distribution<int> hoursAvailableDist(2, 8);

//randomized student age
static std::uniform_int_distribution<int> studentAgeDist(18, 30);

//randomized instructor age
static std::uniform_int_distribution<int> instructorAgeDist(30, 72);

class Person {

    protected:
        std::string name;
        int age;

    public:
        Person(std::string n);

        double randomizedRating();
        double randomizedGPA();
        int randomizedAvailability();

        virtual int randomizedAge() = 0;
        virtual void do_work() = 0;
        virtual void printInfo() = 0;
        virtual std::string getName() = 0;

};

#endif
