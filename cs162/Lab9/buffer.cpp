#include "buffer.hpp"

void bufferSim(int steps, int addT, int removeT) {

    //setting up random number generators
    std::random_device randomGenerator;
    std::mt19937 Twister(randomGenerator());

    //Call n(Twister) to generate N
    std::uniform_int_distribution<int> n(0, 1000);
    //Call to100(Twister) to generate random numbers to compare to 
    //removeT and addT
    std::uniform_int_distribution<int> to100(0, 100);

    std::list<int> simList;

    int stepCounter = 1;

    while (stepCounter < steps) {

        int addRoll = to100(Twister);
        int removeRoll = to100(Twister);
        int rolledN = n(Twister);

        std::cout << "Step #" << stepCounter << std::endl;
        std::cout << "N: " << rolledN << std::endl;
        std::cout << "Add Threshold: " << addT << std::endl;
        std::cout << "Remove Threshold: " << removeT << std::endl;
        std::cout << "Add Threshold Roll: " << addRoll << std::endl;
        std::cout << "Remove Threshold Roll: " << removeRoll << std::endl;
        
        if (addRoll <= addT) {
            simList.push_back(rolledN);
            std::cout << "Adding " << rolledN << " to the back of the buffer." << std::endl;
        }

        if ((!simList.empty()) && removeRoll <= removeT) {
            simList.pop_front();
            std::cout << "Removing first number in the buffer." << std::endl;
        }
        
        //Average length of buffer
        int buffSize = simList.size();
        std::cout << "Buffer Average Length: "; 
        std::cout << averageLength(stepCounter, buffSize);
        std::cout << std::endl;
        //Printing the buffer
        std::cout << "Values held in buffer: ";

        //We won't print if at the last step
        if (stepCounter != steps -1) {

            //Printing
            //To print, we create an iterator set to the front of the list, then increment until at the back
        auto listIter = simList.begin();
        while (listIter != simList.end()) {
            std::cout << " " << *listIter;
            listIter++;
        }

    }

        std::cout << std::endl;
        std::cout << std::endl;

        stepCounter++;
}

    //Print the queue at the end
    while (!simList.empty()) {
        std::cout << " " << simList.front();
        simList.pop_front();

    }
}

//Calculate the average length of the buffer.
//Last average length is static so we can preserve the value between function calls
double averageLength(int steps, int size) {
 
    static double lastAverageLength = 0;
    double averageLength;

    averageLength = (lastAverageLength * (steps - 1) + size ) / (steps);

    lastAverageLength = averageLength;

    return averageLength;
} 

