#include <iostream>
using namespace std;

enum enNumberType {even = 1, odd = 2};

int readNumber() {
    int number;
    cout << "enter the number:- " << endl;
    cin >> number;
    return number;
}

enNumberType checkNumberType(int number) {

    if (number % 2 == 0)
        return enNumberType::even;
    else
        return enNumberType::odd;
}

void printNumber(enNumberType numerType) {
    
    if (numerType == enNumberType::even) {
        cout << "the number is even";
    }
    else {
        cout << "the number is odd";
    }
}


int main()
{
    printNumber(checkNumberType(readNumber()));
}
