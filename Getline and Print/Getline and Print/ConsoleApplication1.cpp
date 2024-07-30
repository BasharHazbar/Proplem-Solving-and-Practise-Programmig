// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> 
#include <string>
using namespace std;

string printName(string name) {
    return "your name is " +  name + "\n";
}

string readName() {
    cout << "enter your name :- " << endl;
    string name;
    
    getline(cin,name);

    return name;
}

int main()
{
   
   //cout << printName("BASHAR Abdulwahab");

    cout << printName(readName());



}

