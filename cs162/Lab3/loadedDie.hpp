#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP

#include "die.hpp"

class LoadedDie: public Die {
    private:
        double weight; // Weights random results toward high numbers by 
                                //a factor of 1.25x

    public:
        LoadedDie();
        LoadedDie(int sides, double userWeight);
        int roll();
        double getWeight();
        int getSides();
};
#endif
