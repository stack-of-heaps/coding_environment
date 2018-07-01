#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <iostream>
#include <string>

class Building {

    protected:
        std::string name;
        std::string address;
        double sqft;

    public:
        Building(std::string n, std::string addy, double area);
        void printInfo();
};

#endif
