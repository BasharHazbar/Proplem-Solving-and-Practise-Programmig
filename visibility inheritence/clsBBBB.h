#pragma once
#include <string>
#include "clsAAAA.h"
using namespace std;

class clsB : public clsA {
private:
    string s;
    string s1;
protected:
    string f;
    string fun1() {
        return "f";
    }
public:
    string p;
    string fun1() {
        return "p";

        clsA::fun1();
    }
    clsB(string a, string b, string c, string s, string f, string p) : clsA(a, b, c) {
        this->s = s;
        this->f = f;
        this->p = p;
    }
};


