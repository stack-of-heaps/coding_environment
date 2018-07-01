#include "zoo.hpp"
#include "yomu.hpp"

/*
 *
 * Each turn is a “day”. At the beginning of the day, all animals increase age by 1 day, and the user needs to pay the feeding cost of each animal. Feeding is required so the animals don’t die. After the feeding cost is subtracted from the bank, one randomized event takes place during the day.  You can determine how to implement the random functions by yourself.  The random function will pick one random event from the following list:
 *
*
 * After the random event, calculate the profit for the day based on the number of each animals and their payoff. If there is a bonus for the day, add it to the profit as well. 
 *
 * Before the day ends, ask the player if they would like to buy an adult animal. If they do, ask for the type of animal they would like, then add the animal to the zoo and subtract that cost from the bank. The adult animal that is bought will be 3 days old.  
 *
 * After the end of a day, prompt user whether to keep playing or end the game. If the user has no money, print a message to tell the user the game is over, and end the game.
 *
*/

void Zoo::setup(){

    initializeAnimalArrays();

    int userInput;

    std::cout << "Let's get your Zoo started." << std::endl;
    std::cout << "You have $" << bankAccount << " to spend." <<std::endl;
    std::cout << "First, let's decide which animals to buy." << std::endl;
    std::cout << "Tigers cost $10,000 each." << std::endl;
    std::cout << "Penguins cost $1,000 each." << std::endl;
    std::cout << "Turtles cost $100 each." << std::endl;
    std::cout << "Please buy 1 or 2 of each animal." << std::endl;
    std::cout << "How many tigers?" << std::endl;

    userInput = intYomu(1, 2, "strict");

    newTiger(userInput);    

    std::cout << "How many penguins?" << std::endl;

    userInput = intYomu(1, 2, "strict");

    newPenguin(userInput);

    std::cout << "How many turtles?" << std::endl;

    userInput = intYomu(1, 2, "strict");

    newTurtle(userInput);

    std::cout << "How many days would you like to run the simulation for?" << std::endl;
    std::cout << "You will have a chance to add more time before the timer runs out." << std::endl;

    userInput = intYomu(1);

    setDays(userInput);

}

//done
int Zoo::getDays() {
    return days;
}

//done
int Zoo::getDaysElapsed() {
    return daysCounter;
}

//done
void Zoo::setDays(int num) {
    days += num;
}

void Zoo::run() {

    while (days >= 0) {
       
        daysCounter++;
        std::cout << "Day #" << daysCounter << std::endl;
        foodQualityPrompt();
        feedAnimals(); //This will also "age" the animals one day
        randomEventGenerator();
        animalPayoff();
        buyAnimalPrompt();
        daySummary();
        depositRevenue();
        costOfBusiness();

        if (bankAccount <= 0) {
            std::cout << "Whoops! You ran out of money. Game over." << std::endl;
            exit (EXIT_SUCCESS);
        }
        
        days--;

    };
}
/*********************************************
//ANIMAL ARRAY MANAGEMENT
**********************************************
//Instead of calling "newTiger()" by itself, we call roomForNewAnimalCheck to
//make sure we have room in the array. If not, it resizes the array and 
//then completes the creation of the new animals. If there is room in the array,
//it simply adds the animals.
**********************************************/

void Zoo::initializeAnimalArrays() {
    
    tigerCohort = new Tiger*[10];
    tigerArraySize = 10;
        
    turtleCohort = new Turtle*[10];
    turtleArraySize = 10;
        
    penguinCohort = new Penguin*[10];
    penguinArraySize = 10;
        
}

void Zoo::roomForNewAnimalCheck(int newAnimals, ANIMAL_TYPE animal) { 

    switch (animal) {
        case TIGER: { 
            if (newAnimals + numberOfTigers > tigerArraySize) {
                resizeAnimalArray(TIGER);                
                newTiger(newAnimals);
            }

            else 
                newTiger(newAnimals);

            break;
            }

        case PENGUIN: {
            if (newAnimals + numberOfPenguins > penguinArraySize) {
                resizeAnimalArray(PENGUIN);                
                newPenguin(newAnimals);
            }

            else 
                newPenguin(newAnimals);

            break;
        }

        case TURTLE: {
            if (newAnimals + numberOfTurtles > turtleArraySize) {
                resizeAnimalArray(TURTLE);                
                newTurtle(newAnimals);
            }

            else 
                newTurtle(newAnimals);

            break;
        }
   };
}

