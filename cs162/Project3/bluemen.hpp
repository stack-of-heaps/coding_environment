#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "character.hpp"

class BlueMen : public Character {

    public:
        BlueMen(std::string n);
        void defend(int* attackArray);
        void mobStrength();
        
};

#endif
