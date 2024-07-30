
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World!\n";
    int array[10] = { 1,2,3,4,5,6,7,8,9,10 };
    for (int number : array) {
        cout << number;
    }
}
