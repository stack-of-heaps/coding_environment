/*******************************************************************
 * Name: Kyle Karthauser                                            *
 * Date: 2/26/18                                                    *
 * Description: void transformArray(int* [], arraySize) takes a as  *
 * parameters a pointer to an array plus the size of that array.    *
 * The goal is to produce a new array. Half of the new array        *
 * shares the same data as the original; the second half            *
 * is populated with the original array values +1 for each          *
 * position. sampleArray[2] = {1, 2} would produce                  *
 * transformedArray[4] = {1, 2, 2, 3}.                              *
 * *****************************************************************/

#include <iostream>

void transformArray(int*& , int);

//dynamicArray will be the result of transformArray


int main(){
int *ptr = NULL;


int* myArray = new int[3];
myArray[0] = 4;
myArray[1] = 2;
myArray[2] = 5;
transformArray(myArray, 3);

std::cout<<"back in the main program, we have: " << std::endl;

for (int i = 0; i < 6; i++)
std::cout << myArray[i] << std::endl;

    return 0;
}

void transformArray(int* &array, int arraySize){

int *arrayPointer = new int[arraySize * 2];                 // Creating the new array to be twice as long as the old
    
    for (int i = 0; i < arraySize; i++)                     //This for covers first half of pointerArray
        arrayPointer[i] = array[i];                     // First element of pointerArray = first element of arg array
    for (int i = arraySize; i < arraySize*2; i++)           //This for covers second half of pointerArray
        arrayPointer[i] = array[i - arraySize] + 1;     // Now we are at i = arraySize; halfway + 1

delete array;

array = arrayPointer;

    for (int i = 0; i < arraySize * 2; i++)
    std::cout << arrayPointer[i] << std::endl;

}
