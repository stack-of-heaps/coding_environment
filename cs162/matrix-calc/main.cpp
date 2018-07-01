#include "determinant.hpp"
#include "readMatrix.hpp"

#include <iostream>

int main() {

//I will be using an approach to "dynamic 2D arrays" provided by Mehrdad Afshari
// stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
//Accessed 4/5/18
//This is an "array of pointers to arrays"
	
//prompt user for array size: "2" for 2x2, "3" for 3x3
	int userInput = 0;
    int** array;
	std::cout << "Please enter 2 for a 2x2 array or 3 for a 3x3 array." << std::endl;
    std::cin >> userInput;

	switch (userInput){
	case 2: {
			array = new int*[userInput];
				for (int i = 0; i < userInput; i++) 
						array[i] = new int[userInput];
                //Now we initialize the array with 0 values in each cell

                for (int x = 0; x < userInput; x++) {
                    for (int y = 0; y < userInput; y++) 
                        array[x][y] = 0;
                }
    		break;
	        }
    
    case 3: {
            array = new int*[userInput];
                for (int i = 0; i < userInput; i++)
                    array[i] = new int[userInput];

                //Initialize array with 0 values in each cell
                for (int x = 0; x < userInput; x++){
                    for (int y = 0; y < userInput; y++)
                        array[x][y] = 0;
                }
            break;
            }
    }

    readMatrix(array, userInput);

    int determinantResult = 0;

    determinantResult = determinant(array, userInput);

    //Display array
    for (int x = 0; x < userInput; x++) {
        std::cout << std::endl; 
        for (int y = 0; y < userInput; y++) 
            std::cout << array[x][y];
    }

    std::cout << "\nArray Determinant: " << determinantResult << std::endl;
    
    return 0;

    //Freeing memory
    for (int i = 0; i < userInput; i++)
        delete [] array[i];

    delete [] array;
}
