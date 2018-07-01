ZOOM
/*************************************************************************
*
** Author: Josh Kinzel
** Date: 02/21/2018
** Assignment 7b
** Description: Function stdDev calculates and returns the standard
deviation
** of all the integers of variable "age" in an array of type class
"Person"
** passed to function.
*************************************************************************
*/
#include "Person.hpp"
#include <cmath>
double stdDev(Person personList[], int listSize){
double sum;                 //sum of all ages passed by array
double mean;                //average of all ages
double sumSquared;          //sum of the squared differences
double standardDeviation;   //standard deviation of all ages
//calculate sum of all ages in "Person" array
for (int i = 0; i < listSize; i++)
sum += personList[i].getAge();
//calculate average of all ages
mean = sum / listSize;
//calculate sum of squared differences (age - mean)^2
for (int i = 0; i < listSize; i++)
sumSquared += pow((personList[i].getAge() - mean), 2);
//calculate standard deviation of all ages
standardDeviation = sqrt(sumSquared / listSize);
//return standard deviation of all ages
return standardDeviation;
}


