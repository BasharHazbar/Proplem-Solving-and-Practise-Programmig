

#include <iostream>
#include <string>
using namespace std;

int readNumber() {
    int r;
    cout << "enter the radios of circle:- " << endl;
    cin >> r;
    return r;
}

float calcAreaRectangle(int r) {
    const float pi = 3.14159265359;
    float area = pi * pow(r,2);
    return area;
}

void printNumber(float area) {
    cout << "the area of circle is:- " << area;
}

int main()
{   
    printNumber(calcAreaRectangle(readNumber()));
}

