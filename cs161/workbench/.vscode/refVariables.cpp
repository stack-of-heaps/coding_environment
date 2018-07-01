#include <iostream>
#include <string>

using namespace std;

void getName(string &);
void printName(string);

int main(){

string nickName;

getName(nickName);

nickName = printName(nickName);

    return 0;
}

void getName(string)
{    
    cout<<"Enter your nickname"<<endl;
    cin>>nickName;
}

void printName(string)
{
    cout>>nickName;
}