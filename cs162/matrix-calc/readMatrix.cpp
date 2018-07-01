/* Name: Kyle Karthauser
 * Date: April 6, 2018
 * Description: void readMatrix(int** array, int arraySize) 
 * This function takes a pointer to a dynamic 2D array and its
 * "size" ("2" for 2x2 and "3" for 3x3) and asks the user to input
 * the appropriate number of values to fill in the array.
 */

#include "readMatrix.hpp"
#include <iostream>

void readMatrix(int** array, int arraySize){

    std::cout << "Please enter values for the new " << arraySize << "x" << arraySize << " array. Enter one integer at a time." << std::endl;

    //We will store user input in 1D array to facilitate collection and 
    //re-assignment of values in array
    int valIn = 0; //User input
    int* answers = NULL; //Allocating memory for answers array
    int answersSize = arraySize * arraySize; //Determining size of array
    answers = new int[answersSize]; //Creating the array
   
    //Collecting array values 
    for (int i = 0; i < answersSize; i++){
        std::cout << "Value " << i + 1 << " of " << answersSize << std::endl;
        std::cin >> valIn;
        answers[i] = valIn;
    } 

    //Now we assign array user inputted values above
    int counter = 0; 
    for (int x = 0; x < arraySize; x++) {
        for (int y = 0; y < arraySize; y++) {
            array[x][y] = answers[counter];
            counter++;
        }
    }

    //Freeing up answers array memory
    delete [] answers;

}         
