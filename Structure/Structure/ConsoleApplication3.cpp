#include <iostream>
using namespace std;

struct stInfo{
    int age;
    char isHasDraivedLecience;
    char isHasRecommendation;
};

stInfo readInfo(stInfo &info) {
    cout << "enter your age:- \n";
    cin >> info.age;
    cout << "Do you have DraivedLecience enter 'y' or 'n' :- \n";
    cin >> info.isHasDraivedLecience;
    cout << "Do you have recommendation enter 'y' or 'no' :- \n";
    cin >> info.isHasRecommendation;

    return info;
}

bool isAccept(stInfo info) {
    if (info.isHasRecommendation == 'y') {
      return true;
    }
    else {
        return (info.age >= 18 && info.isHasDraivedLecience == 'y');
        //if (info.age >= 18 && info.isHasDraivedLecience == 'y') {
        //    return true;
        //}
        //else {
        //    return false;
        //}
    }
}

void printResult(stInfo info) {
    if (isAccept(info)) {
        cout << "Hired";
    }
    else
        cout << "reject";
}

int main()
{
    stInfo info;
    printResult(readInfo(info));
}
