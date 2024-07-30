

#include <iostream>
#include <string>

using namespace std;

//int readCircumFerence() {
//    int circumFerence = 0;
//    cout << "ener the circumFerence of cercle:- " << endl;
//    cin >> circumFerence;
//
//    return circumFerence;
//}
//
//float calcCircumFerence(int l) {
//    const float pi = 3.14159265359;
//    float area = pow(l, 2) / (4 * pi);
//    return area;
//}
//
//void printArea(float area) {
//    cout << "the area of circle by CircumFerence == " << area << endl;
//}

struct stNums {
    double a, b, c;
};

stNums readCircumFerence(stNums & nums) {
    cout << "ener the a num:- " << endl;
    cin >> nums.a;
    cout << "ener the b num:- " << endl;
    cin >> nums.b;
    cout << "ener the c num:- " << endl;
    cin >> nums.c;

    return nums;
}

//float calcCircumFerence(stNums nums) {
//    const float pi = 3.14159265359;
//    float area = (pi * (pow(nums.b,2) / 4)) * ( 2 * nums.a  - nums.b) / (2 * nums.a + nums.b);
//    return area;
//}

float calcArea(stNums nums) {
    const double pi = 3.14159265359;
    double p = (nums.a + nums.b + nums.c) / 2;
    double power = (nums.a * nums.b * nums.c) 
        / (4 * sqrt(p * (p - nums.a) * (p - nums.b) * (p - nums.c)));
    cout << "power = " << power << endl;
    double area = pi * pow(power,2);
    return area;
}

void printArea(double area) {
    cout << "the area of circle by CircumFerence == " << area << endl;
}

int main()
{
    stNums nums;
    printArea(calcArea(readCircumFerence(nums)));
    
    return 0;
}

