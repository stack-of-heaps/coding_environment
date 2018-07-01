#include "university.hpp"
#include "yomu.hpp"

int main() {

    //instantiating university and adding personnel/buildings
    University a;

    Person* b;
    b = new Instructor("billy thorn");
    a.addInstructor("billy bob");
    a.addInstructor("john mayhew");
    a.addInstructor("peter jackson");
    a.addStudent("billy madison");
    a.addStudent("money bags");
    a.addStudent("steve naptoo");
    a.addBuilding("SD Combine Shed", "2000 NE GRANGER AVE CORVALLIS, OR 97331", 9040);
    a.addBuilding("FRL Lumber Storage", "CORVALLIS, OR 97331", 1966);
    a.addBuilding("AS 4 Feeding Silo", "28120 BEEF BARN RD CORVALLIS, OR 97330", 3650);



    //begin menu
    std::cout << "Hello, and welcome to " << a.printUName() << std::endl;
    std::cout << "Please choose an option: " << std::endl;
    std::cout << "1. List of selected buildings on campus," << std::endl;
    std::cout << "2. List of selected instructors and students on campus," << std::endl;
    std::cout << "3. Choose a student or instructor to do work" << std::endl;
    std::cout << "4. Exit this program." << std::endl;

    int userChoice = intYomu(1, 4);

    switch (userChoice) {
        case 1: a.printBuildingInfo();
            break;
        case 2: a.printPeopleInfo();
            break;
        case 3: a.chooseWork();
            break;
        case 4: exit (EXIT_SUCCESS);
            break;
        };


    return 0;
}
