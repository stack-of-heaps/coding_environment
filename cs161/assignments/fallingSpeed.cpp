#include <iostream>
#include <string>
#include <cmath>
using namespace std;

double fallingDistance(int userTime);
int getTime();

int timeIn;
char answer;

int main(){

do
{
    timeIn = getTime();
    fallingDistance(timeIn);

    cout<<endl<<"Would you like to run again with a different input?"<<endl;
    cout<<"Enter 'Y' or 'N' : ";
    cin>>answer;
}
while (answer == 'Y' || answer == 'y');

    return 0;
}

double fallingDistance(int userTime)
    {
    const double G = 9.8;
    double distance;
    distance = .5*G*pow(userTime, 2);
    cout<<distance<<" meters";
    return userTime;
    }
 
int getTime()
{
    cout<<"Please input a time (in seconds): "<<endl;
    cin>>timeIn;
    return timeIn;
}