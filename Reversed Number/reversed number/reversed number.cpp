
#include <iostream>
#include <string>

using namespace std;

void fillArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "please enter a positive number:- " << endl;
        cin >> array[i];
    }
}

void printAndMakeInRevers(int array[], int n) {
    cout << "the number in reverse :- " << endl;
    for (int i = n - 1; i >= 0; i--) {
        cout << array[i];
    }
}


int main()
{
    //int n = 0;
    //cout << "enter the n of numbers:- " << endl;
    //cin >> n;
    int array[100], n = 5;
    fillArray(array, n);
    printAndMakeInRevers(array, n);
}