void Zoo::resizeAnimalArray(ANIMAL_TYPE animal){
   /*The process
    --New array created at arrayPointer address
    newArray = new animalType*[arraySize * 2];
    
    --Copy old array
    for (int i = 0; i < arraySize; i++)   
        newArray[i] = array[i];       
    
    --New array is complete; delete old    
    delete [] array;
    
    --Assign the new array to the old memory address
    array = newArray;
    */

    Tiger** newTigerArray;
    Turtle** newTurtleArray;
    Penguin** newPenguinArray;

    int arraySize;

    switch (animal) {
        case TIGER: {
            newTigerArray = new Tiger*[tigerArraySize * 2];
            
            for (int i = 0; i < numberOfTigers + 1; i++)   
                newTigerArray[i] = tigerCohort[i];       
            
            delete [] tigerCohort;
            
            tigerCohort = newTigerArray;

            tigerArraySize = tigerArraySize * 2;

            break;
        }

        case TURTLE: {
             newTurtleArray = new Turtle*[turtleArraySize * 2];
            
            for (int i = 0; i < numberOfTurtles + 1; i++)   
                newTurtleArray[i] = turtleCohort[i];       
            
            delete [] turtleCohort;
            
            turtleCohort = newTurtleArray;

            turtleArraySize = turtleArraySize * 2;

            break;
        }
        
        case PENGUIN: {
            newPenguinArray = new Penguin*[penguinArraySize * 2];
                
                for (int i = 0; i < numberOfPenguins + 1; i++)   
                    newPenguinArray[i] = penguinCohort[i];       
                
                delete [] penguinCohort;
                
                penguinCohort = newPenguinArray;

                penguinArraySize = penguinArraySize * 2;

                break;
        }
    
    };
}

void Zoo::animalDies(ANIMAL_TYPE animal){

    Tiger** newTigerArray;
    Turtle** newTurtleArray;
    Penguin** newPenguinArray;

    int arraySize;

    switch (animal) {
        case TIGER: {
            newTigerArray = new Tiger*[tigerArraySize];
            
            for (int i = 0; i < numberOfTigers; i++)   
                newTigerArray[i] = tigerCohort[i];       
            
            delete [] tigerCohort;
            
            tigerCohort = newTigerArray;

            numberOfTigers--;

            break;
        }

        case TURTLE: {
             newTurtleArray = new Turtle*[turtleArraySize];
            
            for (int i = 0; i < numberOfTurtles; i++)   
                newTurtleArray[i] = turtleCohort[i];       
            
            delete [] turtleCohort;
            
            turtleCohort = newTurtleArray;

            numberOfTurtles--;

            break;
        }
        
        case PENGUIN: {
            newPenguinArray = new Penguin*[penguinArraySize];
                
                for (int i = 0; i < numberOfPenguins; i++)   
                    newPenguinArray[i] = penguinCohort[i];       
                
                delete [] penguinCohort;
                
                penguinCohort = newPenguinArray;

                numberOfPenguins--;
                break;
        }
    
    };
}


void Zoo::newTiger(int newAnimals) {

    for (int i = numberOfTigers; i < numberOfTigers + newAnimals; i++) 
        tigerCohort[i] = new Tiger;
    
    numberOfTigers += newAnimals;
} 

void Zoo::newPenguin(int newAnimals) {

    for (int i = numberOfPenguins; i < numberOfPenguins + newAnimals; i++) 
        penguinCohort[i] = new Penguin;
    
    numberOfPenguins += newAnimals;
}

void Zoo::newTurtle(int newAnimals) {

    for (int i = numberOfTurtles; i < numberOfTurtles + newAnimals; i++) 
        turtleCohort[i] = new Turtle;

    numberOfTurtles += newAnimals;
}

/************************************************
 * FEEDING ANIMALS
 * *********************************************/

void Zoo::feedAnimals() {

    for (int i = 0; i < numberOfTigers; i++) 
        expense(tigerCohort[i] -> feed());

    for (int i = 0; i < numberOfPenguins; i++) 
        expense(penguinCohort[i] -> feed());

    for (int i = 0; i < numberOfTurtles; i++) 
        expense(turtleCohort[i] -> feed());
}

