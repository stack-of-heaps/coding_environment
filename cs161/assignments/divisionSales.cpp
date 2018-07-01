#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

enum Divisions { Southwest = 1, Southeast, Northeast, Northwest, Quit };

double getSales(int);
void divisionWinner(double);

int main()
    {

    string stars;
    int division;
    double salesFig;
    double passThrough;

     do
        {
        cout << "1. Southwest" << endl;
        cout << "2. Southeast" << endl;
        cout << "3. Northeast" << endl;
        cout << "4. Northwest" << endl;

        cout << "Choose a division." << endl;

        cin >> division;

        switch (division)
        case 1: 
            cout << "Please enter a sales figure: $";
            cin >> salesFig;
           // passThrough = getSales(salesFig);
            break;
        }
        while (division != 5 || division != Quit);

    }