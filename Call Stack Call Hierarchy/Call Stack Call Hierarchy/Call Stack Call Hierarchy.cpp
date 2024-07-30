// Call Stack Call Hierarchy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>



void function1() {
      std::cout << "Hello World!\n";
}

void function2() {

    function1();
}

void function3() {
    function2();
}

void function4() {
    function3();
}

void function5() {
    function4();
}
void function6() {
    function5();
}


int main()
{
    function1();
}
