/********************************************************
* Author: Kyle Karthauser                               *
* Date: 1/20/18                                         *
* Description: This program allows the user to determine*
* how many integers to examine, asks for the integers,  *
* then outputs the highest and lowest integer entered.  *
********************************************************/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int intLimit; // User-defined number of integers
int lowInt; // Stores lowest entered integer
int highInt; // Stores highest entered integer
int userInt; // Stores user entered integer
int firstRun = 1; //Used to initialized highInt and lowInt with non-arbitrary values on line 21

int main()
  {

  cout << "How many integers would you like to enter?" << endl;
  cin >> intLimit;
  std::cout << "Please enter " << intLimit << " integers.\n";

  for (int n = 1; n <= intLimit; n++) // Start of integer entry
    {
    std::cin >> userInt;
    if (firstRun) //Ensures that highInt and lowInt are initialized by a non-arbitrary value
      {
      highInt = userInt;
      lowInt = userInt;
      firstRun--;
      }

      if (userInt < lowInt) // Sorting low int
        lowInt = userInt;

      if (userInt > highInt) // Sorting high int
        highInt = userInt;

      if (intLimit == 1) // Don't dislay max/min if only 1 int entered
        {
        std::cout << "You chose to enter only 1 integer. \n";
        std::cout << "Therefore, there is no max/min. Only your integer " << userInt << ". \n";
        return 0;
        }

      if (n == intLimit && highInt == lowInt) // If user enters same integer every time
          {
          std::cout << "You entered the same integer " << n << " times. \n";
          std::cout << "Therefore, there is no min or max. Only your integer " << userInt << ". \n";
          return 0;
          }
    };

  std::cout<<"min: " << lowInt << std::endl; // End of program; display lowest and highest int
  std::cout<<"max: " << highInt << std::endl;

  return 0;
  }
