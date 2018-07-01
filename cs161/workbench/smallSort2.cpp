/* ******************************************************
 *       Name: Kyle Karthauser                           *
 *       Date: 1/28/18                                   *
 *       Description: This program will accept three int *
 *     parameters as reference variables. It will sort   *
 *       the three integers, lowest to high, and output  *
 *       them in that order.                             *
*********************************************************/

#include <iostream>

using namespace std;

void smallSort(int&, int&, int&);

int main(){

int a, b, c;

cout << "Enter three integers\n";

cin >> a >> b >> c;

smallSort(a, b, c);

    return 0;
}

void smallSort(int &a, int &b, int &c){
 
int valueShift1, valueShift2, valueShift3; // This variable will take on a reference variable value and let us sort before re-assigning

if (c < b && c < a)
    {
    cout << "case 1" << endl;
    valueShift1 = a;
    valueShift2 = b;
    valueShift3 = c;
    a = valueShift3;

        if (valueShift2 < valueShift1)
        {
        b = valueShift2;
        c = valueShift1;
        }
    }

    else if (b < c && b < a)
    {
    cout << "case 2";
    valueShift1 = a;
    valueShift2 = c;
    valueShift3 = b;
    a = valueShift3;

        if (valueShift2 < valueShift1)
        {
        b = valueShift2;
        c = valueShift1;
        }
    }

    else if (a < b && a < c)
    {
    cout << "case 3";
    valueShift1 = b;
    valueShift2 = c;
    valueShift3 = a;
    
        if (valueShift2 < valueShift1)
        {
        b = valueShift2;
        c = valueShift1;
        }
    };    */

    cout << "v1: " << valueShift1 << endl << "v2: " << valueShift2 << endl << "v3: " << valueShift3 << endl;
    cout << "Sorting now" << endl << "a = " << a << endl <<"b = " << b << endl << "c = " << c << endl;
}


