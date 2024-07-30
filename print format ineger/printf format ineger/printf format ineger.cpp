// printf format ineger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int number = 1, number2 = 2;
    printf("hallo my numer is:-  %d\n", number);
    printf("hallo my numer is:-  %0*d \n", 2, number);
    printf("hallo my numer is:-  %0*d \n", 3, number);
    printf("hallo my numer is:-  %0*d \n", 4, number);
    printf("hallo my numer is:-  %0*d \n", 5, number);
    printf("hallo my numer is:-  %0*d \n",6, number);
    printf("sum:- %d + %d = %d \n", number, number2, number + number2);
    printf("milti:- %d * %d = %d \n", number, number2, number * number2);

}

