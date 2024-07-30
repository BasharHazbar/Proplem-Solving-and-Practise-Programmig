// local time and universal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma warning(disable : 4996)

#include <iostream>
#include <ctime>


using namespace std;

int main()

{
    time_t t = time(0);

    char* dt = ctime(&t);

    cout << "Local date and time is: " << dt << "\n";

    // converting now to tm struct for UTC date/time
    tm* gmtm = gmtime(&t);    
    dt = asctime(gmtm);    
    cout << "UTC date and time is: " << dt;
}

