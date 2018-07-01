#include "menu.hpp"
#include "algorithms.hpp"
#include "yomu.hpp"

void readInFiles(std::string fileName, vec &vec) {

    std::cout << "Reading in file " << fileName << " values to vector..." << std::endl;

    std::fstream inputFile;
    int data;

    inputFile.open(fileName);

    while (inputFile >> data)
        vec.push_back(data);

    inputFile.close();

    std::cout << "Done." << std::endl;

    std::cout << "Vector values: ";
    std::cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        if (i == vec.size() -1)
            std::cout << vec[i] << "]";
        else
            std::cout << vec[i] << ", ";
    }


    std::cout << std::endl;
    std::cout << std::endl;
}

void simpleSearch(vec &vec1, vec &vec2, vec &vec3, vec &vec4) {
    std::cout << "Simple Search" << std::endl;
    std::cout << "Please enter an integer to search for: " << std::endl;
    int userInput = intYomu();

    std::cout << "Searching for: " << userInput << std::endl;

    bool searchResult;

    std::cout << "File0.txt: ";
    searchResult = algoSearch(userInput, vec1);
    if (searchResult == true)
        std::cout << "Target value found" << std::endl;
    else
        std::cout << "Target value not found" << std::endl;

    std::cout<< std::endl;
    
    std::cout << "File1.txt: " << std::endl;
    searchResult = algoSearch(userInput, vec2);
    if (searchResult == true)
        std::cout << "Target value found" << std::endl;
    else
        std::cout << "Target value not found" << std::endl;
   
    std::cout << "File2.txt: " << std::endl;
    searchResult = algoSearch(userInput, vec3);
    if (searchResult == true)
        std::cout << "Target value found" << std::endl;
    else
        std::cout << "Target value not found" << std::endl;
   
    std::cout << "File3.txt: " << std::endl;
    searchResult = algoSearch(userInput, vec4);
    if (searchResult == true)
        std::cout << "Target value found" << std::endl;
    else
        std::cout << "Target value not found" << std::endl;

}

void simpleSort(int val, vec vec1, vec vec2, vec vec3, vec vec4) {

    std::cout << "Simple Sort" << std::endl;

    std::cout << "File0.txt: " << std::endl;
    std::cout << "File1.txt: " << std::endl;
    std::cout << "File2.txt: " << std::endl;
    std::cout << "File3.txt: " << std::endl;

}

void binarySearch(int val, vec vec1, vec vec2, vec vec3, vec vec4) {

    std::cout << "Binary Search" << std::endl;
    std::cout << "Searching for: " << val << std::endl;

    std::cout << "File0.txt: " << std::endl;
    std::cout << "File1.txt: " << std::endl;
    std::cout << "File2.txt: " << std::endl;
    std::cout << "File3.txt: " << std::endl;
}

void bSearch(vec vec0, vec vec1, vec vec2, vec vec3) {
    std::cout << "Binary Search" << std::endl;
    std::cout << "Please enter an integer to search for: " << std::endl;
    int userInput = intYomu();

    std::cout << "Searching for: " << userInput << std::endl;

    bool searchResult;

    std::cout << "File0.txt: ";
    searchResult = algoBinarySearch(userInput, vec0, 0, 9);
    if (searchResult == true)
        std::cout << "Target value found" << std::endl;
    else
        std::cout << "Target value not found" << std::endl;

    std::cout<< std::endl;
    
    std::cout << "File1.txt: " << std::endl;
    searchResult = algoBinarySearch(userInput, vec1, 0, 10);
    if (searchResult == true)
        std::cout << "Target value found" << std::endl;
    else
        std::cout << "Target value not found" << std::endl;
   
    std::cout << "File2.txt: " << std::endl;
    searchResult = algoBinarySearch(userInput, vec2, 0, 10);
    if (searchResult == true)
        std::cout << "Target value found" << std::endl;
    else
        std::cout << "Target value not found" << std::endl;
   
    std::cout << "File3.txt: " << std::endl;
    searchResult = algoBinarySearch(userInput, vec3, 0, 10);
    if (searchResult == true)
        std::cout << "Target value found" << std::endl;
    else
        std::cout << "Target value not found" << std::endl;

}
