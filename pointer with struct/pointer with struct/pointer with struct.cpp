
#include <iostream>
using namespace std;

struct stEmployee
{
    string firstName;
    float salary;

};

int main()
{
    stEmployee empoyee, * op;

    empoyee.firstName = "bashar";
    empoyee.salary = 1212.334;

    cout << empoyee.firstName << endl;
    cout << empoyee.salary << endl;

    op = &empoyee;

    cout << op << endl;
    cout << op->firstName << endl;
    cout << op->salary << endl;

}

