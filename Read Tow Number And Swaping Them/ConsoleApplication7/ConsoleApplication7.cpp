// ConsoleApplication7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;


//void read2Number(int & num_1, int& num_2) {
//    cout << "enter the number_1:- " << endl;
//    cin >> num_1;
//
//    cout << "enter the number_2:- " << endl;
//    cin >> num_2;  
//}
//
//void print2Number(int num_1, int num_2) {
//    cout << "the number one is " << num_1 << endl;
//    cout << "the number tow is " << num_2 << endl;
//}
//
//void swap2Numbers(int& num_1, int& num_2) {
//    cout << "swap start ============= " << endl;
//    int temp = num_1;
//    num_1 = num_2;
//    num_2 = temp;
//}

struct stNumbers {
    int num_1, num_2;
};

stNumbers read2Number(stNumbers& numbers) {
    cout << "enter the number_1:- " << endl;
    cin >> numbers.num_1;

    cout << "enter the number_2:- " << endl;
    cin >> numbers.num_2;

    return numbers;
}

void print2Number(stNumbers info) {
    cout << "the number one is " << info.num_1 << endl;
    cout << "the number tow is " << info.num_2 << endl;
}

stNumbers swap2Numbers(stNumbers & info) {
    cout << "swap start ============= " << endl;
    int temp = info.num_1;
    info.num_1 = info.num_2;
    info.num_2 = temp;

    return info;
}


int main()
{
    //int num_1, num_2;
    //read2Number(num_1, num_2);
    //print2Number(num_1, num_2);
    //swap2Numbers(num_1, num_2);
    //print2Number(num_1, num_2);

    stNumbers info;

    print2Number(read2Number(info));
    print2Number(swap2Numbers(info));


  /*  cout << "Hello World!\n";*/
}
