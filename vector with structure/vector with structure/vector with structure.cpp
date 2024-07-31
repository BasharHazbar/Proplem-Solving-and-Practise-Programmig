// vector with structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

struct stEmployee {
    string firstName;
    string lastName;
    string phone;
};

int main()
{
    vector <stEmployee> vEmployee;

    stEmployee em;
    em.firstName = "bashar";
    em.lastName = "abdulwahab";
    em.phone = "12323232323";

    vEmployee.push_back(em);

    em.firstName = "bashar1";
    em.lastName = "abdulwahab1";
    em.phone = "123232323231";

    vEmployee.push_back(em);
    
    em.firstName = "bashar2";
    em.lastName = "abdulwahab2";
    em.phone = "123232323232";

    vEmployee.push_back(em);

    for (stEmployee & employee : vEmployee) {

        cout << "first name:- " << employee.firstName << endl;
        cout << "last name:- " << employee.lastName << endl;
        cout << "phone :- " << employee.phone << endl;

        cout << "\n\n";
    }
}

