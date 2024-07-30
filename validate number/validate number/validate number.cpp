

#include <iostream>
using namespace std;

int readNumber() {
    int number;
    cout << "enter a valid number:- ";
    cin >> number;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "enter a valid number:- ";
        cin >> number;
    }
    return number;
}

int main()
{
    cout << "Hello World!\n";

    int number = readNumber();

    cout << number;
}
