#include <iostream>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;

double findMedian(int [], int);

int main() {
 
  int arrayGo[5] = {0, 1, 52, 5235, -5};
  //int arrayLength = sizeof(arrayGo)/sizeof(arrayGo[0]);
  
  //cout << "length of array is " << arrayLength << endl;
  
  cout << "the median is: " <<  findMedian(arrayGo, 5);  
  
  return 0;
}

/******************************************************************
* Description: findMedian() accepts an array of ints and an int   *
* as arguments and returns an int value.                          *
* The function sorts a given array (changing the original array   *
* in the process) using the sort() function, and then determines  *
* the array's median value. The returned int value is the median. *
******************************************************************/

double findMedian(int array[], int size)
{
  //int arraySize = sizeof(array)/sizeof(array[0]);
  
  double median, medianFlag;
  
  std::sort(array, array + size); // Sort() array values
  for (int i = 0; i < size; i++) 
     cout << array[i] << ' ' << endl;
    
  if (size <= 2)
     return median = double((array[0]) + array[1])/2;
  if (size % 2 == 0)
  {
   cout << array[(size/2)] << ", " << array[(size/2)-1] << endl;
    return median = double((array[(size/2)])+array[(size/2)-1])/2;
  }
  else 
    return median = array[size/2];
}

