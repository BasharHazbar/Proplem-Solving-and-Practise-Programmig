

#include <iostream>
#include <string>
using namespace std;


void printMultiplationTabel() {

    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            cout << i << " * " << j << " = " << i * j << endl;
        }
        cout << "   " << endl;
    }
}
int main()
{
    printMultiplationTabel();
}

