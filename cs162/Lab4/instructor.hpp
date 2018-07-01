#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include "person.hpp"

#include <string>

class Instructor : public Person {

    protected:
        double rating = -1.0;

    public:
        Instructor(std::string n);
        void do_work();
        int randomizedAge();
        void printInfo();
        std::string getName();
};
#endif