void Zoo::foodQualityPrompt() {

    double qualityLevel = getFoodQuality();
    std::string qualityString;

    if (qualityLevel == .5) 
        qualityString = "poor";
    else if (qualityLevel == 1.0)
        qualityString = "average";
    else if (qualityLevel == 2.0)
        qualityString = "high";
   
    int userChoice;

    std::cout << "Currently, you are feeding your animals " << qualityString << " food." << std::endl;
    std::cout << "Would you like to change this?" << std::endl;
    std::cout << "1. Yes" << std::endl;
    std::cout << "2. No" << std::endl;
    userChoice = intYomu(1, 2, "strict");

    if (userChoice == 1) {
        std::cout << "1. Poor quality" << std::endl;
        std::cout << "2. Average quality" << std::endl;
        std::cout << "3. High quality" << std::endl;

       int qualityChoice = intYomu(1, 3);

       switch (qualityChoice) {
           case 1: setFoodQuality(.5);
                   break;
           case 2: setFoodQuality(1.0);
                   break;
           case 3: setFoodQuality(2.0);
                   break;
       };

    }
}

double Zoo::getFoodQuality() {

    if (numberOfTigers > 0)
        return tigerCohort[0] -> getFoodQuality();
    else if (numberOfPenguins > 0)
        return penguinCohort[0] -> getFoodQuality();
    else if (numberOfTurtles > 0)
        return turtleCohort[0] -> getFoodQuality();
}

void Zoo::setFoodQuality(double qualityChoice) {

    for (int i = 0; i < numberOfTigers; i++) 
        tigerCohort[i] -> setFoodQualityMultiplier(qualityChoice);

    for (int i = 0; i < numberOfPenguins; i++) 
        penguinCohort[i] -> setFoodQualityMultiplier(qualityChoice);

    for (int i = 0; i < numberOfTurtles; i++) 
        turtleCohort[i] -> setFoodQualityMultiplier(qualityChoice);
}

/**********************************************
 * FINANCIALS
 * *******************************************/

void Zoo::expense(double amount) {
    dailySpending += amount;
}

void Zoo::income(double amount) {
    dailyEarnings += amount;
}

void Zoo::depositRevenue(){
    bankAccount += dailyEarnings;
    dailyEarnings = 0;
}

void Zoo::costOfBusiness(){
    bankAccount -= dailySpending;
    dailySpending = 0;
}

void Zoo::animalPayoff() {

    for (int i = 0; i < numberOfTigers; i++) 
        income(tigerCohort[i] -> getPayoff());

    for (int i = 0; i < numberOfTurtles; i++) 
        income(turtleCohort[i] -> getPayoff());

    for (int i = 0; i < numberOfPenguins; i++) 
        income(penguinCohort[i] -> getPayoff());
}

//Financial summary for the day AND the mechanism for adding more days or letting the Zoo simulation end
void Zoo::daySummary() {

    std::cout << "Summary for the Zoo, Day #" << daysCounter << ":" << std::endl;

    std::cout << "Revenue: $" << dailyEarnings << std::endl;
    std::cout << "Operation Cost: $" << dailySpending << std::endl;
    std::cout << "Profit: $" << dailyEarnings - dailySpending << std::endl;
    std::cout << "Funds in the bank: $" << bankAccount << std::endl;
    std::cout << "# of tigers: " << numberOfTigers << std::endl;
    std::cout << "Tiger Array: " << tigerArraySize << std::endl;
    std::cout << "# of turtles: " << numberOfTurtles << std::endl;
    std::cout << "turtle array: " << turtleArraySize << std::endl;
    std::cout << "# of penguins: " << numberOfPenguins << std::endl;
    std::cout << "penguin array: " << penguinArraySize << std::endl;

    int keepRunning = -1;

    if (days - 1 == 0) {
        std::cout << "Tomorrow is the Zoo's last scheduled day. Do you want to add more?" << std::endl;
        std::cout << "Enter 1 for yes, 2 for no." << std::endl;
        keepRunning = intYomu(1, 2, "strict");

        if (keepRunning == 1) {

            std::cout << "How many days should we add?" << std::endl;
            setDays(intYomu(1));
        }
        else 
            std::cout << "Okay, tomorrow will be the Zoo's last day." << std::endl;
    }
}

/***********************************
 * RANDOM EVENTS
 * 1. Random animal dies
 * 2. Attendance boost
 * 3. Random baby is born
 * 4. Nothing
 * ********************************/

