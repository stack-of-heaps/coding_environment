#include "student.hpp"

//The constructor only takes the name of the student as a parameter.
//GPA and age are randomized
Student::Student(std::string n) : Person(n) {
    GPA = randomizedGPA();
    age = randomizedAge();
}

//returns a random age
int Student::randomizedAge() {
    return studentAgeDist(theTwister);
}

//returns a randomized number of hours of homework done
void Student::do_work() {
    std::cout << name << " did " << randomizedAvailability() << " hours of homework." << std::endl;
}

//prints name, age, gpa
void Student::printInfo() {

    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "GPA: " << GPA << std::endl;
    
}

//returns the student's name
std::string Student::getName() {
    return name;
}
