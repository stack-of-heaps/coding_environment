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

void transformArray(int *&array, int arraySize){
    
    //New memory space for dynamic array
    int *arrayPointer;
    
    //New array created at arrayPointer address
    arrayPointer = new int[arraySize * 2];
    
    //Copy old array
    for (int i = 0; i < arraySize; i++)   
        arrayPointer[i] = array[i];       
    
    //Generate second half of new array
    for (int i = arraySize; i < arraySize*2; i++)  
        arrayPointer[i] = array[i - arraySize] + 1;      
        
    //New array is complete; delete old    
    delete array;
    
    //Assign the new array to the old memory address
    array = arrayPointer;
}
