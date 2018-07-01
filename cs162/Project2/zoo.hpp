#ifndef ZOO_HPP
#define ZOO_HPP

#include "animal.hpp"
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"
#include "yomu.hpp"

#include <string>
#include <fstream>
#include <ctime>
#include <algorithm>

enum ANIMAL_TYPE { TIGER, TURTLE, PENGUIN } ;

class Zoo {

    private:
        double bankAccount = 100000.0;
        double dailySpending = 0.0; // Amount of money spent by zoo in a day
        double dailyEarnings = 0.0;

        int days = 0;           // How many days to run the zoo--counts down
        int daysCounter = 0;    // Days elapsed

        Tiger** tigerCohort;
        Penguin** penguinCohort;
        Turtle** turtleCohort;

        int numberOfTigers = 0;
        int numberOfPenguins = 0;
        int numberOfTurtles = 0;

        int tigerArraySize = 10;
        int turtleArraySize = 10;
        int penguinArraySize = 10;

        double getFoodQuality();

        void foodQualityPrompt();
        void setFoodQuality(double qualityChoice);

        std::random_device rd;

    public:

        void setup();
        void setDays(int num);
        void run();         //move one day forward. all animals age. 

        int getDays();
        int getDaysElapsed();

        void newTiger(int newAnimals);
        void newPenguin(int newAnimals);
        void newTurtle(int newAnimals);

        //Checks to see if given animal array has room for new animals. If not, resizes.
        void roomForNewAnimalCheck(int newAnimals, ANIMAL_TYPE animal);
        //Allocates new array double the size of the original, copies contents of the old,
        //deletes the old, and reassigns the new array to the old memory location
        void resizeAnimalArray(ANIMAL_TYPE animalType);
        
        //Initializes all animal arrays to size 10 and populates them with uninitialized animal instances
        void initializeAnimalArrays();

        void income(double amount); // Add money to be deposited into bank account at the end of the day 
        void expense(double amount); // Add money to be withdrawn from the bank account at the end of the day
        void depositRevenue(); //Add money to bank account
        void costOfBusiness(); //Take money out of bank account
        void daySummary();

        void animalPayoff(); // Calculate how much we earn from each animal
        void feedAnimals(); // Feed all animals. All animals age.

        void randomEventGenerator(); //Select a random event to occur

        void randomSickness(std::string textFile, int line); //Random animal dies
        void animalDies(ANIMAL_TYPE animalType); //This actually "kills" the animal

        void randomAttendanceBoom(std::string textFile); //Make more money per tiger

        void randomBabyIsBorn(std::string textFile);
        void randomBabyEvent();
        bool areThereAnyAdults(int animalChoice = 0); //Make sure we have adult animals that can have babies

        void buyAnimalPrompt(); // Does the user want to buy any animals?

        void printAnimalInfo();

};
#endif
