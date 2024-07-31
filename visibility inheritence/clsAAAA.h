#pragma once
#include <string>
using namespace std;
class clsA {
private:
    string a;
    string a1;
protected:
    string b;
    string fun1() {
        return "b";
    }
public:
    string c;
    string fun1() {
        return "c";
    }
    clsA(string a, string b, string c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

