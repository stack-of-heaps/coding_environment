/******************************************************************
* Description: findMedian() accepts an array of ints and an int   *
* as arguments and returns an int value.                          *
* The function sorts a given array (changing the original array   *
* in the process) using the sort() function, and then determines  *
* the array's median value. The returned int value is the median. *
******************************************************************/

#include <algorithm>

double findMedian(int array[], int size)
{
    double median;
  
    std::sort(array, array + size); // Sort() array values
    
    if (size <= 2)
         return median = (double(array[0]) + array[1]/2);
    if (size % 2 == 0)
        return median = double((array[(size/2)])+array[(size/2)-1])/2;
    else 
        return median = double(array[size/2]);
}