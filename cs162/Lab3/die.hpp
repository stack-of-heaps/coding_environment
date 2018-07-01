#ifndef DIE_HPP
#define DIE_HPP
#include "yomu.hpp"

#include <random>
#include <cstdlib>
#include <ctime>
#include <iostream>

class Die {
    
    protected:
        int n;
        int score;
        std::random_device rd;

    public:
        Die();
        Die(int sides);
        virtual int roll();
        int getSides();
};

#endif
