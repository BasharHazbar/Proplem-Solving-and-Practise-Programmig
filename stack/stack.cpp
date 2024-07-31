
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    
    stack <int> stkNumber;

    stkNumber.push(12);
    stkNumber.push(34);
    stkNumber.push(14);
    stkNumber.push(17);
    stkNumber.push(19);
    stkNumber.push(14);
    stkNumber.push(13);

    while (!stkNumber.empty())
    {
        cout << "cout ==> " << stkNumber.top() << endl;

        stkNumber.pop();
    }


    stack <int> myStack_1;
 
    myStack_1.push(12);
    myStack_1.push(34);
    myStack_1.push(14);
    myStack_1.push(17);
    myStack_1.push(19);
    myStack_1.push(14);
    myStack_1.push(13);

    stack <int> myStack_2;
    myStack_2.push(13);
    myStack_2.push(35);
    myStack_2.push(17);
    myStack_2.push(19);
    myStack_2.push(15);
    myStack_2.push(13);
    myStack_2.push(13);

    myStack_1.swap(myStack_2);

    cout << "\n================================================\n";

    while (!myStack_1.empty())
    {
        cout << myStack_1.top() << "  ";

        myStack_1.pop();
    }

    cout << "\n================================================\n";

    while (!myStack_2.empty())
    {
        cout << myStack_2.top() << "  ";

        myStack_2.pop();
    }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
