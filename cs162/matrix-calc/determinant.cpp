/* Name: Kyle Karthauser
 * Date: April 6, 2018
 * Description: int determinant(int** array, arraySize)
 * This function takes a pointer to a dynamically generated
 * 2D array and the "size" of the array as parameters
 * ("2" for 2x2, "3" for 3x3), calculates the array's
 * determinant (according to a process provided by
 * Mathisfun.com), and returns that value as an integer.
 */

#include "determinant.hpp"

int determinant(int** array, int arraySize) {

int determinantResult = 0;

switch (arraySize) {
    case 2: {
            return determinantResult = (array[0][0] * array[1][1]) - (array[0][1] * array[1][0]);
            break;
        }
   
            //Splitting this into 3 parts will make this easier for everybody 
    case 3: {
            int colA = array[0][0] * ((array[1][1] * array[2][2]) - (array[1][2] * array[2][1]));
            int colB = array[0][1] * ((array[1][0] * array[2][2]) - (array[1][2] * array[2][0]));
            int colC = array[0][2] * ((array[1][0] * array[2][1]) - (array[1][1] * array[2][0]));
            return determinantResult = colA - colB + colC;
            break;
        }

    default: std::cout << "Oops, something went wrong." << std::endl;
             break;
    } 
}
