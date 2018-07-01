#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "character.hpp"

class BlueMen : public Character {

    public:
        BlueMen(std::string n);
        int defend(int attack);
        void mobStrength();
        
};

#endif
