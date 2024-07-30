// visibility inheritence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "clsAAAA.h"
#include "clsBBBB.h"

using namespace std;


class clsC : protected clsB{
   
    string test() {
        return clsB::f;
    }
public:
    clsC(string a, string b, string c, string s, string f, string p) : clsB(a, b, c,s,f,p) {

    }
};

class clsG : public clsC {
public:
    clsG(string a, string b, string c, string s, string f, string p) : clsC(a, b, c, s, f, p) {
        
    }

};
int main()
{
    clsC c(" ", " ", " ", " ", " ", " ");
    clsG G(" ", " ", " ", " ", " ", " ");
   
}