void Zoo::randomEventGenerator(){

    //initialize the randomizer
    std::mt19937 mt(rd());

    //Set type of randomization, output, and distribution range
    //Dist1 selects for the type of random event with NORMAL QUALITY FOOD
    //1 = random sickness
    //2 = attendance boom
    //3 = baby is born
    //4 = nothing special happens
    std::uniform_int_distribution<int> normalFood(1, 4);

    //for bad food
    //discrete_distribution is initialized here such that 
    //0 has 0 chance of being "rolled,"
    //"1" has 2x chance,
    //"2" has 1x chance,
    //"3" has 1x chance,
    //"4" has 1x chance
    std::discrete_distribution<int> badFood {0, 2, 1, 1, 1}; 

    //for good food
    std::discrete_distribution<int> goodFood {0, .5, 1, 1, 1};

    //dist 2, in random sickness, selects which kind of animal gets sick
    std::uniform_int_distribution<int> whichAnimal(0, 2);

    int randomEvent;

    double foodType = getFoodQuality();

    if (foodType == .5)
        randomEvent = badFood(mt);
    if (foodType == 1)
        randomEvent = normalFood(mt);
    if (foodType == 2)
        randomEvent = goodFood(mt);

        switch (randomEvent) {
            case 1: randomSickness("randomSickness.txt", (whichAnimal(mt)));
                    break;
            case 2: randomAttendanceBoom("randomAttendanceBoom.txt");
                    break;
            case 3: randomBabyIsBorn("randomBabyIsBorn.txt");
                    break;
            case 4: std::cout << "Just a normal day at the Zoo!" << std::endl;
                    break;
        };
}
 
/********************
 * RANDOM ANIMAL DIES
 * ******************/

//Random Sickness file has 3 lines, one for each animal. 
//Read in each line, make an array of the lines, then take a randomly generated
//number between 1 and 3. This will represent the animal that randomly dies.
//This is based on the line numbers in the text file.
//Line 1 -> Tiger
//Line 2 -> Turtle
//ilne 3 ->  Penguin
void Zoo::randomSickness(std::string textFile, int line){

    std::string readLineIn;
    std::string fileOutput[3];

    std::fstream file;

    file.open(textFile, std::ios::in);

    for (int i = 0; i < 3; i++) {
        getline(file, readLineIn);

        fileOutput[i] =  readLineIn;
    }

    std::cout << fileOutput[line] << std::endl;

    switch (line) {
        case 0: animalDies(TIGER);
            break;
        case 1: animalDies(TURTLE);
            break;
        case 2: animalDies(PENGUIN);
            break;
    };
}

/***************************
 * RANDOM ATTENDANCE BOOM
 * *************************/
void Zoo::randomAttendanceBoom(std::string textFile){

    std::mt19937 mt(rd());

    std::uniform_real_distribution<double> dollarAmount(250.0, 500.0);

    double tigerBonus = dollarAmount(mt);
    std::string input;
    std::fstream thisFile;
    
    thisFile.open(textFile, std::ios::in);

    while (thisFile) {
        std::cout << input << std::endl;
        getline(thisFile, input);
    };

    std::cout << "You will receive a bonus of $" << tigerBonus << " per tiger." << std::endl;

    income(numberOfTigers * tigerBonus);

} 

/*****************
 * BABY IS BORN !
 * ***************/

void Zoo::randomBabyIsBorn(std::string textFile) {

// are there any adult animals at the zoo?

    
    if (areThereAnyAdults())
        randomBabyEvent();

    else 
        randomEventGenerator();

}
    //if a given animal cohort has no adults, they can't produce a baby

void Zoo::randomBabyEvent() {

    //prepare baby birth messages
    std::string readLineIn;
    std::string fileOutput[3];

    std::fstream file;

    file.open("randomBabyIsBorn.txt", std::ios::in);

    for (int i = 0; i < 3; i++) {
        getline(file, readLineIn);
        fileOutput[i] = readLineIn;
    }

    //initialize the randomizer
    std::mt19937 mt(rd());

    //Set type of randomization, output, and distribution range
    //We will use the same integer types again:
    //1 -> Tiger
    //2 -> Turtle
    //3 -> Penguin
    std::uniform_int_distribution<int> dist(1, 3);

    int randomInt = dist(mt);

    switch (randomInt) {
        case 1: {
            if ((areThereAnyAdults(1))) {
                int numBabies = tigerCohort[0] -> getBabies();
                roomForNewAnimalCheck(numBabies, TIGER);
                std::cout << fileOutput[0] << std::endl;
            }
            else
                randomBabyEvent();
            break;
        }

        case 2: {
            if ((areThereAnyAdults(2))) {
                int numBabies = turtleCohort[0] -> getBabies();
                roomForNewAnimalCheck(numBabies, TURTLE);
                std::cout << fileOutput[1] << std::endl;
            }
            else
                randomBabyEvent();
            break;
        }
          case 3: {
            if ((areThereAnyAdults(3))) {
                int numBabies = penguinCohort[0] -> getBabies();
                roomForNewAnimalCheck(numBabies, PENGUIN);
                std::cout << fileOutput[2] << std::endl;
            }
            else
                randomBabyEvent();
            break;
        }
    };
    
} 

