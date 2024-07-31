

#include <iostream>
#include <string>
using namespace std;

int readTheNumber(string Message) {
    cout << Message << endl;
    int number = 0;
    cin >> number;
    return number;
}

int sumNumberUntillEnter_99(){
    int counter = 1;
    int number;
    int sum = 0;
    do {
        number = readTheNumber("enter the number " + to_string(counter));
        if (number != -99) {
            sum += number;
        }
        counter++;

    } while (number != -99);
    return sum;
}

void printNumber(int sum) {
    cout << "the result of sum is: " << sum;
}

int main()
{
    printNumber(sumNumberUntillEnter_99());
}

