#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include "student.hpp"
#include "instructor.hpp"
#include "building.hpp"

#include <vector>
#include <string>
#include <iostream>

class University {

    private:
    std::vector<Person*> people;
    std::vector<Building*> buildings;

    std::string name = "Oregon State University";

    public:
    void printBuildingInfo();
    void printPeopleInfo();
    void chooseWork();

    void addBuilding(std::string n, std::string addy, double area);
    void addStudent(std::string n);
    void addInstructor(std::string n);

    std::string printUName();
    

};

#endif
