#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "person.hpp"

#include <string>

class Student : public Person {

    protected:
        double GPA = -1.0;

    public:
        Student(std::string n);
        void do_work();
        int randomizedAge();
        void printInfo();
        std::string getName();

};

#endif
