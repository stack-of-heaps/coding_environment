#include "building.hpp"

//Building's instructor requires a building name, address, and square footage
Building::Building(std::string n, std::string addy, double area) {
    name = n;
    address = addy;
    sqft = area;
}

void Building::printInfo() {

    std::cout << "Name: " << name << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "Area: " << sqft << std::endl;

}