//If param is default value of 0, checks all animal arrays for adults
//If param is 1, checks only for Tiger adults
//If 2, checks only for Turtle adults
//If 3, checks only for Penguin adults
bool Zoo::areThereAnyAdults(int animalChoice) {

    switch (animalChoice) {

        case 1: {
            for (int i = 0; i < numberOfTigers; i++) {
                if (tigerCohort[i] -> isAdult() == true)
                    return true;
            }
            break;
        }   
 
        case 2: {
            for (int i = 0; i < numberOfTurtles; i++) {
                if (turtleCohort[i] -> isAdult() == true)
                    return true;
            }
            break;
        }

        case 3: {
            for (int i = 0; i < numberOfPenguins; i++) {
                if (penguinCohort[i] -> isAdult() == true)
                    return true;
            }
            break;
        }
        default: {
            for (int i = 0; i < numberOfTigers; i++) {
                if (tigerCohort[i] -> isAdult() == true)
                    return true;
            }
 
            for (int i = 0; i < numberOfTurtles; i++) {
                if (turtleCohort[i] -> isAdult() == true)
                    return true;
            }

            for (int i = 0; i < numberOfPenguins; i++) {
                if (penguinCohort[i] -> isAdult() == true)
                    return true;
            }
            break;
        }
    }
}

/*********************************
 * BUY AN ADULT ANIMAL?
 ********************************/

void Zoo::buyAnimalPrompt() {

    std::cout << "Would you like to buy an adult animal?" << std::endl;

    int userChoice;

    std::cout << "1. Yes" << std::endl;
    std::cout << "2. No" << std::endl;

    userChoice = intYomu(1, 2, "strict");

    if (userChoice == 1) {
        std::cout << "Which animal?" << std::endl;
        std::cout << "1. Tiger" << std::endl;
        std::cout << "2. Turtle" << std::endl;
        std::cout << "3. Penguin" << std::endl;
        userChoice = intYomu(1, 3);

        switch (userChoice) {
            case 1: {
                roomForNewAnimalCheck(1, TIGER);
                expense(tigerCohort[numberOfTigers -1] -> getCost());
                tigerCohort[numberOfTigers - 1] -> setAge(3);
                break;
            }
            case 2: {
                roomForNewAnimalCheck(1, TURTLE);
                expense(turtleCohort[numberOfTurtles -1] -> getCost());
                turtleCohort[numberOfTurtles - 1] -> setAge(3);
                break;
            }
            case 3: {
                roomForNewAnimalCheck(1, PENGUIN);
                expense(penguinCohort[numberOfPenguins -1] -> getCost());
                penguinCohort[numberOfPenguins - 1] -> setAge(3);
                break;
             }
         };
    }
}

/**************************************
 * TESTING
 * ***********************************/

void Zoo::printAnimalInfo() {

    int counter = 1;

    std::cout << "Tigers: " << numberOfTigers << std::endl;
    for (int i = 0; i < numberOfTigers; i++){
        std::cout << "Tiger #: " << counter << std::endl;
        tigerCohort[i] -> info();
        counter++;
    }

    counter = 1;

    std::cout << "Penguins: " << numberOfPenguins << std::endl;
        for (int i = 0; i < numberOfPenguins; i++){ 
            std::cout << "Penguin #: " << counter << std::endl;
            penguinCohort[i] -> info();
            counter++;
        }

    counter = 1;

    std::cout << "Turtles: " << numberOfTurtles << std::endl;
        for (int i = 0; i < numberOfTurtles; i++) {
            std::cout << "Turtle #: " << counter << std::endl;
            turtleCohort[i] -> info();
            counter++;
        }

}

