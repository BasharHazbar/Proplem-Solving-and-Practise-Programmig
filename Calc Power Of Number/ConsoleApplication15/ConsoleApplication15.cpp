// ConsoleApplication15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

struct enPowerN {
    int n, num;
};

enPowerN readNimberAndN( enPowerN & powerN) {
    do {
        cout << "enter power of number :- " << endl;
        cin >> powerN.n;
        cout << " enter the number to make the power " << endl;
        cin >> powerN.num;
    } while (powerN.n < 0 && powerN.num< 0);
    return powerN;
}

int findPowerOfNumber(enPowerN powerN) {
    int i, power = 1;
    for (i = 1; i <= powerN.n; i++) {
        power *= powerN.num;
    }
    return power;
}

void printPowerOfNumber(enPowerN powerN, int power) {
    cout << "the power of number " << powerN.num << " is:- " << power;
}


int main()
{
    enPowerN powerN;
    printPowerOfNumber(powerN, findPowerOfNumber(readNimberAndN(powerN)));

}


